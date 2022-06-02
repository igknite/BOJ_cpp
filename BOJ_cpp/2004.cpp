#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int five = 0, two = 0;
	for (int i = 1; a >= pow(5, i); i++) {
		int power = pow(5, i);
		five += a / power;
		five -= b / power;
		five -= (a - b) / power;
	}
	for (int i = 1; a >= pow(2, i); i++) {
		int power = pow(2, i);
		two += a / power;
		two -= b / power;
		two -= (a - b) / power;
	}

	cout << min(two, five) << endl;

	return 0;
}

// �ܼ� factorial ���� 0�� ������ ���� �� �ƴ϶� Combination �̹Ƿ� 2�� ������ ���� �Ѵ�. ex) 5C1 = 5 > 0�� ����.