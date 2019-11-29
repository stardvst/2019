#include <iostream>

template <typename... T>
struct Structure
{
};

template <typename T, typename... Rest>
struct Structure<T, Rest...>
{
	Structure(const T &f, const Rest &... r)
		: first(f)
		, rest(r...)
	{
	}

	template <size_t idx>
	decltype(auto) get()
	{
		return GetHelper<idx, Structure<T, Rest...>>::get(*this);
	}

	T first;
	Structure<Rest...> rest;
};

template <size_t idx, typename T>
struct GetHelper
{
};

template <typename T, typename... Rest>
struct GetHelper<0, Structure<T, Rest...>>
{
	static T get(Structure<T, Rest...> &data)
	{
		return data.first;
	}
};

template <size_t idx, typename T, typename... Rest>
struct GetHelper<idx, Structure<T, Rest...>>
{
	static T get(Structure<T, Rest...> &data)
	{
		return GetHelper<idx - 1, Structure<Rest...>>::get(data.rest);
	}
};

int main()
{
	Structure<int, char, bool> s(5, 'a', false);
	std::cout << s.first << '\n';
	std::cout << s.rest.first << '\n';
	std::cout << s.rest.rest.first << '\n';

	std::cout << s.get<0>() << '\n';
	std::cout << s.get<1>() << '\n';
	std::cout << s.get<2>() << '\n';

	std::cin.get();
}
