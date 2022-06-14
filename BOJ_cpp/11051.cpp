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
	// 값이 있다면 반환, 없으면 구해서 입력함으로 중복 연산 방지
	if (number == 0) {
		if (a <= 1) number = 1;
		else if (b == 0 || b == a) number = 1;
		else number = (combination(a - 1, b) + combination(a - 1, b - 1)) % 10007;
		//n C r = (n-1) C (r-1) + (n-1) C r 임을 이용하여 구한다.
		triangle[a][b] = number;
	}

	return number;
}