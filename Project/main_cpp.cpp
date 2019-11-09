#include <iostream>

template <typename... Ts>
struct tuple
{
};

template <typename T, typename... Ts>
struct tuple<T, Ts...> : tuple<Ts...>
{
	T data;

	tuple(T v, Ts... args)
		: tuple<Ts...>(args...)
		, data(v)
	{
	}
};

template <size_t, typename>
struct elem_type;

template <typename T, typename... Ts>
struct elem_type<0, tuple<T, Ts...>>
{
	using type = T;
};

template <size_t N, typename T, typename... Ts>
struct elem_type<N, tuple<T, Ts...>>
{
	using type = typename elem_type<N - 1, tuple<Ts...>>::type;
};

template <size_t N, typename... Ts>
typename std::enable_if<N == 0, typename elem_type<0, tuple<Ts...>>::type &>::type get(tuple<Ts...> &t)
{
	return t.data;
}

template <size_t N, typename T, typename... Ts>
typename std::enable_if<N != 0, typename elem_type<N, tuple<T, Ts...>>::type &>::type get(tuple<T, Ts...> &t)
{
	tuple<Ts...> &base = t;
	return get<N - 1>(base);
}

int main()
{
	tuple<double, uint64_t, const char *> t1(12.2, 42, "big");

	std::cout << "0th element is " << get<0>(t1) << '\n';
	std::cout << "1st element is " << get<1>(t1) << '\n';
	std::cout << "2nd element is " << get<2>(t1) << '\n';

	get<1>(t1) = 103;
	std::cout << "1st element is " << get<1>(t1) << '\n';

	std::cin.get();
}
