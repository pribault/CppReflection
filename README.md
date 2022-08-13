# CppReflection

[![GitHub license](https://img.shields.io/github/license/pribault/CppReflection)](https://github.com/pribault/CppReflection/blob/master/LICENSE)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/pribault/CppReflection/graphs/commit-activity)

A non intrusive, powerful c++ reflection library

## Getting started

### Include

To enable reflection you only have to include the <b>Reflectable.h</b> header in your code.

### The Reflectable class

CppReflection provides a simple class I highly recommend to inherit in order to reflect an object.

### The Reflection macros

CppReflection provides a set of macros to put inside the definition of your class in order to manage reflection:
|Macro|Description|
|-|-|
|START_REFLECTION(className, parents) |First macro to put in the class. The first parameter is the class name, and the others are the parents of the class if any|
|REFLECT_ATTRIBUTE(attribute)         |Reflect an attribute, the first parameter is the attribute name. This macro must be added after START_REFLECTION in order to work|
|END_REFLECTION()                     |End reflection. This macro must be added after all the previous ones|

### Example

```
class	Point : public Reflectable
{
	public:

		START_REFLECTION(Point)
		REFLECT_ATTRIBUTE(x)
		REFLECT_ATTRIBUTE(y)
		END_REFLECTION()

	private:

		int	x;
		int	y;
};

class	Rectangle : public Point
{
	public:

		START_REFLECTION(Rectangle, Point)
		REFLECT_ATTRIBUTE(w)
		REFLECT_ATTRIBUTE(h)
		END_REFLECTION()

	private:

		int	w;
		int	h;
};
```

This example demonstrates how to reflect an attribute and how to inherit from another Reflectable object

## More details

### Type

The CppReflection focuses on the concept of Type. The Type is a Singleton defining a class, all its parents, attributes, name etc... This way we don't have to store any additional data inside the objects to reflect.
You can retrieve the type of a Reflectable using its getType method, or for any class you can also use the CppReflection::findType<type>() method, example:
```
IType* intType = CppReflection::findType<int>();
```
The type can provide a lot of informations, the type name, the size, the related std::type_info, it can also be used to instanciate a new object etc...
If the type is a Reflectable (you can now this with the IType::isReflectable method), you can also retrieve the parent classes and the attributes (defined by the Attribute class).

### Attribute

An attribute can be retrieve from a IReflectableType object. An attribute contains the related parent class, the attribute name, offset (relative to the parent object), and of course the type.
