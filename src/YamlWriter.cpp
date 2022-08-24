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
 * File: YamlWriter.cpp
 * Created: 15th August 2022 12:11:29 am
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 15th August 2022 12:38:34 am
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/YamlWriter.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/Reflectable.h"

// yamlcpp
#include <yaml-cpp/yaml.h>

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

YamlWriter::YamlWriter()
	: _emitter(nullptr)
{
}

YamlWriter::~YamlWriter()
{
	if (_emitter)
	{
		delete _emitter;
		_emitter = nullptr;
	}
}

std::string		YamlWriter::compute(const Reflectable& reflectable)
{
	if (!_emitter)
	{
		_emitter = new YAML::Emitter();

		const IReflectableType*	type = reflectable.getType();

		type->iterate(*this, (void*)&reflectable);

		std::string	result = _emitter->c_str();

		delete _emitter;
		_emitter = nullptr;

		return result;
	}
	return "";
}

void	YamlWriter::value(const IType* valueType, void* valueInstance)
{
	if (!valueInstance)
		*_emitter << YAML::Null;
	else if (*valueType == *TypeManager::findType<std::string>())
		*_emitter << *(std::string*)valueInstance;
	else if (*valueType == *TypeManager::findType<uint8_t>())
		*_emitter << *(uint8_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<uint16_t>())
		*_emitter << *(uint16_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<uint32_t>())
		*_emitter << *(uint32_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<uint64_t>())
		*_emitter << *(uint64_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<int8_t>())
		*_emitter << *(int8_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<int16_t>())
		*_emitter << *(int16_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<int32_t>())
		*_emitter << *(int32_t*)valueInstance;
	else if (*valueType == *TypeManager::findType<int64_t>())
		*_emitter << *(int64_t*)valueInstance;
	else
		*_emitter << YAML::Null;
}

void	YamlWriter::beforeReflectable(Reflectable& reflectable)
{
	*_emitter << YAML::BeginMap;
	*_emitter << YAML::Key << "type";
	*_emitter << YAML::Value << reflectable.getType()->getName();
}

void	YamlWriter::reflectableAttribute(const Attribute* attribute, void* attributeInstance)
{
	const IType*	type = attribute->getType();

	*_emitter << YAML::Key << attribute->getName();
	*_emitter << YAML::Value;
	type->iterate(*this, attributeInstance);
}

void	YamlWriter::afterReflectable()
{
	*_emitter << YAML::EndMap;
}

void	YamlWriter::beforeList()
{
	*_emitter << YAML::BeginSeq;
}

void	YamlWriter::listValue(const IType* valueType, void* valueInstance)
{
	valueType->iterate(*this, valueInstance);
}

void	YamlWriter::afterList()
{
	*_emitter << YAML::EndSeq;
}

void	YamlWriter::beforeMap()
{
	*_emitter << YAML::BeginMap;
}

void	YamlWriter::mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance)
{
	*_emitter << YAML::Key;
	keyType->iterate(*this, keyInstance);
	*_emitter << YAML::Value;
	valueType->iterate(*this, valueInstance);
}

void	YamlWriter::afterMap()
{
	*_emitter << YAML::EndMap;
}
