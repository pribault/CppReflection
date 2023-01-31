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
 * File: JsonReader.h
 * Created: Saturday, 7th January 2023 9:40:44 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 7th January 2023 9:40:46 pm
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
	/**
	 * @class JsonReader JsonReader.h CppReflection/JsonReader.h
	 * @brief Json deserializer
	 */
	class	JsonReader : public Iterator
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
			 * @brief Load a reflectable from the given json string
			 * 
			 * @param input The json string to deserialize
			 * @return Reflectable* The resulting Reflectable
			 */
			static Reflectable*	load(const std::string& input);

			/**
			 * @brief Load a reflectable from the given json string
			 * 
			 * @tparam T The type to load
			 * @param input The json string to deserialize
			 * @return T* The resulting Reflectable
			 */
			template		<typename T>
			static T*			load(const std::string& input);

			void	value(const IType* valueType, void* valueInstance) override;

			void	beforeReflectable(Reflectable& reflectable) override;
			void	reflectableAttribute(const Attribute* attribute, void* attributeInstance) override;
			void	afterReflectable() override;

			void	beforeList(const IListType* listType, void* listInstance) override;
			void	listValue(const IType* valueType, void* valueInstance) override;
			void	afterList() override;

			void	beforeMap(const IMapType* mapType, void* mapInstance) override;
			void	mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance) override;
			void	afterMap() override;

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
			 * @brief Construct a new JsonReader object
			 */
			JsonReader();

			/**
			 * @brief Destroy the JsonReader object
			 */
			~JsonReader();

			/**
			 * @brief Internal method to load a reflectable from a json string
			 * 
			 * @param input The json string
			 * @return Reflectable* The resulting Reflectable
			 */
			Reflectable*		internalLoad(const std::string& input);

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

#include <CppReflection/JsonReader.inl>
