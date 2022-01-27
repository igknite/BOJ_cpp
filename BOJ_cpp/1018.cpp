#include <iostream>
#include <vector>

using namespace std;

int check(vector<int> cut);
int main() {
	int a, b = 0;
	cin >> a >> b;
	vector<vector<int>> vec(a, vector<int>(b, 0));
	vector<int> cut(64);
	
	char T;
	for (int i = 0; i < a; i++) {
		for (int l = 0; l < b; l++) {
			cin >> T;
			if (T == 'B') vec[i][l] = 0;
			else vec[i][l] = 1;
		}
	}
	int min = 64;
	for (int i = 0; i < a - 7; i++) {
		for (int l = 0; l < b - 7; l++) {
			for (int n = 0; n < 8; n++) {
				for (int m = 0; m < 8; m++) {
					cut[8 * n + m] = vec[i + n][l + m];
				}
			}
			int num = check(cut);
			if (min > num) min = num;
			if (min > 64 - num) min = 64 - num;
		}
	}

	cout << min << endl;
	return 0;
}

int check(vector<int> cut) {
	vector<int> ans(64);
	int answer = 0;
	for (int i = 0; i < 64; i++) {
		ans[i] = (i / 8 + i) % 2;
	}
	for (int i = 0; i < 64; i++) {
		answer += ans[i] ^ cut[i];
	}
	return answer;
}