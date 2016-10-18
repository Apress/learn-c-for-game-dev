#pragma once

#include <cassert>

template <typename T>
class Singleton
{
private:
	static T* m_instance;

public:
	Singleton()
	{
		assert(m_instance == nullptr);
		if (m_instance == nullptr)
		{
			m_instance = static_cast<T*>(this);
		}
	}

	virtual ~Singleton()
	{
		m_instance = nullptr;
	}

	static T& GetSingleton()
	{
		return *m_instance;
	}

	static T* GetSingletonPtr()
	{
		return m_instance;
	}
};

template <typename T>
T* Singleton<T>::m_instance = nullptr;