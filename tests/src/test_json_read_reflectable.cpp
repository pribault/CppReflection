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
 * File: test_json_read_reflectable.cpp
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

class	TestJsonReadReflectable_Base : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadReflectable_Base)
		REFLECT_ATTRIBUTE(baseValue)
		END_REFLECTION()

		std::string	baseValue;
};

class	TestJsonReadReflectable_Derived : public TestJsonReadReflectable_Base
{
	public:
		START_REFLECTION(TestJsonReadReflectable_Derived, TestJsonReadReflectable_Base)
		REFLECT_ATTRIBUTE(derivedValue)
		END_REFLECTION()

		std::string	derivedValue;
};

class	TestJsonReadReflectable : public Reflectable
{
	public:
		START_REFLECTION(TestJsonReadReflectable)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		TestJsonReadReflectable() : value(nullptr) { }

		TestJsonReadReflectable_Base*	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_read_reflectable()
{
	IType*	reflectableType = TypeManager::findType<TestJsonReadReflectable>();
	IType*	baseType = TypeManager::findType<TestJsonReadReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestJsonReadReflectable_Derived>();

	// expect to find the derived class and the according attributes and values
	TestJsonReadReflectable*	test;
	std::string					expectedBaseValue = "Hello base!";
	std::string					expectedDerivedValue = "Hello derived!";

	std::string	input = "\
{\n\
	\"type\": \"TestJsonReadReflectable\",\n\
	\"value\":\n\
	{\n\
		\"type\": \"TestJsonReadReflectable_Derived\",\n\
		\"baseValue\": \"" + expectedBaseValue + "\",\n\
		\"derivedValue\": \"" + expectedDerivedValue + "\"\n\
	}\n\
}\n\
";

	test = JsonReader::load<TestJsonReadReflectable>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value, "null value")
	const IType*	valueType = test->value->getType();
	ASSERT(*valueType == *derivedType, "expecting value type '" + derivedType->getName() + "' but was '" + valueType->getName() + "'")
	ASSERT(test->value->baseValue == expectedBaseValue, "base value to be '" + expectedBaseValue + "' but was '" + test->value->baseValue + "'")
	std::string derivedValue = static_cast<TestJsonReadReflectable_Derived*>(test->value)->derivedValue;
	ASSERT(derivedValue == expectedDerivedValue, "base value to be '" + expectedDerivedValue + "' but was '" + derivedValue + "'")
}

void	test_json_read_reflectable_type_mismatch()
{
	IType*	reflectableType = TypeManager::findType<TestJsonReadReflectable>();
	IType*	baseType = TypeManager::findType<TestJsonReadReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestJsonReadReflectable_Derived>();

	// expect to find the base class because no conversion was possible
	TestJsonReadReflectable*	test;
	std::string					expectedBaseValue = "";

	std::string	input = "\
{\n\
	\"type\": \"TestJsonReadReflectable\",\n\
	\"value\":\n\
	{\n\
		\"type\": \"TestJsonReadReflectable\"\n\
	}\n\
}\n\
";

	test = JsonReader::load<TestJsonReadReflectable>(input);
	ASSERT(test, "JsonReader::load returned a null object")
	ASSERT(test->value, "null value")
	const IType*	valueType = test->value->getType();
	ASSERT(*valueType == *baseType, "expecting value type '" + baseType->getName() + "' but was '" + valueType->getName() + "'")
	ASSERT(test->value->baseValue == expectedBaseValue, "base value to be '" + expectedBaseValue + "' but was '" + test->value->baseValue + "'")
}
