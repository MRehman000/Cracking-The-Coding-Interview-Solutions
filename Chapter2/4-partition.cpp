#include<iostream>
#include<unordered_set>
using namespace std;

struct node {
	int data;
	struct node *next;
};

node* partition(node* head, int n){
	node* slow = head;
	node* fast = head;
	while(slow != NULL){
		if (slow->data > n){
			while(fast != NULL){
				if(fast->data < n){
					int temp = slow->data;
					slow->data = fast->data;
					fast->data = temp;

				}
				fast = fast->next;
				}

		}
		slow = slow->next;
		fast = slow;
	}
	return head;
}



int main(){

	node* head = new node();
	head->data = 0;
	node* temp;
	//node* next;
	temp = head;

	for(int i = 1; i < 5; i++){
		node* new_data = new node();
		new_data->data = i;
		temp->next = new_data;
		temp = temp->next;
	}
	node* middle = new node();
	middle->data = 123232;
	temp->next = middle;
	temp = middle;
	for(int i = 3; i > 0; i--){
		node* new_data = new node();
		new_data->data = i;
		temp->next = new_data;
		temp = temp->next;
	}
	partition(head, 2);
	cout<<"Parition is done"<<endl;
	for (temp = head; temp != NULL; temp = temp->next){
		cout<<temp->data<<endl;
	}

	return 0;
}