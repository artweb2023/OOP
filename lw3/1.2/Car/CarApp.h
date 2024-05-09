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
	// сделать метобы константные
	bool Info(const int arg) const;
	bool EngineOn(const int arg) const;
	bool EngineOff(const int arg) const;
	bool SetSpeed(const int arg) const;
	bool SetGear(const int arg) const;
	int ConvertGearToInt(const Car::Gear& gear) const;
	Car::Gear ConvertIntToGear(const int gear) const;
	std::string ConvertDirectionToString(const Car::Direction& d) const;
	using Handler = std::function<bool(int arg)>;
	using ActionMap = std::map<std::string, Handler>;
	const ActionMap m_actionMap;
	Car& m_car;
	std::istream& m_input;
	std::ostream& m_output;
};