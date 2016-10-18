#pragma once

#include <string>

class Player
{
private:
	std::string m_name;

public:
	Player()
	{
	}

	void SetName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& GetName() const
	{
		return m_name;
	}
};