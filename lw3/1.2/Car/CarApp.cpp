#include "CarApp.h"


CarApp::CarApp(Car& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap(
		{
		  { "Info", [this](const int arg) { return Info(arg); } },
		  { "EngineOn", [this](const int arg) { return EngineOn(arg); } },
		  { "EngineOff", [this](const int arg) { return EngineOff(arg); } },
		  { "SetGear", [this](const int arg) { return SetGear(arg); } },
		  { "SetSpeed", [this](const int arg) { return SetSpeed(arg); } }
		}
	)
{
}

bool CarApp::HandleCommand()
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream isstream(commandLine);
	std::string action;
	isstream >> action;
	int arg = isstream >> arg ? arg : 0;
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(arg);
	}
	return false;
}

bool CarApp::EngineOn(const int /*arg*/)
{
	if (m_car.TurnOnEngine())
	{
		m_output << "Engine turn on was successful" << std::endl;
		return true;
	}
	m_output << "Engine turn on was falled" << std::endl;
	return false;
}

bool CarApp::EngineOff(const int /*arg*/)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine turn off was successful" << std::endl;
		return true;
	}
	m_output << "Engine turn off was falled" << std::endl;
	return false;
}

bool CarApp::Info(const int /*arg*/)
{
	m_output << " State Engine is: " << (m_car.IsTurnedOn() ? "on" : "off") << std::endl;
	m_output << " Speed is: " << m_car.GetSpeed() << std::endl;
	m_output << " Gear is: " << ConvertGearToInt(m_car.GetGear()) << std::endl;
	m_output << " Direction is: " << ConvertDirectionToString(m_car.GetDirection()) << std::endl;
	return true;
}

int CarApp::ConvertGearToInt(const Car::Gear& gear)
{
	switch (gear)
	{
	case Car::Gear::Reverse: return -1;
	case Car::Gear::Neutral: return 0;
	case Car::Gear::First:   return 1;
	case Car::Gear::Second:  return 2;
	case Car::Gear::Third:   return 3;
	case Car::Gear::Fourth:  return 4;
	case Car::Gear::Fifth:   return 5;
	}
}

Car::Gear CarApp::ConvertIntToGear(const int gear)
{
	switch (gear)
	{
	case -1: return Car::Gear::Reverse;
	case 0:  return Car::Gear::Neutral;
	case 1:  return Car::Gear::First;
	case 2:  return Car::Gear::Second;
	case 3:  return Car::Gear::Third;
	case 4:  return Car::Gear::Fourth;
	case 5:  return Car::Gear::Fifth;
	}
}

std::string CarApp::ConvertDirectionToString(const Car::Direction& d)
{
	switch (d)
	{
	case Car::Direction::Forward: return "forward";
	case Car::Direction::Back:    return "backward";
	case Car::Direction::Stay:    return "standing still";
	}
}

bool CarApp::SetGear(const int arg)
{
	const Car::Gear gear = ConvertIntToGear(arg);
	if (m_car.SetGear(gear))
	{
		m_output << "Current gear is " << arg << std::endl;
		return true;
	}
	m_output << "Set gear was falled!" << std::endl;
	return true;
}

bool CarApp::SetSpeed(const int arg)
{
	if (m_car.SetSpeed(arg))
	{
		m_output << "Current speed is " << arg << std::endl;
		return true;
	}
	m_output << "Set speed was falled!" << std::endl;
	return true;
}