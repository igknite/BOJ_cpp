#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
bool desc(int a, int b);
int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end(), desc);
	cout << s;
	return 0;
}
bool desc(int a, int b) {
	return a > b;
}