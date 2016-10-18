#include "Room.h"
#include <cassert>
#include <iostream>

Room::Room(unsigned int serializableId)
: Serializable(serializableId)
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(JoiningDirections::Max); ++i)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}

void Room::AddRoom(Room::JoiningDirections direction, Room::Pointer room)
{
	m_pJoiningRooms[static_cast<unsigned int>(direction)] = room;
}

Room::Pointer Room::GetRoom(Room::JoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast<unsigned int>(direction)];
}

void Room::PrintOptions() const
{
	for (unsigned int i = 0; i < m_dynamicOptions.size(); ++i)
	{
		const Option::Pointer option = m_dynamicOptions[i];
		std::cout << i + 1 << ": " << option->GetOutputText() << std::endl << std::endl;
	}

	for (StaticOptions::const_iterator iter = m_staticOptions.cbegin(); iter != m_staticOptions.cend(); ++iter)
	{
		const Option::Pointer option = iter->second;
		const unsigned int chosenOption = iter->first + m_dynamicOptions.size();
		std::cout << chosenOption << ": " << option->GetOutputText() << std::endl << std::endl;
	}
}

Option::Pointer Room::EvaluateInput(unsigned int playerInput)
{
	Option::Pointer option = nullptr;
	const unsigned int numDynamicOptions = m_dynamicOptions.size();
	if (playerInput <= numDynamicOptions)
	{
		unsigned int dynamicIndex = playerInput - 1;
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

	unsigned int numDynamicOptions;
	file >> numDynamicOptions;
	if (numDynamicOptions > 0)
	{
		for (unsigned int i = 0; i < numDynamicOptions; ++i)
		{
			unsigned int optionId;
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