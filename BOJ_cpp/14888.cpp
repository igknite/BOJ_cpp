#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
vector<int> number(11, 0);
vector<int> symbol(4, 0);
int tmp;
int MAX = -1000000000;
int MIN = 1000000000;
void calc(int count);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> cnt;
	int num;
	for (int i = 0; i < cnt; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> symbol[i];
	}
	tmp = number[0];
	calc(1);

	cout << MAX << '\n' << MIN;
	return 0;
}

void calc(int count) {
	if (count == cnt) {
		//cout << "tmp : " << tmp << '\n';
		if (MIN > tmp) MIN = tmp;
		if (MAX < tmp) MAX = tmp;
	}
	for (int i = 0; i < 4; i++) {
		int tempNow = tmp;
		if (symbol[i] != 0) {
			switch (i) {
			case 0:
				tmp = tmp + number[count];
				break;
			case 1:
				tmp = tmp - number[count];
				break;
			case 2:
				tmp = tmp * number[count];
				break;
			case 3:
				tmp = tmp / number[count];
				break;
			default:
				cout << "ERROR";
				return;
			}
			symbol[i]--;
			calc(count + 1);
			symbol[i]++;
			tmp = tempNow; //**
		}
	}
}

/*
 * 연산자 갯수만 신경써서 틀린 경우.
 * 임시 계산값(tmp)가 단계를 되돌아올 때(연산자를 바꾸러 돌아올 때) 이전 단계로 되돌리는 작업을 하지 않았다.
 * 각 단계에서 연산자를 적용하기 이전에 임시 연산값을 저장해두고 연산자 변경 전에 값을 되돌려서 해결했다.
 */