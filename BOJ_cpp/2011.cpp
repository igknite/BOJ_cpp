#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string script = "";
	cin >> script;
	
	vector<int> ciper(script.length() + 1);
	ciper[0] = 1;
	if (script[script.length() - 1] - 48 != 0) ciper[1] = 1;
	int now, pre = 0;
	for (int i = 2; i <= script.length(); i++) {
		now = script[script.length() - i] - 48;
		pre = script[script.length() - i + 1] - 48;
		if (now != 0) {
			ciper[i] += ciper[i - 1];
			if (now * 10 + pre <= 26) ciper[i] += ciper[i - 2];
		}
		ciper[i] = ciper[i] % 1000000;
	}
	cout << ciper[script.length()] << endl;
	return 0;
}