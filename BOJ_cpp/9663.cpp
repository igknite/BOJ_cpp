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
		// queen[i] == queen[level] ���� �ٸ� row�� ���� column���� �����ϸ� �ȵ�
		// abs(queen[level] - queen[i]) == level - i �� ������ �� �밢�� ���� �����ϸ� �׻� ������.
	}
	return true;
}