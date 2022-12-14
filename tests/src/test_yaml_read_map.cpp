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
 * File: test_yaml_read_map.cpp
 * Created: Friday, 23rd December 2022 10:12:23 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 23rd December 2022 10:13:04 pm
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
#include <map>

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

class	TestYamlReadMap : public Reflectable
{
	public:
		START_REFLECTION(TestYamlReadMap)
		REFLECT_ATTRIBUTE(value)
		END_REFLECTION()

		std::map<std::string, int>	value;
};

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

template	<typename K, typename V>
std::string	map_to_string(const std::map<K, V>& map)
{
	std::string	result = "{";
	size_t	index = 0;
	typename std::map<K, V>::const_iterator	it;
	typename std::map<K, V>::const_iterator	end = map.cend();

	for (it = map.cbegin(); it != end; it++)
	{
		K	key = it->first;
		V	value = it->second;
		result.append(key + ": " + std::to_string(value));
		if (index != map.size() - 1)
			result.append(", ");
		index++;
	}

	return result.append("}");
}

void	test_yaml_read_map()
{
	TypeManager::findType<TestYamlReadMap>();
	std::string value = "\n  a: 1\n  b: 2\n  c: 3";
	// expect to find the same map
	std::map<std::string, int> expected({
		std::make_pair("a", 1),
		std::make_pair("b", 2),
		std::make_pair("c", 3)
	});

	TestYamlReadMap*	test;

	std::string	input = "type: TestYamlReadMap\nvalue: " + value;

	test = YamlReader().load<TestYamlReadMap>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + map_to_string(expected) + "', was '" + map_to_string(test->value) + "'")
}

void	test_yaml_read_map_null()
{
	TypeManager::findType<TestYamlReadMap>();
	std::string value = "~";
	// expect to find an empty map
	std::map<std::string, int> expected;

	TestYamlReadMap*	test;

	std::string	input = "type: TestYamlReadMap\nvalue: " + value;

	test = YamlReader().load<TestYamlReadMap>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + map_to_string(expected) + "', was '" + map_to_string(test->value) + "'")
}

void	test_yaml_read_map_array()
{
	TypeManager::findType<TestYamlReadMap>();
	std::string value = "\n- 1\n- 2\n- 3";
	// expect to find an empty map
	std::map<std::string, int> expected;

	TestYamlReadMap*	test;

	std::string	input = "type: TestYamlReadMap\nvalue: " + value;

	test = YamlReader().load<TestYamlReadMap>(input);
	ASSERT(test, "YamlReader::load returned a null object")
	ASSERT(test->value == expected, "failed to retrieve string value from YAML input, expecting '" + map_to_string(expected) + "', was '" + map_to_string(test->value) + "'")
}
