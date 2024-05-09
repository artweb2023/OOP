#pragma once

#include "ICanvas.h"

class ICanvasDrawable
{
public:
	// вы€снить дл€ чего нужен виртуальный диструктор
	virtual ~ICanvasDrawable() {}
	virtual void Draw(ICanvas& canvas) const = 0;
};