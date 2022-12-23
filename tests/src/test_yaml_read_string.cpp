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
 * File: test_yaml_read_string.cpp
 * Created: Friday, 23rd December 2022 4:21:25 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 23rd December 2022 4:21:46 pm
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

class	TestYamlReadString : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadString)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		std::string	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_yaml_read_string()
{
	TypeManager::findType<TestYamlReadString>();
	std::string value = "'Hello world!'";
	// expect to find the same string
	std::string expected = "Hello world!";

	TestYamlReadString*	test;

	std::string	input = "type: class TestYamlReadString\nvalue: " + value;

	test = YamlReader().load<TestYamlReadString>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + expected + "', was '" + test->value + "'")
}

void	test_yaml_read_string_from_null()
{
	TypeManager::findType<TestYamlReadString>();
	std::string value = "~";
	// expect to find an empty string
	std::string expected = "";

	TestYamlReadString*	test;

	std::string	input = "type: class TestYamlReadString\nvalue: " + value;

	test = YamlReader().load<TestYamlReadString>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + expected + "', was '" + test->value + "'")
}

void	test_yaml_read_string_from_array()
{
	TypeManager::findType<TestYamlReadString>();
	std::string value = "\n- 42\n- 43\n- 44";
	// expect to find an empty string
	std::string expected = "";

	TestYamlReadString*	test;

	std::string	input = "type: class TestYamlReadString\nvalue: " + value;

	test = YamlReader().load<TestYamlReadString>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + expected + "', was '" + test->value + "'")
}

void	test_yaml_read_string_from_map()
{
	TypeManager::findType<TestYamlReadString>();
	std::string value = "\n  a: 42\n  b: 43\n  c: 44";
	// expect to find an empty string
	std::string expected = "";

	TestYamlReadString*	test;

	std::string	input = "type: class TestYamlReadString\nvalue: " + value;

	test = YamlReader().load<TestYamlReadString>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + expected + "', was '" + test->value + "'")
}
