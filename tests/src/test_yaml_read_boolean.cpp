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
 * File: test_yaml_read_boolean.cpp
 * Created: Friday, 23rd December 2022 11:30:33 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 23rd December 2022 11:30:51 pm
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

class	TestYamlReadBoolean : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadBoolean)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		bool	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_yaml_read_boolean()
{
	std::map<std::string, bool>	testsMap({
		std::make_pair("true", true),
		std::make_pair("True", true),
		std::make_pair("TRUE", true),
		std::make_pair("false", false),
		std::make_pair("False", false),
		std::make_pair("FALSE", false)
	});

	TypeManager::findType<TestYamlReadBoolean>();

	TestYamlReadBoolean*	test;
	std::string				input;

	for (const std::pair<std::string, bool>& pair : testsMap)
	{
		std::string value = pair.first;
		bool expected = pair.second;

		input = "type: TestYamlReadBoolean\nvalue: " + value;

		test = YamlReader::load<TestYamlReadBoolean>(input);
		ASSERT(test, "YamlReader::load returned a null object")
		ASSERT(test->value == expected, "failed to retrieve boolean value from YAML input (" + value + "), expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
	}
}

void	test_yaml_read_boolean_null()
{
	TypeManager::findType<TestYamlReadBoolean>();
	std::string value = "~";
	// expect to find boolean default value: false
	bool expected = false;

	TestYamlReadBoolean*	test;

	std::string	input = "type: TestYamlReadBoolean\nvalue: " + value;

	test = YamlReader::load<TestYamlReadBoolean>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_boolean_array()
{
	TypeManager::findType<TestYamlReadBoolean>();
	std::string value = "\n- 42\n- 43\n- 44";
	// expect to find boolean default value: false
	bool expected = false;

	TestYamlReadBoolean*	test;

	std::string	input = "type: TestYamlReadBoolean\nvalue: " + value;

	test = YamlReader::load<TestYamlReadBoolean>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_boolean_map()
{
	TypeManager::findType<TestYamlReadBoolean>();
	std::string value = "\n  a: 42\n  b: 43\n  c: 44";
	// expect to find boolean default value: false
	bool expected = false;

	TestYamlReadBoolean*	test;

	std::string	input = "type: TestYamlReadBoolean\nvalue: " + value;

	test = YamlReader::load<TestYamlReadBoolean>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}
