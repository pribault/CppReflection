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
 * File: IMapType.h
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
	 * @class IMapType IMapType.h CppReflection/IMapType.h
	 * @brief A specialization of IType used to represent map types
	 */
	class		IMapType : public IType
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
			 * @brief Destroy the IMapType object
			 */
			virtual ~IMapType();

			/**
			 * @brief Get the type of the key objects of this map type
			 * 
			 * @return const IType* Get the type of the key objects of this map type
			 */
			const IType*	getKeyType() const;

			/**
			 * @brief Get the type of the value objects of this map type
			 * 
			 * @return const IType* Get the type of the value objects of this map type
			 */
			const IType*	getValueType() const;

			/**
			 * @brief Check if this type is map (can be cast to IMapType)
			 * 
			 * @return True if this type is map, false otherwise
			 */
			bool			isMap() const override;

			/**
			 * @brief Insert a new key value pair in the given map instance
			 * 
			 * @param mapInstance The map instance to insert a new element inside
			 * @param keyInstance The key instance to insert inside the map
			 * @param valueInstance The value instance to insert inside the map
			 */
			virtual void	insert(void* mapInstance, const void *keyInstance, const void* valueInstance) const = 0;

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
			 * @brief Construct a new IMapType object
			 * 
			 * @param size The size of an instance created using this type
			 * @param typeInfo The type info related to this type
			 * @param keyType The type of the key objects of this map type
			 * @param valueType The type of the value objects of this map type
			 */
			IMapType(size_t size, const std::type_info* typeInfo, IType* keyType, IType* valueType);

			/*
			****************
			** attributes **
			****************
			*/

			/**
			 * @brief The type of the key objects of this map type
			 */
			IType*	_keyType;

			/**
			 * @brief The type of the value objects of this map type
			 */
			IType*	_valueType;

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
			 * @brief Construct a new IMapType object
			 */
			IMapType();

	};
}
