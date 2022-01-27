#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m = 0;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int max = 0;
	for (int a = 0; a < n - 2; a++) {
		for (int b = a + 1; b < n - 1; b++) {
			for (int c = b + 1; c < n; c++) {
				int temp = vec[a] + vec[b] + vec[c];
				if (temp <= m && temp >= max) max = temp;
			}
		}
	}
	cout << max << endl;
	return 0;
}