#include<iostream>
#include<unordered_set>
using namespace std;

struct node {
	int data;
	struct node *next;
};

node* kthToLast(node* head, int k){
	node* fast = head;
	node* slow = head;

	for(int i = 0; i < k; i++){
		fast = fast->next;
	}
	while(fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


int main(){

	node* head = new node();
	head->data = 5;
	node* temp;
	//node* next;
	temp = head;

	for(int i = 0; i < 10; i++){
		node* new_data = new node();
		new_data->data = 25*i;
		temp->next = new_data;
		temp = temp->next;
	}
	cout<<"kthToLast is "<<kthToLast(head,3)->data<<endl;
	for (temp = head; temp != NULL; temp = temp->next){
		cout<<temp->data<<endl;
	}

	return 0;
}