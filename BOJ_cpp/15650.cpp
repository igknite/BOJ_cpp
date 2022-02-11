#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> arr(9, 0);
vector<bool> visited(9, false);

void search(int level, int k);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	search(0, 1);
	return 0;
}

void search(int level, int k) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = k; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[level] = i;
			search(level + 1, i + 1);
			visited[i] = false;
		}
	}
}
