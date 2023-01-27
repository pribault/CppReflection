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
 * File: test_yaml_read_double.cpp
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

// stl
#include <cmath>
#include <limits>

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

class	TestYamlReadDouble : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadDouble)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		double		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_yaml_read_double()
{
	TypeManager::findType<TestYamlReadDouble>();
	std::string value = "42.424242";
	// expect to find the same number
	double 	expected = 42.424242;

	TestYamlReadDouble*	test;

	std::string	input = "type: TestYamlReadDouble\nvalue: " + value;

	test = YamlReader::load<TestYamlReadDouble>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_double_null()
{
	TypeManager::findType<TestYamlReadDouble>();
	std::string value = "~";
	// expect to find 0 (no conversion can be done)
	double 	expected = 0;

	TestYamlReadDouble*	test;

	std::string	input = "type: TestYamlReadDouble\nvalue: " + value;

	test = YamlReader::load<TestYamlReadDouble>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_double_lowest()
{
	TypeManager::findType<TestYamlReadDouble>();
	double expected = std::numeric_limits<double>::min();
	std::string value = std::to_string(expected);

	TestYamlReadDouble*	test;

	std::string	input = "type: TestYamlReadDouble\nvalue: " + value;

	test = YamlReader::load<TestYamlReadDouble>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_double_highest()
{
	TypeManager::findType<TestYamlReadDouble>();
	double expected = std::numeric_limits<double>::max();
	std::string value = std::to_string(expected);

	TestYamlReadDouble*	test;

	std::string	input = "type: TestYamlReadDouble\nvalue: " + value;

	test = YamlReader::load<TestYamlReadDouble>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_yaml_read_double_string()
{
	TypeManager::findType<TestYamlReadDouble>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	double 	expected = 0;

	TestYamlReadDouble*	test;

	std::string	input = "type: TestYamlReadDouble\nvalue: " + value;

	test = YamlReader::load<TestYamlReadDouble>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from YAML input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}
