#include<iostream>
#include<unordered_set>
using namespace std;

struct node {
	int data;
	struct node *next;
};

node* delMiddleNode(node* middle){
	node* next = middle->next;
	middle->data = next->data;
	middle->next = middle->next->next;
	return middle;
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
	node* middle = new node();
	middle->data = 123232;
	temp->next = middle;
	temp = middle;
	for(int i = 0; i < 5; i++){
		node* new_data = new node();
		new_data->data = 25*i;
		temp->next = new_data;
		temp = temp->next;}
	delMiddleNode(middle);
	cout<<"Deleted Middle Node"<<endl;
	for (temp = head; temp != NULL; temp = temp->next){
		cout<<temp->data<<endl;
	}

	return 0;
}