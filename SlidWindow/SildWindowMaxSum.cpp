/*
给一组大小为n的整数数组，计算长度为k的子数组的最大值。
Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23} of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole array is 2.

解题思路
（1）使用线性循环计算n个项中前k个元素的总和，并将总和存储在变量window_sum中。
（2）在阵列上应用滑动窗口技术线性滑动直至达到最终并同时追踪最大和。
（3）要获得k个元素块的当前总和，只需从前一个块中减去第一个元素并添加当前块的最后一个元素即可。
*/

#include <iostream>
using namespace std;


int maxSum(int arr[], int n, int k) {
    if(n < k) {
        cout << "Invaild";
        return -1;
    }
    int max_sum = 0;
    for (int i = 0; i < k; i++) {
        max_sum += arr[i];
    }
    int windows_sum = max_sum;
    for (int i = k; i < n; i++) {
        windows_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, windows_sum);
    }
    return max_sum;
}


int main() {
    //1
    int arr[4] = { 100,200,300,400 };
    int k = 2;
    int result = maxSum(arr,sizeof(arr)/sizeof(int),k);
    cout << result << endl;
    //2
    int arr1[9] = { 1, 4, 2, 10, 23, 3, 1, 0, 20 };
    k = 4;
    result = maxSum(arr1, sizeof(arr1) / sizeof(int), k);
    cout << result << endl;
    //3
    int arr2[2] = { 2,3 };
    k = 3;
    result = maxSum(arr2, sizeof(arr2) / sizeof(int), k);
    cout << result << endl;

	cin.get();
	return (0);
}
