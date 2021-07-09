#include<vector>
#include<iostream>
#include<deque>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	if (a == b) cout << 0 << endl;
	else {
		deque<int> queue;
		vector<bool> visit(100001);
		int depth = 0;

		visit[a] = true;
		queue.push_back(a);
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				int point = queue.front();
				queue.pop_front();
				//cout << point << endl;

				if (point == b) {
					cout << depth << endl;
					deque<int> emptyQueue;
					queue = emptyQueue;
					break;
				}
				if (point + 1 <= 100000 && !visit[point + 1]) {
					queue.push_back(point + 1);
					visit[point + 1] = true;
				}
				if (point - 1 >= 0 && !visit[point - 1]) {
					queue.push_back(point - 1);
					visit[point - 1] = true;
				}
				if (point * 2 <= 100000 && !visit[point * 2]) {
					queue.push_back(point * 2);
					visit[point * 2] = true;
				}
			}
			depth++;
		}
	}
	return 0;
}
