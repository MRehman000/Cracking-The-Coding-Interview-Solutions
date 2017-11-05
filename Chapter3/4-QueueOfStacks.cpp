#include<iostream>
#include<stack>
using namespace std;
class Queue {
private:
	stack<int> in;
	stack<int> out;
public:
	void enqueue(int value){
		in.push(value);
	}
	int dequeue(){
		if(in.size() == 0){
			return -1;
		}
		while(!in.empty()){
			int item = in.top();
			in.pop();
			out.push(item);
		}
		int value = out.top();
		out.pop();
		while(!out.empty()){
			int item = out.top();
			out.pop();
			in.push(item);

		}
		return value;
	}

};

int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(34);
	q.enqueue(25);
	q.enqueue(14);
	q.enqueue(554);
	q.enqueue(42);
	q.enqueue(35);
	for(int i = 0; i < 12; i++){
		cout<<q.dequeue()<<endl;
	}
}