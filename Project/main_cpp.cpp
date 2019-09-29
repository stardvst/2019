#include <iostream>

struct FunctionBase
{
	virtual void operator()() = 0;
	virtual ~FunctionBase() = default;
};

template <typename TFunc>
struct FunctionImpl : FunctionBase
{
	TFunc functor;

	FunctionImpl(TFunc f) : functor(f) {}

	void operator()() override
	{
		functor();
	}
};

struct VoidFunctionCaller
{
	std::shared_ptr<FunctionBase> functor;

	template <typename TFunc>
	VoidFunctionCaller(TFunc f)
		: functor(std::shared_ptr<FunctionBase>(new FunctionImpl(f)))
	{
	}

	void operator()()
	{
		(*functor)();
	}
};

void callFunction(VoidFunctionCaller f)
{
	f();
}

int main()
{
	auto f = []() { std::cout << "from lambda\n"; };
	callFunction(f);

	std::cin.get();
}
