#include <iostream>

using namespace std;
int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int arr[31] = { 1, 0 };
    int n, m, num;
    cin >> num;
    for (int k = 0; k < num; k++) {
        cin >> n >> m;
        for (int i = 0; i <= m; i++) {
            arr[i] = 1;
            for (int j = i - 1; j > 0; j--) {
                arr[j] = (arr[j] + arr[j - 1]);
            }
        }
        // 11051���� n C k�� ȿ�������� ���ϴ� ��� ä��.
        // (m + (n + 1) - n -1) C (n + 1) - 1 = m C n
        cout << arr[n] << "\n";
    }
    return 0;
}