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
 * File: unit_tests.h
 * Created: Friday, 23rd December 2022 4:21:04 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Friday, 23rd December 2022 4:22:03 pm
 * Modified By: Ribault Paul (pribault.dev@gmail.com)
 */

#pragma once

/*
**************
** includes **
**************
*/

// stl
#include <stdexcept>

/*
*************
** defines **
*************
*/

#define ASSERT(condition, errorMessage)			if (!(condition)) throw std::runtime_error(errorMessage);
#define EXPECT_EXCEPTION(statement, exception)	\
	try\
	{\
		statement;\
	}\
	catch (exception e)\
	{\
	}

/*
***************
** functions **
***************
*/

void	test_yaml_read_string();
void	test_yaml_read_string_null();
void	test_yaml_read_string_array();
void	test_yaml_read_string_map();

void	test_yaml_read_uint8();
void	test_yaml_read_uint8_null();
void	test_yaml_read_uint8_lowest();
void	test_yaml_read_uint8_underflow();
void	test_yaml_read_uint8_highest();
void	test_yaml_read_uint8_overflow();
void	test_yaml_read_uint8_float();
void	test_yaml_read_uint8_string();

void	test_yaml_read_uint16();
void	test_yaml_read_uint16_null();
void	test_yaml_read_uint16_lowest();
void	test_yaml_read_uint16_underflow();
void	test_yaml_read_uint16_highest();
void	test_yaml_read_uint16_overflow();
void	test_yaml_read_uint16_float();
void	test_yaml_read_uint16_string();

void	test_yaml_read_uint32();
void	test_yaml_read_uint32_null();
void	test_yaml_read_uint32_lowest();
void	test_yaml_read_uint32_underflow();
void	test_yaml_read_uint32_highest();
void	test_yaml_read_uint32_overflow();
void	test_yaml_read_uint32_float();
void	test_yaml_read_uint32_string();

void	test_yaml_read_uint64();
void	test_yaml_read_uint64_null();
void	test_yaml_read_uint64_lowest();
void	test_yaml_read_uint64_underflow();
void	test_yaml_read_uint64_highest();
void	test_yaml_read_uint64_overflow();
void	test_yaml_read_uint64_float();
void	test_yaml_read_uint64_string();

void	test_yaml_read_int8();
void	test_yaml_read_int8_null();
void	test_yaml_read_int8_lowest();
void	test_yaml_read_int8_underflow();
void	test_yaml_read_int8_highest();
void	test_yaml_read_int8_overflow();
void	test_yaml_read_int8_float();
void	test_yaml_read_int8_string();

void	test_yaml_read_int16();
void	test_yaml_read_int16_null();
void	test_yaml_read_int16_lowest();
void	test_yaml_read_int16_underflow();
void	test_yaml_read_int16_highest();
void	test_yaml_read_int16_overflow();
void	test_yaml_read_int16_float();
void	test_yaml_read_int16_string();

void	test_yaml_read_int32();
void	test_yaml_read_int32_null();
void	test_yaml_read_int32_lowest();
void	test_yaml_read_int32_underflow();
void	test_yaml_read_int32_highest();
void	test_yaml_read_int32_overflow();
void	test_yaml_read_int32_float();
void	test_yaml_read_int32_string();

void	test_yaml_read_int64();
void	test_yaml_read_int64_null();
void	test_yaml_read_int64_lowest();
void	test_yaml_read_int64_underflow();
void	test_yaml_read_int64_highest();
void	test_yaml_read_int64_overflow();
void	test_yaml_read_int64_float();
void	test_yaml_read_int64_string();

void	test_yaml_read_boolean();
void	test_yaml_read_boolean_null();
void	test_yaml_read_boolean_array();
void	test_yaml_read_boolean_map();
