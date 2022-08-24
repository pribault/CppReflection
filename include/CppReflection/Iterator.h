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
 * File: Iterator.h
 * Created: 15th August 2022 12:10:21 am
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 15th August 2022 12:10:23 am
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	Attribute;
	class	IType;
	class	Reflectable;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	class	Iterator
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

			Iterator();
			~Iterator();

			virtual void	value(const IType* valueType, void* valueInstance);

			virtual void	beforeReflectable(Reflectable& reflectable);
			virtual void	reflectableAttribute(const Attribute* attribute, void* attributeInstance);
			virtual void	afterReflectable();

			virtual void	beforeList();
			virtual void	listValue(const IType* valueType, void* valueInstance);
			virtual void	afterList();

			virtual void	beforeMap();
			virtual void	mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance);
			virtual void	afterMap();

	};
}
