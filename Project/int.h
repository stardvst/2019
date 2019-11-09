#ifndef INT_HPP
#define INT_HPP

#include <iostream>
#include <limits>


namespace Integer
{

	struct err
	{
		const char *msg;
		err(const char *e) : msg(e) {}
	};

	template<typename T> struct Type;
	template<> struct Type<int> { typedef int type; };
	template<> struct Type<char> { typedef char type; };
	template<> struct Type<long> { typedef long type; };
	template<> struct Type<bool> { typedef bool type; };
	template<> struct Type<short> { typedef short type; };
	template<> struct Type<wchar_t> { typedef wchar_t type; };
	template<> struct Type<signed char> { typedef signed char type; };
	template<> struct Type<unsigned int> { typedef unsigned int type; };
	template<> struct Type<unsigned char> { typedef unsigned char type; };
	template<> struct Type<unsigned long> { typedef unsigned long type; };
	template<> struct Type<unsigned short> { typedef unsigned short type; };


	template<typename T>
	class Int
	{
		template<typename C>
		friend std::istream &operator>>(std::istream &, Int<C> &);
	public:
		typedef typename Type<T>::type value_type;

		Int(value_type v = 0) : value(v)
		{
			if (v < std::numeric_limits<typename Type<T>::type>::min() || v > std::numeric_limits<typename Type<T>::type>::max())
			{
				value = 0;
				throw err("error: initial value out of range\n");
			}
		}

		Int<T> &operator=(value_type);

		Int<T> &operator+=(const Int<T> &);
		Int<T> &operator+=(value_type);
		Int<T> &operator-=(const Int<T> &);
		Int<T> &operator-=(value_type);
		Int<T> &operator*=(const Int<T> &);
		Int<T> &operator*=(value_type);
		Int<T> &operator/=(const Int<T> &);
		Int<T> &operator/=(value_type);

		Int<T> &operator++();
		Int<T> operator++(int);
		Int<T> &operator--();
		Int<T> operator--(int);

		value_type operator-() { return -value; }
		bool operator!() const { return !value; }
		value_type operator~() const;

		operator value_type() const { return value; }

		value_type get_value() const { return value; }
	private:
		value_type value;
	};


