#pragma once

#include "Entity.h"
#include "Item.h"
#include "Option.h"
#include <array>
#include <map>
#include <vector>

class Room
	: public Entity
{
public:
	using Pointer = std::shared_ptr<Room>;

	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};

private:
	using JoiningRooms = std::array<Pointer, static_cast<size_t>(JoiningDirections::Max)>;
	JoiningRooms m_pJoiningRooms;

	using StaticOptions = std::map<unsigned int, Option::Pointer>;
	StaticOptions m_staticOptions;
	unsigned int m_staticOptionStartKey{ 1 };

	using DynamicOptions = std::vector<Option::Pointer>;
	DynamicOptions m_dynamicOptions;

public:
	Room();

	void AddRoom(JoiningDirections direction, Pointer room);
	Pointer GetRoom(JoiningDirections direction) const;

	Option::Pointer EvaluateInput(unsigned int playerInput);
	void AddStaticOption(Option::Pointer option);
	void AddDynamicOption(Option::Pointer option);
	void PrintOptions() const;
};