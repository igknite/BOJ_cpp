#include <iostream>
#include <numeric>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a = 0, b = 0, num = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}

	return 0;
}