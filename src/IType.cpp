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
 * File: IType.cpp
 * Created: 13th August 2022 2:59:07 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 2:59:11 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/IType.h"

/*
**************
** includes **
**************
*/

#ifdef __GNUG__
# include <cstdlib>
# include <memory>
# include <cxxabi.h>
#endif

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

IType::IType(void)
{
}

IType::IType(size_t size, const std::type_info* typeInfo) :
	_name(name(typeInfo)),
	_size(size),
	_typeInfo(typeInfo)
{
}

IType::~IType(void)
{
}

bool					IType::isPointer() const
{
	return false;
}

bool					IType::isReflectable() const
{
	return false;
}

bool					IType::isList() const
{
	return false;
}

bool					IType::isMap() const
{
	return false;
}

const std::string&		IType::getName(void) const
{
	return (_name);
}

size_t					IType::getSize(void) const
{
	return (_size);
}

const std::type_info*	IType::getTypeInfo(void) const
{
	return (_typeInfo);
}

void					IType::remove(void* instance) const
{
	// do nothing by default
}

void					IType::initialize(void* instance) const
{
	// do nothing by default
}

bool					IType::operator==(const IType& other) const
{
	return (*getTypeInfo() == *other.getTypeInfo());
}

bool					IType::operator!=(const IType& other) const
{
	return (*getTypeInfo() != *other.getTypeInfo());
}


std::string				IType::name(const std::type_info* typeInfo)
{
#ifdef __GNUG__
	int status; // some arbitrary value to eliminate the compiler warning

	std::unique_ptr<char, void(*)(void*)>	res {
		abi::__cxa_demangle(typeInfo->name(), NULL, NULL, &status),
		std::free
	};

	return (status == 0) ? res.get() : typeInfo->name();
#else

	std::string result = typeInfo->name();

	if (!result.compare(0, 6, "class "))
		result = result.substr(6, std::string::npos);

	return result;
#endif
}
