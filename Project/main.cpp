#include <iostream>
#include <stack>

std::string reverseInParentheses(std::string s)
{
	std::stack<int> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			st.push(i);
		if (s[i] == ')')
		{
			int start = st.top(); st.pop();
			reverse(s.begin() + start + 1, s.begin() + i);
		}
	}
	std::string ans;
	for (char i : s)
		if (i != '(' && i != ')')
			ans = ans + i;
	return ans;
}


int main()
{
	std::cout << reverseInParentheses("foo(bar(baz))blim");

	std::cin.get();
	return 0;
}
