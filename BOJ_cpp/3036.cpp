#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int ring = 0;
	cin >> ring;
	vector<int> rings(ring);
	for (int i = 0; i < ring; i++) {
		cin >> rings[i];
	}
	int first = rings[0];
	for (int i = 1; i < ring; i++) {
		int G = gcd(first, rings[i]);
		if (G == rings[i]) cout << first / G << "/1\n";
		else cout << first / G << "/" << rings[i] / G << "\n";
	}

	return 0;
}