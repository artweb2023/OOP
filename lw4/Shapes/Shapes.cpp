#include "CCanvas.h"
#include "ShapeCreator.h"
#include "ShapesApp.h"
#include "stdafx.h"

int main()
{
	ShapeCreator shapeCreator;
	CCanvas canvas;
	ShapesApp shapesApp(canvas, shapeCreator, std::cin, std::cout);
	while (!std::cin.eof() && !std::cin.fail())
	{
		try
		{
			shapesApp.HandleCommand();
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Error parsing input: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	shapesApp.PrintShapesInfo();
	shapesApp.PrintInfo();
	shapesApp.Draw();
	shapesApp.ClearShapes();
	return 0;
}

