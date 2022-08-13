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
 * File: IReflectableType.cpp
 * Created: 13th August 2022 4:36:30 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 4:36:33 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/IReflectableType.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/Attribute.h"

/*
****************
** namespaces **
****************
*/

using namespace	CppReflection;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

IReflectableType::IReflectableType(void)
{
}

IReflectableType::IReflectableType(const std::string& name, size_t size, const std::type_info* typeInfo) :
	IType(name, size, typeInfo)
{
}

IReflectableType::~IReflectableType(void)
{
}

void							IReflectableType::addParent(IReflectableType* parent)
{
	_parents.push_back(parent);
}

void							IReflectableType::removeParent(size_t index)
{
	if (index < _parents.size())
		return ;
	std::vector<IReflectableType*>::iterator iterator = _parents.begin() + index;
	_parents.erase(iterator);
}

size_t							IReflectableType::getNbParents(void) const
{
	return (_parents.size());
}

IReflectableType* 				IReflectableType::getParent(size_t index) const
{
	if (index < _parents.size())
		return (_parents[index]);
	return (nullptr);
}

void							IReflectableType::addAttribute(Attribute* attribute)
{
	_attributes.push_back(attribute);
}

void							IReflectableType::removeAttribute(size_t index)
{
	if (index < _attributes.size())
		return ;
	std::vector<Attribute*>::iterator iterator = _attributes.begin() + index;
	_attributes.erase(iterator);
}

size_t							IReflectableType::getNbAttributes(void) const
{
	return (_attributes.size());
}

Attribute*						IReflectableType::getAttribute(size_t index) const
{
	if (index < _attributes.size())
		return (_attributes[index]);
	return (nullptr);
}

size_t							IReflectableType::findAttribute(const std::string& name) const
{
	for (size_t index = 0; index < _attributes.size(); index++)
	{
		Attribute*	attribute = _attributes[index];

		if (attribute->getName() == name)
			return (index);
	}
	return ((size_t)-1);
}
