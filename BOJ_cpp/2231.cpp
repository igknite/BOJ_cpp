#include <iostream>
#include<cmath>

using namespace std;
int newN(int n);
int main() {
	int n = 0;
	cin >> n;
	int logN = log10(n);
	int now = 0;
	for (int i = 1; i < n; i++) {
		if (n == newN(i)) {
			now = i;
			break;
		}
	}
	cout << now << endl;
	return 0;
}

int newN(int n) {
	int newN = n;
	for (; n > 0; n /= 10) {
		newN += n % 10;
	}
	return newN;
}