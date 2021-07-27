#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool sort_dict(string a, string b);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<string> S(N);
	for (int n = 0; n < N; n++) {
		cin >> S[n];
	}
	cout << endl;
	sort(S.begin(), S.end(),sort_dict);
	S.erase(unique(S.begin(), S.end()), S.end());
	for (int n = 0; n < S.size(); n++) {
		/*if (n < S.size() - 1) {
			if(!S[n].compare(S[n+1])) continue;
		}*/
		cout << S[n] << endl;
	}
	return 0;
}
bool sort_dict(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else return a < b;
}