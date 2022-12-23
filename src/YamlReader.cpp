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

// stl
#ifndef NDEBUG
# include <iostream>
#endif
#include <optional>
#include <stdexcept>

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

static std::optional<YAML::Node>	getAttribute(const YAML::Node& node, const std::string& attribute)
{
	try
	{
		YAML::Node	result = node[attribute];

		if (result.IsDefined())
			return result;

		return std::nullopt;
	}
	catch (const std::exception&)
	{
		return std::nullopt;
	}
}

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

	std::optional<YAML::Node>	typeNode = getAttribute(root, "type");

	std::string typeName;
	try
	{
		typeName = typeNode.value().as<std::string>();
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error(std::string("couldn't retrieve node type: '") + e.what() + "'");
	}
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
				try
				{
					*((std::string*)valueInstance) = node.as<std::string>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve string: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((uint8_t*)valueInstance) = node.as<uint8_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve uint8: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((uint16_t*)valueInstance) = node.as<uint16_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve uint16: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((uint32_t*)valueInstance) = node.as<uint32_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve uint32: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((uint64_t*)valueInstance) = node.as<uint64_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve uint64: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((int8_t*)valueInstance) = node.as<int8_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve int8: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((int16_t*)valueInstance) = node.as<int16_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve int16: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((int32_t*)valueInstance) = node.as<int32_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve int32: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
				try
				{
					*((int64_t*)valueInstance) = node.as<int64_t>();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve int64: '" << e.what() << "'" << std::endl;
				}
#else
				catch (const std::exception&)
				{
				}
#endif
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
	const std::string&			attributeName = attribute->getName();
	const IType*				type = attribute->getType();
	const YAML::Node&			node = *_stack.back();
	std::optional<YAML::Node>	child;

	child = getAttribute(node, attributeName);
	if (!child.has_value())
		return ;

	_stack.push_back(new YAML::Node(child.value()));
	if (type->isPointer())
	{
		const IPointerType* pointerType = static_cast<const IPointerType*>(type);
		bool				instanceInitialized = false;

		std::optional<YAML::Node>	typeNode = getAttribute(child.value(), "type");
		if (typeNode.has_value())
		{
			std::string		typeName;
			try
			{
				typeName = typeNode.value().as<std::string>();
			}
#ifndef NDEBUG
			catch (const std::exception& e)
			{
				std::cerr << "couldn't retrieve node type: '" << e.what() << "'" << std::endl;
			}
#else
			catch (const std::exception&)
			{
			}
#endif
			if (!typeName.empty())
			{
				const IType*	nodeType = TypeManager::findType(typeName);
				if (nodeType->isReflectable())
				{
					const IReflectableType* reflectableNodeType = static_cast<const IReflectableType*>(nodeType);
					if (reflectableNodeType)
					{
						if (reflectableNodeType->inherits(pointerType->getSubType()))
						{
							type = reflectableNodeType;
							reflectableNodeType->getPointerType()->initialize(attributeInstance);
							instanceInitialized = true;
							attributeInstance = *(void**)attributeInstance;
						}
					}
				}
			}
		}

		if (!instanceInitialized)
			pointerType->initialize(attributeInstance);
	}
	type->iterate(*this, attributeInstance);
	delete _stack.back();
	_stack.pop_back();
}

void	YamlReader::afterReflectable()
{
}

void	YamlReader::beforeList(const IListType* listType, void* listInstance)
{
	const YAML::Node&		node = *_stack.back();
	YAML::const_iterator	it;
	const IType*			valueType = listType->getSubType();
	void*					valueInstance = nullptr;

	if (!node.IsScalar())
		return ;

	std::vector<YAML::Node> list;
	try
	{
		list = node.as<std::vector<YAML::Node>>();
	}
#ifndef NDEBUG
	catch (const std::exception& e)
	{
		std::cerr << "couldn't retrieve node list: '" << e.what() << "'" << std::endl;
		return ;
	}
#else
	catch (const std::exception&)
	{
		return ;
	}
#endif
	for (const YAML::Node& child : list)
	{
		_stack.push_back(new YAML::Node(child));
		valueInstance = valueType->create();
		valueType->iterate(*this, valueInstance);
		delete _stack.back();
		_stack.pop_back();

		listType->insert(listInstance, valueInstance);
		valueType->remove(valueInstance);
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

	if (!node.IsMap())
		return ;
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
		keyType->remove(keyInstance);
		valueType->remove(valueInstance);
	}
}

void	YamlReader::mapPair(const IType* keyType, void* keyInstance, const IType* valueType, void* valueInstance)
{
}

void	YamlReader::afterMap()
{
}
