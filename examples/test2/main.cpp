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

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/Reflectable.h>
#include <CppReflection/YamlReader.h>

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
		REFLECT_ATTRIBUTE(test)
		REFLECT_ATTRIBUTE(test2)
		REFLECT_ATTRIBUTE(test3)
		REFLECT_ATTRIBUTE(test4)
		REFLECT_ATTRIBUTE(test5)
		END_REFLECTION()

		int	w;
		int	h;
		std::vector<int>			test;
		std::map<std::string, int>	test2;
		int*						test3;
		int*						test4;
		Point						test5;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

int		main(int argc, char** argv)
{
	Reflectable*	rectangle;

	TypeManager::findType<Rectangle>();

	std::string	input = "type: class Rectangle\n\
x: 42\n\
y: -66\n\
w: 1920\n\
h: -1080\n\
test:\n\
  - 1\n\
  - 2\n\
  - 3\n\
test2:\n\
  \"!\": 44\n\
  Hello: 42\n\
  World: 43\n\
test3: -42\n\
test4: ~\n\
test5:\n\
  type: class Point\n\
  x: -858993460\n\
  y: -858993460";

	rectangle = YamlReader().load(input);

	return 0;
}
