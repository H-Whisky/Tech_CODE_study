/*
��һ���СΪn���������飬���㳤��Ϊk������������ֵ��
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

����˼·
��1��ʹ������ѭ������n������ǰk��Ԫ�ص��ܺͣ������ܺʹ洢�ڱ���window_sum�С�
��2����������Ӧ�û������ڼ������Ի���ֱ���ﵽ���ղ�ͬʱ׷�����͡�
��3��Ҫ���k��Ԫ�ؿ�ĵ�ǰ�ܺͣ�ֻ���ǰһ�����м�ȥ��һ��Ԫ�ز���ӵ�ǰ������һ��Ԫ�ؼ��ɡ�
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
