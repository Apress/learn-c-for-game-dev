#pragma once

#include "SDBMHash.h"
#include "Singleton.h"
#include <fstream>
#include <unordered_map>

class Serializable;

class SerializationManager
	: public Singleton<SerializationManager>
{
private:
	using Serializables = std::unordered_map<unsigned int, Serializable*>;
	Serializables m_serializables;

	const char* const m_filename{"Save.txt"};

public:
	void RegisterSerializable(Serializable* pSerializable);

	void RemoveSerializable(Serializable* pSerializable);

	Serializable* GetSerializable(unsigned int serializableId) const;

	void ClearSave();

	void Save();

	bool Load();
};