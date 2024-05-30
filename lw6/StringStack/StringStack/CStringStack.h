#pragma once
#include <string>

class CStringStack
{
public:
	CStringStack() = default;
	~CStringStack() noexcept;
	CStringStack(const CStringStack& other);
	CStringStack(CStringStack&& other) noexcept;
	CStringStack& operator=(const CStringStack& other);
	CStringStack& operator=(CStringStack&& other) noexcept;
	void Push(const std::string& str);
	void Pop();
	const std::string& Top() const;
	bool IsEmpty() const;
	size_t GetSize() const;
private:
	void Resize(size_t newCapacity);
	std::string* m_data = nullptr;
	size_t m_capacity = 0;
	size_t m_size = 0;
};