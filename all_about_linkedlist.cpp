#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data=d;
		next=NULL;
	}
};

void insertAtHead(Node* &head,int d){
	if(head==NULL){
		head=new Node(d);
		return;

	}	
	Node * n=new Node(d);
	n->next=head;
	head=n;
	return;
}
int lengthOfLinkedList(Node* head){
	int cnt=0;
	while(head){
		cnt++;
		head=head->next;
	}
	return cnt;
}
void insertAtTail(Node* &head,int d){
	// if no linked list exists
	if(head==NULL){
		head=new Node(d);
		return;
	}
	//go to the last node
	Node* tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=new Node(d);
	return;
}


void insertInMiddle(Node* &head,int d,int pos){
	//if pos=0
	if(head==NULL or pos==0){
		insertAtHead(head,d);
		return;
	}

	//if pos is greater than the length of linkedlist
	else if(lengthOfLinkedList(head)<pos){
		insertAtTail(head,d);
	}	
	else{
		//react the postion by taking pos-1 jumps
		int jump=1;
		Node* temp=head;
		while(jump<=pos-1){
			temp=temp->next;
			jump++;
		}
		//create a new node
		Node* n=new Node(d);
		n->next=temp->next;
		temp->next=n;
	}
}

void deleteHead(Node* &head){
	if(head==NULL) return;

	Node *temp=head->next;
	delete head;
	head=temp;
	return;
}
void deleteMiddle(Node* &head,int pos){
	if(head==NULL) return;
	else if(pos==0) deleteHead(head);
	else if(lengthOfLinkedList(head)<pos){
		return ;
	}
	else{
	Node *temp=head,*prev=NULL;
	int jump=1;
		while(jump<=pos){
			prev=temp;
			temp=temp->next;
			jump++;
		}

	prev->next=temp->next;
	delete temp;
	}
}

void deleteTail(Node* &head){
	Node* temp=head;
	if(temp->next==NULL) deleteHead(head);
	else{
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next=NULL;
		return;
	}
}

void print(Node* head){
	while(head){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node *head=NULL;	
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	
	print(head);

	insertInMiddle(head,4,3);
	insertAtTail(head,7);
	print(head);

	deleteHead(head);
	print(head);
	deleteMiddle(head,2);
	print(head);
	deleteTail(head);
	print(head);

	return 0;
}
