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

std::optional<SpeedRange> Car::IsInRange(Gear gear) const
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
	if (!m_isTurnOnEngine || (GetDirection() == Direction::Back && gear != Gear::Reverse))
	{
		return false;
	}
	if (gear == Gear::Neutral)
	{
		m_gear = gear;
		return true;
	}
	if (gear == Gear::Reverse && m_speed != 0)
	{
		return false;
	}
	if (auto range = IsInRange(gear))
	{
		auto [min, max] = range.value();
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
	}
	return false;
}

// метод должен принимать абсолютное значе
bool Car::SetSpeed(int speed)
{
	speed = std::abs(speed);
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
	if (auto range = IsInRange(m_gear))
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