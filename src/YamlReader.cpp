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
 * File: YamlReader.cpp
 * Created: 15th August 2022 12:11:24 am
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 15th August 2022 12:38:31 am
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/YamlReader.h"

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

YamlReader::YamlReader()
{
}

YamlReader::~YamlReader()
{
}

Reflectable*	YamlReader::load(const std::string& input)
{
	Reflectable*	result = nullptr;

	YAML::Node	root = YAML::Load(input);
	if (!root.IsMap())
		return nullptr;

	YAML::Node	typeNode = root["type"];
	if (typeNode.IsNull())
		return nullptr;

	std::string typeName = typeNode.as<std::string>();
	IType*	type = TypeManager::findType(typeName);
	if (!type)
		return nullptr;

	result = (Reflectable*)type->create();

	_stack.push_back(new YAML::Node(root));
	type->iterate(*this, result);
	delete _stack.back();
	_stack.pop_back();

	return result;
}

void	YamlReader::value(const IType* valueType, void* valueInstance)
{
	const YAML::Node&	node = *_stack.back();

	if (!valueInstance)
		return ;

	if (*valueType == *TypeManager::findType<std::string>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((std::string*)valueInstance) = "";
				break;
			case YAML::NodeType::Scalar:
				*((std::string*)valueInstance) = node.as<std::string>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<uint8_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((uint8_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((uint8_t*)valueInstance) = node.as<uint8_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<uint16_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((uint16_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((uint16_t*)valueInstance) = node.as<uint16_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<uint32_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((uint32_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((uint32_t*)valueInstance) = node.as<uint32_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<uint64_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((uint64_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((uint64_t*)valueInstance) = node.as<uint64_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<int8_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((int8_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((int8_t*)valueInstance) = node.as<int8_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<int16_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((int16_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((int16_t*)valueInstance) = node.as<int16_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<int32_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((int32_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((int32_t*)valueInstance) = node.as<int32_t>();
				break;
			default:
				break;
		}
	}
	else if (*valueType == *TypeManager::findType<int64_t>())
	{
		switch (node.Type())
		{
			case YAML::NodeType::Null:
				*((int64_t*)valueInstance) = 0;
				break;
			case YAML::NodeType::Scalar:
				*((int64_t*)valueInstance) = node.as<int64_t>();
				break;
			default:
				break;
		}
	}
}

void	YamlReader::beforeReflectable(Reflectable& reflectable)
{
}

void	YamlReader::reflectableAttribute(const Attribute* attribute, void* attributeInstance)
{
	const std::string&	attributeName = attribute->getName();
	const IType*		type = attribute->getType();
	const YAML::Node&	node = *_stack.back();
	YAML::Node			child;

	try
	{
		child = node[attributeName];
	}
	catch (const std::exception& e)
	{
		return;
	}

	_stack.push_back(new YAML::Node(child));
	if (type->isPointer())
	{
		const IPointerType* pointerType = static_cast<const IPointerType*>(type);
		pointerType->initialize(attributeInstance);
	}
	type->iterate(*this, attributeInstance);
	delete _stack.back();
	_stack.pop_back();
}

void	YamlReader::afterReflectable()
{
}

#include <iostream>

void	YamlReader::beforeList(const IListType* listType, void* listInstance)
{
	const YAML::Node&		node = *_stack.back();
	YAML::const_iterator	it;
	const IType*			valueType = listType->getSubType();
	void*					valueInstance = nullptr;

	std::vector<YAML::Node> list = node.as<std::vector<YAML::Node>>();
	for (const YAML::Node& child : list)
	{
		_stack.push_back(new YAML::Node(child));
		valueInstance = valueType->create();
		valueType->iterate(*this, valueInstance);
		delete _stack.back();
		_stack.pop_back();

		listType->insert(listInstance, valueInstance);
		delete valueInstance;
	}
}

void	YamlReader::listValue(const IType* valueType, void* valueInstance)
{
}

void	YamlReader::afterList()
{
}

void	YamlReader::beforeMap(const IMapType* mapType, void* mapInstance)
{
	const YAML::Node&		node = *_stack.back();
	YAML::const_iterator	it;
	const IType*			keyType = mapType->getKeyType();
	const IType*			valueType = mapType->getValueType();
	void*					keyInstance = nullptr;
	void*					valueInstance = nullptr;

	for (it = node.begin(); it != node.end(); it++)
	{
		_stack.push_back(new YAML::Node(it->first));
		keyInstance = keyType->create();
		keyType->iterate(*this, keyInstance);
		delete _stack.back();
		_stack.pop_back();

		_stack.push_back(new YAML::Node(it->second));
		valueInstance = valueType->create();
		valueType->iterate(*this, valueInstance);
		delete _stack.back();
		_stack.pop_back();

		mapType->insert(mapInstance, keyInstance, valueInstance);
		delete keyInstance;
		delete valueInstance;
	}
}

void	YamlReader::mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance)
{
}

void	YamlReader::afterMap()
{
}
