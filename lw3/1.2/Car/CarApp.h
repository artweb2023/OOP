#pragma once
#include "ClassCar.h"
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

class CarApp
{
public:
	CarApp(Car& car, std::istream& input, std::ostream& output);
	bool HandleCommand();
private:
	bool Info(const int arg);
	bool EngineOn(const int arg);
	bool EngineOff(const int arg);
	bool SetGear(const int arg);
	bool SetSpeed(const int arg);
	int ConvertGearToInt(const Car::Gear& gear);
	Car::Gear ConvertIntToGear(const int gear);
	std::string ConvertDirectionToString(const Car::Direction& d);
	using Handler = std::function<bool(int arg)>;
	using ActionMap = std::map<std::string, Handler>;
	const ActionMap m_actionMap;
	Car& m_car;
	std::istream& m_input;
	std::ostream& m_output;
};