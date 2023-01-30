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
	class	Attribute;
	class	IPointerType;
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
	 * @class IReflectableType IReflectableType.h CppReflection/IReflectableType.h
	 * @brief A specialization of IType used to represent reflectable types\n
	 * This type can store additionnal informations like parents and attributes
	 */
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

			/**
			 * @brief Construct a new IReflectableType object
			 * 
			 * @param size The size of an instance created using this type
			 * @param typeInfo The type info related to this type
			 */
			IReflectableType(size_t size, const std::type_info* typeInfo);

			/**
			 * @brief Destroy the IReflectableType object
			 */
			virtual ~IReflectableType();

			/**
			 * @brief Check if this type is reflectable (can be cast to IReflectableType)
			 * 
			 * @return True if this type is reflectable, false otherwise
			 */
			bool						isReflectable() const override;

			/**
			 * @brief Iterate over this type using the given Iterator
			 * 
			 * @param iterator The iterator to use
			 * @param instance The object instance
			 */
			void						iterate(Iterator& iterator, void* instance) const override;

			/**
			 * @brief Check if this type inherits from the given type
			 * 
			 * @param other The type to check inheritance with
			 * @return True if this type inherits from the given type
			 */
			bool						inherits(const IType* other) const;

			/**
			 * @brief Get the Pointer Type object
			 * 
			 * @return const IPointerType* 
			 */
			virtual const IPointerType*	getPointerType() const = 0;

			/**
			 * @brief Add a parent type
			 * 
			 * @param parent The parent type to add
			 */
			void						addParent(IType* parent);

			/**
			 * @brief Remove a parent type
			 * 
			 * @param index The index of the parent to remove
			 */
			void						removeParent(size_t index);

			/**
			 * @brief Get the number of parent types
			 * 
			 * @return size_t The number of parent types
			 */
			size_t						getNbParents() const;

			/**
			 * @brief Get the parent type at the given index
			 * 
			 * @param index The parent type index
			 * @return const IType* The parent type
			 */
			const IType*				getParent(size_t index) const;

			/**
			 * @brief Add an attribute
			 * 
			 * @param attribute The attribute to add
			 */
			void						addAttribute(Attribute* attribute);

			/**
			 * @brief Remove an attribute
			 * 
			 * @param index The index of the attribute to remove
			 */
			void						removeAttribute(size_t index);

			/**
			 * @brief Get the number of attributes
			 * 
			 * @return size_t The number of attributes
			 */
			size_t						getNbAttributes() const;

			/**
			 * @brief Get the attribute at the given index
			 * 
			 * @param index The attribute index
			 * @return const Attribute* The attribute
			 */
			const Attribute*			getAttribute(size_t index) const;

			/**
			 * @brief Find an attribute index from a name
			 * 
			 * @param name The name of the attribute to find
			 * @return size_t The attribute index
			 */
			size_t						findAttribute(const std::string& name) const;

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
			 * @brief Construct a new IReflectableType object
			 */
			IReflectableType();

			/**
			 * @brief Iterate over this type using the given Iterator
			 * 
			 * @param iterator The iterator to use
			 * @param instance The object instance
			 */
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
