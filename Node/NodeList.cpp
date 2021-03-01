/*
        链表是一种动态数据结构，
		他的特点是用一组任意的存储单元（可以是连续的，也可以是不连续的）
		存放数据元素。链表中每一个元素成为“结点”，
		每一个结点都是由数据域和指针域组成的，每个结点中的指针域指向下一个结点。
		Head是“头指针”，表示链表的开始，用来指向第一个结点，
		而最后一个指针的指针域为NULL(空地址)，表示链表的结束。
		可以看出链表结构必须利用指针才能实现，即一个结点中必须包含一个指针变量，
		用来存放下一个结点的地址。实际上，
		链表中的每个结点可以用若干个数据和若干个指针。
		结点中只有一个指针的链表称为单链表，这是最简单的链表结构。
		再c++中实现一个单链表结构比较简单。
======================================================
怎么理解链表
看有个人写的很好，就是说你现在有一个小纸条，
上面写着一个抽屉的地址，
那个抽屉里有一些你需要的东西，
和一个新的写着地址的小纸条，这个小纸条又指向了一个新的抽屉，
大体可以这么理解
=======================================================
*/

#include <iostream>
#include <cstdlib>//随机顺序的链表
#include <string>
using namespace std;

//FIRST
//对数据进行封装
typedef struct data {
	int nubmber;
	char name[20];
	char sex[20];
}data;
//构建抽屉
typedef struct listPoint {
	//存的数据
	struct::data* information;
	//指向下一个节点的指针
	listPoint* next;
	//指向上一个节点的指针
	listPoint* last;
	listPoint* branch;
}listPoint;

//SECOND
//1.创建一个基础链表
//链表每一个节点都是指向listPoint结构的指针，所以返回值是listPoint *,n是指创建的链表的节点数目
listPoint *create_normal_list(int n) {
	listPoint *head, *normal, *end;//创建头节点，其他节点和尾节点
	head = (listPoint*)malloc(sizeof(listPoint));
	head->information = (struct::data*)malloc(sizeof(struct::data));
	//分配内存
	end = head;//最开始最后一个节点就是头节点
	for (int i = 0; i < n; i++) {
		normal = (listPoint*)malloc(sizeof(listPoint));
		normal->information = (struct::data*)malloc(sizeof(struct::data));
		cout << "input the number: ";
		cin >> normal->information->nubmber;
		cout << "input the name: ";
		cin >> normal->information->name;
		cout << "input the sex: ";
		cin >> normal->information->sex;
		cout << "------------------------------------" << endl;
		//往新节点存入数据，注意我们只给后面的节点存入数据，head不存数据
		end->next = normal;//往end后增添新节点
		normal->last = end;//新节点的上一个节点就是end
		end = normal;//最后一个节点变成新节点
	}
	end->next = NULL;//链表的最后指向一个新地址
	head->last = NULL;//链表最开始的节点没有上一个节点
	return head;
}
//2.创建环状链表
listPoint* create_loop_list(int n) {
	listPoint* head, * normal, * end;
	head = (listPoint*)malloc(sizeof(listPoint));
	head->information = (struct::data*)malloc(sizeof(struct::data));
	end = head;
	for (int i = 0; i < n; i++) {
		normal = (listPoint*)malloc(sizeof(listPoint));
		normal->information = (struct::data*)malloc(sizeof(struct::data));
		cout << "input the number: ";
		cin >> normal->information->nubmber;
		cout << "input the name: ";
		cin >> normal->information->name;
		cout << "input the sex: ";
		cin >> normal->information->sex;
		cout << "------------------------------------" << endl;
		//往新节点存入数据，注意我们只给后面的节点存入数据，head不存数据
		end->next = normal;//往end后增添新节点
		normal->last = end;//新节点的上一个节点就是end
		end = normal;//最后一个节点变成新节点
	}
	end->next = head;
	head->last = end;
	return head;
}
//3.创建随机枝杈链表
/*
每一个节点都有一个分支指向随机一个节点，
这时候我们就要引入ctime库用来使用srand((int)(time(NULL)));
以生成随机数，这里还用到了后面的一个函数
listpoint *search_point(listpoint *list,int n);
是用来搜索节点的
*/
listPoint* create_random_branch_list(int n) {
	listPoint* search_point(listPoint * list, int n);
	listPoint* head;
	head = create_normal_list(n);
	listPoint* p, * bp;
	p = head;
	srand((int)(time(NULL)));
	int rand_num;
	while ((p = p->next) != NULL) {
		rand_num = rand() % n + 1;
		bp = search_point(head, rand_num);
		p->branch = bp;
	}
	return head;
}



//THIRD
//增删改查的方法
void change_point(listPoint* list, int n, struct::data* infomation) {
	listPoint* p;
	p = list;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	p->information = infomation;
}

void delete_point(listPoint* list, int n) {
	listPoint* p;
	p = list;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	p->last->next = p->next;
	p->next->last = p->last;
	free(p);
}

void insert_point(listPoint* list, int n, struct::data* information) {
	listPoint* p;
	p = list;
	for (int i = 0; i < n - 1; i++) {
		p = p->next;
	}
	listPoint* insertpoint;
	insertpoint = (listPoint*)malloc(sizeof(listPoint));
	insertpoint->information = information;
	insertpoint->next = p->next;
	p->next->last = insertpoint;
	p->next = insertpoint;
	insertpoint->last = p;
}

listPoint* search_point(listPoint* list, int n) {
	listPoint* p;
	p = list;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	return p;
}


//FORTH
void output_point(listPoint* point) {
	cout << "the number is: " << point->information->nubmber << endl;
	cout << "the name is: " << point->information->name<< endl;
	cout << "the sex is: " << point->information->sex<< endl;
	cout << "------------------------------------"<< endl;
	
}

void output_list(listPoint* point) {
	listPoint* p;
	p = point;
	cout << endl << endl<<endl;
	while ((p=p->next)!=NULL) {
		output_point(p);
	}
}

void output_list_part(listPoint* list, int m, int n) {
	int difference = n - m;
	listPoint* p;
	p = list;
	cout << endl << endl << endl;
	for (int i = 0; i < m; i++) {
		p = p->next;
	}
	for (int i = 0; i < difference + 1; i++) {
		output_point(p);
		p = p->next;
	}
}

//FIVTH
int main() {
	listPoint* head1;
	listPoint* head2;
	listPoint* head3;
	//head1 = create_normal_list(5);
	//head2 = create_loop_list(5);
	head3 = create_random_branch_list(3);
	output_list(head3);
	cin.get();
	return (0);
}