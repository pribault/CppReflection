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
 * File: test_yaml_read_pointer.cpp
 * Created: Saturday, 24th December 2022 2:36:56 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 24th December 2022 2:36:57 pm
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

class	TestYamlReadPointer : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadPointer)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		TestYamlReadPointer() : value(nullptr) { }

		std::string*	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(YamlReader, pointer)
{
	TypeManager::findType<TestYamlReadPointer>();
	std::string value = "'Hello world!'";
	// expect to find the same string
	std::string expected = "Hello world!";

	TestYamlReadPointer*	test;

	std::string	input = "type: TestYamlReadPointer\nvalue: " + value;

	test = YamlReader::load<TestYamlReadPointer>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_TRUE(test->value);
	GTEST_ASSERT_EQ(*test->value, expected);
}

GTEST_TEST(YamlReader, pointer_fromNull)
{
	TypeManager::findType<TestYamlReadPointer>();
	std::string value = "~";
	// expect to find an empty string
	std::string expected = "";

	TestYamlReadPointer*	test;

	std::string	input = "type: TestYamlReadPointer\nvalue: " + value;

	test = YamlReader::load<TestYamlReadPointer>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_TRUE(test->value);
	GTEST_ASSERT_EQ(*test->value, expected);
}
