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
 * File: test_json_read_int8.cpp
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

class	TestJsonReadInt8 : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadInt8)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		int8_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_read_int8()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "42";
	// expect to find the same number
	int8_t 	expected = 42;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int8_lowest()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "-128";
	// expect to find -128
	int8_t 	expected = -128;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int8_underflow()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "-129";
	// expect to find 0 (no conversion can be done)
	int8_t 	expected = 0;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int8_highest()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "127";
	// expect to find 127
	int8_t 	expected = 127;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int8_overflow()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "128";
	// expect to find 0 (no conversion can be done)
	int8_t 	expected = 0;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int8_float()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "42.42424242";
	// expect to find 0 (no conversion can be done)
	int8_t 	expected = 0;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_int8_string()
{
	TypeManager::findType<TestJsonReadInt8>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	int8_t 	expected = 0;

	TestJsonReadInt8*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt8\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt8>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve int8 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}
