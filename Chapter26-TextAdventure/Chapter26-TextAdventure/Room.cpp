#include "Room.h"
#include <cassert>
#include <iostream>

Room::Room(const uint32_t serializableId)
: Serializable(serializableId)
{
	for (uint32_t i = 0; i < static_cast<uint32_t>(JoiningDirections::Max); ++i)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}

void Room::AddRoom(Room::JoiningDirections direction, Room::Pointer room)
{
	m_pJoiningRooms[static_cast<uint32_t>(direction)] = room;
}

Room::Pointer Room::GetRoom(Room::JoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast<uint32_t>(direction)];
}

void Room::PrintOptions() const
{
	for (uint32_t i = 0; i < m_dynamicOptions.size(); ++i)
	{
		const Option::Pointer option = m_dynamicOptions[i];
		std::cout << i + 1 << ": " << option->GetOutputText() << std::endl << std::endl;
	}

	for (StaticOptions::const_iterator iter = m_staticOptions.cbegin(); iter != m_staticOptions.cend(); ++iter)
	{
		const Option::Pointer option = iter->second;
		const uint32_t chosenOption = iter->first + m_dynamicOptions.size();
		std::cout << chosenOption << ": " << option->GetOutputText() << std::endl << std::endl;
	}
}

Option::Pointer Room::EvaluateInput(uint32_t playerInput)
{
	Option::Pointer option = nullptr;
	const uint32_t numDynamicOptions = m_dynamicOptions.size();
	if (playerInput <= numDynamicOptions)
	{
		uint32_t dynamicIndex = playerInput - 1;
		option = m_dynamicOptions[dynamicIndex];
		m_dynamicOptions.erase(m_dynamicOptions.begin() + dynamicIndex);
	}
	else
	{
		option = m_staticOptions.at(playerInput - numDynamicOptions);
	}
	return option;
}

void Room::AddStaticOption(Option::Pointer option)
{
	assert(option != nullptr);
	m_staticOptions[m_staticOptionStartKey++] = option;
}

void Room::AddDynamicOption(Option::Pointer option)
{
	assert(option != nullptr);
	m_dynamicOptions.push_back(option);
}

void Room::OnSave(std::ofstream& file)
{
	file << m_dynamicOptions.size();
	file << std::endl;
	for (auto& dynamicOption : m_dynamicOptions)
	{
		file << dynamicOption->GetId();
		file << std::endl;
	}
}

void Room::OnLoad(std::ifstream& file)
{
	m_dynamicOptions.clear();

	uint32_t numDynamicOptions;
	file >> numDynamicOptions;
	if (numDynamicOptions > 0)
	{
		for (uint32_t i = 0; i < numDynamicOptions; ++i)
		{
			uint32_t optionId;
			file >> optionId;
			Option* pOption = dynamic_cast<Option*>(SerializationManager::GetSingleton().GetSerializable(optionId));
			if (pOption)
			{
				Option::Pointer sharedPointer = pOption->GetPointer();
				m_dynamicOptions.emplace_back{ sharedPointer };
			}
		}
	}
}