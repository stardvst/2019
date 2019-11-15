#include <iostream>
#include <chrono>
#include <ctime>

//////////////////////////////////////////////////////////////////////////
// c++14 features
//////////////////////////////////////////////////////////////////////////

// return type deduction for functions
auto square(int n)
{
	return n * n;
}

//////////////////////////////////////////////////////////////////////////

// generic lambdas
auto lambda = [](auto a, auto b) { return a * b; };
//struct lambdaImpl
//{
//	template <typename A, typename B>
//	auto operator()(A a, B b) -> decltype(a *b)
//	{
//		return a * b;
//	}
//};
//auto lambda = lambdaImpl();

//////////////////////////////////////////////////////////////////////////

// extended capturing in lambdas
auto timer = [val = std::chrono::system_clock::now()]
{
	return std::chrono::system_clock::time_point(std::chrono::system_clock::now() - val);
};

//////////////////////////////////////////////////////////////////////////

int main()
{
	std::cout << square(5) << '\n';
	std::cout << lambda(3, 4) << '\n';

	auto tt = std::chrono::system_clock::to_time_t(timer());
	std::cout << std::ctime(&tt);

	auto p = std::make_unique<int>(10);
	auto lmb = [p = std::move(p)]{ return *p; }; // declares new data member p
	std::cout << lmb() << '\n';

	std::cin.get();
	return 0;
}