#pragma once
#include "stdafx.h"

class CPoint
{
public:
	CPoint(const double x = 0, const double y = 0)
	{
		m_x = x;
		m_y = y;
	};
	double GetX() const;
	std::string ToString() const;
	double GetY() const;
private:
	double m_x;
	double m_y;
};
