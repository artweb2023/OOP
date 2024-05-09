#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw3/1.2/Car/ClassCar.h"
#include <iostream>

//Перекомпоновать тесты , не нужно дублировать проверки

SCENARIO("test engine")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is off")
		{
			THEN("check engine")
			{
				REQUIRE(!car.IsTurnedOn());
			}
		}
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			THEN("check engine")
			{
				REQUIRE(car.IsTurnedOn());
			}
		}
	}
}

// разбить на несколько WHEN
SCENARIO("test neutral gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			THEN("try set speed on neutral gear")
			{
				CHECK(car.SetSpeed(150) == false);
				AND_THEN("the speed is above zero")
				{
					car.SetGear(Car::Gear::First);
					car.SetSpeed(30);
					AND_THEN("try decrease speed on first gear")
					{
						car.SetSpeed(20);
						REQUIRE(car.GetSpeed() == 20);
					}
				}
			}
			THEN("set reverse gear")
			{
				car.SetGear(Car::Gear::Reverse);
				THEN("set speed is 20")
				{
					car.SetSpeed(20);
					CHECK(car.GetDirection() == Car::Direction::Back);
					AND_THEN("set neutral gear")
					{
						CHECK(car.SetGear(Car::Gear::Neutral));
						AND_THEN("reduce speed")
						{
							car.SetSpeed(19);
							REQUIRE(car.GetSpeed() == 19);
						}
					}
				}
			}
		}
	}
}

SCENARIO("test first gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			WHEN("first gear is selected")
			{
				car.SetGear(Car::Gear::First);
				CHECK(car.GetGear() == Car::Gear::First);
				THEN("set speed 40")
				{
					REQUIRE(!car.SetSpeed(40));
					REQUIRE(car.GetSpeed() == 0);
				}
				THEN("set max speed")
				{
					REQUIRE(car.SetSpeed(30));
					REQUIRE(car.GetSpeed() == 30);
				}
				THEN("set speed 15")
				{
					CHECK(car.SetSpeed(15));
					CHECK(car.GetSpeed() == 15);
					AND_THEN("try set second gear")
					{
						car.SetGear(Car::Gear::Second);
						REQUIRE(car.GetGear() == Car::Gear::First);
					}
				}
			}
		}
	}
}

SCENARIO("test second gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			WHEN("second gear is selected")
			{
				car.SetGear(Car::Gear::First);
				car.SetSpeed(30);
				car.SetGear(Car::Gear::Second);
				CHECK(car.GetGear() == Car::Gear::Second);
				CHECK(car.GetSpeed() == 30);
				THEN("set first gear")
				{
					REQUIRE(car.SetGear(Car::Gear::First));
					REQUIRE(car.GetGear() == Car::Gear::First);
				}

				THEN("set third gear")
				{
					REQUIRE(car.SetGear(Car::Gear::Third));
					REQUIRE(car.GetGear() == Car::Gear::Third);
				}

				THEN("try set speed 15")
				{
					REQUIRE(!car.SetSpeed(15));
					REQUIRE(car.GetSpeed() == 30);
				}

				THEN("try set speed 51")
				{
					REQUIRE(!car.SetSpeed(51));
					REQUIRE(car.GetSpeed() == 30);
				}

				THEN("try set speed 40")
				{
					REQUIRE(car.SetSpeed(50));
					REQUIRE(car.GetSpeed() == 50);

					AND_THEN("set third gear")
					{
						REQUIRE(car.SetGear(Car::Gear::Third));
						REQUIRE(car.GetGear() == Car::Gear::Third);
					}
				}
			}
		}
	}
}

SCENARIO("test third gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			WHEN("third gear is selected")
			{
				car.SetGear(Car::Gear::First);
				car.SetSpeed(30);
				car.SetGear(Car::Gear::Second);
				CHECK(car.GetGear() == Car::Gear::Second);
				CHECK(car.GetSpeed() == 30);
				car.SetSpeed(50);
				car.SetGear(Car::Gear::Third);
				THEN("set first gear")
				{
					REQUIRE(car.SetGear(Car::Gear::First) == false);
					REQUIRE(car.GetGear() == Car::Gear::Third);
				}
				THEN("set second gear")
				{
					REQUIRE(car.SetGear(Car::Gear::Second));
					REQUIRE(car.GetGear() == Car::Gear::Second);
				}
				THEN("try set speed 29")
				{
					REQUIRE(!car.SetSpeed(29));
					REQUIRE(car.GetSpeed() == 50);
				}
				THEN("try set speed 61")
				{
					REQUIRE(!car.SetSpeed(61));
					REQUIRE(car.GetSpeed() == 50);
				}
				THEN("try set speed 60")
				{
					REQUIRE(car.SetSpeed(60));
					REQUIRE(car.GetSpeed() == 60);
					AND_THEN("set fourth gear")
					{
						REQUIRE(car.SetGear(Car::Gear::Fourth));
						REQUIRE(car.GetGear() == Car::Gear::Fourth);
					}
				}
			}
		}
	}
}

