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
 * File: main.cpp
 * Created: 13th August 2022 3:27:39 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 3:27:41 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include <CppReflection/Reflectable.h>

/*
**************
** includes **
**************
*/

// stl
#include <iostream>

/*
****************
** namespaces **
****************
*/

using namespace	CppReflection;

/*
*************
** classes **
*************
*/

class	Point : public Reflectable
{
	public:
		START_REFLECTION(Point)
		REFLECT_ATTRIBUTE(x)
		REFLECT_ATTRIBUTE(y)
		END_REFLECTION()

		int	x;
		int	y;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

int	main(int argc, char** argv)
{
	// initialize object
	Point	point;
	
	point.x = 42;
	point.y = -66;

	// get object type
	const IReflectableType*	type = point.getType();

	// print object type
	std::cout << type->getName() << ":" << std::endl;

	// iterate over attributes
	for (size_t i = 0; i < type->getNbAttributes(); i++)
	{
		Attribute* attribute = type->getAttribute(i);

		// print attribute type, name, offset and size
		std::cout << " - " << attribute->getType()->getName() << " '" << attribute->getName() << "' (offset=" << attribute->getOffset() << ", size=" << attribute->getType()->getSize() << ")" << std::endl;
	}
	return 0;
}
