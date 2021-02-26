#include<iostream>
#include <algorithm>
using namespace std;

void quickSort(int nums[],int low, int high) {
	if (low > high) {
		return;
	}

	int l = low;
	int r = high;
	int tmp = nums[l];

	while (l<r) {
		while (nums[r] > tmp && l < r) {
			r--;
		}
		while (nums[l] <= tmp && l < r) {
			l++;
		}
		if (l < r) {
			swap(nums[l], nums[r]);
		}
	}

	swap(nums[low],nums[r]);
	quickSort(nums,low,l-1);
	quickSort(nums,l+1,high);
}

int main() {
	int nums[10] = { 4,5,2,64,12,6,2,22.41,432 };
	quickSort(nums, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;


	cin.get();
	return (0);
}