#include<vector>
#include<iostream>
#include<deque>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	if (a == b) cout << 0 << endl << 1 << endl;
	else {
		deque<int> queue;
		vector<int> visit(100001);
		vector<int> visitDepth(100001);
		int depth = 0;

		visit[a]++;
		visitDepth[a] = 0;
		queue.push_back(a);
		bool reach = false;
		int shortcutCount = 0;
		while (!reach) {
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				int point = queue.front();
				queue.pop_front();

				if (point == b) {
					reach = true;
					shortcutCount += visit[point];
				}
				else if (!reach) {


					if (point + 1 <= 100000) {
						//cout << point + 1 << " " << visitDepth[point] << endl;
						if (!visit[point + 1]) {
							queue.push_back(point + 1);
							visitDepth[point + 1] = depth;
						}
						if (visitDepth[point + 1] == depth) visit[point + 1] += visit[point];
					}
					if (point - 1 >= 0) {
						//cout << point - 1 << " " << visitDepth[point] << endl;
						if (!visit[point - 1]) {
							queue.push_back(point - 1);
							visitDepth[point - 1] = depth;
						}
						if (visitDepth[point - 1] == depth) visit[point - 1] += visit[point];
					}
					if (point * 2 <= 100000) {
						//cout << point * 2 << " " << visitDepth[point] << endl;
						if (!visit[point * 2]) {
							queue.push_back(point * 2);
							visitDepth[point * 2] = depth;
						}
						if (visitDepth[point * 2] == depth) visit[point * 2] += visit[point];
					}
				}
			}
			//cout << endl;
			if (reach) {
				cout << depth << endl;
				cout << shortcutCount << endl;
			}
			depth++;
		}
	}
	return 0;
}