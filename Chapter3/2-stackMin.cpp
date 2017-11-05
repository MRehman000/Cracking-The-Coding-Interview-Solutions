#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};
class Stack{
private:
	node* top;
public:
	
	node* min;
	int pop(){
		if(top == NULL){
			return -1;
		}
		int item = top->data;
		top = top->next;
		if (item == min->data)
			min = min->next;
		return item;
	}
	void push(int value){
		if (top == NULL){
			node* newMin = new node();
			newMin->data = value;
			newMin ->next = min;
			min = newMin;
		}
		node* pushedNode = new node();
		pushedNode->data = value;
		pushedNode -> next = top;
		top = pushedNode;
		if (value < min->data){
			node* newMin = new node();
			newMin->data = value;
			newMin->next = min;
			min = newMin;
		}
	}

	int peek(){
		if (top == NULL)
			return -1;
		return top->data;

	}
	int getMin(){
		if (top == NULL)
			return -1;
		return min->data;
	}

};

int main(){
	Stack s;
	s.push(1);
	cout<<s.getMin()<<endl;
	s.push(54);
	cout<<s.getMin()<<endl;
	s.push(57);
	cout<<s.getMin()<<endl;
	s.push(3);
	cout<<s.getMin()<<endl;
	s.push(2);
	cout<<s.getMin()<<endl;


	for (int i = 0; i < 5; i++){
		
		cout<<"Min is "<<s.getMin()<<endl;
		cout<<"Popped element"<<s.pop()<<endl;
	}
}

