# CppReflection

[![GitHub license](https://img.shields.io/github/license/pribault/CppReflection)](https://github.com/pribault/CppReflection/blob/master/LICENSE)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/pribault/CppReflection/graphs/commit-activity)

A non intrusive, powerful c++ reflection library.<br/>
This library currently supports:
- class reflection and introspection
- c++ fundamental types (booleans, floating point numbers, signed and unsigned integers, pointers)
- some stl containers (<b>std::string</b>, <b>std::vector</b>, <b>std::list</b>, <b>std::map</b>)
- runtime type check
- <b>json</b> and <b>yaml</b> serialization and deserialization.<br/>

[Documentation](https://github.com/pribault/CppReflection/wiki)

## Getting started

### Dependencies

Before compiling the project, you need to install the following dependencies :
- <b>python3</b>
- <b>cmake</b>
- <b>vcpkg</b>
- a c++ compiler depending on your platform (<b>msvc</b> for Windows, <b>clang++</b> or <b>g++</b> for Unix systems), minimum c++ version: 11

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

### Tests

This project uses GoogleTest to guarantee quality and stability over time.

### A quick example

```
#include <CppReflection/Reflectable.h>
#include <CppReflection/YamlWriter.h>
#include <iostream>

using namespace	CppReflection;

class	Point : public Reflectable
{
	public:

		START_REFLECTION(Point)
		REFLECT_ATTRIBUTE(x)
		REFLECT_ATTRIBUTE(y)
		END_REFLECTION()

		int	x;
		int	y;
};

int main()
{
	Point	point;

	point.x = 42;
	point.y = 42;
	std::cout << YamlWriter::compute(point) << std::endl;
	return 0;
}
```

This example demonstrates how to reflectable a class and serialize it to yaml.
Take a look at [the wiki](https://github.com/pribault/CppReflection/wiki) for more informations.
