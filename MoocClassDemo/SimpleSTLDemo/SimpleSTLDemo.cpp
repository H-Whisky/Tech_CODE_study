#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <stack>
#include <queue>
using namespace std;

int main() {
	vector<int> vector1, vector2;
	list<int> list1, list2;
	deque<int> deque1, deque2;
	set<int> set1, set2;
	multiset<int> multiset1, multiset2;
	stack<int> stack1, stack2;
	queue<int> queue1, queue2;

	cout << "Vector: " << endl;
	vector1.push_back(1);
	vector1.push_back(2);
	vector2.push_back(30);
	cout << "size of vector1: " << vector1.size() << endl;
	cout << "size of vector2: " << vector2.size() << endl;
	cout << "maximum size of vector1: " << vector1.max_size() << endl;
	cout << "maximum size of vector2: " << vector2.max_size() << endl;
	vector1.swap(vector2);
	cout << "size of vector1: " << vector1.size() << endl;
	cout << "size of vector2: " << vector2.size() << endl;
	cout << "vector1 < vector2? " << (vector1 < vector2)<< endl<<endl;

	cout << "List: " << endl;
	list1.push_back(1);
	list1.push_back(2);
	list2.push_back(30);
	cout << "size of list1: " << list1.size() << endl;
	cout << "size of list2: " << list2.size() << endl;
	cout << "maximum size of list1: " << list1.max_size() << endl;
	cout << "maximum size of list2: " << list2.max_size() << endl;
	list1.swap(list2);
	cout << "size of list1: " << list1.size() << endl;
	cout << "size of list2: " << list2.size() << endl;
	cout << "list1 < list2? " << (list1 < list2) << endl<<endl;

	cout << "Deque: " << endl;
	deque1.push_back(1);
	deque1.push_back(2);
	deque2.push_back(30);
	cout << "size of deque1: " << deque1.size() << endl;
	cout << "size of deque2: " << deque2.size() << endl;
	cout << "maximum size of deque1: " << deque1.max_size() << endl;
	cout << "maximum size of deque2: " << deque2.max_size() << endl;
	deque1.swap(deque2);
	cout << "size of deque1: " << deque1.size() << endl;
	cout << "size of deque2: " << deque2.size() << endl;
	cout << "deque1 < deque2? " << (deque1 < deque2) << endl << endl;

	cout << "Set: " << endl;
	set1.insert(1);
	set1.insert(2);
	set2.insert(30);
	cout << "size of set1: " << set1.size() << endl;
	cout << "size of set2: " << set2.size() << endl;
	cout << "maximum size of set1: " << set1.max_size() << endl;
	cout << "maximum size of set2: " << set2.max_size() << endl;
	set1.swap(set2);
	cout << "size of set1: " << set1.size() << endl;
	cout << "size of set2: " << set2.size() << endl;
	cout << "set1 < set2? " << (set1 < set2) << endl << endl;

	cout << "Stack: " << endl;
	stack1.push(1);
	stack1.push(1);
	stack1.push(2);
	stack2.push(30);
	cout << "size of stack1: " << stack1.size() << endl;
	cout << "size of stack2: " << stack2.size() << endl;
	// stack1里面任意整数都比stack2里面元素小
	cout << "stack1 < stack2? " << (stack1 < stack2) << endl << endl;
}