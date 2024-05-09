#include "CPoint.h"


std::string CPoint::ToString() const
{
	std::ostringstream oss;
	oss << "(" << std::fixed << std::setprecision(2) << m_x << ", " << m_y << ")";
	return oss.str();
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}