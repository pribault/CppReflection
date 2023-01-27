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
 * File: test_yaml_read_reflectable.cpp
 * Created: Saturday, 24th December 2022 2:40:38 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 24th December 2022 2:40:39 pm
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

class	TestYamlReadReflectable_Base : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadReflectable_Base)
		REFLECT_ATTRIBUTE(baseValue)
		END_REFLECTION()

		std::string	baseValue;
};

class	TestYamlReadReflectable_Derived : public TestYamlReadReflectable_Base
{
	public:
		START_REFLECTION(TestYamlReadReflectable_Derived, TestYamlReadReflectable_Base)
		REFLECT_ATTRIBUTE(derivedValue)
		END_REFLECTION()

		std::string	derivedValue;
};

class	TestYamlReadReflectable : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadReflectable)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		TestYamlReadReflectable() : value(nullptr) { }

		TestYamlReadReflectable_Base*	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(YamlReader, reflectable)
{
	IType*	reflectableType = TypeManager::findType<TestYamlReadReflectable>();
	IType*	baseType = TypeManager::findType<TestYamlReadReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestYamlReadReflectable_Derived>();

	// expect to find the derived class and the according attributes and values
	TestYamlReadReflectable*	test;
	std::string					expectedBaseValue = "Hello base!";
	std::string					expectedDerivedValue = "Hello derived!";

	std::string	input = "\
type: TestYamlReadReflectable\n\
value:\n\
  type: TestYamlReadReflectable_Derived\n\
  baseValue: \"" + expectedBaseValue + "\"\n\
  derivedValue: \"" + expectedDerivedValue + "\"\n\
";

	test = YamlReader::load<TestYamlReadReflectable>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_TRUE(test->value);
	const IType*	valueType = test->value->getType();
	GTEST_ASSERT_EQ(*valueType, *derivedType);
	GTEST_ASSERT_EQ(test->value->baseValue, expectedBaseValue);
	std::string derivedValue = static_cast<TestYamlReadReflectable_Derived*>(test->value)->derivedValue;
	GTEST_ASSERT_EQ(derivedValue, expectedDerivedValue);
}

GTEST_TEST(YamlReader, reflectable_withTypeMismatch)
{
	IType*	reflectableType = TypeManager::findType<TestYamlReadReflectable>();
	IType*	baseType = TypeManager::findType<TestYamlReadReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestYamlReadReflectable_Derived>();

	// expect to find the base class because no conversion was possible
	TestYamlReadReflectable*	test;
	std::string					expectedBaseValue = "";

	std::string	input = "\
type: TestYamlReadReflectable\n\
value:\n\
  type: TestYamlReadReflectable\n\
";

	test = YamlReader::load<TestYamlReadReflectable>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_TRUE(test->value);
	const IType*	valueType = test->value->getType();
	GTEST_ASSERT_EQ(*valueType, *baseType);
	GTEST_ASSERT_EQ(test->value->baseValue, expectedBaseValue);
}

GTEST_TEST(YamlReader, reflectable_fromNull)
{
	IType*	reflectableType = TypeManager::findType<TestYamlReadReflectable>();
	IType*	baseType = TypeManager::findType<TestYamlReadReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestYamlReadReflectable_Derived>();

	// expect to find the base class
	TestYamlReadReflectable*	test;
	std::string					expectedBaseValue = "";

	std::string	input = "\
type: TestYamlReadReflectable\n\
value: ~\n\
";

	test = YamlReader::load<TestYamlReadReflectable>(input);
	GTEST_ASSERT_TRUE(test);
	GTEST_ASSERT_TRUE(test->value);
	const IType*	valueType = test->value->getType();
	GTEST_ASSERT_EQ(*valueType, *baseType);
	GTEST_ASSERT_EQ(test->value->baseValue, expectedBaseValue);
}
