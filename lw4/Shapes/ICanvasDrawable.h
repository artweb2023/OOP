#pragma once

#include "ICanvas.h"

class ICanvasDrawable
{
public:
	// вы€снить дл€ чего нужен виртуальный диструктор
	virtual ~ICanvasDrawable() = default;
	virtual void Draw(ICanvas& canvas) const = 0;
};