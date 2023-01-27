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
 * File: test_json_read_int64.cpp
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

class	TestJsonReadInt64 : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadInt64)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		int64_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(JsonReader, int64)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "42";
	// expect to find the same number
	int64_t 	expected = 42;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(JsonReader, int64_fromLowest)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "-9223372036854775808";
	// expect to find -9223372036854775808
	int64_t 	expected = -9223372036854775808;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(JsonReader, int64_fromUnderflow)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "-9223372036854775809";
	// expect to find 0 (no conversion can be done)
	int64_t 	expected = 0;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(JsonReader, int64_fromHighest)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "9223372036854775807";
	// expect to find 9223372036854775807
	int64_t 	expected = 9223372036854775807;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(JsonReader, int64_fromOverflow)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "9223372036854775808";
	// expect to find 0 (no conversion can be done)
	int64_t 	expected = 0;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(JsonReader, int64_fromFloat)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "42.42424242";
	// expect to find 0 (no conversion can be done)
	int64_t 	expected = 0;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(JsonReader, int64_fromString)
{
	TypeManager::findType<TestJsonReadInt64>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	int64_t 	expected = 0;

	TestJsonReadInt64*	test;

	std::string	input = "{\"type\": \"TestJsonReadInt64\", \"value\": " + value + "}";

	test = JsonReader::load<TestJsonReadInt64>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}
