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
 * function team() ���� idx�� �߰����� �ʾƼ� ������ 0���� ��ȸ�ϰ� �־���.
 * �̷� ��� ���� ������ ����� �� ��ü�� �� �� �ƴ϶� �� ���ø��� 0���� Ȯ���ؾ� �ϹǷ� ���ʿ��� ��ȸ�� �߻��Ѵ�.
 * �׷� ���� �ð��ʰ��� Ʋ�� ��찡 �־���.
 */