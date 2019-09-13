#include <iostream>

struct IEngine
{
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual ~IEngine() = default;
};

std::unique_ptr<IEngine> makeV8Engine();

class V8Engine : public IEngine
{
public:
	void start() override { std::cout << "V8Engine::start\n"; }
	void stop() override { std::cout << "V8Engine::stop\n"; }
};

std::unique_ptr<IEngine> makeV8Engine()
{
	return std::make_unique<V8Engine>();
}

template <typename TEngine>
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
	TEngine m_engine;
};

class MockEngine : public IEngine
{
public:
	void start() override { std::cout << "MockEngine::start\n";	}
	void stop() override { std::cout << "MockEngine::stop\n"; }
};

int main()
{
	Car<V8Engine> car;
	car.drive();

	std::cin.get();
	return 0;
}
