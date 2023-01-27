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
 * File: test_json_read_double.cpp
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
#include <CppReflection/JsonReader.h>

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

class	TestJsonReadDouble : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadDouble)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		double		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_read_double()
{
	TypeManager::findType<TestJsonReadDouble>();
	std::string value = "42.424242";
	// expect to find the same number
	double 	expected = 42.424242;

	TestJsonReadDouble*	test;

	std::string	input = "{\"type\": \"TestJsonReadDouble\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadDouble>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_double_lowest()
{
	TypeManager::findType<TestJsonReadDouble>();
	double expected = std::numeric_limits<double>::min();
	std::string value = std::to_string(expected);

	TestJsonReadDouble*	test;

	std::string	input = "{\"type\": \"TestJsonReadDouble\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadDouble>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_double_highest()
{
	TypeManager::findType<TestJsonReadDouble>();
	double expected = std::numeric_limits<double>::max();
	std::string value = std::to_string(expected);

	TestJsonReadDouble*	test;

	std::string	input = "{\"type\": \"TestJsonReadDouble\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadDouble>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_double_string()
{
	TypeManager::findType<TestJsonReadDouble>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	double 	expected = 0;

	TestJsonReadDouble*	test;

	std::string	input = "{\"type\": \"TestJsonReadDouble\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadDouble>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(std::fabs(test->value - expected) <= std::numeric_limits<double>::epsilon(), "failed to retrieve double value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}
