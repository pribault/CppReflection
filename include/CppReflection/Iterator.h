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
	class	IListType;
	class	IMapType;
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
	/**
	 * @class Iterator Iterator.h CppReflection/Iterator.h
	 * @brief Base class for serializers and deserializers\n
	 * This class is made to iterate over reflectables and their attributes
	 */
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

			/**
			 * @brief Construct a new Iterator object
			 */
			Iterator();

			/**
			 * @brief Destroy the Iterator object
			 */
			~Iterator();

			/**
			 * @brief Method called by fundamental types to iterate over them (booleans, signed/unsigned integers, floating point numbers, strings)
			 * 
			 * @param valueType The value type
			 * @param valueInstance The value instance
			 */
			virtual void	value(const IType* valueType, void* valueInstance) = 0;

			/**
			 * @brief Method called by IReflectableType::iterate before iterating over a Reflectable
			 * 
			 * @param reflectable The reflectable to iterate on
			 */
			virtual void	beforeReflectable(Reflectable& reflectable) = 0;

			/**
			 * @brief Method called by IReflectableType::iterate to iterate over a Reflectable attribute
			 * 
			 * @param attribute The attribute
			 * @param attributeInstance The attribute instance to iterate on
			 */
			virtual void	reflectableAttribute(const Attribute* attribute, void* attributeInstance) = 0;

			/**
			 * @brief Method called by IReflectableType::iterate after iterating over a Reflectable
			 */
			virtual void	afterReflectable() = 0;

			/**
			 * @brief Method called by list types before iterating over a list
			 * 
			 * @param listType The list type
			 * @param listInstance The list instance to iterate on
			 */
			virtual void	beforeList(const IListType* listType, void* listInstance) = 0;

			/**
			 * @brief Method called by list types to iterate over a list element
			 * 
			 * @param valueType The element type
			 * @param valueInstance The element instance to iterate on
			 */
			virtual void	listValue(const IType* valueType, void* valueInstance) = 0;

			/**
			 * @brief Method called by list types after iterating over a list
			 */
			virtual void	afterList() = 0;

			/**
			 * @brief Method called by map types before iterating over a map
			 * 
			 * @param mapType The map type
			 * @param mapInstance The map instance to iterate on
			 */
			virtual void	beforeMap(const IMapType* mapType, void* mapInstance) = 0;

			/**
			 * @brief Method called by map types to iterate over a map pair
			 * 
			 * @param keyType The key type
			 * @param keyInstance The key instance to iterate on
			 * @param valueType The value type
			 * @param valueInstance The value instance to iterate on
			 */
			virtual void	mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance) = 0;

			/**
			 * @brief Method called by map types after iterating over a map
			 */
			virtual void	afterMap() = 0;

	};
}
