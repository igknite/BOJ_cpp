#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, tmp;
	cin >> n;
	vector<int> vec;
	for (int a = 0; a < n; a++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	for (int a = 0; a < n; a++) {
		cout << vec[a] << '\n';
	}
	return 0;
}