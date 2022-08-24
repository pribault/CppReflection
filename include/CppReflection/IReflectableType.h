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
 * File: IReflectableType.h
 * Created: 13th August 2022 4:35:34 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 4:35:36 pm
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
#include <vector>

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	Reflectable;
	class	Attribute;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	class	IReflectableType : public IType
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

			IReflectableType(const std::string& name, size_t size, const std::type_info* typeInfo);
			virtual ~IReflectableType();

			virtual bool			isReflectable() const;

			virtual void			iterate(Iterator& iterator, void* instance) const;

			// parents
			void					addParent(IType* parent);
			void					removeParent(size_t index);
			size_t					getNbParents() const;
			const IType*			getParent(size_t index) const;

			// attributes
			void					addAttribute(Attribute* attribute);
			void					removeAttribute(size_t index);
			size_t					getNbAttributes() const;
			const Attribute*		getAttribute(size_t index) const;
			size_t					findAttribute(const std::string& name) const;

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

			IReflectableType();

			void	iterate(Iterator& iterator, Reflectable& instance) const;

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

			std::vector<IType*>		_parents;
			std::vector<Attribute*>	_attributes;

	};
}
