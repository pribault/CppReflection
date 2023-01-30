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
 * File: YamlWriter.h
 * Created: 15th August 2022 12:11:15 am
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 15th August 2022 12:38:27 am
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

namespace	YAML
{
	class	Emitter;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	/**
	 * @class YamlWriter YamlWriter.h CppReflection/YamlWriter.h
	 * @brief Yaml serializer
	 */
	class	YamlWriter : public Iterator
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
			 * @brief Serialize the given reflectable into a yaml string
			 * 
			 * @param reflectable The reflectable to serialize
			 * @return std::string The resulting yaml string
			 */
			static std::string		compute(const Reflectable& reflectable);

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
			 * @brief Construct a new YamlWriter object
			 */
			YamlWriter();

			/**
			 * @brief Destroy the YamlWriter object
			 */
			~YamlWriter();

			/**
			 * @brief Internal method to serialize a given reflectable into a yaml string
			 * 
			 * @param reflectable The reflectable to serialize
			 * @return std::string The resulting yaml string
			 */
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

			YAML::Emitter*	_emitter;

	};
}
