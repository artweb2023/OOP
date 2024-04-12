#include "CRectangle.h"

CRectangle::CRectangle(Point point, int width, int height)
{
	m_point = point;
	m_width = (width < 0) ? 0 : width;
	m_height = (height < 0) ? 0 : height;
}

Point CRectangle::GetLeftTop() const
{
	return m_point;
}

Point  CRectangle::GetRightBottom() const
{
	Point rightBottom;
	rightBottom.x = m_width + m_point.x;
	rightBottom.y = m_height + m_point.y;
	return rightBottom;

}

int CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

int CRectangle::GetArea() const
{
	return m_width * m_height;
}

int CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

Point CRectangle::SetLeftTop(const Point& point)
{
	return m_point = point;
}

int CRectangle::SetWidth(int width)
{
	return (width < 0) ? 0 : m_width = width;
}

int CRectangle::SetHeight(int height)
{
	return (height < 0) ? 0 : m_height = height;
}

void CRectangle::Move(int dx, int dy)
{
	m_point.x += dx;
	m_point.y += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx > 0 && sy > 0)
	{
		m_width *= sx;
		m_height *= sy;
	}
}

bool CRectangle::Intersect(const CRectangle& other)
{
	Point thisRightBottom = GetRightBottom();
	Point otherRightBottom = other.GetRightBottom();
	if ((m_point.x < otherRightBottom.x) && (thisRightBottom.x > other.m_point.x)
		&& (m_point.y < otherRightBottom.y) && (thisRightBottom.y > other.m_point.y))
	{
		int newWidth = std::min(m_point.x + m_width, otherRightBottom.x) -
			std::max(m_point.x, other.m_point.x);
		int newHeight = std::min(m_point.y + m_height, otherRightBottom.y) -
			std::max(m_point.y, other.m_point.y);
		m_width = newWidth;
		m_height = newHeight;
		return true;
	}
	else
	{
		m_width = 0;
		m_height = 0;
		return false;
	}
}