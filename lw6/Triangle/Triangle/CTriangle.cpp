#include "CTriangle.h"

namespace
{
	const double& AssureNotNegative(const double& value, const std::string& argName = std::string())
	{
		if (value >= 0)
		{
			return value;
		}
		throw std::invalid_argument(argName.empty() ? "Argument" : argName + " can not be negative.");
	}
}


CTriangle::CTriangle(double side1, double side2, double side3)
	: m_side1(AssureNotNegative(side1, "Side 1"))
	, m_side2(AssureNotNegative(side2, "Side 2"))
	, m_side3(AssureNotNegative(side3, "Side 3"))
{
	ValidateSideLength(side1, side2, side3, 1, 2, 3);
	ValidateSideLength(side2, side1, side3, 2, 1, 3);
	ValidateSideLength(side3, side1, side2, 3, 1, 2);
}

double CTriangle::GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}

double CTriangle::GetPerimeter()const
{
	return m_side1 + m_side2 + m_side3;
}

double CTriangle::GetArea()const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
}

void CTriangle::ValidateSideLength(
	double sideToCheck, double side1, double side2,
	int checkedSideIndex, int side1Index, int side2Index)
{
	if (sideToCheck > side1 + side2)
	{
		std::ostringstream msg;
		msg << "Side " << checkedSideIndex << " can not be greater than sum of side "
			<< side1Index << " and side " << side2Index;
		throw std::domain_error(msg.str());
	}
}