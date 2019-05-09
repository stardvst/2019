#include <iostream>

class Base
{
	friend std::ostream &operator<<(std::ostream &o, const Base &b);
protected:
	virtual void printOn(std::ostream &s) const;
private:
	std::string m_type = "base";
};

inline std::ostream &operator<<(std::ostream &o, const Base &b)
{
	b.printOn(o);
	return o;
}

void Base::printOn(std::ostream &s) const
{
	s << m_type << '\n';
	s << std::string(4, ' ');
}

class Derived : public Base
{
protected:
	void printOn(std::ostream &s) const override;
private:
	std::string m_type = "derived";
};

void Derived::printOn(std::ostream &s) const
{
	Base::printOn(s);
	s << m_type << '\n';
	s << std::string(4, ' ');
}

int main()
{
	Derived d;
	std::cout << d;

	std::cin.get();
	return 0;
}
