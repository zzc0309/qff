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
			p->next = q;		//��һ���ڵ�ָ������ڵ� 
			p = q;  			//��������ڵ� 
		}
	}
}

Node* In_reverseList(Node* H)
{
	if (H == NULL || H->next == NULL)       //����Ϊ��ֱ�ӷ��أ���H->nextΪ���ǵݹ��
		return H;
	Node* newHead = In_reverseList(H->next); //һֱѭ������β 
	H->next->next = H;                       //��ת�����ָ��
	H->next = NULL;                          //�ǵø�ֵNULL����ֹ�������
	return newHead;                          //������ͷ��Զָ�����ԭ�������β
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
	
