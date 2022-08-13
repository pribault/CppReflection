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
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
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

			IType(const std::string& name, size_t size, const std::type_info* typeInfo);
			virtual ~IType(void);

			virtual bool			isPointer() const;
			virtual bool			isReflectable() const;

			// getters
			const std::string&		getName(void) const;
			size_t					getSize(void) const;
			const std::type_info*	getTypeInfo(void) const;

			virtual void*			create(void) const = 0;
			virtual void			initialize(void* instance) const;

			// operators
			bool					operator==(const IType& other);
			bool					operator!=(const IType& other);

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

			IType(void);

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
