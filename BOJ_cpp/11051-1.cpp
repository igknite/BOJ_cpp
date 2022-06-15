#include <iostream>

using namespace std;
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int arr[1001] = { 1, 0 };
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        arr[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            arr[j] = (arr[j] + arr[j - 1]) % 10007;
        }
    }
    // i�� �����Կ� ���� �Ľ�Į�� �ﰢ�� i+1��° ���� �ϼ��ȴ�.
    // n C k �� �ᱹ �Ľ�Į�� �ﰢ�� n+1 ��° �� k+1��° ���ڸ� �ǹ��ϹǷ� [k]�� �о���� �ϼ�.
    cout << arr[k];
    return 0;
}