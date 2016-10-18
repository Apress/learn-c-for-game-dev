#pragma once

#include "SerializationManager.h"

class Serializable
{
	uint32_t m_id{ 0 };

public:
	explicit Serializable(const uint32_t id)
		: m_id{ id }
	{
		SerializationManager::GetSingleton().RegisterSerializable(this);
	}

	Serializable::~Serializable()
	{
		SerializationManager* pSerializationManager = SerializationManager::GetSingletonPtr();
		if (pSerializationManager)
		{
			pSerializationManager->RemoveSerializable(this);
		}
	}

	virtual void OnSave(std::ofstream& file) = 0;
	virtual void OnLoad(std::ifstream& file) = 0;

	uint32_t GetId() const { return m_id; }
};