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
    // i가 증가함에 따라 파스칼의 삼각형 i+1번째 줄이 완성된다.
    // n C k 란 결국 파스칼의 삼각형 n+1 번째 줄 k+1번째 숫자를 의미하므로 [k]를 읽어오면 완성.
    cout << arr[k];
    return 0;
}