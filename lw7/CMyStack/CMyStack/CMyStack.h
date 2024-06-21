#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
class CMyStack
{
public:
	CMyStack() = default;
	~CMyStack() noexcept
	{
		delete[] m_data;
	}
	CMyStack(const CMyStack& other)
		: m_data(nullptr)
		, m_capacity(other.m_capacity)
		, m_size(other.m_size)
	{
		if (other.m_capacity > 0)
		{
			m_data = new T[other.m_capacity];
			try
			{
				std::copy(other.m_data, other.m_data + other.m_size, m_data);
			}
			catch (...)
			{
				delete[] m_data;
				m_data = nullptr;
				throw;
			}
		}
	}
	CMyStack(CMyStack&& other) noexcept
		: m_data(other.m_data)
		, m_size(other.m_size)
		, m_capacity(other.m_capacity)
	{
		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	CMyStack& operator=(const CMyStack& other)
	{
		if (this != &other)
		{
			CMyStack temp(other);
			std::swap(m_data, temp.m_data);
			std::swap(m_size, temp.m_size);
			std::swap(m_capacity, temp.m_capacity);
		}
		return *this;
	}
	CMyStack& operator=(CMyStack&& other) noexcept
	{
		if (this != &other)
		{
			delete[] m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			other.m_data = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;
		}
		return *this;
	}
	void Push(const T& value)
	{
		if (m_size == m_capacity)
		{
			Resize(m_capacity == 0 ? 1 : m_capacity * 2);
		}
		m_data[m_size++] = value;
	}
	void Pop()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("Stack is empty");
		}
		--m_size;
	}
	const T& Top() const
	{
		if (IsEmpty())
		{
			throw std::out_of_range("Stack is empty");
		}
		return m_data[m_size - 1];
	}
	bool IsEmpty() const
	{
		return m_size == 0;
	}
	size_t GetSize() const
	{
		return m_size;
	}
	void Clear()
	{
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
	}
private:
	void Resize(size_t newCapacity)
	{
		if (newCapacity == 0)
		{
			newCapacity = 1;
		}
		T* newData = new T[newCapacity];
		try
		{
			std::copy(m_data, m_data + m_size, newData);
		}
		catch (...)
		{
			delete[] newData;
			newData = nullptr;
			throw;
		}
		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	}
	T* m_data = nullptr;
	size_t m_capacity = 0;
	size_t m_size = 0;
};