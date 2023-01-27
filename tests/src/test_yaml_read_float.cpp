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
 * File: test_yaml_read_float.cpp
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

class	TestYamlReadFloat : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadFloat)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		float		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(YamlReader, float)
{
	TypeManager::findType<TestYamlReadFloat>();
	std::string value = "42.424242";
	// expect to find the same number
	float 	expected = 42.424242f;

	TestYamlReadFloat*	test;

	std::string	input = "type: TestYamlReadFloat\nvalue: " + value;

	test = YamlReader::load<TestYamlReadFloat>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_LE(std::fabs(test->value - expected), std::numeric_limits<float>::epsilon());
}

GTEST_TEST(YamlReader, float_fromNull)
{
	TypeManager::findType<TestYamlReadFloat>();
	std::string value = "~";
	// expect to find 0 (no conversion can be done)
	float 	expected = 0;

	TestYamlReadFloat*	test;

	std::string	input = "type: TestYamlReadFloat\nvalue: " + value;

	test = YamlReader::load<TestYamlReadFloat>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_LE(std::fabs(test->value - expected), std::numeric_limits<float>::epsilon());
}

GTEST_TEST(YamlReader, float_fromLowest)
{
	TypeManager::findType<TestYamlReadFloat>();
	float expected = std::numeric_limits<float>::min();
	std::string value = std::to_string(expected);

	TestYamlReadFloat*	test;

	std::string	input = "type: TestYamlReadFloat\nvalue: " + value;

	test = YamlReader::load<TestYamlReadFloat>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_LE(std::fabs(test->value - expected), std::numeric_limits<float>::epsilon());
}

GTEST_TEST(YamlReader, float_fromHighest)
{
	TypeManager::findType<TestYamlReadFloat>();
	float expected = std::numeric_limits<float>::max();
	std::string value = std::to_string(expected);

	TestYamlReadFloat*	test;

	std::string	input = "type: TestYamlReadFloat\nvalue: " + value;

	test = YamlReader::load<TestYamlReadFloat>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_LE(std::fabs(test->value - expected), std::numeric_limits<float>::epsilon());
}

GTEST_TEST(YamlReader, float_fromString)
{
	TypeManager::findType<TestYamlReadFloat>();
	std::string value = "Hello world!";
	// expect to find 0 (no conversion can be done)
	float 	expected = 0;

	TestYamlReadFloat*	test;

	std::string	input = "type: TestYamlReadFloat\nvalue: " + value;

	test = YamlReader::load<TestYamlReadFloat>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_LE(std::fabs(test->value - expected), std::numeric_limits<float>::epsilon());
}
