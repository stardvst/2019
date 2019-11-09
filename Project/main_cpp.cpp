#include <iostream>
#include "int.h"


int main()
{

	Integer::Int<Integer::Type<int>::type> i;
	try
	{
		// i=Integer::Int<Integer::Type<int>::type>(-555555555555555555555555555555555555555);
	}
	catch (const Integer::err & e)
	{
		std::cerr << e.msg;
	}
	std::cout << i;

	// Integer::Int<Integer::Type<int>::type> i1;

	// std::cout << "i1, default value = " << i1 << "\n\n";

	// std::cout << "Enter i1: ";
	// try {
	//   std::cin >> i1;
	// }
	// catch(const Integer::err& e) {
	//   std::cerr << e.msg;
	// }
	// std::cout << "\ni1 = " << i1 << '\n';

	// Integer::Int<Integer::Type<int>::type> i2 = 12;
	// std::cout << "i2 = " << i2 << '\n'
	//   << "gcd(i1, i2) = " << gcd(i1, i2) << '\n'
	//   << "lcm(i1, i2) = " << lcm(i1, i2) << "\n\n";

	// Integer::Int<Integer::Type<int>::type> i3(i1);
	// std::cout << "i3 = i1 = " << i3 << "\n\n";

	// int i;
	// std::cout << "Enter an int: ";
	// std::cin >> i;

	// std::cout << "\ni1 = " << i1 << '\n';
	// std::cout << "i = " << i << "\n\n"

	//   << i1 << " + " << i3 << " = " << i1 + i3 << '\n'
	//   << i1 << " + " << i << " = " << i1 + i << '\n'
	//   << i << " + " << i1 << " = " << i + i1 << '\n'
	//   << i1 << " - " << i3 << " = " << i1 - i3 << '\n'
	//   << i1 << " - " << i << " = " << i1 - i << '\n'
	//   << i << " - " << i1 << " = " << i - i1 << '\n'
	//   << i1 << " * " << i3 << " = " << i1 * i3 << '\n'
	//   << i1 << " * " << i << " = " << i1 * i << '\n'
	//   << i << " * " << i1 << " = " << i * i1 << '\n';
	// try {
	//   std::cout << i1 << " / " << i3 << " = " << i1 / i3 << '\n';
	// }
	// catch(const Integer::err& e) {
	//   std::cerr << i1 << " / " << i3 << ": " << e.msg;
	// }
	// try {
	//   std::cout << i1 << " / " << i << " = " << i1 / i << '\n';
	// }
	// catch(const Integer::err& e) {
	//   std::cerr << i1 << " / " << i << ": " << e.msg;
	// }
	// try {
	//   std::cout << i << " / " << i1 << " = " << i / i1 << '\n';
	// }
	// catch(const Integer::err& e) {
	//   std::cerr << i << " / " << i1 << ": " << e.msg;
	// }

	// std::cout << "\n\n" << i1 << " == " << i3 << ": " << std::boolalpha << (i1 == i3) << '\n'
	//   << i1 << " == " << i << ": " << std::boolalpha << (i1 == i) << '\n'
	//   << i << " == " << i1 << ": " << std::boolalpha << (i == i1) << '\n'
	//   << i1 << " != " << i3 << ": " << std::boolalpha << (i1 != i3) << '\n'
	//   << i1 << " != " << i << ": " << std::boolalpha << (i1 != i) << '\n'
	//   << i << " != " << i1 << ": " << std::boolalpha << (i != i1) << '\n'
	//   << i1 << " < " << i3 << ": " << std::boolalpha << (i1 < i3) << '\n'
	//   << i1 << " < " << i << ": " << std::boolalpha << (i1 < i) << '\n'
	//   << i << " < " << i1 << ": " << std::boolalpha << (i < i1) << '\n'
	//   << i1 << " > " << i3 << ": " << std::boolalpha << (i1 > i3) << '\n'
	//   << i1 << " > " << i << ": " << std::boolalpha << (i1 > i) << '\n'
	//   << i << " > " << i1 << ": " << std::boolalpha << (i > i1) << '\n'
	//   << i1 << " <= " << i3 << ": " << std::boolalpha << (i1 <= i3) << '\n'
	//   << i1 << " <= " << i << ": " << std::boolalpha << (i1 <= i) << '\n'
	//   << i << " <= " << i1 << ": " << std::boolalpha << (i <= i1) << '\n'
	//   << i1 << " >= " << i3 << ": " << std::boolalpha << (i1 >= i3) << '\n'
	//   << i1 << " >= " << i << ": " << std::boolalpha << (i1 >= i) << '\n'
	//   << i << " >= " << i1 << ": " << std::boolalpha << (i >= i1) << "\n\n\n"

	//   << i1 << " += " << i3 << "; ";
	// i1 += i3; 
	// std::cout << i1 << '\n' << i1 << " += " << i << '\n';
	// i1 += i;
	// std::cout << i1 << '\n' << i << " += " << i1 << '\n';
	// i += i1;
	// std::cout << i << '\n' << i1 << " -= " << i3 << '\n';
	// i1 -= i3; 
	// std::cout << i1 << '\n' <<  i1 << " -= " << i << '\n';
	// i1 -= i;
	// std::cout << i1 << '\n' << i << " -= " << i1 << '\n';
	// i -= i1;
	// std::cout << i << "\n\n"

	//   << "i1++ = ";
	// std::cout << i1++ << '\n';
	// std::cout << "++i1 = ";
	// std::cout << ++i1 << '\n';
	// std::cout << "i1-- = ";
	// std::cout << i1-- << '\n';
	// std::cout << "--i1 = ";
	// std::cout << --i1 << "\n\n"

	//   << !i1 << '\n' << ~i1 << "\n\n\n";

	// int a = 0;
	// std::cout << "a = 0\ni1 = " << i1 << "\na = i1 => a = " << (a = i1) << std::endl;

	return 0;
}
