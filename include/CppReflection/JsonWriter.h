/*
 * MIT License
 * 
 * Copyright (c) 2023 paul ribault
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
 * File: JsonWriter.h
 * Created: Tuesday, 24th January 2023 9:52:41 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Tuesday, 24th January 2023 9:52:44 pm
 * Modified By: Ribault Paul (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/Iterator.h>

// stl
#include <list>
#include <string>

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	Reflectable;
}

namespace	Json
{
	class	Value;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	class	JsonWriter : public Iterator
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

			static std::string		compute(const Reflectable& reflectable);

			virtual void	value(const IType* valueType, void* valueInstance) override;

			virtual void	beforeReflectable(Reflectable& reflectable) override;
			virtual void	reflectableAttribute(const Attribute* attribute, void* attributeInstance) override;
			virtual void	afterReflectable() override;

			virtual void	beforeList(const IListType* listType, void* listInstance) override;
			virtual void	listValue(const IType* valueType, void* valueInstance) override;
			virtual void	afterList() override;

			virtual void	beforeMap(const IMapType* mapType, void* mapInstance) override;
			virtual void	mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance) override;
			virtual void	afterMap() override;

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

			JsonWriter();
			~JsonWriter();

			std::string		internalCompute(const Reflectable& reflectable);

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

			std::list<Json::Value*>	_stack;

	};
}
