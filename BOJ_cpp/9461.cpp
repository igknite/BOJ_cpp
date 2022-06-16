#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<long long> len(100);
	// 뒤로 가면 INT 범위를 벗어난다. 
	len[0] = 1;
	len[1] = 1;
	len[2] = 1;
	len[3] = 2;
	len[4] = 2;
	for (int i = 5; i < 100; i++) {
		len[i] = len[i - 1] + len[i - 5];
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cout << len[a - 1] << '\n';
	}

	return 0;
}