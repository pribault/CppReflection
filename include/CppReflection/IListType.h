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
 * File: IListType.h
 * Created: 21th September 2022 4:48:00 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 21th September 2022 4:48:00 pm
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

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	/**
	 * @class IListType IListType.h CppReflection/IListType.h
	 * @brief A specialization of IType used to represent list types
	 */
	class		IListType : public IType
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
			 * @brief Destroy the IListType object
			 */
			virtual ~IListType();

			/**
			 * @brief Get the type of the objects stored by this list type
			 * 
			 * @return const IType* The type of the objects stored by this list type
			 */
			const IType*	getSubType() const;

			/**
			 * @brief Check if this type is list (can be cast to IListType)
			 * 
			 * @return True if this type is list, false otherwise
			 */
			bool			isList() const override;

			/**
			 * @brief Insert a new element in the given list instance
			 * 
			 * @param instance The list instance to insert a new element inside
			 * @param valueInstance The element instance to insert inside the list
			 */
			virtual void	insert(void* instance, const void* valueInstance) const = 0;

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
			 * @brief Construct a new IListType object
			 * 
			 * @param size The size of an instance created using this type
			 * @param typeInfo The type info related to this type
			 * @param subType The type of the objects stored by this list type
			 */
			IListType(size_t size, const std::type_info* typeInfo, IType* subType);

			/*
			****************
			** attributes **
			****************
			*/

			/**
			 * @brief The type of the objects stored by this list type
			 */
			IType*	_subType;

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

			/**
			 * @brief Construct a new IListType object
			 */
			IListType();

	};
}
