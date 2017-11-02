#include<iostream>
#include<unordered_set>
using namespace std;

struct node {
	int data;
	struct node *next;
};

node* removeDups(node* head){
	node* ptr = head;
	node* prev = NULL;
	unordered_set<int> dups;
	while(ptr != NULL){
		if (dups.find(ptr->data) != dups.end()){

			prev->next = ptr->next;
		}
		else{
		dups.insert(ptr->data);
		prev = ptr;
		}
		ptr = prev->next;
	}
	return head;
}

int main(){

	node* head = new node();
	head->data = 5;
	node* temp;
	//node* next;
	temp = head;

	for(int i = 0; i < 10; i++){
		node* new_data = new node();
		new_data->data = 25*(i%3);
		temp->next = new_data;
		temp = temp->next;
	}
	removeDups(head);
	for (temp = head; temp != NULL; temp = temp->next){
		cout<<temp->data<<endl;
	}

	return 0;
}