#include <iostream>

using namespace std;

int factorial(int num);

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int a = 0, b = 0;
	cin >> a >> b;

	cout << factorial(a) / factorial(b) / factorial(a - b);

	return 0;
}

int factorial(int num) {
	int ret = 1;
	for (int i = num; i > 1; i --) {
		ret *= i;
	}
	return ret;
}