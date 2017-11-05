#include<iostream>
#include<stack>

using namespace std;

stack<int> sortStack(stack<int> s){
	stack<int> copyStack;
	while(!s.empty()){
		int value = s.top();
		s.pop();
	
			while(!copyStack.empty() && value < copyStack.top())
			{
				int item = copyStack.top();
				copyStack.pop();
				s.push(item);
			}
			copyStack.push(value);
		
	}

	return copyStack;
}

int main(){
	stack<int> s;

	s.push(11);
	s.push(54);
	s.push(57);
	s.push(3454);
	s.push(223);
	s.push(6);
	s.push(5);
	s.push(42121);
	stack<int> sorted = sortStack(s);
	cout<<"sort Successful"<<endl;
	for(int i = 0; i < 8; i++){
		cout<<sorted.top()<<endl;
		sorted.pop();
	}
}