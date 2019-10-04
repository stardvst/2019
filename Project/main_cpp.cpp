#include <iostream>
#include <limits>
#include <vector>

namespace MyLib
{

	template <typename T>
	class MyAlloc
	{
	public:
		using value_type = T;
		using pointer = T *;
		using const_pointer = const T *;
		using reference = T &;
		using const_reference = const T &;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;

		MyAlloc() noexcept = default;
		MyAlloc(const MyAlloc &) noexcept = default;

		template <typename U>
		MyAlloc(const MyAlloc<U> &) noexcept {};

		~MyAlloc() = default;

		template <typename U>
		struct rebind
		{
			using other = MyAlloc<U>;
		};

		static pointer address(reference value)
		{
			return &value;
		}

		static const_pointer address(const_reference value)
		{
			return &value;
		}

		pointer allocate(size_type num, const void *= nullptr)
		{
			std::cerr <<
				"allocate " << num << " element(s) of size " << sizeof(T) << '\n';

			auto ret = static_cast<pointer>(::operator new(num * sizeof(T)));
			std::cerr << "allocated at " << static_cast<void *>(ret) << '\n';
			return ret;
		}

		static void construct(pointer p, const T &value)
		{
			std::cerr << "constructing " << value << "...\n";
			new(static_cast<void *>(p)) T(value);
		}

		static void deallocate(pointer p, size_type num)
		{
			std::cerr <<
				"deallocate " << num << " element(s) of size " << sizeof(T)
				<< " at " << static_cast<void *>(p) << '\n';

			::operator delete(static_cast<void *>(p));
		}

		static void destroy(pointer p)
		{
			std::cerr << "destroying " << *p << "...\n";
			p->~T();
		}

		[[nodiscard]] static size_type max_size() noexcept
		{
			return std::numeric_limits<std::size_t>::max() / sizeof(T);
		}
	};

	template <typename T1, typename T2>
	bool operator==(const MyAlloc<T1> &t1, const MyAlloc<T2> &t2) noexcept
	{
		return true;
	}

	template <typename T1, typename T2>
	bool operator!=(const MyAlloc<T1> &t1, const MyAlloc<T2> &t2) noexcept
	{
		return false;
	}

}

int main() noexcept
{
	std::vector<int, MyLib::MyAlloc<int>> vec;

	std::cout << "insert 42:\n";
	vec.push_back(42);

	std::cout << "\ninsert 56:\n";
	vec.push_back(56);

	std::cout << "\ninsert 11:\n";
	vec.push_back(11);

	std::cout << "\ninsert 22:\n";
	vec.push_back(22);

	std::cout << "\ninsert 33:\n";
	vec.push_back(33);

	std::cout << "\ninsert 44:\n";
	vec.push_back(44);

	std::cin.get();
	return 0;
}