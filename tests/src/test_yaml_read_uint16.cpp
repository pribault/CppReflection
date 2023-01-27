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
 * File: test_yaml_read_uint16.cpp
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

class	TestYamlReadUint16 : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadUint16)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		uint16_t		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(YamlReader, uint16)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "42";
	// expect to find the same number
	uint16_t 	expected = 42;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromNull)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "~";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromLowest)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "0";
	// expect to find 0
	uint16_t 	expected = 0;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromUnderflow)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "-1";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromHighest)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "65535";
	// expect to find 65535
	uint16_t 	expected = 65535;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromOverflow)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "65536";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromFloat)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "42.42424242";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}

GTEST_TEST(YamlReader, uint16_fromString)
{
	TypeManager::findType<TestYamlReadUint16>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	uint16_t 	expected = 0;

	TestYamlReadUint16*	test;

	std::string	input = "type: TestYamlReadUint16\nvalue: " + value;

	test = YamlReader::load<TestYamlReadUint16>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_EQ(test->value, expected);
}
