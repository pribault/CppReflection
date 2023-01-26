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
 * File: test_json_read_int32.cpp
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

class	TestJsonReadInt32 : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadInt32)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		int32_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_read_int32()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "42";
	// expect to find the same number
	int32_t 	expected = 42;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int32_lowest()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "-2147483648";
	// expect to find -2147483648
	int32_t 	expected = -2147483648;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int32_underflow()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "-2147483649";
	// expect to find 0 (no conversion can be done)
	int32_t 	expected = 0;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int32_highest()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "2147483647";
	// expect to find 2147483647
	int32_t 	expected = 2147483647;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int32_overflow()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "2147483648";
	// expect to find 0 (no conversion can be done)
	int32_t 	expected = 0;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int32_float()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "42.42424242";
	// expect to find 0 (no conversion can be done)
	int32_t 	expected = 0;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int32_string()
{
	TypeManager::findType<TestJsonReadInt32>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	int32_t 	expected = 0;

	TestJsonReadInt32*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt32\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt32>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int32 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}
