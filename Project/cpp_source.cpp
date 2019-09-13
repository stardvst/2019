#include <iostream>

class V8Engine
{
public:
	void start() { std::cout << "V8Engine::start\n"; }
	void stop() { std::cout << "V8Engine::stop\n"; }
};

class Car
{
public:
	void drive()
	{
		m_engine.start();
		std::cout << "driving...\n";
		m_engine.stop();
	}

private:
	V8Engine m_engine;
};

int main()
{
	Car car;
	car.drive();

	std::cin.get();
	return 0;
}
