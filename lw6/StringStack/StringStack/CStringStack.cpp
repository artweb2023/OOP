#include "CStringStack.h"
#include <algorithm>
#include <stdexcept>

CStringStack::CStringStack(const CStringStack& other)
	: m_data(nullptr)
	, m_capacity(other.m_capacity)
	, m_size(other.m_size)
{
	if (other.m_capacity > 0)
	{
		m_data = new std::string[other.m_capacity];
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

CStringStack::CStringStack(CStringStack&& other) noexcept
	: m_data(other.m_data)
	, m_size(other.m_size)
	, m_capacity(other.m_capacity)
{
	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

CStringStack::~CStringStack() noexcept
{
	delete[] m_data;
}

CStringStack& CStringStack::operator=(const CStringStack& other)
{
	if (this != &other)
	{
		CStringStack temp(other);
		std::swap(m_data, temp.m_data);
		std::swap(m_size, temp.m_size);
		std::swap(m_capacity, temp.m_capacity);
	}
	return *this;
}

// лучше сделать через конструктор перемещения
CStringStack& CStringStack::operator=(CStringStack&& other) noexcept
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

void CStringStack::Push(const std::string& str)
{
	if (m_size == m_capacity)
	{
		Resize(m_capacity == 0 ? 1 : m_capacity * 2);
	}
	m_data[m_size++] = str;
}


void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::out_of_range("Stack is empty");
	}
	--m_size;
}

const std::string& CStringStack::Top() const
{
	if (IsEmpty())
	{
		throw std::out_of_range("Stack is empty");
	}
	return m_data[m_size - 1];
}

bool CStringStack::IsEmpty() const
{
	return m_size == 0;
}

size_t CStringStack::GetSize() const
{
	return m_size;
}

void CStringStack::Resize(size_t newCapacity)
{
	if (newCapacity == 0)
	{
		newCapacity = 1;
	}
	std::string* newData = new std::string[newCapacity];
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
