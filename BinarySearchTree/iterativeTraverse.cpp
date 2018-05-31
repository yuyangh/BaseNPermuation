#include <iostream>
#include <stack>

using namespace std;
struct Item{
	int value;
	Item* left;
	Item* right;
	Item(int val,Item* l, Item* r):value(val),left(l),right(r){}
};


void preorderIterative(Item* root){
	if(root==NULL){
		return;
	}
	stack<Item*> s;
	s.push(root);
	while(!s.empty()){
		Item* node=s.top();
		cout<<node->value<<endl;
		s.pop();
		if(node->right!=NULL){
			s.push(node->right);
		}
		if(node->left!=NULL){
			s.push(node->left);
		}
	}
}