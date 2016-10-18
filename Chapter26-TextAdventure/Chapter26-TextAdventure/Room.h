#pragma once

#include "Entity.h"
#include "Item.h"
#include "Option.h"
#include "Serializable.h"
#include <array>
#include <map>
#include <vector>

class Room
	: public Entity
	, public Serializable
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

	using StaticOptions = std::map<uint32_t, Option::Pointer>;
	StaticOptions m_staticOptions;
	uint32_t m_staticOptionStartKey{ 1 };

	using DynamicOptions = std::vector<Option::Pointer>;
	DynamicOptions m_dynamicOptions;

	Pointer m_pointer{ this };

public:
	explicit Room(const uint32_t serializableId);

	void AddRoom(JoiningDirections direction, Pointer room);
	Pointer GetRoom(JoiningDirections direction) const;

	Option::Pointer EvaluateInput(const uint32_t playerInput);
	void AddStaticOption(Option::Pointer option);
	void AddDynamicOption(Option::Pointer option);
	void PrintOptions() const;

	virtual void OnSave(std::ofstream& file);
	virtual void OnLoad(std::ifstream& file);

	Pointer GetPointer() const { return m_pointer; }
};