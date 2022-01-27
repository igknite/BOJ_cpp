#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MAX = 10000001; // root(10^14) = 10^7

ll A, B;
bool visited[MAX];
vector<int> Prime;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// �Ҽ� ��������
	for (int i = 2; i < MAX; ++i) {
		if (visited[i]) continue;
		Prime.push_back(i);
		for (int j = 2 * i; j < MAX; j += i) visited[j] = true;
	}

	cin >> A >> B;

	ll ans = 0LL;
	for (auto it : Prime) {
		ll curr = 1LL * it; // ���� ����
		ll temp = curr; // curr�� x���� ( 2�������� ���� �� �� �ִ�.)
		while (temp <= B / curr) { // temp*curr <= B �϶���
			temp *= curr; // �����غ���
			if (temp >= A) ans++; // ���� �������� üũ
		}
	}
	cout << ans << '\n';
	return 0;
}