SCENARIO("test fourth gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			WHEN("fourth gear is selected")
			{
				car.SetGear(Car::Gear::First);
				car.SetSpeed(30);
				car.SetGear(Car::Gear::Second);
				car.SetSpeed(40);
				car.SetGear(Car::Gear::Fourth);
				CHECK(car.GetGear() == Car::Gear::Fourth);
				CHECK(car.GetSpeed() == 40);
				car.SetSpeed(80);
				THEN("set second gear")
				{
					REQUIRE(!car.SetGear(Car::Gear::Second));
					REQUIRE(car.GetGear() == Car::Gear::Fourth);
				}
				THEN("try set speed 39")
				{
					REQUIRE(!car.SetSpeed(39));
					REQUIRE(car.GetSpeed() == 80);
				}
				THEN("try set speed 91")
				{
					REQUIRE(!car.SetSpeed(91));
					REQUIRE(car.GetSpeed() == 80);
				}
				THEN("try set speed 90")
				{
					REQUIRE(car.SetSpeed(90));
					REQUIRE(car.GetSpeed() == 90);
					AND_THEN("set fifth gear")
					{
						REQUIRE(car.SetGear(Car::Gear::Fifth));
						REQUIRE(car.GetGear() == Car::Gear::Fifth);
						AND_THEN("set neutral gear")
						{
							REQUIRE(car.SetGear(Car::Gear::Neutral));
							REQUIRE(car.GetGear() == Car::Gear::Neutral);
							AND_THEN("increase speed")
							{
								REQUIRE(!car.SetSpeed(91));
							}
							AND_THEN("decrease speed")
							{
								REQUIRE(car.SetSpeed(80));
								REQUIRE(car.SetSpeed(0));
							}
						}
					}
				}
			}
		}
	}
}

SCENARIO("test fifth gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			WHEN("fifth gear is selected")
			{
				car.SetGear(Car::Gear::First);
				car.SetSpeed(30);
				car.SetGear(Car::Gear::Second);
				car.SetSpeed(50);
				car.SetGear(Car::Gear::Fifth);
				CHECK(car.GetGear() == Car::Gear::Fifth);
				CHECK(car.GetSpeed() == 50);
				car.SetSpeed(100);
				THEN("set fourth gear")
				{
					REQUIRE(!car.SetGear(Car::Gear::Fourth));
					REQUIRE(car.GetGear() == Car::Gear::Fifth);
				}
				THEN("try set speed 49")
				{
					REQUIRE(!car.SetSpeed(49));
					REQUIRE(car.GetSpeed() == 100);
				}
				THEN("try set speed 151")
				{
					REQUIRE(!car.SetSpeed(151));
					REQUIRE(car.GetSpeed() == 100);
				}
				THEN("try set speed 150")
				{
					REQUIRE(car.SetSpeed(150));
					REQUIRE(car.GetSpeed() == 150);
					AND_THEN("set neutral gear")
					{
						REQUIRE(car.SetGear(Car::Gear::Neutral));
						REQUIRE(car.GetGear() == Car::Gear::Neutral);
						AND_THEN("decrease speed")
						{
							REQUIRE(car.SetSpeed(140));
							REQUIRE(car.SetSpeed(0));
						}
					}
				}
			}
		}
	}
}

SCENARIO("test reverse gear")
{
	GIVEN("Create car")
	{
		Car car;
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			WHEN("first gear is selected")
			{
				car.SetGear(Car::Gear::First);
				WHEN("the speed is 30")
				{
					car.SetSpeed(30);
					THEN("try set reverse gear")
					{
						REQUIRE(!car.SetGear(Car::Gear::Reverse));
					}
				}
				WHEN("the speed is zero")
				{
					THEN("try set reverse gear")
					{
						REQUIRE(car.SetGear(Car::Gear::Reverse));
					}
				}
				WHEN("the speed is 20")
				{
					car.SetSpeed(20);
					THEN("try set reverse gear")
					{
						REQUIRE(!car.SetGear(Car::Gear::Reverse));
					}
				}
			}
		}
	}
}

SCENARIO("test direction")
{
	GIVEN("Create car")
	{
		Car car;
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetDirection() == Car::Direction::Stay);
		CHECK(car.GetGear() == Car::Gear::Neutral);
		WHEN("engine is on")
		{
			car.TurnOnEngine();
			THEN("check direction")
			{
				REQUIRE(car.GetDirection() == Car::Direction::Stay);
			}
			WHEN("reverse gear is selected")
			{
				car.SetGear(Car::Gear::Reverse);
				THEN("check direction")
				{
					REQUIRE(car.GetDirection() == Car::Direction::Stay);
					WHEN("set speed one")
					{
						car.SetSpeed(1);
						THEN("check direction")
						{
							REQUIRE(car.GetDirection() == Car::Direction::Back);
						}
					}
				}
			}
			WHEN("forward gear is selected")
			{
				car.SetGear(Car::Gear::First);
				THEN("check direction")
				{
					CHECK(car.GetDirection() == Car::Direction::Stay);
					WHEN("set speed 1")
					{
						car.SetSpeed(1);
						THEN("check direction")
						{
							REQUIRE(car.GetDirection() == Car::Direction::Forward);
						}
					}
				}
			}
		}
	}
}