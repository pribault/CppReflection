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
 * File: TypeManager.inl
 * Created: 13th August 2022 3:53:16 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 3:53:17 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/PointerType.h"
#include "CppReflection/Type.h"
#include "CppReflection/ReflectableType.h"

// stl
#include <type_traits>

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

template		<typename T>
typename std::enable_if<IF_POINTER, CppReflection::IType*>::type						CppReflection::TypeManager::findType()
{
	return (PointerType<typename std::remove_pointer<T>::type>::get());
}
template		<typename T>
typename std::enable_if<IF_REFLECTABLE && !IF_POINTER, CppReflection::IType*>::type	CppReflection::TypeManager::findType()
{
	return (ReflectableType<T>::get());
}
template		<typename T>
typename std::enable_if<!IF_REFLECTABLE && !IF_POINTER, CppReflection::IType*>::type	CppReflection::TypeManager::findType()
{
	return (Type<T>::get());
}
