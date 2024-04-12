#include "CCanvas .h"

CCanvas::CCanvas(unsigned width, unsigned height)
	: m_width(width), m_height(height), m_pixels(width* height, ' ')
{
}

unsigned CCanvas::GetWidth() const
{
	return m_width;
}

unsigned  CCanvas::GetHeight() const
{
	return m_height;
}

void CCanvas::Clear(char code)
{
	for (auto& pixel : m_pixels) {
		pixel = code;
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
	{
		m_pixels[y * m_width + x] = code;
	}
}

char CCanvas::GetPixel(int x, int y) const
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
	{
		return m_pixels[y * m_width + x];
	}
	return ' ';
}

void CCanvas::Write(std::ostream& ostream) const
{
	for (auto y = 0; y < m_height; ++y)
	{
		for (auto x = 0; x < m_width; ++x)
		{
			ostream << GetPixel(x, y);
		}
		ostream << '\n';
	}
}
