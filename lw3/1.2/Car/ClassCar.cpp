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

const std::optional<SpeedRange> Car::FindSpeedRangeForGear(Gear gear)
{
	for (const auto& pair : m_gearRanges)
	{
		if (pair.first == gear)
		{
			return pair.second;
		}
	}
	return std::nullopt;
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
	if (auto range = FindSpeedRangeForGear(gear))
	{
		auto [min, max] = range.value();
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
	}
	return false;
}


// метод должен принимать абсолютное значе
bool Car::SetSpeed(int speed)
{
	if (speed < 0)
	{
		return false;
	}
	if (!m_isTurnOnEngine || (m_gear == Gear::Neutral && speed != minSpeed))
	{
		if (std::abs(m_speed) > speed && speed >= minSpeed)
		{
			m_speed = speed;
			return true;
		}
		return false;
	}
	// сделать метод который бы возвращал опционал
	if (auto range = FindSpeedRangeForGear(m_gear))
	{
		auto [min, max] = range.value();
		if (speed >= min && speed <= max)
		{
			m_speed = (m_gear == Car::Gear::Reverse) ? -speed : speed;
			return true;
		}
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