// Implementation of queue
#include <iostream>
#include <string>

using namespace std;

struct node {
    int val;
    struct node *next;
};

class myQueue {
    
    private:
        node *first;
        node *last;
    public:
    myQueue(){
        first = NULL;
        last = NULL;
    }
    void push(int x){
        if(first == NULL){
            node* newNode= new node();
            newNode->val = x;
            first = newNode;
            last=first;
            return;
        }
        node* newNode = new node();
        newNode->val = x;
        last->next = newNode;
        last = newNode;
    }
    
    int pop(){
        int ret = first->val;
        first = first->next;
        return ret;
    }
   
};

int main()
{
    myQueue q;
    q.push(5);
    q.push(3);
    q.push(2);
    q.push(5);
    q.push(23);
    q.push(31);
    q.push(22);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
}
