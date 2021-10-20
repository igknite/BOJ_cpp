#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<long long> num(90);
	num[0] = 1;
	num[1] = 1;
	// 한자리 이친수는 1 하나뿐.
	// 0으로 끝나는 이친수는 한자리 적은 모든 이친수에 0만 붙이면 된다.
	// 1로 끝나는 이친수는 한자리 적은 0으로 끝난 이친수에 1을 붙인것뿐이다.
	// 
	// [0] 0 1 1 2 3 5 8
	// [1] 1 0 1 1 2 3 5
	// 합  1 1 2 3 5 8 13
	// 이친수의 갯수는 그냥 피보나치수열.
	for (int n = 2; n < N; n++) {
		num[n] = num[n - 1] + num[n - 2];
	}
	cout << num[N - 1];
	

	return 0;
}