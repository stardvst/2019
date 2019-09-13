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

class V6Engine : public IEngine
{
public:
	void start() override { std::cout << "V6Engine::start\n"; }
	void stop() override { std::cout << "V6Engine::stop\n"; }
};

std::unique_ptr<IEngine> makeV8Engine()
{
	return std::make_unique<V8Engine>();
}

struct ICar
{
	virtual void drive() = 0;
	virtual ~ICar() = default;
};

std::unique_ptr<ICar> makeV8Car();
std::unique_ptr<ICar> makeV6Car();

template <typename TEngine>
class Car : public ICar
{
public:
	void drive() override
	{
		m_engine.start();
		std::cout << "driving...\n";
		m_engine.stop();
	}

private:
	TEngine m_engine;
};

std::unique_ptr<ICar> makeV8Car()
{
	return std::make_unique<Car<V8Engine>>();
}

std::unique_ptr<ICar> makeV6Car()
{
	return std::make_unique<Car<V6Engine>>();
}

class MockEngine : public IEngine
{
public:
	void start() override { std::cout << "MockEngine::start\n";	}
	void stop() override { std::cout << "MockEngine::stop\n"; }
};

int main()
{
	auto v8Car = makeV8Car();
	v8Car->drive();

	auto v6Car = makeV6Car();
	v6Car->drive();

	std::cin.get();
	return 0;
}
