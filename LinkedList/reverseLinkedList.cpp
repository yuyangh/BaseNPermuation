#include <iostream>

using namespace std;

struct Item{
	int value;
	Item* next;
	Item(int val,Item* n):value(val),next(n){}
};

/*
change the direction of the Linked List
*/
Item* reverse(Item *head){
	Item* node=head;
	Item* prev=NULL;
	while(node!=NULL){
		Item* next=node->next;
		node->next=prev;
		prev=node;
		node=next;
	}
	return prev;
}
