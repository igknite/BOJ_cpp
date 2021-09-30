#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int inp = 0;
	cin >> inp;
	vector<int> map(inp);
	vector<int> round(10, 1);
	map[0] = 10;
	for (int i = 1; i < inp; i++) {
		for (int l = 0; l < 10; l++) {
			int roundData = 0;
			for (int k = l; k < 10; k++) {
				roundData += round[k];
			}
			round[l] = roundData % 10007;
		}
		int rnum = 0;
		for (int l = 0; l < 10; l++) {
			rnum += round[l];
		}
		map[i] = rnum % 10007;
	}
	
	cout << map[inp - 1] % 10007 << endl;
	
	return 0;
}