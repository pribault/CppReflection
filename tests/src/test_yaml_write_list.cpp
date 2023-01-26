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
 * File: test_yaml_write_list.cpp
 * Created: Saturday, 7th January 2023 1:22:52 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Saturday, 7th January 2023 1:24:25 pm
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
#include <CppReflection/YamlWriter.h>

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

class	TestYamlWriteList : public Reflectable
{
	public:
		START_REFLECTION(TestYamlWriteList)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		std::vector<int>	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

void	test_yaml_write_list()
{
	TypeManager::findType<TestYamlWriteList>();

	TestYamlWriteList	test;
	test.value = {42, 43, 44};

	std::string	expected = "\
type: TestYamlWriteList\n\
value:\n\
  - 42\n\
  - 43\n\
  - 44";

	std::string result = YamlWriter::compute(test);

	ASSERT(result == expected, "invalid YamlWriter result, expecting '\n" + expected + "\n', was '\n" + result + "\n'")
}
