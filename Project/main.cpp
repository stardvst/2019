#include <iostream>
#include <string>

struct A
{
	template <typename String>
	void setStr(String&& first)
	{
		m_sStr += static_cast<String&&>(first);
	}

	template <typename String, typename... Strings>
	void setStr(String&& str, Strings&&... rest);

	std::string m_sStr;
};

template <typename String, typename... Strings>
void A::setStr(String&& str, Strings&&... rest)
{
	m_sStr = static_cast<String&&>(str);
	setStr(static_cast<Strings&&>(rest)...);
}

int main()
{
	A a;
	a.setStr("hello", " world");
	a.setStr("1", " 2");
	std::cout << a.m_sStr;

	std::cin.get();
}
