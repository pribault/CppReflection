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

class	Rectangle : public Point
{
	public:
		START_REFLECTION(Rectangle, Point)
		REFLECT_ATTRIBUTE(w)
		REFLECT_ATTRIBUTE(h)
		END_REFLECTION()

		int	w;
		int	h;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	addIndentation(size_t indentation)
{
	for (size_t i = 0; i < indentation; i++)
		std::cout << "  ";
}

void	debugType(const IReflectableType* type, size_t indentation)
{
	// print object type
	addIndentation(indentation);
	std::cout << type->getName() << " (size=" << type->getSize() << "):" << std::endl;

	// iterate over attributes
	for (size_t i = 0; i < type->getNbAttributes(); i++)
	{
		Attribute* attribute = type->getAttribute(i);

		// print attribute type, name, offset and size
		addIndentation(indentation + 1);
		std::cout << " - " << attribute->getType()->getName() << " '" << attribute->getName() << "' (offset=" << attribute->getOffset() << ", size=" << attribute->getType()->getSize() << ")" << std::endl;
	}

	// iterate over parents
	if (type->getNbParents())
	{
		addIndentation(indentation + 1);
		std::cout << "parents:" << std::endl;
	}
	for (size_t i = 0; i < type->getNbParents(); i++)
	{
		IType* parent = type->getParent(i);

		// If type is reflectable debug it too
		if (parent->isReflectable())
			debugType(static_cast<IReflectableType*>(parent), indentation + 2);
	}
}

int		main(int argc, char** argv)
{
	// initialize object
	Rectangle	rectangle;

	rectangle.x = 42;
	rectangle.y = -66;
	rectangle.w = 1920;
	rectangle.h = -1080;

	// get object type
	const IReflectableType* type = rectangle.getType();

	debugType(type, 0);

	return 0;
}
