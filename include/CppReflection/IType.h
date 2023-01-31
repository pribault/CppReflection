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
 * File: IType.h
 * Created: 13th August 2022 2:57:59 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 2:58:50 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// stl
#include <string>
#include <typeinfo>
#include <vector>

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	Iterator;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	/**
	 * @class IType IType.h CppReflection/IType.h
	 * @brief Base class for all types
	 */
	class	IType
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
			 * @brief Construct a new IType object
			 * 
			 * @param size The size of an instance created using this type
			 * @param typeInfo The type info related to this type
			 */
			IType(size_t size, const std::type_info* typeInfo);

			/**
			 * @brief Destroy the IType object
			 */
			virtual ~IType();

			/**
			 * @brief Check if this type is pointer (can be cast to IPointerType)
			 * 
			 * @return True if this type is pointer, false otherwise
			 */
			virtual bool			isPointer() const;

			/**
			 * @brief Check if this type is reflectable (can be cast to IReflectableType)
			 * 
			 * @return True if this type is reflectable, false otherwise
			 */
			virtual bool			isReflectable() const;

			/**
			 * @brief Check if this type is list (can be cast to IListType)
			 * 
			 * @return True if this type is list, false otherwise
			 */
			virtual bool			isList() const;

			/**
			 * @brief Check if this type is map (can be cast to IMapType)
			 * 
			 * @return True if this type is map, false otherwise
			 */
			virtual bool			isMap() const;

			/**
			 * @brief Get the type name
			 * 
			 * @return const std::string& The type name
			 */
			const std::string&		getName() const;

			/**
			 * @brief Get the size of an instance created using this type
			 * 
			 * @return size_t The instance size
			 */
			size_t					getSize() const;

			/**
			 * @brief Get the related type info object
			 * 
			 * @return const std::type_info* The type info object
			 */
			const std::type_info*	getTypeInfo() const;

			/**
			 * @brief Instanciate a new object
			 * 
			 * @return void* The newly allocated object instance
			 */
			virtual void*			create() const = 0;

			/**
			 * @brief Initialize the given instance
			 * 
			 * @param instance The instance to initialize
			 */
			virtual void			initialize(void* instance) const;

			/**
			 * @brief Remove the given instance
			 * 
			 * @param instance The instance to remove
			 */
			virtual void			remove(void* instance) const;

			/**
			 * @brief Iterate over this type using the given Iterator
			 * 
			 * @param iterator The iterator to use
			 * @param instance The object instance
			 */
			virtual void			iterate(Iterator& iterator, void* instance) const = 0;

			/**
			 * @brief Check if this type is equal to the given one (is the same type)
			 * 
			 * @param other The type to check equality with
			 * @return True if this type is equal to the given one, false otherwise
			 */
			bool					operator==(const IType& other) const;

			/**
			 * @brief Check if this type is not equal to the given one (is a different type)
			 * 
			 * @param other The type to check equality with
			 * @return True if this type is not the same as the given one, false otherwise
			 */
			bool					operator!=(const IType& other) const;

			/*
			*************
			** methods **
			*************
			*/

			/**
			 * @brief Construct a new IType object
			 */
			IType();

		/*
		************************************************************************
		******************************* PROTECTED ******************************
		************************************************************************
		*/

		protected:

			/*
			*************
			** methods **
			*************
			*/

			/**
			 * @brief Retrieve the type name from a type info. Should be the same on all plateforms
			 * 
			 * @param typeInfo The type info to retrieve the type name from
			 * @return std::string The type name
			 */
			static std::string	name(const std::type_info* typeInfo);

		/*
		************************************************************************
		******************************** PRIVATE *******************************
		************************************************************************
		*/

		private:

			/*
			****************
			** attributes **
			****************
			*/

			std::string				_name;
			size_t					_size;
			const std::type_info*	_typeInfo;

	};
}
