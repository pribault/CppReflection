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
 * File: Type.h
 * Created: 13th August 2022 2:57:42 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 2:58:45 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/IListType.h>
#include <CppReflection/IMapType.h>
#include <CppReflection/IType.h>

// stl
#include <list>
#include <map>
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
	template	<typename T>
	class		Type : public IType
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

			void*			create() const override;

			static Type<T>*	get();

			void			iterate(Iterator& iterator, void* instance) const override;

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

			Type();
			virtual ~Type();

			/*
			****************
			** attributes **
			****************
			*/

			static Type<T>*	_instance;

	};

	template	<typename T>
	class		Type<std::vector<T>> : public IListType
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

			void*							create() const override;

			static Type<std::vector<T>>*	get();

			void							iterate(Iterator& iterator, void* instance) const override;

			void							insert(void* instance, const void* valueInstance) const override;

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

			Type();
			virtual ~Type();

			/*
			****************
			** attributes **
			****************
			*/

			static Type<std::vector<T>>*	_instance;

	};

	template	<typename T>
	class		Type<std::list<T>> : public IListType
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

			void*							create() const override;

			static Type<std::list<T>>*		get();

			void							iterate(Iterator& iterator, void* instance) const override;

			void							insert(void* instance, const void* valueInstance) const override;

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

			Type();
			virtual ~Type();

			/*
			****************
			** attributes **
			****************
			*/

			static Type<std::list<T>>*	_instance;

	};

	template	<typename K, typename V>
	class		Type<std::map<K, V>> : public IMapType
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

			void*							create() const override;

			static Type<std::map<K, V>>*	get();

			void							iterate(Iterator& iterator, void* instance) const override;

			void							insert(void* mapInstance, const void *keyInstance, const void* valueInstance) const override;

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

			Type();
			virtual ~Type();

			/*
			****************
			** attributes **
			****************
			*/

			static Type<std::map<K, V>>*	_instance;

	};
}

#include <CppReflection/Type.inl>
