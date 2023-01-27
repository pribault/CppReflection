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
 * File: test_json_write_string.cpp
 * Created: Saturday, 7th January 2023 1:22:38 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 7th January 2023 1:24:35 pm
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

class	TestJsonWriteString : public Reflectable
{
	public:
		START_REFLECTION(TestJsonWriteString)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		std::string		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(JsonWriter, string)
{
	TypeManager::findType<TestJsonWriteString>();

	TestJsonWriteString	test;
	test.value = "Hello World!";

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteString\",\n\t\"value\" : \"Hello World!\"\n}";

	std::string result = JsonWriter::compute(test);

	GTEST_ASSERT_EQ(result, expected);
}

GTEST_TEST(JsonWriter, string_quotes)
{
	TypeManager::findType<TestJsonWriteString>();

	TestJsonWriteString	test;
	test.value = "Hello\nWorld!";

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteString\",\n\t\"value\" : \"Hello\\nWorld!\"\n}";

	std::string result = JsonWriter::compute(test);

	GTEST_ASSERT_EQ(result, expected);
}
