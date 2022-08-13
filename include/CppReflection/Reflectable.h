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
 * File: Reflectable.h
 * Created: 13th August 2022 2:56:48 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 2:58:37 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

#include <CppReflection/Attribute.h>
#include <CppReflection/TypeManager.h>

/*
************
** macros **
************
*/

#define ATTRIBUTE_OFFSET(className, attr)	((size_t)&((className*)nullptr)->attr)

#define START_REFLECTION(className, ...)	\
	typedef className	ClassType;\
	\
	virtual const CppReflection::IReflectableType*	getType(void) const\
	{\
		return (CppReflection::ReflectableType<className>::get());\
	}\
	\
	static void		staticInitReflection(void)\
	{\
		CppReflection::IReflectableType*	type = CppReflection::ReflectableType<className>::get();\
		CppReflection::addParents<__VA_ARGS__>(type);

#define REFLECT_ATTRIBUTE(attr)	\
		type->addAttribute(new CppReflection::Attribute(type, #attr, ATTRIBUTE_OFFSET(ClassType, attr), CppReflection::TypeManager::findType<decltype(attr)>()));

#define END_REFLECTION()	\
	}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	template	<typename ... Parents>
	void		addParents(IReflectableType* type);

	class	Reflectable
	{

		/*
		************************************************************************
		******************************** PUBLIC ********************************
		************************************************************************
		*/

		public:

			/*
			*************
			** methods **
			*************
			*/

			Reflectable(void);
			virtual ~Reflectable(void);

			virtual const IReflectableType*	getType(void) const = 0;

	};
}

#include <CppReflection/Reflectable.inl>
