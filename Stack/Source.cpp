#include<string>
#include"Stack.h"

int main() {
	string line = "([x-y-z] * [x + 2y) - {z + 4x)]";
	Stack<char>scopes(15);
	enum ScopeTypes {
		LeftParenthesis = '(',
		RightParenthesis=')',
		LeftSquareBracket='[',
		RightSquareBracket=']',
		LeftCurlyBrace='{',
		RightCurlyBrace='}'
	};
	bool res = true;
	for (size_t i = 0; i <= line.size(); i++) {
		switch (line[i]) {
		case LeftParenthesis:
		case LeftSquareBracket:
		case LeftCurlyBrace:
			scopes.Push(line[i]);
			break;

		case RightParenthesis:
			if (scopes.Peek() == LeftParenthesis)
				scopes.Pop();
			else
				res = false;
			break;

		case RightSquareBracket:
			if (scopes.Peek() == LeftSquareBracket)
				scopes.Pop();
			else
				res = false;
			break;
		case RightCurlyBrace:
			if (scopes.Peek() == LeftCurlyBrace)
				scopes.Pop();
			else
				res = false;
			break;
		}
		if (res == false) {
			cout << "Incorrect line.\n";
			cout << line.substr(0, i);
			break;
		}
	}
	if (res == true)
		cout << "Correct line.\n";

	return 0;
}