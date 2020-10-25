#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
int n;
Node* first;
int a[20];

void init() {
	Node* q, * p=NULL;
	first = new Node;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			q = new Node;
			first->next = q;
			q->data = a[i];
			q->next = NULL;
			p = q;
		}
		else {
			q = new Node;
			q->data = a[i];
			q->next = NULL;
			p->next = q;		//上一个节点指向这个节点 
			p = q;  			//保存这个节点 
		}
	}
}

Node* In_reverseList(Node* H)
{
	if (H == NULL || H->next == NULL)       //链表为空直接返回，而H->next为空是递归基
		return H;
	Node* newHead = In_reverseList(H->next); //一直循环到链尾 
	H->next->next = H;                       //翻转链表的指向
	H->next = NULL;                          //记得赋值NULL，防止链表错乱
	return newHead;                          //新链表头永远指向的是原链表的链尾
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	init();
	Node* p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n-----------\n";
	p = In_reverseList(first);
	while (p != NULL&&p->next!=NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}
	
