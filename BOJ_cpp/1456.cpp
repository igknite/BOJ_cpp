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

	// 소수 만들어놓기
	for (int i = 2; i < MAX; ++i) {
		if (visited[i]) continue;
		Prime.push_back(i);
		for (int j = 2 * i; j < MAX; j += i) visited[j] = true;
	}

	cin >> A >> B;

	ll ans = 0LL;
	for (auto it : Prime) {
		ll curr = 1LL * it; // 현재 숫자
		ll temp = curr; // curr의 x제곱 ( 2제곱부터 답이 될 수 있다.)
		while (temp <= B / curr) { // temp*curr <= B 일때만
			temp *= curr; // 제곱해보고
			if (temp >= A) ans++; // 범위 들어오는지 체크
		}
	}
	cout << ans << '\n';
	return 0;
}