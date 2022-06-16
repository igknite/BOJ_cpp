#include <iostream>
#include <vector>

using namespace std;
#define MOD 15746
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int prev = 1, pprev = 1, now = 1;
	for (int i = 1; i < N; i++) {
		now = pprev + prev;
		pprev = prev;
		prev = now;
		if (prev >= MOD) prev -= MOD;
	}
	cout << prev;

	return 0;
}
// 피보나치 수열의 값을 가져오는 문제.
// 한번만 가져오면 되는 문제이므로 괜히 저장하여 메모리, 시간 늘리지 말고 바로 더해서 값을 가져올것.