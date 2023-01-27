/*
 * MIT License
 * 
 * Copyright (c) 2023 paul ribault
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
 * File: test_json_write_int8.cpp
 * Created: Saturday, 7th January 2023 1:21:42 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 7th January 2023 1:24:16 pm
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
#include <CppReflection/JsonWriter.h>

// stl
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

class	TestJsonWriteInt8 : public Reflectable
{
	public:
		START_REFLECTION(TestJsonWriteInt8)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		int8_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(JsonWriter, int8)
{
	TypeManager::findType<TestJsonWriteInt8>();

	TestJsonWriteInt8	test;
	test.value = std::numeric_limits<int8_t>::max() / 2;

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteInt8\",\n\t\"value\" : " + std::to_string(test.value) + "\n}";

	std::string result = JsonWriter::compute(test);

	GTEST_ASSERT_EQ(result, expected);
}

GTEST_TEST(JsonWriter, int8_min)
{
	TypeManager::findType<TestJsonWriteInt8>();

	TestJsonWriteInt8	test;
	test.value = std::numeric_limits<int8_t>::min();

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteInt8\",\n\t\"value\" : " + std::to_string(test.value) + "\n}";

	std::string result = JsonWriter::compute(test);

	GTEST_ASSERT_EQ(result, expected);
}

GTEST_TEST(JsonWriter, int8_max)
{
	TypeManager::findType<TestJsonWriteInt8>();

	TestJsonWriteInt8	test;
	test.value = std::numeric_limits<int8_t>::max();

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteInt8\",\n\t\"value\" : " + std::to_string(test.value) + "\n}";

	std::string result = JsonWriter::compute(test);

	GTEST_ASSERT_EQ(result, expected);
}
