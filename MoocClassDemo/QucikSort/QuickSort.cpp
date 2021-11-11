#include <iostream>

using namespace std;


void quickSort(int nums[],int low,int high) {
	//��������
	if (low > high) {
		return;
	}

	int l = low;
	int r = high;
	int tmp = nums[l];
	while (l < r) {
		//��tmpΪ�磬��tmp��ķ��ұ�
		while (nums[r] > tmp&&l<r) {
			r--;
		}
		//��tmpΪ�磬��tmpС����ȵķ����
		while (nums[l] <= tmp&&l<r) {
			l++;
		}
		if (l < r) {
			swap(nums[l],nums[r]);
		}
	}
	swap(nums[low], nums[r]);
	//�ݹ�������
	quickSort(nums, low, l - 1);
	//�ݹ�������
	quickSort(nums, l + 1, high);
}

int main() {
	int nums[10] = { 2,1,4,7,6,9,3,0,5,10 };
	quickSort(nums, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;




	cin.get();
	return (0);
}