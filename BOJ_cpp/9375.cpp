#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int clothesNum = 0;
		cin >> clothesNum;
		vector<string> clothes;
		vector<int> num;
		int wearCase = 1;
		for (int j = 0; j < clothesNum; j++) {
			string name, clothType;
			cin >> name >> clothType;
			auto iter = find(clothes.begin(), clothes.end(), clothType);
			if (iter == clothes.end()) {
				clothes.push_back(clothType);
				num.push_back(1);
			}
			else {
				int index = iter - clothes.begin();
				num[index]++;
			}
		}
		for (int k = 0; k < num.size(); k++) {
			wearCase *= num[k] + 1;
		}
		cout << wearCase - 1 << '\n';
	}

	return 0;
}