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
 * File: IPointerType.h
 * Created: 14th August 2022 7:36:10 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 14th August 2022 9:27:08 pm
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
	 * @class IPointerType IPointerType.h CppReflection/IPointerType.h
	 * @brief A specialization of IType used to represent pointer types
	 */
	class		IPointerType : public IType
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
			 * @brief Destroy the IPointerType object
			 */
			virtual ~IPointerType();

			/**
			 * @brief Get the pointed type
			 * 
			 * @return const IType* The pointed type
			 */
			const IType*	getSubType() const;

			/**
			 * @brief Check if this type is pointer (can be cast to IPointerType)
			 * 
			 * @return True if this type is pointer, false otherwise
			 */
			bool			isPointer() const override;

			/**
			 * @brief Iterate over this type using the given Iterator
			 * 
			 * @param iterator The iterator to use
			 * @param instance The object instance
			 */
			void			iterate(Iterator& iterator, void* instance) const override;

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
			 * @brief Construct a new IPointerType object
			 * 
			 * @param size The size of an instance created using this type
			 * @param typeInfo The type info related to this type
			 * @param subType The pointed type
			 */
			IPointerType(size_t size, const std::type_info* typeInfo, IType* subType);

			/*
			****************
			** attributes **
			****************
			*/

			/**
			 * @brief The pointed type
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
			 * @brief Construct a new IPointerType object
			 */
			IPointerType();

	};
}
