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
 * File: Attribute.h
 * Created: 13th August 2022 3:12:46 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 3:12:49 pm
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

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	IType;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	/**
	 * @class Attribute Attribute.h CppReflection/Attribute.h
	 * @brief Representation of a class attribute relative to a parent IType
	 */
	class	Attribute
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
			 * @brief Construct a new Attribute object
			 * 
			 * @param parentClass The parent class
			 * @param name The attribute name
			 * @param offset The attribute offset relative to an instance
			 * @param type The attribute type
			 */
			Attribute(const IType* parentClass, const std::string& name, off_t offset, const IType* type);

			/**
			 * @brief Destroy the Attribute object
			 */
			~Attribute();

			/**
			 * @brief Get the parent class type
			 * 
			 * @return const IType* The parent class type
			 */
			const IType*			getParentClass() const;

			/**
			 * @brief Get the attribute name
			 * 
			 * @return const std::string& The attribute name
			 */
			const std::string&		getName() const;

			/**
			 * @brief Get the attribute offset relative to an instance
			 * 
			 * @return off_t The attribute offset
			 */
			off_t					getOffset() const;

			/**
			 * @brief Get the attribute type
			 * 
			 * @return const IType* The attribute type
			 */
			const IType*			getType() const;

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
			 * @brief Construct a new Attribute object
			 */
			Attribute();

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

			const IType*	_parentClass;
			std::string		_name;
			off_t			_offset;
			const IType*	_type;

	};
}
