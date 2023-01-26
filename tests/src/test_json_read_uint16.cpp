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
 * File: test_json_read_uint16.cpp
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

class	TestJsonReadUint16 : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadUint16)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		uint16_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_read_uint16()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "42";
	// expect to find the same number
	uint16_t 	expected = 42;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_uint16_lowest()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "0";
	// expect to find 0
	uint16_t 	expected = 0;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_uint16_underflow()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "-1";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_uint16_highest()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "65535";
	// expect to find 65535
	uint16_t 	expected = 65535;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_uint16_overflow()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "65536";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_uint16_float()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "42.42424242";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}

void	test_json_read_uint16_string()
{
	TypeManager::findType<TestJsonReadUint16>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestJsonReadUint16*	test;

	std::string	input = "{\"type\": \"TestJsonReadUint16\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadUint16>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve uint16 value from JSON input, expecting '" + std::to_string(expected) + "', was '" + std::to_string(test->value) + "'")
}