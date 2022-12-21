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
 * File: Type.inl
 * Created: 13th August 2022 4:11:44 pm
 * Author: Paul Ribault (pribault.dev@gmail.com)
 * 
 * Last Modified: 13th August 2022 4:11:46 pm
 * Modified By: Paul Ribault (pribault.dev@gmail.com)
 */

/*
**************
** includes **
**************
*/

// CppReflection
#include "CppReflection/Iterator.h"

/*
***********************************************************************************
************************************ ATTRIBUTES ***********************************
***********************************************************************************
*/

template	<typename T>
CppReflection::Type<T>*	CppReflection::Type<T>::_instance = nullptr;

template	<typename T>
CppReflection::Type<std::vector<T>>*	CppReflection::Type<std::vector<T>>::_instance = nullptr;

template	<typename T>
CppReflection::Type<std::list<T>>*		CppReflection::Type<std::list<T>>::_instance = nullptr;

template	<typename K, typename V>
CppReflection::Type<std::map<K, V>>*	CppReflection::Type<std::map<K, V>>::_instance = nullptr;

/*
********************************************************************************
************************************ METHODS ***********************************
********************************************************************************
*/

// default

template	<typename T>
CppReflection::Type<T>::Type()
	: IType(typeid(T).name(), sizeof(T), &typeid(T))
{
}

template	<typename T>
CppReflection::Type<T>::~Type()
{
}

template	<typename T>
void*		CppReflection::Type<T>::create() const
{
	return (new T);
}

template	<typename T>
CppReflection::Type<T>*	CppReflection::Type<T>::get()
{
	if (!_instance)
		_instance = new Type<T>();
	return _instance;
}

template	<typename T>
void	CppReflection::Type<T>::iterate(Iterator& iterator, void* instance) const
{
	iterator.value(this, instance);
}

// vector

template	<typename T>
CppReflection::Type<std::vector<T>>::Type()
	: IListType(typeid(std::vector<T>).name(), sizeof(std::vector<T>), &typeid(std::vector<T>), TypeManager::findType<T>())
{
}

template	<typename T>
CppReflection::Type<std::vector<T>>::~Type()
{
}

template	<typename T>
void*		CppReflection::Type<std::vector<T>>::create() const
{
	return (new std::vector<T>());
}

template	<typename T>
CppReflection::Type<std::vector<T>>*	CppReflection::Type<std::vector<T>>::get()
{
	if (!_instance)
		_instance = new Type<std::vector<T>>();
	return _instance;
}

template	<typename T>
void	CppReflection::Type<std::vector<T>>::iterate(Iterator& iterator, void* instance) const
{
	iterator.beforeList(this, instance);
	std::vector<T>*	vector = (std::vector<T>*)instance;
	for (const T& value : *vector)
		iterator.listValue(_subType, (void*)&value);
	iterator.afterList();
}

template	<typename T>
void	CppReflection::Type<std::vector<T>>::insert(void* instance, const void* valueInstance) const
{
	std::vector<T>*	vector = (std::vector<T>*)instance;
	T				value = *(T*)valueInstance;

	vector->push_back(value);
}

// list

template	<typename T>
CppReflection::Type<std::list<T>>::Type()
	: IListType(typeid(std::list<T>).name(), sizeof(std::list<T>), &typeid(std::list<T>), TypeManager::findType<T>())
{
}

template	<typename T>
CppReflection::Type<std::list<T>>::~Type()
{
}

template	<typename T>
void*		CppReflection::Type<std::list<T>>::create() const
{
	return (new std::list<T>());
}

template	<typename T>
CppReflection::Type<std::list<T>>*	CppReflection::Type<std::list<T>>::get()
{
	if (!_instance)
		_instance = new Type<std::list<T>>();
	return _instance;
}

template	<typename T>
void	CppReflection::Type<std::list<T>>::iterate(Iterator& iterator, void* instance) const
{
	iterator.beforeList(this, instance);
	std::list<T>*	list = (std::list<T>*)instance;
	for (const T& value : *list)
		iterator.listValue(_subType, (void*)&value);
	iterator.afterList();
}

template	<typename T>
void	CppReflection::Type<std::list<T>>::insert(void* instance, const void* valueInstance) const
{
	std::list<T>*	list = (std::list<T>*)instance;
	T				value = *(T*)valueInstance;

	list->push_back(value);
}

// map

template	<typename K, typename V>
CppReflection::Type<std::map<K, V>>::Type()
	: IMapType(typeid(std::map<K, V>).name(), sizeof(std::map<K, V>), &typeid(std::map<K, V>), TypeManager::findType<K>(), TypeManager::findType<V>())
{
}

template	<typename K, typename V>
CppReflection::Type<std::map<K, V>>::~Type()
{
}

template	<typename K, typename V>
void*		CppReflection::Type<std::map<K, V>>::create() const
{
	return (new std::map<K, V>());
}

template	<typename K, typename V>
CppReflection::Type<std::map<K, V>>*	CppReflection::Type<std::map<K, V>>::get()
{
	if (!_instance)
		_instance = new Type<std::map<K, V>>();
	return _instance;
}

template	<typename K, typename V>
void	CppReflection::Type<std::map<K, V>>::iterate(Iterator& iterator, void* instance) const
{
	iterator.beforeMap(this, instance);
	std::map<K, V>*	map = (std::map<K, V>*)instance;
	for (const std::pair<K, V>& pair : *map)
	{
		iterator.mapPair(_keyType, (void*)&pair.first, _valueType, (void*)&pair.second);
	}
	iterator.afterMap();
}

template	<typename K, typename V>
void	CppReflection::Type<std::map<K, V>>::insert(void* mapInstance, const void *keyInstance, const void* valueInstance) const
{
	std::map<K, V>*	map = (std::map<K, V>*)mapInstance;
	K				key = *(K*)keyInstance;
	V				value = *(V*)valueInstance;

	map->insert(std::make_pair(key, value));
}
