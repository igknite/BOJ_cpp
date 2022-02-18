#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> performance(20, vector<int>(20, 0));
vector<bool> selected(20, false);
int member = 0;
int best = 10000;
void team(int idx, int count);

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> member;
	vector<int> row(member, 0);
	for (int i = 0; i < member; i++) {
		for (int l = 0; l < member; l++) {
			cin >> row[l];
		}
		performance[i] = row;
	}
	team(0, 0);
	cout << best;
	return 0;
}

void team(int idx, int count) {
	if (count == (member / 2)) {
		vector<int> team1;
		vector<int> team2;
		for (int i = 0; i < member; i++) {
			if (selected[i]) team1.push_back(i);
			else team2.push_back(i);
		}
		int con1 = 0;
		int con2 = 0;

		for (int i = 0; i < (member / 2); i++) {
			for (int l = 0; l < (member / 2); l++) {
				con1 += performance[team1[i]][team1[l]];
				con2 += performance[team2[i]][team2[l]];
			}
		}
		int temp = abs(con1 - con2);


		if (best > temp) best = temp;
	}
	for (int i = idx; i < member; i++) {
		if (!selected[i]) {
			selected[i] = true;
			team(i, count + 1);
			selected[i] = false;
		}
	}
}

/*
 * function team() 에서 idx를 추가하지 않아서 무조건 0부터 순회하고 있었다.
 * 이럴 경우 팀원 선택의 경우의 수 자체가 늘 뿐 아니라 매 선택마다 0부터 확인해야 하므로 불필요한 순회가 발생한다.
 * 그로 인해 시간초과로 틀린 경우가 있었다.
 */