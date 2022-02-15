#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9,-1));
vector<pair<int, int>> zeroPoint;
int zeroCount = 0;
bool found = false;

bool check(int row, int column);
void fillSudoku(int count);

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int tmp = 0;
	vector<int> row(9, -1);
	for (int i = 0; i < 9; i++) {
		for (int l = 0; l < 9; l++) {
			cin >> tmp;
			if (tmp == 0) {
				zeroCount++;
				zeroPoint.push_back(make_pair(i, l));
			}
			row[l] = tmp;
		}
		sudoku[i] = row;
	}

	fillSudoku(0);

	return 0;
}

void fillSudoku(int count) {
	if (count == zeroCount) {
		for (int i = 0; i < 9; i++) {
			for (int l = 0; l < 9; l++) {
				cout << sudoku[i][l] << ' ';
			}
			cout << '\n';
		}
		found = true; // 최적해를 발견한 경우
		return;
	}
	int row = zeroPoint[count].first;
	int column = zeroPoint[count].second;
	for (int i = 1; i <= 9; i++) {
		sudoku[row][column] = i;
		if (check(row,column)) {
			//cout << count << endl;
			//cout << row << ' ' << column << ' ' << sudoku[row][column] << '\n';
			fillSudoku(count + 1);
			if (found) return; // 최적해를 발견했으면 출력 후 종료
		}
	}
	sudoku[row][column] = 0; // 윗 단계로 돌아갈 경우 값 초기화
}
bool check(int row, int column) {
	// if row or column has same number return false
	for (int i = 0; i < 9; i++) {
		if (column != i) {
			if (sudoku[row][i] == sudoku[row][column]) return false;
		}
		if (row != i) {
			if (sudoku[row][column] == sudoku[i][column]) return false;
		}
	}
	int x = row / 3;
	int y = column / 3;

	// if square has same number return false
	for (int i = 3 * x; i < 3 * x + 3; i++) {
		for (int l = 3 * y; l < 3 * y + 3; l++) {
			if (i == row && l == column) continue;
			if (sudoku[row][column] == sudoku[i][l]) return false;
		}
	}
	/*
	for (int i = 0; i < 3; i++) {
		for (int l = 0; l < 3; l++) {
			if (3 * x + i == row && 3 * y + l == column) continue;
			if (sudoku[row][column] == sudoku[3 * x + i][3 * y + l]) return false;
		}
	}
	// 위 for문과 결과는 같지만 보기 좋지 않다.
	*/
	return true;
}




/*
 * 최적해를 찾지 못한 경우 되돌아가면서 값 초기화를 하지 않아 실패한 경우가 있었음.
 * 최적해가 여렷일 경우 하나만 출력한다. 부분을 무시하여 많이 틀렸음.
 */