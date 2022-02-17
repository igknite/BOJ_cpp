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
 * ������ ������ �Ű�Ἥ Ʋ�� ���.
 * �ӽ� ��갪(tmp)�� �ܰ踦 �ǵ��ƿ� ��(�����ڸ� �ٲٷ� ���ƿ� ��) ���� �ܰ�� �ǵ����� �۾��� ���� �ʾҴ�.
 * �� �ܰ迡�� �����ڸ� �����ϱ� ������ �ӽ� ���갪�� �����صΰ� ������ ���� ���� ���� �ǵ����� �ذ��ߴ�.
 */