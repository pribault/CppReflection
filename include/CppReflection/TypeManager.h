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
 * File: TypeManager.h
 * Created: 13th August 2022 2:57:50 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 2:58:47 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/IType.h>

// stl
#include <map>
#include <string>
#include <type_traits>

/*
************
** macros **
************
*/

#define IF_REFLECTABLE	std::is_base_of<CppReflection::Reflectable, T>::value
#define IF_POINTER		std::is_pointer<T>::value

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	Reflectable;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	/**
	 * @class TypeManager TypeManager.h CppReflection/TypeManager.h
	 * @brief Singleton used to store all types, allowing type creation, deduction and retrieval
	 */
	class	TypeManager
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

			/**
			 * @brief Get the type manager instance
			 * 
			 * @return TypeManager* The type manager instance
			 */
			static TypeManager*	get();

			/**
			 * @brief Deduce type from a given template parameter
			 * @tparam T The type to deduce
			 * 
			 * @return IType* The corresponding type
			 */
			template		<typename T>
			static typename std::enable_if<IF_POINTER, IType*>::type						findType();

			/**
			 * @brief Deduce type from a given template parameter
			 * @tparam T The type to deduce
			 * 
			 * @return IType* The corresponding type
			 */
			template		<typename T>
			static typename std::enable_if<IF_REFLECTABLE && !IF_POINTER, IType*>::type		findType();

			/**
			 * @brief Deduce type from a given template parameter
			 * @tparam T The type to deduce
			 * 
			 * @return IType* The corresponding type
			 */
			template		<typename T>
			static typename std::enable_if<!IF_REFLECTABLE && !IF_POINTER, IType*>::type	findType();

			/**
			 * @brief Retrieve a type from a given name
			 * 
			 * @param typeName The name of the type to retrieve
			 * @return IType* The corresponding type
			 */
			static IType*	findType(const std::string& typeName);

		/*
		************************************************************************
		******************************* PROTECTED ******************************
		************************************************************************
		*/

		protected:

			/*
			***********
			** types **
			***********
			*/

			/**
			 * @brief The type map, associating types with their name
			 */
			typedef std::map<std::string, IType*>	TypeMap;

		/*
		************************************************************************
		******************************** PRIVATE *******************************
		************************************************************************
		*/

		private:

			/*
			*************
			** methods **
			*************
			*/

			TypeManager();
			~TypeManager();

			IType*		registerAndGet(IType* type);
			IType*		getType(const std::string& typeName) const;

			/*
			****************
			** attributes **
			****************
			*/

			static TypeManager*	_instance;

			TypeMap				_typeMap;

	};
}

#include <CppReflection/TypeManager.inl>
