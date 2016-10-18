#include "SerializationManager.h"
#include "EventManager.h"
#include "Serializable.h"
#include <string>

void SerializationManager::RegisterSerializable(Serializable* pSerializable)
{
	assert(m_serializables.find(pSerializable->GetId()) == m_serializables.end());
	m_serializables.emplace{ pSerializable->GetId(), pSerializable };
}

void SerializationManager::RemoveSerializable(Serializable* pSerializable)
{
	auto iter = m_serializables.find(pSerializable->GetId());
	if (iter != m_serializables.end())
	{
		m_serializables.erase(iter);
	}
}

Serializable* SerializationManager::GetSerializable(unsigned int serializableId) const
{
	Serializable* pSerializable{ nullptr };
	auto iter = m_serializables.find(serializableId);
	if (iter != m_serializables.end())
	{
		pSerializable = iter->second;
	}
	return pSerializable;
}

void SerializationManager::ClearSave()
{
	std::ofstream file{ m_filename };
	file << false;
}

void SerializationManager::Save()
{
	std::ofstream file{ m_filename };
	file << true;
	file << std::endl;
	for (auto& serializable : m_serializables)
	{
		Serializable* pSerializable = serializable.second;
		file << pSerializable->GetId();
		file << std::endl;
		pSerializable->OnSave(file);

		file << std::endl;
		file << std::endl;
	}
}

bool SerializationManager::Load()
{
	std::ifstream file{ m_filename };
	bool found = file.is_open();
	if (found)
	{
		bool isValid;
		file >> isValid;
		if (isValid)
		{
			std::cout << "Save game found, would you like to load? (Type yes to load)" << std::endl << std::endl;
			std::string shouldLoad;
			std::cin >> shouldLoad;
			if (shouldLoad == "yes")
			{
				while (!file.eof())
				{
					unsigned int serializableId{ 0 };
					file >> serializableId;
					auto iter = m_serializables.find(serializableId);
					if (iter != m_serializables.end())
					{
						iter->second->OnLoad(file);
					}
				}
			}
		}
		else
		{
			found = false;
		}
	}
	return found;
}
