#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> arr(9, 0);
vector<bool> visited(9, false);

void search(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[level] = i;
			search(level + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	search(0);
	return 0;
}