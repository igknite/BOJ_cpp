#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> arr(9, 0);

void search(int level);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	search(0);
	return 0;
}

void search(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[level] = i;
		search(level + 1);
	}
}
