#include "hashtable.h"
#include <iostream>

using namespace std;

#define A 54059 
#define B 76963 
#define C 86969 

/**
Hash function for the CS104 hash table.

@param s c-string to hash
@return unsigned int value hashed from the input
*/
unsigned hash_str(const char* s)
{
   unsigned h = 31;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h % C; 
}

/**
Creates a hash table of the given input size. Creates the array and vectors used for the hash table.

@param size The size of the hash table.
*/
HashTable::HashTable(int size) {
	this->size = size;
	data = new vector<string>*[size];

	for(int i = 0; i < size; i++) {
		data[i] = new vector<string>;
	}
}

/**
Deletes the vectors and array used for the hash table.
*/
HashTable::~HashTable() {
	for(int i = 0; i < size; i++) {
		delete data[i];
	}
	delete [] data;
}

/**
Doxygen comments here!

Insert should do nothing if the name already exists in the hash table.
 @param name string, The content of insertion
*/
void HashTable::insert(string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	// TODO
	if(!find(name)){
		data[hash]->push_back(name);
	}
}

/**
Doxygen comments here!

Find should return true if the name exists in the hash table.
 @param name string, The content for looking up
 @return bool value for whether the string is find or not
*/
bool HashTable::find(string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	// TODO
	for (auto &&item : *data[hash]) {
		if(item==name)
			return true;
	}
	return false;
}

/**
Doxygen comments here!

Remove should do nothing if the name does not exist in the hash table.
@param name string, the content to delete from the hashtable
*/
void HashTable::remove(string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	// TODO
    if(find(name)){
        for (int index = 0; index <data[hash]->size() ; ++index) {
            if(name==(*data[hash])[index])
                data[hash]->erase(data[hash]->begin()+index);
        }
    }
}
