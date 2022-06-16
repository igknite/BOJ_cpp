#include <iostream>

using namespace std;
int fib[40] = { 1, 1, 0 };
void fibonacci(int n);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	fibonacci(n);

	cout << fib[n-1] << " " << n - 2;

	return 0;
}

void fibonacci(int n) {
	for (int i = 2; i < n; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}
}