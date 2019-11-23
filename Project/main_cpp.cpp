#include <iostream>

template <typename...>
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

template <size_t, typename...>
struct elem_type;

template <typename T, typename... Ts>
struct elem_type<0, T, Ts...>
{
	using type = T;
};

template <size_t N, typename T, typename... Ts>
struct elem_type<N, T, Ts...>
{
	using type = typename elem_type<N - 1, Ts...>::type;
};

template <size_t N, typename... Ts>
typename std::enable_if_t<N == 0, typename elem_type<0, Ts...>::type> &get(tuple<Ts...> &t)
{
	return t.data;
}

template <size_t N, typename T, typename... Ts>
typename std::enable_if_t<N != 0, typename elem_type<N, T, Ts...>::type> &get(tuple<T, Ts...> &t)
{
	tuple<Ts...> &base = t;
	return get<N - 1>(base);
}

//////////////////////////////////////////////////////////////////////////

//template <class ElemType, typename T, typename... Ts>
//typename std::enable_if_t<std::is_same_v<ElemType, T>, ElemType> &get(tuple<T, Ts...> &t)
//{
//	static_assert(!(std::is_same_v<T, Ts> || ...), "duplicate type T in get<T>(tuple)"); // c++17
//	return t.data;
//}
//
//template <class ElemType, typename T, typename... Ts>
//typename std::enable_if_t<!std::is_same_v<ElemType, T>, ElemType> &get(tuple<T, Ts...> &t)
//{
//	tuple<Ts...> &base = t;
//	return get<ElemType>(base);
//}

template <class ElemType>
void get(tuple<> &t)
{
}

template <class ElemType, typename T, typename... Ts, std::enable_if_t<std::is_same_v<T, ElemType>, int> = 0>
ElemType &get(tuple<T, Ts...> &t)
{
	tuple<Ts...> &base = t;
	static_assert(std::is_void_v<decltype(get<ElemType>(base))>);
	return t.data;
}

template <class ElemType, typename T, typename... Ts, std::enable_if_t<!std::is_same_v<T, ElemType>, int> = 0>
decltype(auto) get(tuple<T, Ts...> &t)
{
	tuple<Ts...> &base = t;
	return get<ElemType>(base);
}

int main()
{
	tuple<double, int, char> t1(12.2, 42, 'a');

	std::cout << "0th element is " << get<0>(t1) << '\n';
	std::cout << "1st element is " << get<1>(t1) << '\n';
	std::cout << "2nd element is " << get<2>(t1) << '\n';

	get<1>(t1) = 103;
	std::cout << "1st element is " << get<1>(t1) << '\n';

	std::cout << "\ndouble element is " << get<double>(t1) << '\n';
	std::cout << "int element is " << get<int>(t1) << '\n';
	std::cout << "char element is " << get<char>(t1) << '\n';

	tuple<double, int, char, double, int> t2(12.2, 42, 'a', 3.3, 4);
	std::cout << "double element of new tuple is " << get<double>(t2) << '\n';
	std::cout << "int element of new tuple is " << get<int>(t2) << '\n';

	std::cin.get();
}
