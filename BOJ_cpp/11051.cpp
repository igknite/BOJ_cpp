#include <iostream>
#include <vector>
using namespace std;

int combination(int a, int b);
int triangle[1001][1001] = { 0, };
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a = 0, b = 0;
	cin >> a >> b;
	
	combination(a, b);
	cout << triangle[a][b];
	
	return 0;
}

int combination(int a, int b) {
	int number = triangle[a][b];
	// ���� �ִٸ� ��ȯ, ������ ���ؼ� �Է������� �ߺ� ���� ����
	if (number == 0) {
		if (a <= 1) number = 1;
		else if (b == 0 || b == a) number = 1;
		else number = (combination(a - 1, b) + combination(a - 1, b - 1)) % 10007;
		//n C r = (n-1) C (r-1) + (n-1) C r ���� �̿��Ͽ� ���Ѵ�.
		triangle[a][b] = number;
	}

	return number;
}