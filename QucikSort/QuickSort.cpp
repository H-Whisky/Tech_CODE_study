#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int nums[], int low, int high) {
	//出口条件
	if (low > high) {
		return;
	}
	int l = low;
	int r = high;
	int tmp = nums[l];
	while (l < r) {
		//以tmp为界限，比tmp大，放左边
		while (nums[r] > tmp && l < r) {
			r--;
		}
		//以tmp为界限，比tmp小于等于的，放右边
		while (nums[l] <= tmp && l < r) {
			l++;
		}
		if (l < r) {
			swap(nums[l],nums[r]);
		}
	}

	swap(nums[low], nums[r]);
	//递归左序列
	quickSort(nums, low, l - 1);
	//递归右序列
	quickSort(nums, l + 1, high);
}


int main() {
	int nums[10] = { 6,7,3,8,2,1,59,32,44,22 };
	quickSort(nums, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	cin.get();
	return (0);
}