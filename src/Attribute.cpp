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
 * File: Attribute.cpp
 * Created: 13th August 2022 3:49:06 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 3:49:08 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/Attribute.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/IType.h"

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

Attribute::Attribute()
{
}

Attribute::Attribute(const IType* parentClass, const std::string& name, off_t offset, const IType* type)
	: _parentClass(parentClass)
	, _name(name)
	, _offset(offset)
	, _type(type)
{
}

Attribute::~Attribute()
{
}

const IType*	Attribute::getParentClass() const
{
	return (_parentClass);
}

const std::string&		Attribute::getName() const
{
	return (_name);
}

off_t					Attribute::getOffset() const
{
	return (_offset);
}

const IType*			Attribute::getType() const
{
	return (_type);
}
