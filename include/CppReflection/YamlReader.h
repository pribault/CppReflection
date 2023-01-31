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
 * File: YamlReader.h
 * Created: 15th August 2022 12:11:08 am
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 15th August 2022 12:36:59 am
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
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

namespace	YAML
{
	class	Node;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	/**
	 * @class YamlReader YamlReader.h CppReflection/YamlReader.h
	 * @brief Yaml deserializer
	 */
	class	YamlReader : public Iterator
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
			 * @brief Load a reflectable from the given yaml string
			 * 
			 * @param input The yaml string to deserialize
			 * @return Reflectable* The resulting Reflectable
			 */
			static Reflectable*	load(const std::string& input);

			/**
			 * @brief Load a reflectable from the given yaml string
			 * 
			 * @tparam T The type to load
			 * @param input The yaml string to deserialize
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
			 * @brief Construct a new YamlReader object
			 */
			YamlReader();

			/**
			 * @brief Destroy the YamlReader object
			 */
			~YamlReader();

			/**
			 * @brief Internal method to load a reflectable from a yaml string
			 * 
			 * @param input The yaml string
			 * @return Reflectable* The resulting Reflectable
			 */
			Reflectable*	internalLoad(const std::string& input);

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

			std::list<YAML::Node*>	_stack;

	};
}

#include <CppReflection/YamlReader.inl>