	template<typename T>
	Int<T> &Int<T>::operator=(typename Type<T>::type i)
	{
		if (i < std::numeric_limits<typename Type<T>::type>::min() || i > std::numeric_limits<typename Type<T>::type>::max())
		{
			throw err("error: assigned value out of range\n");
		}
		value = i;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator+=(const Int<T> &o)
	{
		if (value > 0 && o.get_value() > std::numeric_limits<typename Type<T>::type>::max() - value)
		{
			throw err("error: sum overflow\n");
		}
		else if (value < 0 && o.get_value() < std::numeric_limits<typename Type<T>::type>::min() - value)
		{
			throw err("error: sum underflow\n");
		}
		value += o.value;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator+=(typename Type<T>::type i)
	{
		if (value > 0 && i > std::numeric_limits<typename Type<T>::type>::max() - value)
		{
			throw err("error: sum overflow\n");
		}
		else if (value < 0 && i < std::numeric_limits<typename Type<T>::type>::min() - value)
		{
			throw err("error: sum underflow\n");
		}
		value += i;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator-=(const Int<T> &o)
	{
		if (value > 0 && o.get_value() > std::numeric_limits<typename Type<T>::type>::max() + value)
		{
			throw err("error: subtraction overflow\n");
		}
		else if (value < 0 && o.get_value() < std::numeric_limits<typename Type<T>::type>::min() + value)
		{
			throw err("error: subtraction underflow\n");
		}
		value -= o.value;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator-=(typename Type<T>::type i)
	{
		if (value > 0 && i > std::numeric_limits<typename Type<T>::type>::max() + value)
		{
			throw err("error: subtraction overflow\n");
		}
		else if (value < 0 && i < std::numeric_limits<typename Type<T>::type>::min() + value)
		{
			throw err("error: subtraction underflow\n");
		}
		value -= i;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator*=(const Int<T> &o)
	{
		if (value > std::numeric_limits<typename Type<T>::type>::max() / value)
		{
			throw err("error: multiplication overflow\n");
		}
		else if (value < std::numeric_limits<typename Type<T>::type>::min() / value)
		{
			throw err("error: multiplication underflow\n");
		}
		value *= o.value;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator*=(typename Type<T>::type i)
	{
		if (value > std::numeric_limits<typename Type<T>::type>::max() / value)
		{
			throw err("error: multiplication overflow\n");
		}
		else if (value < std::numeric_limits<typename Type<T>::type>::min() / value)
		{
			throw err("error: multiplication underflow\n");
		}
		value *= i;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator/=(const Int<T> &o)
	{
		if (!o.value)
		{
			throw err("error: division by 0\n");
		}
		value /= o.value;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator/=(typename Type<T>::type i)
	{
		if (!i)
		{
			throw err("error: division by 0\n");
		}
		value /= i;
		return *this;
	}

	template<typename T>
	Int<T> &Int<T>::operator++()
	{
		if (++value > std::numeric_limits<typename Type<T>::type>::max())
		{
			throw err("incremented value out of range\n");
		}
		return *this;
	}

	template<typename T>
	Int<T> Int<T>::operator++(int)
	{
		Int tmp = *this;
		if (++value > std::numeric_limits<typename Type<T>::type>::max())
		{
			throw err("the new incremented value out of range\n");
		}
		return tmp;
	}

	template<typename T>
	Int<T> &Int<T>::operator--()
	{
		if (--value < std::numeric_limits<typename Type<T>::type>::min())
		{
			throw err("decremented value out of range\n");
		}
		return *this;
	}

	template<typename T>
	Int<T> Int<T>::operator--(int)
	{
		Int tmp = *this;
		if (--value < std::numeric_limits<typename Type<T>::type>::min())
		{
			throw err("the new decremented value out of range\n");
		}
		return tmp;
	}

	template<typename T>
	typename Type<T>::type Int<T>::operator~() const
	{
		return ~value;
	}


	template<typename T>
	Int<T> operator+(const Int<T> &o1, const Int<T> &o2)
	{
		if (o2.get_value() > 0 && o1.get_value() > std::numeric_limits<typename Type<T>::type>::max() - o2.get_value())
		{
			throw err("error: sum overflow\n");
		}
		else if (o2.get_value() < 0 && o1.get_value() < std::numeric_limits<typename Type<T>::type>::max() - o2.get_value())
		{
			throw err("error: sum underflow\n");
		}
		return Int<T>(o1.get_value() + o2.get_value());
	}

	template<typename T>
	Int<T> operator+(const Int<T> &o, typename Type<T>::type i)
	{
		if (i > 0 && o.get_value() > std::numeric_limits<typename Type<T>::type>::max() - i)
		{
			throw err("error: sum overflow\n");
		}
		else if (i < 0 && o.get_value() < std::numeric_limits<typename Type<T>::type>::max() - i)
		{
			throw err("error: sum underflow\n");
		}
		return Int<T>(o.get_value() + i);
	}

	template<typename T>
	Int<T> operator+(typename Type<T>::type i, const Int<T> &o)
	{
		if (o.get_value() > 0 && i > std::numeric_limits<typename Type<T>::type>::max() - o.get_value())
		{
			throw err("error: sum overflow\n");
		}
		else if (o.get_value() < 0 && i < std::numeric_limits<typename Type<T>::type>::max() - o.get_value())
		{
			throw err("error: sum underflow\n");
		}
		return Int<T>(o + i);
	}

	template<typename T>
	Int<T> operator-(const Int<T> &o1, const Int<T> &o2)
	{
		if (o2.get_value() > 0 && o1.get_value() > std::numeric_limits<typename Type<T>::type>::max() + o2.get_value())
		{
			throw err("error: subtraction overflow\n");
		}
		else if (o2.get_value() < 0 && o1.get_value() < std::numeric_limits<typename Type<T>::type>::max() + o2.get_value())
		{
			throw err("error: subtraction underflow\n");
		}
		return Int<T>(o1.get_value() - o2.get_value());
	}

	template<typename T>
	Int<T> operator-(const Int<T> &o, typename Type<T>::type i)
	{
		if (i > 0 && o.get_value() > std::numeric_limits<typename Type<T>::type>::max() + i)
		{
			throw err("error: subtraction overflow\n");
		}
		else if (i < 0 && o.get_value() < std::numeric_limits<typename Type<T>::type>::max() + i)
		{
			throw err("error: subtraction underflow\n");
		}
		return Int<T>(o.get_value() - i);
	}

	template<typename T>
	Int<T> operator-(typename Type<T>::type i, const Int<T> &o)
	{
		if (o.get_value() > 0 && i > std::numeric_limits<typename Type<T>::type>::max() + i)
		{
			throw err("error: subtraction overflow\n");
		}
		else if (o.get_value() < 0 && i < std::numeric_limits<typename Type<T>::type>::max() + i)
		{
			throw err("error: subtraction underflow\n");
		}
		return Int<T>(i - o.get_value());
	}

	template<typename T>
	Int<T> operator*(const Int<T> &o1, const Int<T> &o2)
	{
		if (o2.get_value() > 0 && o1.get_value() > std::numeric_limits<typename Type<T>::type>::max() / o2.get_value())
		{
			throw err("error: multiplication overflow\n");
		}
		else if (o2.get_value() < 0 && o1.get_value() < std::numeric_limits<typename Type<T>::type>::max() / o2.get_value())
		{
			throw err("error: multiplication underflow\n");
		}
		return Int<T>(o1.get_value() * o2.get_value());
	}

	template<typename T>
	Int<T> operator*(const Int<T> &o, typename Type<T>::type i)
	{
		if (i > 0 && o.get_value() > std::numeric_limits<typename Type<T>::type>::max() / i)
		{
			throw err("error: multiplication overflow\n");
		}
		else if (i < 0 && o.get_value() < std::numeric_limits<typename Type<T>::type>::max() / i)
		{
			throw err("error: multiplication underflow\n");
		}
		return Int<T>(o.get_value() * i);
	}

	template<typename T>
	Int<T> operator*(typename Type<T>::type i, const Int<T> &o)
	{
		if (o.get_value() > 0 && i > std::numeric_limits<typename Type<T>::type>::max() / o.get_value())
		{
			throw err("error: multiplication overflow\n");
		}
		else if (o.get_value() < 0 && i < std::numeric_limits<typename Type<T>::type>::max() / o.get_value())
		{
			throw err("error: multiplication underflow\n");
		}
		return Int<T>(i * o.get_value());
	}

	template<typename T>
	Int<T> operator/(const Int<T> &o1, const Int<T> &o2)
	{
		if (!o2.get_value())
		{
			throw err("error: division by 0\n");
		}
		return Int<T>(o1.get_value() / o2.get_value());
	}

	template<typename T>
	Int<T> operator/(const Int<T> &o, typename Type<T>::type i)
	{
		if (!i)
		{
			throw err("error: division by 0\n");
		}
		return Int<T>(o.get_value() / i);
	}

	template<typename T>
	Int<T> operator/(typename Type<T>::type i, const Int<T> &o)
	{
		if (!o.get_value())
		{
			throw err("error: division by 0\n");
		}
		return Int<T>(i / o.get_value());
	}

	template<typename T>
	typename Type<T>::type operator+=(typename Type<T>::type i, const Int<T> o)
	{
		if (o.get_value() > 0 && i > std::numeric_limits<typename Type<T>::type>::max() - o.get_value())
		{
			throw err("error: sum overflow\n");
		}
		else if (o.get_value() < 0 && i < std::numeric_limits<typename Type<T>::type>::min() - o.get_value())
		{
			throw err("error: sum underflow\n");
		}
		return i += o.get_value();
	}

	template<typename T>
	typename Type<T>::type operator-=(typename Type<T>::type i, const Int<T> o)
	{
		if (o.get_value() > 0 && i > std::numeric_limits<typename Type<T>::type>::max() + o.get_value())
		{
			throw err("error: sum overflow\n");
		}
		else if (o.get_value() < 0 && i < std::numeric_limits<typename Type<T>::type>::min() + o.get_value())
		{
			throw err("error: sum underflow\n");
		}
		return i -= o.get_value();
	}

	template<typename T>
	typename Type<T>::type operator*=(typename Type<T>::type i, const Int<T> o)
	{
		if (o.get_value() > 0 && i > std::numeric_limits<typename Type<T>::type>::max() / o.get_value())
		{
			throw err("error: sum overflow\n");
		}
		else if (o.get_value() < 0 && i < std::numeric_limits<typename Type<T>::type>::min() / o.get_value())
		{
			throw err("error: sum underflow\n");
		}
		return i *= o.get_value();
	}

	template<typename T>
	typename Type<T>::type operator/=(typename Type<T>::type i, const Int<T> o)
	{
		if (!o.get_value())
		{
			throw err("error: division by 0\n");
		}
		return i /= o.get_value();
	}

	template<typename T>
	bool operator==(const Int<T> &o1, const Int<T> &o2)
	{
		return o1.get_value() == o2.get_value();
	}

	template<typename T>
	bool operator==(const Int<T> &o, typename Type<T>::type i)
	{
		return o.get_value() == i;
	}

	template<typename T>
	bool operator==(typename Type<T>::type i, const Int<T> &o)
	{
		return o == i;
	}

	template<typename T>
	bool operator!=(const Int<T> &o1, const Int<T> &o2)
	{
		return !(o1 == o2);
	}

	template<typename T>
	bool operator!=(const Int<T> &o, typename Type<T>::type i)
	{
		return !(o == i);
	}

	template<typename T>
	bool operator!=(typename Type<T>::type i, const Int<T> &o)
	{
		return o != i;
	}

	template<typename T>
	bool operator<(const Int<T> &o1, const Int<T> &o2)
	{
		return o1.get_value() < o2.get_value();
	}

	template<typename T>
	bool operator<(const Int<T> &o, typename Type<T>::type i)
	{
		return o.get_value() < i;
	}

	template<typename T>
	bool operator<(typename Type<T>::type i, const Int<T> &o2)
	{
		return i < o2.get_value();
	}

	template<typename T>
	bool operator>(const Int<T> &o1, const Int<T> &o2)
	{
		return o2 < o1;
	}

	template<typename T>
	bool operator>(const Int<T> &o, typename Type<T>::type i)
	{
		return i < o;
	}

	template<typename T>
	bool operator>(typename Type<T>::type i, const Int<T> &o)
	{
		return o < i;
	}

	template<typename T>
	bool operator<=(const Int<T> &o1, const Int<T> &o2)
	{
		return o1.get_value() <= o2.get_value();
	}

	template<typename T>
	bool operator<=(const Int<T> &o, typename Type<T>::type i)
	{
		return o.get_value() <= i;
	}

	template<typename T>
	bool operator<=(typename Type<T>::type i, const Int<T> &o)
	{
		return o.get_value() >= i;
	}

	template<typename T>
	bool operator>=(const Int<T> &o1, const Int<T> &o2)
	{
		return o2 <= o1;
	}

	template<typename T>
	bool operator>=(const Int<T> &o, typename Type<T>::type i)
	{
		return i <= o;
	}

	template<typename T>
	bool operator>=(typename Type<T>::type i, const Int<T> &o)
	{
		return o <= i;
	}


	template<typename T>
	std::ostream &operator<<(std::ostream &os, const Int<T> &o)
	{
		os << o.get_value();
		return os;
	}

	template<typename T>
	std::istream &operator>>(std::istream &is, Int<T> &o)
	{
		if (!(is >> o.value))
		{
			o.value = 0;
			throw err("input out of range\n");
		}

		return is;
	}

}

#endif
