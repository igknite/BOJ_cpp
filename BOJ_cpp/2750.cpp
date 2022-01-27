#include <iostream>
#include <vector>

using namespace std;
void quickSort(vector<int>& arr, int start, int end);
void main() {
	int n = 0;
	cin >> n;
	vector<int> vec(n, 0);
	for (int a = 0; a < n; a++) {
		cin >> vec[a];
	}
	quickSort(vec, 0, vec.size() - 1);

	for (int a = 0; a < n; a++) {
		cout << vec[a] << endl;
	}
	return;
}
void quickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return; // 길이가 1 이하이면 sort 완료로 간주, 반환함.
	// determine pivot
	int pivot = arr[start];
	int low = start + 1;
	int high = end;
	// left-right shake
	int temp = 0;
	while (low <= high) {
		if (pivot >= arr[low]) {
			low++;
			continue;
		}
		if (pivot < arr[high]) {
			high--;
			continue;
		}
		temp = arr[low];
		arr[low++] = arr[high];
		arr[high--] = temp;
	}
	//pivot move
	temp = arr[start];
	arr[start] = arr[high];
	arr[high] = temp;

	// left side sort
	quickSort(arr, start, high - 1);
	// right side sort
	quickSort(arr, low, end);
	return;
}
