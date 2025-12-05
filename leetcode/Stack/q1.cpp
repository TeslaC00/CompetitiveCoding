#include<iostream>
#include<string>
#include<stack>

bool isValid(const std::string& s) {
	if (s.size() % 2 == 1) return false;
	std::stack<char> stack;
	for (const char& c : s)
	{
		if (c == '(' || c == '[' || c == '{')
			stack.push(c);
		else
		{
			if (stack.empty())
				return false;

			char top = stack.top();
			if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}'))
				stack.pop();
			else
				return false;
		}
	}
	if (!stack.empty())
		return false;

	return true;
}

int main() {
	std::cout << "" << std::endl;
}
