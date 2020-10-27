#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
Node* first;
int n;
void init() {
	Node* p, * q=NULL;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			p = new Node;
			cin >> p->data;
			first->next = p;
			p->next = NULL;
			q = p;
		}
		else {
			p = new Node;
			cin >> p->data;
			q->next = p;
			p->next = NULL;
			q = p;
		}
	}
}

void deleteSame(){
	Node* p = first->next;
	int temp;
	while (p != NULL) {
		
		while(p->next!=NULL&&p->data == p->next->data) {
			p->next = p->next->next;
		}
		p = p->next;
	}
}
int main() {
	first = new Node;
	cin >> n;
	init();
	cout << "\n-----------\n";
	Node* p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n-----------\n";
	deleteSame();
	Node* q = first->next;
	while (q != NULL) {
		cout << q->data << " ";
		q =q->next;
	}


}