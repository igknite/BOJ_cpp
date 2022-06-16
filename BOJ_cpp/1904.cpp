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
// �Ǻ���ġ ������ ���� �������� ����.
// �ѹ��� �������� �Ǵ� �����̹Ƿ� ���� �����Ͽ� �޸�, �ð� �ø��� ���� �ٷ� ���ؼ� ���� �����ð�.