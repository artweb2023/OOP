#pragma once

#include "CCanvas.h"
#include "ICanvas.h"
#include "IShape.h"
#include "ShapeCreator.h"
#include "stdafx.h"


struct LineArgs
{
	double startX;
	double startY;
	double endX;
	double endY;
	uint32_t color;
};

struct RectArgs
{
	double leftTopX;
	double leftTopY;
	double rightBottomX;
	double rightBottomY;
	uint32_t outlineColor;
	uint32_t fillColor;
};

struct TriangleArgs
{
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	uint32_t outlineColor;
	uint32_t fillColor;
};

struct CircleArgs
{
	double originX;
	double originY;
	double radius;
	uint32_t outlineColor;
	uint32_t fillColor;
};

class ShapesApp
{
public:
	ShapesApp(CCanvas& canvas, ShapeCreator& shapeCreator, std::istream& input, std::ostream& output);
	void HandleCommand();
	void CreateLine(const std::string& args);
	void CreateRectangle(const std::string& args);
	void CreateTriangle(const std::string& args);
	void CreateCircle(const std::string& args);
	void PrintInfo() const;
	void PrintShapesInfo() const;
	std::string GetMaxAreaShapeInfo() const;
	std::string GetMinPerimeterShapeInfo() const;
	const std::vector<std::unique_ptr<IShape>>& GetShapes() const;
	uint32_t ParseColorFromStream(std::istream& stream);
	LineArgs ParseLineArgs(const std::string& string);
	RectArgs ParseRectangleArgs(const std::string& string);
	TriangleArgs ParseTriangleArgs(const std::string& string);
	CircleArgs ParseCircleArgs(const std::string& string);
	void Draw() const;
	void ClearShapes();

private:
	using Handler = std::function<void(std::string& args)>;
	using ActionMap = std::map<std::string, Handler>;
	std::istream& m_input;
	std::ostream& m_output;
	ShapeCreator& m_shapeCreator;
	const ActionMap m_actionMap;
	CCanvas& m_canvas;
};