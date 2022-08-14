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
 * File: ReflectableWriter.h
 * Created: 14th August 2022 6:04:43 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 14th August 2022 6:05:03 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// stl
#include <iostream>

/*
****************
** class used **
****************
*/

namespace	CppReflection
{
	class	Reflectable;
}

/*
**********************
** class definition **
**********************
*/

namespace	CppReflection
{
	class	ReflectableWriter
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

			// Convenience methods to handle both references and pointers
			void			write(std::ostream& outStream, const Reflectable* reflectable, bool writeType = true) const;
			void			write(std::string& output, const Reflectable* reflectable, bool writeType = true) const;
			void			write(const std::string& fileName, bool truncate, const Reflectable* reflectable, bool writeType = true) const;

			// Virtual methods writers will have to implement
			virtual void	write(std::ostream& outStream, const Reflectable& reflectable, bool writeType = true) const = 0;
			virtual void	write(std::string& output, const Reflectable& reflectable, bool writeType = true) const = 0;
			virtual void	write(const std::string& fileName, bool truncate, const Reflectable& reflectable, bool writeType = true) const = 0;

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

			ReflectableWriter();
			virtual ~ReflectableWriter();

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
	};
}
