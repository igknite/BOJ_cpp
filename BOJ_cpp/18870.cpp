#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool sortSecond(pair<int, int> a, pair<int, int> b);
int main() {
	int n;
	cin >> n;
	int tmp;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(make_pair(tmp, i));
	}
	sort(vec.begin(),vec.end());
	int same = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0 && vec[i].first == tmp) {
			vec[i].first = vec[i - 1].first;
			same++;
		}
		else {
			tmp = vec[i].first;
			vec[i].first = i - same;
		}
	}
	sort(vec.begin(), vec.end(), sortSecond);
	for (int i = 0; i < n; i++) {
		cout << vec[i].first << " ";
	}
	return 0;
}

bool sortSecond(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}