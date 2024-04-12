#pragma once

#include <algorithm>

struct Point
{
	int x;
	int y;
};

class CRectangle
{
public:
	CRectangle(Point point, int width, int height);
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetArea() const;
	int GetPerimeter() const;
	Point SetLeftTop(const Point& point);
	int SetWidth(int width);
	int SetHeight(int height);
	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);
private:
	Point m_point;
	int m_width, m_height;
};