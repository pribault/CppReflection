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
 * File: test_type.cpp
 * Created: Friday, 30th December 2022 5:45:47 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 30th December 2022 5:45:49 pm
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

class	TestTypeReflectable_Base : public Reflectable
{
	public:
		START_REFLECTION(TestTypeReflectable_Base)
		REFLECT_ATTRIBUTE(value_base)
		END_REFLECTION()

		std::string	value_base;
};

class	TestTypeReflectable_Derived : public TestTypeReflectable_Base
{
	public:
		START_REFLECTION(TestTypeReflectable_Derived, TestTypeReflectable_Base)
		REFLECT_ATTRIBUTE(value_derived)
		END_REFLECTION()

		int			value_derived;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

GTEST_TEST(Reflectable, type)
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestTypeReflectable_Derived>();
	IType*	stringType = TypeManager::findType<std::string>();
	IType*	intType = TypeManager::findType<int>();

	GTEST_ASSERT_TRUE(baseType);
	GTEST_ASSERT_TRUE(derivedType);
	GTEST_ASSERT_TRUE(stringType);
	GTEST_ASSERT_TRUE(intType);

	// type checks
	GTEST_ASSERT_TRUE(baseType->isReflectable());
	GTEST_ASSERT_FALSE(baseType->isList());
	GTEST_ASSERT_FALSE(baseType->isMap());
	GTEST_ASSERT_FALSE(baseType->isPointer());

	GTEST_ASSERT_TRUE(derivedType->isReflectable());
	GTEST_ASSERT_FALSE(derivedType->isList());
	GTEST_ASSERT_FALSE(derivedType->isMap());
	GTEST_ASSERT_FALSE(derivedType->isPointer());
}

GTEST_TEST(Reflectable, typeInheritance)
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestTypeReflectable_Derived>();
	IType*	stringType = TypeManager::findType<std::string>();
	IType*	intType = TypeManager::findType<int>();

	GTEST_ASSERT_TRUE(baseType);
	GTEST_ASSERT_TRUE(derivedType);
	GTEST_ASSERT_TRUE(stringType);
	GTEST_ASSERT_TRUE(intType);

	IReflectableType*	reflectableBaseType = static_cast<IReflectableType*>(baseType);
	IReflectableType*	reflectableDerivedType = static_cast<IReflectableType*>(derivedType);

	// inheritance checks
	GTEST_ASSERT_EQ(reflectableBaseType->getNbParents(), 0);
	GTEST_ASSERT_EQ(reflectableDerivedType->getNbParents(), 1);
	GTEST_ASSERT_TRUE(reflectableDerivedType->inherits(reflectableBaseType));
}

GTEST_TEST(Reflectable, typeAttributes)
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestTypeReflectable_Derived>();
	IType*	stringType = TypeManager::findType<std::string>();
	IType*	intType = TypeManager::findType<int>();

	GTEST_ASSERT_TRUE(baseType);
	GTEST_ASSERT_TRUE(derivedType);
	GTEST_ASSERT_TRUE(stringType);
	GTEST_ASSERT_TRUE(intType);

	IReflectableType*	reflectableBaseType = static_cast<IReflectableType*>(baseType);
	IReflectableType*	reflectableDerivedType = static_cast<IReflectableType*>(derivedType);

	// attributes checks
	GTEST_ASSERT_EQ(reflectableBaseType->getNbAttributes(), 1);
	GTEST_ASSERT_EQ(reflectableDerivedType->getNbAttributes(), 1);

	const Attribute*	baseAttr = reflectableBaseType->getAttribute(0);
	GTEST_ASSERT_TRUE(baseAttr);
	GTEST_ASSERT_EQ(baseAttr->getName(), "value_base");
	GTEST_ASSERT_EQ(*baseAttr->getType(), *stringType);

	const Attribute*	derivedAttr = reflectableDerivedType->getAttribute(0);
	GTEST_ASSERT_TRUE(derivedAttr);
	GTEST_ASSERT_EQ(derivedAttr->getName(), "value_derived");
	GTEST_ASSERT_EQ(*derivedAttr->getType(), *intType);
}

GTEST_TEST(Reflectable, pointerType)
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	type = TypeManager::findType<TestTypeReflectable_Base*>();

	GTEST_ASSERT_TRUE(baseType);
	GTEST_ASSERT_TRUE(type);
	GTEST_ASSERT_FALSE(baseType->isPointer());
	GTEST_ASSERT_TRUE(type->isPointer());

	IPointerType*	pointerType = static_cast<IPointerType*>(type);

	const IType*	subType = pointerType->getSubType();

	GTEST_ASSERT_TRUE(subType);
	GTEST_ASSERT_FALSE(subType->isPointer());
	GTEST_ASSERT_EQ(*baseType, *subType);
}
