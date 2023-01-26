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
 * File: JsonWriter.cpp
 * Created: Tuesday, 24th January 2023 9:52:30 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 * 
 * Last Modified: Tuesday, 24th January 2023 9:52:48 pm
 * Modified By: Ribault Paul (pribault.dev@gmail.com)
 */

#include "CppReflection/JsonWriter.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/Reflectable.h"

// jsoncpp
#include <json/json.h>

/*
****************
** namespaces **
****************
*/

using namespace	CppReflection;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

JsonWriter::JsonWriter()
{
}

JsonWriter::~JsonWriter()
{
}

std::string		JsonWriter::compute(const Reflectable& reflectable)
{
	return JsonWriter().internalCompute(reflectable);
}

std::string		JsonWriter::internalCompute(const Reflectable& reflectable)
{
	Json::Value result(Json::objectValue);

	const IReflectableType*	type = reflectable.getType();

	_stack.push_back(&result);
	type->iterate(*this, (void*)&reflectable);
	_stack.pop_back();

	Json::StreamWriterBuilder	builder;
	return Json::writeString(builder, result);
}

void	JsonWriter::value(const IType* valueType, void* valueInstance)
{
	if (_stack.empty())
		return;

	Json::Value*	jsonValue = _stack.back();

	if (!valueInstance)
		*jsonValue = Json::Value(Json::nullValue);
	else if (*valueType == *TypeManager::findType<std::string>())
		*jsonValue = Json::Value(*(std::string*)valueInstance);
	else if (*valueType == *TypeManager::findType<uint8_t>())
		*jsonValue = Json::Value(*(uint8_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<uint16_t>())
		*jsonValue = Json::Value(*(uint16_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<uint32_t>())
		*jsonValue = Json::Value(*(uint32_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<uint64_t>())
		*jsonValue = Json::Value(*(uint64_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<int8_t>())
		*jsonValue = Json::Value(*(int8_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<int16_t>())
		*jsonValue = Json::Value(*(int16_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<int32_t>())
		*jsonValue = Json::Value(*(int32_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<int64_t>())
		*jsonValue = Json::Value(*(int64_t*)valueInstance);
	else if (*valueType == *TypeManager::findType<bool>())
		*jsonValue = Json::Value(*(bool*)valueInstance);
	else
		*jsonValue = Json::Value(Json::nullValue);
}

void	JsonWriter::beforeReflectable(Reflectable& reflectable)
{
	Json::Value*	jsonValue = _stack.back();
	*jsonValue = Json::Value(Json::objectValue);
	(*jsonValue)["type"] = reflectable.getType()->getName();
}

void	JsonWriter::reflectableAttribute(const Attribute* attribute, void* attributeInstance)
{
	const IType*	type = attribute->getType();
	Json::Value*	jsonValue = _stack.back();
	Json::Value&	attributeValue = (*jsonValue)[attribute->getName()];
	_stack.push_back(&attributeValue);
	type->iterate(*this, attributeInstance);
	_stack.pop_back();
}

void	JsonWriter::afterReflectable()
{
}

void	JsonWriter::beforeList(const IListType* listType, void* listInstance)
{
	Json::Value*	jsonValue = _stack.back();
	*jsonValue = Json::Value(Json::arrayValue);
}

void	JsonWriter::listValue(const IType* valueType, void* valueInstance)
{
	if (_stack.empty())
		return;

	Json::Value*	parent = _stack.back();
	Json::Value		result;

	_stack.push_back(&result);
	valueType->iterate(*this, valueInstance);
	_stack.pop_back();
	parent->append(result);
}

void	JsonWriter::afterList()
{
}

void	JsonWriter::beforeMap(const IMapType* mapType, void* mapInstance)
{
	Json::Value*	jsonValue = _stack.back();
	*jsonValue = Json::Value(Json::objectValue);
}

void	JsonWriter::mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance)
{
	Json::Value*	jsonValue = _stack.back();
	Json::Value		key;
	_stack.push_back(&key);
	keyType->iterate(*this, keyInstance);
	_stack.pop_back();
	std::string		name = key.asString();
	Json::Value&	attributeValue = (*jsonValue)[name];
	_stack.push_back(&attributeValue);
	valueType->iterate(*this, valueInstance);
	_stack.pop_back();
}

void	JsonWriter::afterMap()
{
}
