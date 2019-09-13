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

struct ICar
{
	virtual void drive() = 0;
	virtual ~ICar() = default;
};

std::unique_ptr<ICar> makeCar(std::unique_ptr<IEngine> &&engine);

class Car : public ICar
{
public:
	Car(std::unique_ptr<IEngine> &&engine)
		: m_engine(std::move(engine))
	{
	}

	void drive()
	{
		m_engine->start();
		std::cout << "driving...\n";
		m_engine->stop();
	}

private:
	std::unique_ptr<IEngine> m_engine;
};

std::unique_ptr<ICar> makeCar(std::unique_ptr<IEngine> &&engine)
{
	return std::make_unique<Car>(std::move(engine));
}

class MockEngine : public IEngine
{
public:
	void start() override { std::cout << "MockEngine::start\n";	}
	void stop() override { std::cout << "MockEngine::stop\n"; }
};

int main()
{
	auto car = makeCar(std::make_unique<MockEngine>());
	car->drive();

	std::cin.get();
	return 0;
}
