#pragma once

#include <array>
#include <optional>
// +передачу можно включать если двигатель включен
// +скорость должна иметь абсолютное значение при движении назад
// +при движении задом на нейтрале не работает замедление
// +методы автомобиля не меняющие его состояния должны быть константные
constexpr int maxSpeed = 150;
constexpr int minSpeed = 0;

struct SpeedRange
{
	int min;
	int max;
};

class Car
{
public:
	enum class Gear
	{
		Reverse,
		Neutral,
		First,
		Second,
		Third,
		Fourth,
		Fifth,
	};
	enum class Direction
	{
		Forward,
		Back,
		Stay,
	};
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(const Gear gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	Gear GetGear() const;
	std::optional<SpeedRange> IsInRange(Gear gear) const;
private:
	using GearRanges = std::array<std::pair<Gear, SpeedRange>, 7>;
	const static inline GearRanges m_gearRanges
	{
		{
			{Gear::Reverse, {0, 20}},
			{Gear::Neutral, {0, 150}},
			{Gear::First, {0, 30}},
			{Gear::Second, {20, 50}},
			{Gear::Third, {30, 60}},
			{Gear::Fourth, {40, 90}},
			{Gear::Fifth, {50, 150}}
		}
	};
	int m_speed = 0;
	Gear m_gear = Gear::Neutral;
	// переименновать 
	bool m_isTurnOnEngine = false;
};