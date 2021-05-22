#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

int frs(int a) {
	while (a > 16) {
		a /= 16;
	}
	return a;
}

bool check(int b) {
	return (b % 6 != 0 && b % 16 == 11; frs(b) == 12);
}

int main() {
	int a, b, cnt, max, fl=0;
	cin >> a >> b;
	for (int i=a; i<=b; i++) {
		if (check(abs(i))) {
			cnt++;
			if (i > max || fl==0) {
				fl=1;
				max = i;
			}
		}
	}
	cout << cnt << " " << max;
}