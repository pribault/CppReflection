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
 * Created: 14th August 2022 6:30:35 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 14th August 2022 6:30:37 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

#include "CppReflection/YamlWriter.h"

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/IType.h"
#include "CppReflection/PointerType.h"
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
***********************************************************************************
************************************ ATTRIBUTES ***********************************
***********************************************************************************
*/

YamlWriter*	YamlWriter::_instance = nullptr;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

YamlWriter::YamlWriter()
{
}

YamlWriter::~YamlWriter()
{
}

YamlWriter*	YamlWriter::get()
{
	if (!_instance)
		_instance = new YamlWriter();
	return _instance;
}

void	YamlWriter::write(std::ostream& outStream, const Reflectable& reflectable, bool writeType) const
{
	YAML::Emitter	emitter;

	writeReflectable(emitter, reflectable, writeType);
	outStream << emitter.c_str();
}

void	YamlWriter::write(std::string& output, const Reflectable& reflectable, bool writeType) const
{
	YAML::Emitter	emitter;

	writeReflectable(emitter, reflectable, writeType);
	output = emitter.c_str();
}

void	YamlWriter::write(const std::string& fileName, bool truncate, const Reflectable& reflectable, bool writeType) const
{
	YAML::Emitter	emitter;

	writeReflectable(emitter, reflectable, writeType);
	std::FILE*	file;
	if (truncate)
		file = std::fopen(fileName.c_str(), "w");
	else
		file = std::fopen(fileName.c_str(), "a");
	if (file)
	{
		std::string	result(emitter.c_str());

		std::fwrite(result.c_str(), sizeof(char), result.size(), file);
		std::fclose(file);
	}
}

void	YamlWriter::writeReflectable(YAML::Emitter& emitter, const Reflectable& reflectable, bool writeType) const
{
	const IReflectableType*	type = reflectable.getType();

	emitter << YAML::BeginMap;

	writeReflectable(emitter, reflectable, *type, writeType);

	emitter << YAML::EndMap;
}

void	YamlWriter::writeReflectable(YAML::Emitter& emitter, const Reflectable& reflectable, const IReflectableType& type, bool writeType) const
{
	if (writeType)
		this->writeType(emitter, type);

	for (size_t i = 0; i < type.getNbParents(); i++)
	{
		const IType*	parent = type.getParent(i);
		if (parent->isReflectable())
		{
			const IReflectableType* reflectableParent = static_cast<const IReflectableType*>(parent);
			writeReflectable(emitter, reflectable, *reflectableParent, false);
		}
	}

	for (size_t i = 0; i < type.getNbAttributes(); i++)
	{
		const Attribute*	attribute = type.getAttribute(i);

		emitter << YAML::Key << attribute->getName();
		writeAttribute(emitter, (const void*)((size_t)&reflectable + attribute->getOffset()), *attribute->getType(), false);
	}
}

void	YamlWriter::writeType(YAML::Emitter& emitter, const IType& type) const
{
	emitter << YAML::Key << "type";
	emitter << YAML::Value << type.getName();
}

void	YamlWriter::writeAttribute(YAML::Emitter& emitter, const void* value, const IType& type, bool writeType) const
{
	if (type == *TypeManager::findType<std::string>())
		emitter << YAML::Value << *(const std::string*)value;
	else if (type == *TypeManager::findType<bool>())
		emitter << YAML::Value << *(const bool*)value;
	else if (type == *TypeManager::findType<uint8_t>())
		emitter << YAML::Value << *(const uint8_t*)value;
	else if (type == *TypeManager::findType<uint16_t>())
		emitter << YAML::Value << *(const uint16_t*)value;
	else if (type == *TypeManager::findType<uint32_t>())
		emitter << YAML::Value << *(const uint32_t*)value;
	else if (type == *TypeManager::findType<uint64_t>())
		emitter << YAML::Value << *(const uint64_t*)value;
	else if (type == *TypeManager::findType<int8_t>())
		emitter << YAML::Value << *(const int8_t*)value;
	else if (type == *TypeManager::findType<int16_t>())
		emitter << YAML::Value << *(const int16_t*)value;
	else if (type == *TypeManager::findType<int32_t>())
		emitter << YAML::Value << *(const int32_t*)value;
	else if (type == *TypeManager::findType<int64_t>())
		emitter << YAML::Value << *(const int64_t*)value;
	else if (type.isReflectable())
		writeReflectable(emitter, *(const Reflectable*)value, writeType);
	else if (type.isPointer())
	{
		const IPointerType&	pointerType = (const IPointerType&)type;
		if (*(void**)value)
			writeAttribute(emitter, *(void**)value, *pointerType.getSubType(), true);
		else
			emitter << YAML::Value << YAML::Null;
	}
	else
		emitter << YAML::Value << YAML::Null;
}
