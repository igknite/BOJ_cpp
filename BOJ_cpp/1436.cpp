#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N = 0;
	cin >> N;
	int ans = 0;
	for (int i = 666; N > 0; i++) {
		string integer = to_string(i);
		int count = 0;
		for (int n = 0; n < integer.length(); n++) {
			if (integer[n] == '6') count++;
			else count = 0;
			if (count == 3) {
				N--;
				ans = i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}