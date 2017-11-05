#include<iostream>
#include<string>
#include<queue>
#include<assert.h>

using namespace std;


struct node{
	struct node* next;
	int data;
};


class Animal{
public:
	int age;
	int type;

	Animal(char c, int x){
		age = x;
		type = c;
	}
};

class Shelter{
private:
	queue<Animal> dogQueue;
	queue<Animal> catQueue;
	int current_age;
public:

	Shelter(){
		current_age = 0;
	}
	void enqueue(char c){
		Animal newAnimal(c, current_age);

		if (newAnimal.type == 'c')
			catQueue.push(newAnimal);
		if (newAnimal.type == 'd')
			dogQueue.push(newAnimal);
		current_age++;

	}
	Animal deQueueDog(){
		assert (!dogQueue.empty());

		Animal dog = dogQueue.front();
		dogQueue.pop();
		return dog;
		
	}

	Animal deQueueCat(){
		assert(!dogQueue.empty());

		Animal cat = catQueue.front();
		catQueue.pop();
		return cat;
	}

	Animal deQueueAny(){
		assert(!dogQueue.empty() || !catQueue.empty());
	    Animal newAnimal('c',0);
		if(dogQueue.empty())
			newAnimal = deQueueCat();
		if(catQueue.empty())
			newAnimal = deQueueDog();
		else{
			if(catQueue.front().age > dogQueue.front().age)
				newAnimal = deQueueCat();
			else
				newAnimal = deQueueDog();
		}
		return newAnimal;
	}

};

int main(){
	Shelter s;
	s.enqueue('c');
	s.enqueue('d');
	s.enqueue('d');
	s.enqueue('c');
	s.enqueue('c');
	s.enqueue('c');

	cout<<"Taking out a dog "<<s.deQueueDog().age<<endl;

}