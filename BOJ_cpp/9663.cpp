#include <iostream>
#include <vector>

using namespace std;

bool check(int level);
void nqueen(int level);
int N = 0;
int cnt = 0;
vector<int> queen(15, -1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	nqueen(0);
	cout << cnt;
	return 0;
}

void nqueen(int level) {
	if (level == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		queen[level] = i;
		if (check(level)) {
			nqueen(level + 1);
		}
	}
}

bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (queen[i] == queen[level] || abs(queen[level] - queen[i]) == level - i) return false;
		// queen[i] == queen[level] 서로 다른 row에 같은 column값이 존재하면 안됨
		// abs(queen[level] - queen[i]) == level - i 두 지점이 한 대각선 위에 존재하면 항상 만족함.
	}
	return true;
}