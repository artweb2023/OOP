#include "ClassCar.h"

bool Car::TurnOnEngine()
{
	return m_isTurnOnEngine = true;
}

bool Car::TurnOffEngine()
{
	if (m_speed == 0 && m_gear == Gear::Neutral)
	{
		m_isTurnOnEngine = false;
		return true;
	}
	return false;
}

bool Car::SetGear(const Gear gear)
{
	// упростить метод
	if (!m_isTurnOnEngine)
	{
		return false;
	}
	if (gear == Gear::Neutral)
	{
		m_gear = gear;
		return true;
	}
	if (GetDirection() == Direction::Back && gear != Gear::Reverse)
	{
		return false;
	}
	auto it = std::find_if(m_gearRanges.begin(), m_gearRanges.end(),
		[gear](const auto& pair) { return pair.first == gear; });
	if (it == m_gearRanges.end())
	{
		return false;
	}
	auto [min, max] = it->second;
	if (gear == Gear::Reverse)
	{
		if (m_speed == 0)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}
	else
	{
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}

	return false;
}

// метод должен принимать абсолютное значе
bool Car::SetSpeed(const int speed)
{
	if (!m_isTurnOnEngine)
	{
		return false;
	}
	if (m_gear == Gear::Neutral && speed != minSpeed)
	{
		if (m_speed > speed && speed > minSpeed)
		{
			m_speed = speed;
			return true;
		}
		return false;
	}
	// сделать метод который бы возвращал опционал
	auto it = std::find_if(m_gearRanges.begin(), m_gearRanges.end(),
		[this](const auto& pair) { return pair.first == m_gear; });
	if (it == m_gearRanges.end())
	{
		return false;
	}
	auto [min, max] = it->second;
	if (speed >= min && speed <= max)
	{
		if (m_gear == Car::Gear::Reverse)
		{
			m_speed = -speed;
			return true;
		}
		m_speed = speed;
		return true;
	}
	return false;
}

bool Car::IsTurnedOn() const
{
	return m_isTurnOnEngine;
}

Car::Direction Car::GetDirection() const
{
	if (m_speed < 0)
	{
		return Car::Direction::Back;
	}
	else if (m_speed > 0)
	{
		return Car::Direction::Forward;
	}
	return Car::Direction::Stay;
}

int Car::GetSpeed() const
{
	return std::abs(m_speed);
}

Car::Gear Car::GetGear() const
{
	return m_gear;
}