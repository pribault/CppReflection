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
 * File: test_json_read_string.cpp
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

class	TestJsonReadString : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadString)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		std::string	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_read_string()
{
	TypeManager::findType<TestJsonReadString>();
	std::string value = "\"Hello world!\"";
	// expect to find the same string
	std::string expected = "Hello world!";

	TestJsonReadString*	test;

	std::string	input = "{\"type\": \"TestJsonReadString\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadString>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from JSON input, expecting '" + expected + "', was '" + test->value + "'")
}

void	test_json_read_string_array()
{
	TypeManager::findType<TestJsonReadString>();
	std::string value = "[42, 43, 44]";
	// expect to find an empty string
	std::string expected = "";

	TestJsonReadString*	test;

	std::string	input = "{\"type\": \"TestJsonReadString\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadString>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from JSON input, expecting '" + expected + "', was '" + test->value + "'")
}

void	test_json_read_string_map()
{
	TypeManager::findType<TestJsonReadString>();
	std::string value = "{\"a\": 42, \"b\": 43, \"c\": 44}";
	// expect to find an empty string
	std::string expected = "";

	TestJsonReadString*	test;

	std::string	input = "{\"type\": \"TestJsonReadString\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadString>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from JSON input, expecting '" + expected + "', was '" + test->value + "'")
}
