#include<iostream>
#include<vector>
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

	int isEmpty(){
		return top == NULL;
	}

};



class StackofStacks {
private:
	int current_stack = 0;
	const int MAX_SIZE = 10;
	int stack_index = 0;
	vector<Stack> stacks;

public:
	StackofStacks(){
		Stack s;
		stacks.push_back(s);

	}
	void push(int value){
		if(stack_index == 9){
			Stack s;
			s.push(value);
			stacks.push_back(s);
			stack_index = 1;
			current_stack++;
			//cout<<"created new stack"<<endl;
		}
		else{stacks[current_stack].push(value);
			stack_index++;
		}

	}

	int pop(){
		if(stack_index == 1){
			//cout<<"popping from empty"<<endl;
			stacks.pop_back();
			current_stack--;
			stack_index = 9;
			return stacks[current_stack].pop();
		}
		else {
			//cout<<"popping from full"<<endl;
			stack_index--;
			return stacks[current_stack].pop();
		}
	}

	

};


int main(){
	StackofStacks s;
	s.push(1);
	s.push(54);
	s.push(57);
	s.push(3454);
	s.push(223);
	s.pop();
	s.pop();
	s.push(1312);
	s.push(54);
	s.push(57);
	s.push(343);
	s.pop();
	
	s.push(223232);
	s.push(1);
	s.push(54);
	
	s.pop();
	s.push(57);
	s.push(7);
	s.pop();
	s.pop();
	s.push(6);
	s.push(5);
	s.push(4);
	s.pop();
	s.pop();
	s.push(3);
	s.push(2);
	s.push(1);
	cout<<"test1"<<endl;


	for (int i = 0; i < 19; i++){
		
		//cout<<"Min is "<<s.getMin()<<endl;
		cout<<"Popped element: "<<s.pop()<<endl;
	}
}

