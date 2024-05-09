#pragma once

#include "ICanvasDrawable.h"
#include "stdafx.h"

class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
	virtual std::string ToString() const = 0;
	virtual Draw() const = 0;
};