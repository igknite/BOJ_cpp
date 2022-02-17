#include <iostream>
#include <vector>

using namespace std;
void test(vector<int>& arr);
void quickSort(vector<int> &arr, int start, int end);
void mergeSort(vector<int> &arr, int start, int end);
void merge(vector<int> &arr, int start, int mid, int end);
void insertionSort(vector<int> &arr);
vector<int> countingSort(vector<int> arr, int count);
void selectionSort(vector<int>& arr);

void main() {
	vector<int> a{ 5,1,3 , 3 , 7 , 6 , 2 , 1 , 4 };
	/*
	 * //counting sort 
	 * vector<int> a{ 5, 7, 1 , 3 , 7 , 6 , 2 , 1 , 4 };
	 * a = countingSort(a, 7);
	 */
	selectionSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	return;
}

void test(vector<int> &arr) {
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	return;
}

void selectionSort(vector<int>& arr) {
	int minIndex = 0;
	int temp = 0;
	for (int i = 0; i < arr.size(); i++) {
		minIndex = i;
		for (int l = i; l < arr.size(); l++) {
			if (arr[minIndex] > arr[l]) minIndex = l;
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void insertionSort(vector<int>& arr) {
	int tmp,i,j;
	for (i = 1; i < arr.size(); i++) {
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}
vector<int> countingSort(vector<int> arr, int count) {
	vector<int> sortArr(arr.size());
	vector<int> countArr(count + 1);
	for (int i = 0; i < arr.size(); i++) {
		countArr[arr[i]]++;
	}
	int tmp = 0;
	for (int i = 0; i < countArr.size(); i++) {
		tmp += countArr[i];
		countArr[i] = tmp;
	}
	for (int i = 0; i < arr.size(); i++) {
		sortArr[--countArr[arr[i]]] = arr[i];
	}
	return sortArr;
}

void mergeSort(vector<int> &arr, int start, int end) {
	if (end == start) return;
	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
	return;
}
void merge(vector<int>& arr, int start, int mid, int end) {
	vector<int> temp;
	int tmp = mid + 1;
	for (int i = start, l = mid + 1; i <= mid || l <= end;) {
		if (i > mid) {
			temp.push_back(arr[l++]);
			continue;
		}
		if (l > end) {
			temp.push_back(arr[i++]);
			continue;
		}
		if (arr[i] >= arr[l]) temp.push_back(arr[l++]);
		else temp.push_back(arr[i++]);
	}
	for (int n = 0; n < temp.size(); n++) {
		arr[n + start] = temp[n];
	}
	return;
}

void bubbleSort(vector<int> &arr) {
	int temp = 0;
	for (int n = 0; n < arr.size(); n++) {
		for (int m = n; m < arr.size(); m++) {
			if (arr[m] >= arr[m + 1]) {
				temp = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = temp;
			}
		}
	}
	return;
}

void quickSort(vector<int> &arr, int start, int end) {
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
