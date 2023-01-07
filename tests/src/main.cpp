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

#include "unit_tests.h"

/*
**************
** includes **
**************
*/

// stl
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

int		main(int argc, char** argv)
{
	std::map<std::string, std::function<void ()>> testsMap({
		std::make_pair("yaml read string", &test_yaml_read_string),
		std::make_pair("yaml read string from null", &test_yaml_read_string_null),
		std::make_pair("yaml read string from array", &test_yaml_read_string_array),
		std::make_pair("yaml read string from map", &test_yaml_read_string_map),
		std::make_pair("yaml read uint8", &test_yaml_read_uint8),
		std::make_pair("yaml read uint8 from null", &test_yaml_read_uint8_null),
		std::make_pair("yaml read uint8 from lowest", &test_yaml_read_uint8_lowest),
		std::make_pair("yaml read uint8 from underflow", &test_yaml_read_uint8_underflow),
		std::make_pair("yaml read uint8 from highest", &test_yaml_read_uint8_highest),
		std::make_pair("yaml read uint8 from overflow", &test_yaml_read_uint8_overflow),
		std::make_pair("yaml read uint8 from floating point number", &test_yaml_read_uint8_float),
		std::make_pair("yaml read uint8 from string", &test_yaml_read_uint8_string),
		std::make_pair("yaml read uint16", &test_yaml_read_uint16),
		std::make_pair("yaml read uint16 from null", &test_yaml_read_uint16_null),
		std::make_pair("yaml read uint16 from lowest", &test_yaml_read_uint16_lowest),
		std::make_pair("yaml read uint16 from underflow", &test_yaml_read_uint16_underflow),
		std::make_pair("yaml read uint16 from highest", &test_yaml_read_uint16_highest),
		std::make_pair("yaml read uint16 from overflow", &test_yaml_read_uint16_overflow),
		std::make_pair("yaml read uint16 from floating point number", &test_yaml_read_uint16_float),
		std::make_pair("yaml read uint16 from string", &test_yaml_read_uint16_string),
		std::make_pair("yaml read uint32", &test_yaml_read_uint32),
		std::make_pair("yaml read uint32 from null", &test_yaml_read_uint32_null),
		std::make_pair("yaml read uint32 from lowest", &test_yaml_read_uint32_lowest),
		std::make_pair("yaml read uint32 from underflow", &test_yaml_read_uint32_underflow),
		std::make_pair("yaml read uint32 from highest", &test_yaml_read_uint32_highest),
		std::make_pair("yaml read uint32 from overflow", &test_yaml_read_uint32_overflow),
		std::make_pair("yaml read uint32 from floating point number", &test_yaml_read_uint32_float),
		std::make_pair("yaml read uint32 from string", &test_yaml_read_uint32_string),
		std::make_pair("yaml read uint64", &test_yaml_read_uint64),
		std::make_pair("yaml read uint64 from null", &test_yaml_read_uint64_null),
		std::make_pair("yaml read uint64 from lowest", &test_yaml_read_uint64_lowest),
		std::make_pair("yaml read uint64 from underflow", &test_yaml_read_uint64_underflow),
		std::make_pair("yaml read uint64 from highest", &test_yaml_read_uint64_highest),
		std::make_pair("yaml read uint64 from overflow", &test_yaml_read_uint64_overflow),
		std::make_pair("yaml read uint64 from floating point number", &test_yaml_read_uint64_float),
		std::make_pair("yaml read uint64 from string", &test_yaml_read_uint64_string),
		std::make_pair("yaml read int8", &test_yaml_read_int8),
		std::make_pair("yaml read int8 from null", &test_yaml_read_int8_null),
		std::make_pair("yaml read int8 from lowest", &test_yaml_read_int8_lowest),
		std::make_pair("yaml read int8 from underflow", &test_yaml_read_int8_underflow),
		std::make_pair("yaml read int8 from highest", &test_yaml_read_int8_highest),
		std::make_pair("yaml read int8 from overflow", &test_yaml_read_int8_overflow),
		std::make_pair("yaml read int8 from floating point number", &test_yaml_read_int8_float),
		std::make_pair("yaml read int8 from string", &test_yaml_read_int8_string),
		std::make_pair("yaml read int16", &test_yaml_read_int16),
		std::make_pair("yaml read int16 from null", &test_yaml_read_int16_null),
		std::make_pair("yaml read int16 from lowest", &test_yaml_read_int16_lowest),
		std::make_pair("yaml read int16 from underflow", &test_yaml_read_int16_underflow),
		std::make_pair("yaml read int16 from highest", &test_yaml_read_int16_highest),
		std::make_pair("yaml read int16 from overflow", &test_yaml_read_int16_overflow),
		std::make_pair("yaml read int16 from floating point number", &test_yaml_read_int16_float),
		std::make_pair("yaml read int16 from string", &test_yaml_read_int16_string),
		std::make_pair("yaml read int32", &test_yaml_read_int32),
		std::make_pair("yaml read int32 from null", &test_yaml_read_int32_null),
		std::make_pair("yaml read int32 from lowest", &test_yaml_read_int32_lowest),
		std::make_pair("yaml read int32 from underflow", &test_yaml_read_int32_underflow),
		std::make_pair("yaml read int32 from highest", &test_yaml_read_int32_highest),
		std::make_pair("yaml read int32 from overflow", &test_yaml_read_int32_overflow),
		std::make_pair("yaml read int32 from floating point number", &test_yaml_read_int32_float),
		std::make_pair("yaml read int32 from string", &test_yaml_read_int32_string),
		std::make_pair("yaml read int64", &test_yaml_read_int64),
		std::make_pair("yaml read int64 from null", &test_yaml_read_int64_null),
		std::make_pair("yaml read int64 from lowest", &test_yaml_read_int64_lowest),
		std::make_pair("yaml read int64 from underflow", &test_yaml_read_int64_underflow),
		std::make_pair("yaml read int64 from highest", &test_yaml_read_int64_highest),
		std::make_pair("yaml read int64 from overflow", &test_yaml_read_int64_overflow),
		std::make_pair("yaml read int64 from floating point number", &test_yaml_read_int64_float),
		std::make_pair("yaml read int64 from string", &test_yaml_read_int64_string),
		std::make_pair("yaml read boolean", &test_yaml_read_boolean),
		std::make_pair("yaml read boolean from null", &test_yaml_read_boolean_null),
		std::make_pair("yaml read boolean from array", &test_yaml_read_boolean_array),
		std::make_pair("yaml read boolean from map", &test_yaml_read_boolean_map),
		std::make_pair("yaml read list", &test_yaml_read_list),
		std::make_pair("yaml read list from null", &test_yaml_read_list_null),
		std::make_pair("yaml read list from map", &test_yaml_read_list_map),
		std::make_pair("yaml read map", &test_yaml_read_map),
		std::make_pair("yaml read map from null", &test_yaml_read_map_null),
		std::make_pair("yaml read map from array", &test_yaml_read_map_array),
		std::make_pair("yaml read pointer", &test_yaml_read_pointer),
		std::make_pair("yaml read pointer from null", &test_yaml_read_pointer_null),
		std::make_pair("yaml read reflectable", &test_yaml_read_reflectable),
		std::make_pair("yaml read reflectable with type mismatch", &test_yaml_read_reflectable_type_mismatch),
		std::make_pair("type reflectable", &test_type_reflectable),
		std::make_pair("type reflectable inheritance", &test_type_reflectable_inheritance),
		std::make_pair("type reflectable attributes", &test_type_reflectable_attributes),
		std::make_pair("type pointer", &test_type_pointer),
		std::make_pair("yaml write boolean", &test_yaml_write_boolean),
		std::make_pair("yaml write int8", &test_yaml_write_int8),
		std::make_pair("yaml write int8 min", &test_yaml_write_int8_min),
		std::make_pair("yaml write int8 max", &test_yaml_write_int8_max),
		std::make_pair("yaml write int16", &test_yaml_write_int16),
		std::make_pair("yaml write int16 min", &test_yaml_write_int16_min),
		std::make_pair("yaml write int16 max", &test_yaml_write_int16_max),
		std::make_pair("yaml write int32", &test_yaml_write_int32),
		std::make_pair("yaml write int32 min", &test_yaml_write_int32_min),
		std::make_pair("yaml write int32 max", &test_yaml_write_int32_max),
		std::make_pair("yaml write int64", &test_yaml_write_int64),
		std::make_pair("yaml write int64 min", &test_yaml_write_int64_min),
		std::make_pair("yaml write int64 max", &test_yaml_write_int64_max),
		std::make_pair("yaml write uint8", &test_yaml_write_uint8),
		std::make_pair("yaml write uint8 min", &test_yaml_write_uint8_min),
		std::make_pair("yaml write uint8 max", &test_yaml_write_uint8_max),
		std::make_pair("yaml write uint16", &test_yaml_write_uint16),
		std::make_pair("yaml write uint16 min", &test_yaml_write_uint16_min),
		std::make_pair("yaml write uint16 max", &test_yaml_write_uint16_max),
		std::make_pair("yaml write uint32", &test_yaml_write_uint32),
		std::make_pair("yaml write uint32 min", &test_yaml_write_uint32_min),
		std::make_pair("yaml write uint32 max", &test_yaml_write_uint32_max),
		std::make_pair("yaml write uint64", &test_yaml_write_uint64),
		std::make_pair("yaml write uint64 min", &test_yaml_write_uint64_min),
		std::make_pair("yaml write uint64 max", &test_yaml_write_uint64_max),
		std::make_pair("yaml write string", &test_yaml_write_string),
		std::make_pair("yaml write string with quotes", &test_yaml_write_string_quotes),
		std::make_pair("yaml write list", &test_yaml_write_list),
		std::make_pair("yaml write map", &test_yaml_write_map),
		std::make_pair("yaml write reflectable", &test_yaml_write_reflectable),
		std::make_pair("yaml write pointer", &test_yaml_write_pointer),
		std::make_pair("yaml write pointer null", &test_yaml_write_pointer_null)
	});
	size_t	failures = 0;
	size_t	index = 1;
	size_t	total = testsMap.size();

	std::map<std::string, std::function<void ()>>::const_iterator it;
	std::map<std::string, std::function<void ()>>::const_iterator end = testsMap.cend();

	// iterate over tests map
	std::cout << "=============================== UNIT TESTS START ===============================" << std::endl;
	for (it = testsMap.cbegin(); it != end; it++)
	{
		// try to run the test
		std::cout << "===== running '" << it->first << "' (test " << index << "/" << total << ")" << std::endl;
		try
		{
			it->second();
		}
		catch (const std::exception& e)
		{
			// handle test failure
			std::cerr << "'" << it->first << "' failed: " << e.what() << std::endl;
			failures++;
		}
		index++;
	}
	// display summary
	std::cout << "===================================== END ======================================" << std::endl
		<< "summary:" << std::endl
		<< "  passed: " << total - failures << std::endl
		<< "  failed: " << failures << std::endl;

	// return EXIT_SUC
	return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
