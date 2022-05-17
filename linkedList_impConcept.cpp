// middle of a linkedList
//Brute by first calculating the length of linked list and then mid by doing l/2
int middleLinkedListBrute(ListNode* head){
	ListNode* temp=head;
	int len=0;
	//calculate the length of the linked list
	while(temp!=NULL){
		temp=temp->next;
		len++;
	}
	//reinstanciate the temp to head
	temp=head;
	//calculate the middle elements postion in linkedlist
	int mid=len/2;
	//loop til the middle elements position
	while(mid){
		temp=temp->next;
		mid--;
	}
	return temp->data;
}

//Using slow and fast pointer
int middleLinkedListOptimal(ListNode* head){
	if(head==NULL || head->next==NULL) return head;

	ListNode* slow=head;
	ListNode* fast=head;

	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}

// ---------------------------------------------------------------------------------------------------------
// Reverse a linkedList
ListNode* reverseLinkedList(ListNode* head){
	ListNode* curr=head;
	ListNode* prev=NULL;
	ListNode* nxt;

	while(curr!=NULL){
		// Store the location of next postion in nxt Node
		nxt=curr->next;
		// point the next of current to the prev node which is initialy NULL
		curr->next=prev;
		//Increment the curr and the prev 
		prev=curr;
		curr=nxt;
	}
	//return the new head of the reversed linkedLise that will be the prev
	return prev;
}
