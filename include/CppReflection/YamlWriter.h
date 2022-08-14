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
 * Created: 14th August 2022 6:28:33 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 14th August 2022 6:28:43 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/ReflectableWriter.h>

/*
****************
** class used **
****************
*/

namespace	YAML
{
	class	Emitter;
}

namespace	CppReflection
{
	class	Attribute;
	class	IType;
	class	IReflectableType;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	class	YamlWriter : public ReflectableWriter
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

			static YamlWriter*	get();

			virtual void	write(std::ostream& outStream, const Reflectable& reflectable, bool writeType = true) const;
			virtual void	write(std::string& output, const Reflectable& reflectable, bool writeType = true) const;
			virtual void	write(const std::string& fileName, bool truncate, const Reflectable& reflectable, bool writeType = true) const;

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

			YamlWriter();
			virtual ~YamlWriter();

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

			void	writeReflectable(YAML::Emitter& emitter, const Reflectable& reflectable, bool writeType) const;
			void	writeReflectable(YAML::Emitter& emitter, const Reflectable& reflectable, const IReflectableType& type, bool writeType) const;
			void	writeAttribute(YAML::Emitter& emitter, const void* value, const IType& type, bool writeType) const;
			void	writeType(YAML::Emitter& emitter, const IType& type) const;

			/*
			****************
			** attributes **
			****************
			*/

			static YamlWriter*	_instance;

	};
}
