#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack <char> a;
	string s;
	cin >> s;
	for (size_t i=0; i<s.size(); i++) {
		if (s[i] == '(' || s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == ']' || s[i] == '}' || s[i] == '>' || s[i] == ')') {
			if (s[i] == '(' || s[i] == '<' || s[i] == '{' || s[i] == '[') a.push(s[i]);
			else {
				if ((s[i] == ')' && a.top() == '(') || (s[i] == '}' && a.top() == '{') || (s[i] == ']' && a.top() == '[') || (s[i] == '>' && a.top() == '<')){
					a.pop();
				}
				else {
					break;
				}
			}
		}
	}
	if (a.empty()) cout << "YES";
	else cout << "NO";
}