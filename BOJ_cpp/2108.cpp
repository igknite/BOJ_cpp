#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	vector<int> pnum;
	int temp;
	int sum = 0;
	int second = vec[n / 2];
	for (int i = 0; i < n; i++) {
		sum += vec[i];
		if (i == 0 || vec[i] != vec[i - 1]) pnum.push_back(1);
		else if (vec[i] == vec[i - 1]) pnum.back()++;
	}
	int fir = 0;
	int sec = -1;
	int max = pnum[0];
	int index = pnum[0] - 1;
	int first = 0;
	if(sum<0) first = ceil(sum / (double)n - 0.5);
	else first = floor(sum / (double)n + 0.5);
	for (int i = 1; i < pnum.size(); i++) {
		index += pnum[i];
		if (max < pnum[i]) {
			max = pnum[i];
			sec = -1;
			fir = index;
		}
		else if (max == pnum[i]) {
			if (sec == -1) sec = index;
			continue;
		}
	}
	int third = 0;
	if (sec == -1) {
		third = vec[fir];
	}
	else third = vec[sec];
	int forth = vec[vec.size() - 1] - vec[0];
	cout << first << '\n' << second << '\n' << third << '\n' << forth;
	return 0;
}