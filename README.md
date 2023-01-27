# CppReflection

[![GitHub license](https://img.shields.io/github/license/pribault/CppReflection)](https://github.com/pribault/CppReflection/blob/master/LICENSE)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/pribault/CppReflection/graphs/commit-activity)

A non intrusive, powerful c++ reflection library

## Getting started

### Dependencies

Before compiling the project, you need to install the following dependencies :
- <b>python</b>
- <b>cmake</b>
- <b>vcpkg</b>
- a c++ compiler depending on your platform (<b>msvc</b> for Windows, <b>clang++</b> or <b>g++</b> for Unix systems)

The environment variable VCPKG_PATH needs to be defined to the vcpkg install directory.
You also need to install some dependencies using vcpkg, on Windows:

`vcpkg install --triplet=x64-windows yaml-cpp jsoncpp gtest`

On Linux systems:

`vcpkg install --triplet=x64-linux yaml-cpp jsoncpp gtest`

### Build

Some scripts are present inside the <b>scripts</b> directory to easily build and package this library.

```
python ./scripts/cmake.py
python ./scripts/build.py
python ./scripts/runTests.py
python ./scripts/release.py
```

The resulting binaires will be located inside the <b>build/bin</b> directory.
Some examples and unit tests will also be built, feel free to try them

### Releases

You can find the release builds here : https://github.com/pribault/CppReflection/releases

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

This example demonstrates how to reflect an attribute and how to inherit from another Reflectable object.

Some classes are also present to help you manipulate your objects, for example to read and write an object from/to YAML :

```
	Rectangle	rectangle;

	rectangle.x = 42;
	rectangle.y = -66;
	rectangle.w = 1920;
	rectangle.h = 1080;

	std::cout << YamlWriter::compute(rectangle) << std::endl;
```

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
