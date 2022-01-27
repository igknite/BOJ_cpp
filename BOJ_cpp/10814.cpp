#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

bool compare(tuple<int, int, string> a, tuple<int, int, string> b);
int main() {
	int n;
	cin >> n;
	int a;
	string b;
	vector<tuple<int, int, string>> vec;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.emplace_back(a, i, b);
	}
	sort(vec.begin(), vec.end()); // compare 없이 된다.
	for (int i = 0; i < n; i++) {
		cout << get<0>(vec[i]) << " " << get<2>(vec[i]) << '\n';
	}
	
	return 0;
}

bool compare(tuple<int, int, string> a, tuple<int, int, string> b) {
	if (get<0>(a) == get<0>(b)) {
		return get<1>(a) < get<1>(b);
	}
	return get<0>(a) < get<0>(b);
}