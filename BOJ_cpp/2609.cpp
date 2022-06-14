#include <iostream>
#include <numeric>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a = 0, b = 0;
	cin >> a >> b;
	cout << gcd(a, b) << '\n' << lcm(a, b);

	return 0;
}