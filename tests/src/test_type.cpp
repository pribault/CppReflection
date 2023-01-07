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

void	test_type_reflectable()
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestTypeReflectable_Derived>();
	IType*	stringType = TypeManager::findType<std::string>();
	IType*	intType = TypeManager::findType<int>();

	ASSERT(baseType, "TypeManager couldn't find TestTypeReflectable_Base type")
	ASSERT(derivedType, "TypeManager couldn't find TestTypeReflectable_Derived type")
	ASSERT(stringType, "TypeManager couldn't find std::string type")
	ASSERT(intType, "TypeManager couldn't find int type")

	// type checks
	ASSERT(baseType->isReflectable(), "TestTypeReflectable_Base isn't reflectable")
	ASSERT(!baseType->isList(), "TestTypeReflectable_Base is list")
	ASSERT(!baseType->isMap(), "TestTypeReflectable_Base is map")
	ASSERT(!baseType->isPointer(), "TestTypeReflectable_Base is pointer")

	ASSERT(derivedType->isReflectable(), "TestTypeReflectable_Derived isn't reflectable")
	ASSERT(!derivedType->isList(), "TestTypeReflectable_Derived is list")
	ASSERT(!derivedType->isMap(), "TestTypeReflectable_Derived is map")
	ASSERT(!derivedType->isPointer(), "TestTypeReflectable_Derived is pointer")
}

void	test_type_reflectable_inheritance()
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestTypeReflectable_Derived>();
	IType*	stringType = TypeManager::findType<std::string>();
	IType*	intType = TypeManager::findType<int>();

	ASSERT(baseType, "TypeManager couldn't find TestTypeReflectable_Base type")
	ASSERT(derivedType, "TypeManager couldn't find TestTypeReflectable_Derived type")
	ASSERT(stringType, "TypeManager couldn't find std::string type")
	ASSERT(intType, "TypeManager couldn't find int type")

	IReflectableType*	reflectableBaseType = static_cast<IReflectableType*>(baseType);
	IReflectableType*	reflectableDerivedType = static_cast<IReflectableType*>(derivedType);

	// inheritance checks
	ASSERT(reflectableBaseType->getNbParents() == 0, "Invalid number of parents for TestTypeReflectable_Base, expecting 0 but was " + std::to_string(reflectableBaseType->getNbParents()))
	ASSERT(reflectableDerivedType->getNbParents() == 1, "Invalid number of parents for TestTypeReflectable_Derived, expecting 1 but was " + std::to_string(reflectableDerivedType->getNbParents()))
	ASSERT(reflectableDerivedType->inherits(reflectableBaseType), "TestTypeReflectable_Derived doesn't inherits TestTypeReflectable_Base")
}

void	test_type_reflectable_attributes()
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	derivedType = TypeManager::findType<TestTypeReflectable_Derived>();
	IType*	stringType = TypeManager::findType<std::string>();
	IType*	intType = TypeManager::findType<int>();

	ASSERT(baseType, "TypeManager couldn't find TestTypeReflectable_Base type")
	ASSERT(derivedType, "TypeManager couldn't find TestTypeReflectable_Derived type")
	ASSERT(stringType, "TypeManager couldn't find std::string type")
	ASSERT(intType, "TypeManager couldn't find int type")

	IReflectableType*	reflectableBaseType = static_cast<IReflectableType*>(baseType);
	IReflectableType*	reflectableDerivedType = static_cast<IReflectableType*>(derivedType);

	// attributes checks
	ASSERT(reflectableBaseType->getNbAttributes() == 1, "Invalid number of attributes for TestTypeReflectable_Base, expecting 1 but was " + std::to_string(reflectableBaseType->getNbAttributes()))
	ASSERT(reflectableDerivedType->getNbAttributes() == 1, "Invalid number of attributes for TestTypeReflectable_Derived, expecting 1 but was " + std::to_string(reflectableDerivedType->getNbAttributes()))

	const Attribute*	baseAttr = reflectableBaseType->getAttribute(0);
	ASSERT(baseAttr, "null attribute for TestTypeReflectable_Base")
	ASSERT(baseAttr->getName() == "value_base", "Invalid attribute name for TestTypeReflectable_Base, expecting \"value_base\" but was \"" + baseAttr->getName() + "\"")
	ASSERT(*baseAttr->getType() == *stringType, "Invalid attribute type for TestTypeReflectable_Base, expecting \"" + stringType->getName() + "\" but was \"" + baseAttr->getType()->getName() + "\"")

	const Attribute*	derivedAttr = reflectableDerivedType->getAttribute(0);
	ASSERT(derivedAttr, "null attribute for TestTypeReflectable_Derived")
	ASSERT(derivedAttr->getName() == "value_derived", "Invalid attribute name for TestTypeReflectable_Derived, expecting \"value_derived\" but was \"" + derivedAttr->getName() + "\"")
	ASSERT(*derivedAttr->getType() == *intType, "Invalid attribute type for TestTypeReflectable_Derived, expecting \"" + intType->getName() + "\" but was \"" + derivedAttr->getType()->getName() + "\"")
}

void	test_type_pointer()
{
	IType*	baseType = TypeManager::findType<TestTypeReflectable_Base>();
	IType*	type = TypeManager::findType<TestTypeReflectable_Base*>();

	ASSERT(baseType, "TypeManager couldn't find TestTypeReflectable_Base type")
	ASSERT(type, "TypeManager couldn't find TestTypeReflectable_Base* type")
	ASSERT(!baseType->isPointer(), "TestTypeReflectable_Base is a pointer")
	ASSERT(type->isPointer(), "TestTypeReflectable_Base* is not a pointer")

	IPointerType*	pointerType = static_cast<IPointerType*>(type);

	const IType*	subType = pointerType->getSubType();

	ASSERT(subType, "sub type is null")
	ASSERT(!subType->isPointer(), "sub type is a pointer")
	ASSERT(*baseType == *subType, "sub type mismatch, expected '" + baseType->getName() + "' but was '" + subType->getName() + "'")
}
