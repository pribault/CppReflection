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
 * File: JsonReader.cpp
 * Created: Wednesday, 11th January 2023 8:50:32 pm
 * Author: Ribault Paul (pribault.dev@gmail.com)
 *
 * Last Modified: Wednesday, 11th January 2023 8:50:34 pm
 * Modified By: Ribault Paul (pribault.dev@gmail.com)
 */

#include "CppReflection/JsonReader.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/Reflectable.h"

// jsoncpp
#include <json/json.h>

// stl
#include <optional>
#include <iostream>

/*
****************
** namespaces **
****************
*/

using namespace CppReflection;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

static const Json::Value*	getAttribute(const Json::Value& node, const std::string& attribute)
{
	if (!node.isObject())
		return nullptr;
	return node.find(&attribute.front(), &attribute.back() + 1);
}

JsonReader::JsonReader()
{
}

JsonReader::~JsonReader()
{
}

Reflectable *JsonReader::load(const std::string &input)
{
	return JsonReader().internalLoad(input);
}

Reflectable *JsonReader::internalLoad(const std::string &input)
{
	Reflectable *result = nullptr;

	Json::CharReaderBuilder rbuilder;
	const std::unique_ptr<Json::CharReader> reader(rbuilder.newCharReader());

	Json::Value root;
	std::string errors;
	bool parseResult = reader->parse(&input.front(), &input.back(), &root, &errors);

	if (!root.isObject())
		return nullptr;

	const Json::Value*	typeNode = getAttribute(root, "type");

	if (!typeNode)
		throw std::runtime_error("couldn't retrieve root node type");
	if (!typeNode->isString())
		throw std::runtime_error("root node type isn't a string");

	std::string typeName = typeNode->asString();
	IType*	type = TypeManager::findType(typeName);
	if (!type)
		return nullptr;

	result = (Reflectable*)type->create();

	_stack.push_back(new Json::Value(root));
	type->iterate(*this, result);
	delete _stack.back();
	_stack.pop_back();

	return result;
}

void JsonReader::value(const IType *valueType, void *valueInstance)
{
	const Json::Value&	node = *_stack.back();

	if (!valueInstance)
		return ;

	if (*valueType == *TypeManager::findType<std::string>())
	{
		switch (node.type())
		{
			case Json::nullValue:
				*((std::string*)valueInstance) = "";
				break;
			case Json::stringValue:
				try
				{
					*((std::string*)valueInstance) = node.asString();
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
	else if (*valueType == *TypeManager::findType<bool>())
	{
		switch (node.type())
		{
			case Json::nullValue:
				*((bool*)valueInstance) = 0;
				break;
			case Json::booleanValue:
				try
				{
					*((bool*)valueInstance) = node.asBool();
				}
#ifndef NDEBUG
				catch (const std::exception& e)
				{
					std::cerr << "couldn't retrieve bool: '" << e.what() << "'" << std::endl;
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
		switch (node.type())
		{
			case Json::nullValue:
				*((uint8_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					uint32_t	value = node.asUInt();
					if (value <= (uint32_t)std::numeric_limits<uint8_t>::max() &&
						value >= (uint32_t)std::numeric_limits<uint8_t>::min())
						*((uint8_t*)valueInstance) = value;
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
		switch (node.type())
		{
			case Json::nullValue:
				*((uint16_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					uint32_t	value = node.asUInt();
					if (value <= (uint32_t)std::numeric_limits<uint16_t>::max() &&
						value >= (uint32_t)std::numeric_limits<uint16_t>::min())
						*((uint16_t*)valueInstance) = value;
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
		switch (node.type())
		{
			case Json::nullValue:
				*((uint32_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					*((uint32_t*)valueInstance) = node.asUInt();
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
		switch (node.type())
		{
			case Json::nullValue:
				*((uint64_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					*((uint64_t*)valueInstance) = node.asUInt64();
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
		switch (node.type())
		{
			case Json::nullValue:
				*((int8_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					int32_t	value = node.asInt();
					if (value <= (int8_t)std::numeric_limits<int8_t>::max() &&
						value >= (int8_t)std::numeric_limits<int8_t>::min())
						*((int8_t*)valueInstance) = value;
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
		switch (node.type())
		{
			case Json::nullValue:
				*((int16_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					int32_t	value = node.asInt();
					if (value <= (int32_t)std::numeric_limits<int16_t>::max() &&
						value >= (int32_t)std::numeric_limits<int16_t>::min())
						*((int16_t*)valueInstance) = value;
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
		switch (node.type())
		{
			case Json::nullValue:
				*((int32_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					*((int32_t*)valueInstance) = node.asInt();
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
		switch (node.type())
		{
			case Json::nullValue:
				*((int64_t*)valueInstance) = 0;
				break;
			case Json::intValue:
			case Json::uintValue:
				try
				{
					*((int64_t*)valueInstance) = node.asInt64();
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

void JsonReader::beforeReflectable(Reflectable &reflectable)
{
}

void JsonReader::reflectableAttribute(const Attribute *attribute, void *attributeInstance)
{
	const std::string&	attributeName = attribute->getName();
	const IType*		type = attribute->getType();
	const Json::Value&	node = *_stack.back();
	const Json::Value*	child;

	child = getAttribute(node, attributeName);
	if (!child)
		return ;

	_stack.push_back(new Json::Value(*child));
	if (type->isPointer())
	{
		const IPointerType* pointerType = static_cast<const IPointerType*>(type);
		bool				instanceInitialized = false;

		const Json::Value*	typeNode = getAttribute(*child, "type");
		if (typeNode && typeNode->isString())
		{
			std::string		typeName;
			typeName = typeNode->asString();
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

void JsonReader::afterReflectable()
{
}

void JsonReader::beforeList(const IListType *listType, void *listInstance)
{
	const Json::Value&		node = *_stack.back();
	const IType*			valueType = listType->getSubType();
	void*					valueInstance = nullptr;

	if (!node.isArray())
		return ;

	for (const Json::Value& child : node)
	{
		_stack.push_back(new Json::Value(child));
		valueInstance = valueType->create();
		valueType->iterate(*this, valueInstance);
		delete _stack.back();
		_stack.pop_back();

		listType->insert(listInstance, valueInstance);
		valueType->remove(valueInstance);
	}
}

void JsonReader::listValue(const IType *valueType, void *valueInstance)
{
}

void JsonReader::afterList()
{
}

void JsonReader::beforeMap(const IMapType *mapType, void *mapInstance)
{
	const Json::Value&			node = *_stack.back();

	if (!node.isObject())
		return ;

	std::vector<std::string>	members = node.getMemberNames();
	const IType*				keyType = mapType->getKeyType();
	const IType*				valueType = mapType->getValueType();
	void*						keyInstance = nullptr;
	void*						valueInstance = nullptr;

	for (const std::string& member : members)
	{
		_stack.push_back(new Json::Value(member));
		keyInstance = keyType->create();
		keyType->iterate(*this, keyInstance);
		delete _stack.back();
		_stack.pop_back();

		_stack.push_back(new Json::Value(*getAttribute(node, member)));
		valueInstance = valueType->create();
		valueType->iterate(*this, valueInstance);
		delete _stack.back();
		_stack.pop_back();

		mapType->insert(mapInstance, keyInstance, valueInstance);
		keyType->remove(keyInstance);
		valueType->remove(valueInstance);
	}
}

void JsonReader::mapPair(const IType *keyType, void *keyInstance, const IType *valueType, void *valueInstance)
{
}

void JsonReader::afterMap()
{
}
