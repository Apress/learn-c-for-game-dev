#pragma once

#include <string>

class Item
{
private:
	std::string m_name;

public:
	Item(const std::string& name)
		: m_name{ name }
	{

	}

	virtual ~Item() {}

	const std::string& GetName() const
	{
		return m_name;
	}
};