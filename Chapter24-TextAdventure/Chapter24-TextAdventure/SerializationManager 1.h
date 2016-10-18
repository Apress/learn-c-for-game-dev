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

	void Save();

	bool Load();
};

constexpr char* const PostLoadEventString = "PostLoadEvent";
constexpr int PostLoadEventStringLength =
#ifndef constexpr
	constexpr_strlen(PostLoadEventString);
#else
	13;
#endif
constexpr int PostLoadEvent = SDBMCalculator<PostLoadEventStringLength>::CalculateValue(PostLoadEventString);