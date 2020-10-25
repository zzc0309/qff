#include<string.h>
#include<map>
#include<iomanip>
#include<stack>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#define updiv(a,b) ((a)/(b)+(((a)%(b))!=0))
typedef long long ll;

using namespace std;
const double eps = 1e-8;
const int N=500;

struct Node{
	int data;
	Node *next;
};
int n;
Node *first;
int a[N];


void init(){
	Node *q,*p;
	first=new Node;
	
	for(int i=0;i<n;i++){
		if(i==0){
		q=new Node;
		first->next=q;
		q->data=a[i];
		q->next=NULL;
		p=q;
	}else{
		q=new Node;
		q->data=a[i];
		q->next=NULL;
		p->next=q;		//上一个节点指向这个节点 
		p=q;  			//保存这个节点 
	}
	}
	
	cout<<"未逆置之前的:"; 
	Node *x=first->next;
	while(x!=NULL){
		cout<<x->data<<"\t";
		x=x->next;
	}
	cout<<endl;
}

int fun(){
	if(first->next==NULL)
	{
		return 0;
	}
	Node *p=first->next,*newfirst=NULL;
	
	while(p!=NULL)
	{
		Node* temp=p->next;
		p->next=newfirst;
		newfirst=p;
		p=temp;
	}
	first=newfirst;
	return 0;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	init();
	fun();
	Node *p=first;
	cout<<"逆置之后的:";
	while(p!=NULL){
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<endl;
}
