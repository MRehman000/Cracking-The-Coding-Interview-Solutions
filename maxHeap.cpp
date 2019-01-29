// Max Heap 
#include <iostream>
#include <string>
#include<queue>
using namespace std;

struct item {
    int val;
    int priority;
};


class myHeap
{
private:
    vector<int> heap;
    int size = 0;
public:
    myHeap() : heap(20){}
  void insert (int x)
  {
    heap[size] = x;
    bubbleUp();
    size++;
  }
  
  int getMax(){
      return heap.front();
  }
  
  void removeMax(){
    heap[0] = heap[size-1];
    size--;
    bubbleDown();
  }
  
  void bubbleUp(){
      int i = size;
      while(heap[i] > heap[parentIndex(i)]){
          swap(i, parentIndex(i));
          i = parentIndex(i);
      }
  }
  
  void bubbleDown(){
      int i = 0;
      while((heap[i] < heap[leftIndex(i)]) || (heap[i] < heap[rightIndex(i)])){
          if(heap[leftIndex(i)] > heap[rightIndex(i)]){
              swap(i,leftIndex(i));
              i = leftIndex(i);
          }
          else{
              swap(i,rightIndex(i));
              i = rightIndex(i);
          }
      }
  }
  
  int leftIndex(int i){
      return i*2+1;
  }
  
  int rightIndex(int i){
      return i*2+2;
  }
  
  int parentIndex(int i){
      return (i-1)/2;
  }
  
  void swap(int first, int second){
      int temp = heap[first];
      heap[first] = heap[second];
      heap[second] = temp;
  }
  
  void display(){
      for(int i = 0; i < size; i++){
          cout<<heap[i]<<" ";
      }
  }

};

int
main ()
{
    myHeap h;
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(4);
    h.insert(13);
    h.insert(23);
    h.insert(6);
    h.insert(9);
    h.insert(10);
    h.removeMax();
    h.removeMax();
    h.removeMax();
    cout<<h.getMax()<<endl;
    h.display();
        
    
}
