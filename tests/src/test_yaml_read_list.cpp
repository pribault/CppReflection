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
 * File: test_yaml_read_list.cpp
 * Created: Friday, 23rd December 2022 10:12:04 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 23rd December 2022 10:13:01 pm
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
#include <CppReflection/YamlReader.h>

// stl
#include <vector>

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

class	TestYamlReadList : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadList)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		std::vector<int>	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

template	<typename T>
std::string	vector_to_string(const std::vector<T>& vector)
{
	std::string	result = "[";

	for (size_t i = 0; i < vector.size(); i++)
	{
		result.append(std::to_string(vector[i]));
		if (i != vector.size() - 1)
			result.append(", ");
	}

	return result.append("]");
}

void	test_yaml_read_list()
{
	TypeManager::findType<TestYamlReadList>();
	std::string	value = "\n- 1\n- 2\n- 3";
	// expect to find the same list
	std::vector<int>	expected({
		1,
		2,
		3
	});

	TestYamlReadList*	test;

	std::string	input = "type: TestYamlReadList\nvalue: " + value;

	test = YamlReader::load<TestYamlReadList>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + vector_to_string(expected) + "', was '" + vector_to_string(test->value) + "'")
}


void	test_yaml_read_list_null()
{
	TypeManager::findType<TestYamlReadList>();
	std::string	value = "~";
	// expect to find an empty list
	std::vector<int>	expected;

	TestYamlReadList*	test;

	std::string	input = "type: TestYamlReadList\nvalue: " + value;

	test = YamlReader::load<TestYamlReadList>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + vector_to_string(expected) + "', was '" + vector_to_string(test->value) + "'")
}

void	test_yaml_read_list_map()
{
	TypeManager::findType<TestYamlReadList>();
	std::string	value = "\n  a: 42\n  b: 43\n  c: 44";
	// expect to find an empty list
	std::vector<int>	expected;

	TestYamlReadList*	test;

	std::string	input = "type: TestYamlReadList\nvalue: " + value;

	test = YamlReader::load<TestYamlReadList>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + vector_to_string(expected) + "', was '" + vector_to_string(test->value) + "'")
}
