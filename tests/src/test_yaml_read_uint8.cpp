/*
 * MIT License
 * 
 * Copyright (c) 2022 paul ribault
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * File: test_yaml_read_uint8.cpp
 * Created: Friday, 23rd December 2022 5:02:19 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 23rd December 2022 5:02:21 pm
 * Modified By: Ribault Paul (pribault.dev@gmail.com)
 */

#include "unit_tests.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/Reflectable.h>
#include <CppReflection/YamlReader.h>

/*
****************
** namespaces **
****************
*/

using namespace	CppReflection;

/*
********************************************************************************
************************************ CLASSES ***********************************
********************************************************************************
*/

class	TestYamlReadUint8 : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadUint8)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		uint8_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_yaml_read_uint8()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "42";
	// expect to find the same number
	uint8_t 	expected = 42;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_uint8_lowest()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "0";
	// expect to find 0
	uint8_t 	expected = 0;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_uint8_underflow()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "-1";
	// expect to find 0 (no conversion can be done)
	uint8_t 	expected = 0;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_uint8_highest()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "255";
	// expect to find 255
	uint8_t 	expected = 255;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_uint8_overflow()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "256";
	// expect to find 0 (no conversion can be done)
	uint8_t 	expected = 0;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_uint8_float()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "42.42424242";
	// expect to find 0 (no conversion can be done)
	uint8_t 	expected = 0;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_uint8_string()
{
	TypeManager::findType<TestYamlReadUint8>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	uint8_t 	expected = 0;

	TestYamlReadUint8*	test;

	std::string	input = "type: TestYamlReadUint8\nvalue: " + value;

	test = YamlReader().load<TestYamlReadUint8>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint8 value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}
