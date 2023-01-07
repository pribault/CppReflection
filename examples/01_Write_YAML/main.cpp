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
#include <CppReflection/YamlWriter.h>

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
	// initialize object
	Rectangle	rectangle;

	rectangle.x = 42;
	rectangle.y = -66;
	rectangle.w = 1920;
	rectangle.h = -1080;
	rectangle.test.push_back(1);
	rectangle.test.push_back(2);
	rectangle.test.push_back(3);
	rectangle.test2["Hello"] = 42;
	rectangle.test2["World"] = 43;
	rectangle.test2["!"] = 44;
	rectangle.test3 = new int(-42);
	rectangle.test4 = nullptr;

	std::cout << YamlWriter().compute(rectangle) << std::endl;

	return 0;
}
