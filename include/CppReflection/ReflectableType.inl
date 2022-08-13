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
 * File: ReflectableType.inl
 * Created: 13th August 2022 4:34:31 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 4:34:40 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

/*
**************
** includes **
**************
*/

// stl
#include <type_traits>

/*
***********************************************************************************
************************************ ATTRIBUTES ***********************************
***********************************************************************************
*/

template	<class T>
CppReflection::ReflectableType<T>*		CppReflection::ReflectableType<T>::_instance = nullptr;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

template	<typename T>
CppReflection::ReflectableType<T>::ReflectableType(void) :
	IReflectableType(typeid(T).name(), sizeof(T), &typeid(T))
{
}

template	<typename T>
CppReflection::ReflectableType<T>::~ReflectableType(void)
{
}

template	<typename T>
void*		CppReflection::ReflectableType<T>::create(void) const
{
	return (new T());
}

template	<typename T>
CppReflection::ReflectableType<T>*	CppReflection::ReflectableType<T>::get(void)
{
	if (_instance == nullptr)
	{
		_instance = new ReflectableType<T>;
		T::staticInitReflection();
	}
	return (_instance);
}
