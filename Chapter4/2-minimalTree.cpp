#include<iostream>
#include<vector>
using namespace std;


struct treeNode{
	struct treeNode* left;
	struct treeNode* right;
	int data;
};
treeNode* makeTreeHelper(vector<int> a, int left, int right  ){
	treeNode* root = new treeNode();
	treeNode* newNode = new treeNode();
	if(left < 0 || right < 0){
		return nullptr;
	}

	if(left == right){
		cout<<"Set a nodes data to "<<a[left]<<endl;
		newNode->data = a[left];
		return newNode;

	}

	if(left > right){
		// newNode->data = a[0];
		// treeNode* nextNode = new treeNode();
		// nextNode->data = a[1];
		// newNode->left = nextNode;
		// return newNode;
		return nullptr;
	}

	int start = left;
	int end = right;
	int mid = (left+right)/2;
	root->data = a[mid];
	cout<<"set root data to"<<root->data<<endl;
	root->left = makeTreeHelper(a,start,mid-1);
	root->right = makeTreeHelper(a,mid+1,end);

	return root;
}
treeNode* makeTree(vector<int> a){

	treeNode* root = new treeNode();
	return makeTreeHelper(a, 0,a.size()-1);

}



void inOrderTraversal(treeNode* root){
	if(root == NULL){
		return;
	}
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(7);
	treeNode* root;
	root = makeTree(a);
	cout<<"SuccessFull Make"<<endl;
	inOrderTraversal(root);
	cout<<"Successful Traversal"<<endl;

	return 0;

}