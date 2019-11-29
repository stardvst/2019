#include <iostream>

//////////////////////////////////////////////////////////////////////////
// Variadic template to make this happen:
// property<T1, T2, T3, T4>::type == boost::property<T1, T2, boost::property<T3, T4>>
//
template <typename Tag, typename Type, typename This>
struct PropertyBase
{
};

template <typename Tag, typename Type>
struct Property
{
	using type = Property<Tag, Type>;
};

template <typename Tag, typename Type, typename... Types>
struct Property
{
	using type = Property<Tag, Type, typename Property<Types...>::type>::type;
};

int main()
{
	std::cin.get();
}
