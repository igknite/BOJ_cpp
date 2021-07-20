#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int N;
	int a;
	cin >> N;
	vector<int> triple, tripleP1, tripleP2;
	for (int n = 0; n < N; n++) {
		cin >> a;
		if (a % 3 == 0) triple.push_back(a);
		else if (a % 3 == 1) tripleP1.push_back(a);
		else tripleP2.push_back(a);
	}
	int T1, T2, T3;
	T1 = tripleP1.size();
	T2 = tripleP2.size();
	T3 = triple.size();
	int t3back, t1back, t2back;
	if (T3 > N / 2 + N % 2) {
		cout << -1 << endl;
	}
	else if (T3 == 0 && T1 != 0 && T2 != 0){
		cout << -1 << endl;
	}
	else {
		while (T1) {
			if (triple.size() <= 1) break;
			t3back = triple.back();
			t1back = tripleP1.back();
			triple.pop_back();
			tripleP1.pop_back();
			cout << t3back << " " << t1back << " ";
			if (!tripleP1.size()) break;
		}
		if (tripleP1.size()) {
			for (int n = 0; n < tripleP1.size(); n++) {
				cout << tripleP1[n] << " ";
			}
		}
		while (T2) {
			if (!triple.size() || !tripleP2.size()) break;
			t3back = triple.back();
			t2back = tripleP2.back();
			triple.pop_back();
			tripleP2.pop_back();
			cout << t3back << " " << t2back << " ";
		}
		if (tripleP2.size()) {
			for (int n = 0; n < tripleP2.size() - 1; n++) {
				cout << tripleP2[n] << " ";
			}
			cout << tripleP2[tripleP2.size() - 1] << endl;
		}
		else if(triple.size()) cout << triple[0] << endl;
		
	}

	return 0;
}