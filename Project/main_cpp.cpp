#include <iostream>
#include <functional>
#include <memory>

struct abc
{
};

// can't delete an incomplete type
//std::unique_ptr<abc> f(std::unique_ptr<abc> p)
//{
//	if (!p) throw int{};
//	return p;
//}

// deleter is type-erased
std::shared_ptr<abc> f(std::shared_ptr<abc> p)
{
	if (!p) throw int{};
	return p;
}

template <typename T>
struct ErasedDeleter : std::function<void(T *)>
{
	ErasedDeleter()
		: std::function<void(T *)>
	{
		[](T *p)
		{
			delete p;
		}
	}
	{
	}
};

template <typename T>
using ErasedPtr = std::unique_ptr<T, ErasedDeleter<T>>;

int main()
{
	ErasedPtr<abc> p{ new abc };

	std::cin.get();
}