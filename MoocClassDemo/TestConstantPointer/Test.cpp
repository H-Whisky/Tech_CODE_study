#include <iostream>

using namespace std;

//output:4+6i
class complex {
public:
	int real;
	int imag;
	complex(int r = 0, int i = 0) {
		real = r;
		imag = i;

	}
};

complex add(complex& a, complex& b) {
	int r = a.real + b.real;
	int i = a.imag + b.imag;
	return complex(r, i);
}

int main() {
	complex x(1, 2), y(3, 4), z;
	z = add(x, y);
	cout << z.real << "+" << z.imag << "i" << endl;
}




/*
public static void main(String[] args) {
    StringBuffer sb = new StringBuffer();
    final int arr_row = 5;//行数(二维数组长度)
    final int arr_colum = 1;//列数


    int arr[][] = new int[arr_row][arr_colum];
    int sum[] = new int[arr_colum];
    int max,min = a[0][0];
    //创建二维数组
    for (int i = 0; i < arr.length; i++) {
        for (int j = 0; j < arr[i].length; j++) {
            int random_num = RandomUtils.nextInt(100);//随机数塞进数组
            arr[i][j] = random_num;
            sb.append(random_num).append("\t");
            sum[j] = sum[j] + random_num;
        }
        sb.append("\r\n");
    }
    //输出
    System.out.println("------------arr--------------");
    System.out.println(sb.toString());
    System.out.println("------------avg--------------");
    for (int i = 0; i < sum.length; i++) {
        System.out.print((float)sum[i] / arr_row + "\t");
    }
    System.out.println("------------sum--------------");
    System.out.print((float)sum[i] + "\t");
    System.out.println("------------maximum--------------");
    for (int i = 0; i < sum.length; i++) {
        for (int j = 0; j < sum.length; j++) {
            if (sum[i][j] > max) {
                max = sum[i][j];
            }
        }
    }
    System.out.println("" + max);
    System.out.println("------------minimum--------------");
    for (int i = 0; i < sum.length; i++) {
        for (int j = 0; j < sum.length; j++) {
            if (sum[i][j] < min) {
                min = sum[i][j];
            }
        }
    }
    System.out.println("" + min);
}
*/