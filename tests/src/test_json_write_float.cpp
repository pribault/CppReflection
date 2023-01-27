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
 * File: test_json_write_float.cpp
 * Created: Saturday, 7th January 2023 1:22:27 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 7th January 2023 1:24:44 pm
 * Modified By: Ribault Paul (pribault.dev@gmail.com)
 */

#include "unit_tests.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include <CppReflection/Reflectable.h>
#include <CppReflection/JsonWriter.h>

// stl
#include <limits>

/*
****************
** namespaces **
****************
*/

using namespace	CppReflection;

/*
********************************************************************************
************************************ CLASSES ***********************************
********************************************************************************
*/

class	TestJsonWriteFloat : public Reflectable
{
	public:
		START_REFLECTION(TestJsonWriteFloat)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		float		value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_json_write_float()
{
	TypeManager::findType<TestJsonWriteFloat>();

	TestJsonWriteFloat	test;
	test.value = std::numeric_limits<float>::max() / 2;

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteFloat\",\n\t\"value\" : 1.7014117331926443e+38\n}";

	std::string result = JsonWriter::compute(test);

	ASSERT(result == expected, "invalid JsonWriter result, expecting '\n" + expected + "\n', was '\n" + result + "\n'")
}

void	test_json_write_float_min()
{
	TypeManager::findType<TestJsonWriteFloat>();

	TestJsonWriteFloat	test;
	test.value = std::numeric_limits<float>::min();

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteFloat\",\n\t\"value\" : 1.1754943508222875e-38\n}";

	std::string result = JsonWriter::compute(test);

	ASSERT(result == expected, "invalid JsonWriter result, expecting '\n" + expected + "\n', was '\n" + result + "\n'")
}

void	test_json_write_float_max()
{
	TypeManager::findType<TestJsonWriteFloat>();

	TestJsonWriteFloat	test;
	test.value = std::numeric_limits<float>::max();

	std::string	expected = "{\n\t\"type\" : \"TestJsonWriteFloat\",\n\t\"value\" : 3.4028234663852886e+38\n}";

	std::string result = JsonWriter::compute(test);

	ASSERT(result == expected, "invalid JsonWriter result, expecting '\n" + expected + "\n', was '\n" + result + "\n'")
}
