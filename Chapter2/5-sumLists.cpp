#include<iostream>
#include<unordered_set>
using namespace std;

struct node {
	int data;
	struct node *next;
};


node* addLists(node* L1, node* L2){
	node* head = new node();
	node* sum = head; int carry = 0;
	while(L1 != NULL || L2 != NULL){
		cout<<"in while loop"<<endl;
		int digit = L1->data + L2->data + carry;
		sum->data = digit % 10;
		if (digit > 9){
			carry = 1;
		}
		else carry = 0;
		node* next_digit = new node();
		sum->next = next_digit;
		sum = sum->next;
		L1=L1->next;
		L2=L2->next;
	}
	

	return head;
}

int main(){
	node* L1 = new node();
	L1->data = 5;
	node* temp;
	temp = L1;

	for(int i = 1; i < 3; i++){
		node* new_data = new node();
		new_data->data = 2*i;
		cout<<new_data->data<<endl;
		temp->next = new_data;
		temp = temp->next;
	}

	node* L2 = new node();
	L2->data = 5;
	//node* temp;
	temp = L2;

	for(int i = 1; i < 3; i++){
		node* new_data = new node();
		new_data->data = 1*i;
		cout<<new_data->data<<endl;
		temp->next = new_data;
		temp = temp->next;
	}
	node* head = addLists(L1,L2);
	for(node* temp = head; temp->next != NULL; temp= temp->next){
		cout<<temp->data<<endl;
	}
	//return -1; 
}