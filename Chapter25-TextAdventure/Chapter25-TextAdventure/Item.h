#pragma once

#include "SDBMHash.h"
#include "Serializable.h"
#include <string>

class Item
	: public Serializable
{
private:
	std::string m_name;

public:
	Item(const std::string& name)
		: m_name{ name }
		, Serializable(SDBMHash(name.c_str()))
	{

	}

	virtual ~Item() {}

	const std::string& GetName() const
	{
		return m_name;
	}

	virtual void OnSave(std::ofstream& file)
	{

	}

	virtual void OnLoad(std::ifstream& file)
	{

	}
};