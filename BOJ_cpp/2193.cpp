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
	// ���ڸ� ��ģ���� 1 �ϳ���.
	// 0���� ������ ��ģ���� ���ڸ� ���� ��� ��ģ���� 0�� ���̸� �ȴ�.
	// 1�� ������ ��ģ���� ���ڸ� ���� 0���� ���� ��ģ���� 1�� ���ΰͻ��̴�.
	// 
	// [0] 0 1 1 2 3 5 8
	// [1] 1 0 1 1 2 3 5
	// ��  1 1 2 3 5 8 13
	// ��ģ���� ������ �׳� �Ǻ���ġ����.
	for (int n = 2; n < N; n++) {
		num[n] = num[n - 1] + num[n - 2];
	}
	cout << num[N - 1];
	

	return 0;
}