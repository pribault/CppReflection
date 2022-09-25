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
 * File: TypeManager.cpp
 * Created: 13th August 2022 3:00:34 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 3:00:36 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/TypeManager.h"

/*
****************
** namespaces **
****************
*/

using namespace	CppReflection;

/*
***********************************************************************************
************************************ ATTRIBUTES ***********************************
***********************************************************************************
*/

TypeManager*	TypeManager::_instance = nullptr;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

TypeManager::TypeManager()
{
}

TypeManager::~TypeManager()
{
}

TypeManager*	TypeManager::get()
{
	if (!_instance)
		_instance = new TypeManager();
	return _instance;
}

IType*	TypeManager::findType(const std::string& typeName)
{
	return TypeManager::get()->getType(typeName);
}

IType*	TypeManager::registerAndGet(IType* type)
{
	TypeMap::const_iterator	it = _typeMap.find(type->getName());

	if (it == _typeMap.cend())
		_typeMap[type->getName()] = type;

	return type;
}

IType*	TypeManager::getType(const std::string& typeName) const
{
	TypeMap::const_iterator	it = _typeMap.find(typeName);

	if (it != _typeMap.cend())
		return it->second;

	return nullptr;
}
