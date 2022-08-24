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
 * File: Iterator.cpp
 * Created: 15th August 2022 12:10:54 am
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 15th August 2022 12:34:34 am
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/Iterator.h"

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

Iterator::Iterator()
{
}

Iterator::~Iterator()
{
}

void	Iterator::value(const IType* valueType, void* valueInstance)
{
}

void	Iterator::beforeReflectable(Reflectable& reflectable)
{
}

void	Iterator::reflectableAttribute(const Attribute* attribute, void* attributeInstance)
{
}

void	Iterator::afterReflectable()
{
}

void	Iterator::beforeList()
{
}

void	Iterator::listValue(const IType* valueType, void* valueInstance)
{
}

void	Iterator::afterList()
{
}

void	Iterator::beforeMap()
{
}

void	Iterator::mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance)
{
}

void	Iterator::afterMap()
{
}
