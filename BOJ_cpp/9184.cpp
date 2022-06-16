#include <iostream>

using namespace std;

int W[21][21][21];
int getW(int a, int b, int c);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << getW(a, b, c) << '\n';
	}

	return 0;
}
int getW(int a, int b, int c) {
	int ret;
	if (a <= 0 || b <= 0 || c <= 0) {
		ret = 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		ret = getW(20, 20, 20);
	}
	else {
		ret = W[a][b][c];
		if (ret == 0) {
			if (a < b && b < c) {
				ret = getW(a, b, c - 1) + getW(a, b - 1, c - 1) - getW(a, b - 1, c);
			}
			else ret = getW(a - 1, b, c) + getW(a - 1, b - 1, c) + getW(a - 1, b, c - 1) - getW(a - 1, b - 1, c - 1);
			W[a][b][c] = ret;
		}
	}
	
	return ret;
}