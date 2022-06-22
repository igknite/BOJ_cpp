#include <iostream>
#include <vector>

using namespace std;

vector<int> point(300);
vector<int> maxPoint(300);
int stair(int now);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> point[i];
	}
	maxPoint[0] = 0;
	maxPoint[1] = point[1];
	maxPoint[2] = point[1] + point[2];
	maxPoint[3] = max(point[1], point[2]) + point[3];
	cout << stair(N);

	return 0;
}

int stair(int now) {
	if (now == 0) return 0;
	int pnt = maxPoint[now];
	if (pnt == 0) {
		pnt = max(stair(now - 2), stair(now - 3) + point[now - 1]) + point[now];
		maxPoint[now] = pnt;
	}
	return pnt;
}