#pragma once

#include "IShape.h"
#include "stdafx.h"

class ISolidShape : public IShape
{
	virtual uint32_t GetFillColor() const = 0;
};