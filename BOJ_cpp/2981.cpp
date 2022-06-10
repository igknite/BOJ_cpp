#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> vec(N - 1);
	int cur = 0, now = 0;
	// vec : 주어진 수들의 차
	cin >> cur;
	for (int i = 0; i < N - 1; i++) {
		cin >> now;
		vec[i] = cur - now;
		cur = now;
	}
	// G : vec(주어진 수들의 차)의 최대공약수
	int G = gcd(vec[0], vec[1]);
	for (int i = 2; i < vec.size() - 1; i++) {
		G = gcd(vec[i], G);
	}
	// G의 약수(1 제외)가 문제의 해가 된다.
	vector<int> prt;
	prt.push_back(G);
	// 루트G 까진 즉시 출력 + 반대 약수는 vector에 저장, 역순으로 출력
	for (int i = 2; i * i <= G; i++) {
		if (G % i == 0) {
			printf("%d ", i);
			if(i * i != G) prt.push_back(G / i);
		}
	}
	reverse(prt.begin(), prt.end());
	for (const auto& v : prt) {
		printf("%d ", v);
	}

	return 0;
}