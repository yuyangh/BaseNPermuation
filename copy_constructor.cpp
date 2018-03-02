#include <iostream>
using namespace std;

class MyArray
{
 public:
  MyArray() { cout << "In default constructor" << endl;
              dat = NULL; len = 0; }
  MyArray(int d[], int num); //normal
   MyArray(const MyArray& other);  
  ~MyArray();
  int& operator[](int loc) { return dat[loc]; }
  int const & operator[](int loc) const { return dat[loc]; }
  int size() const         { return len;      }
 private:
  int len; int *dat;

};

// Normal constructor
MyArray::MyArray(int d[], int num)
{
  dat = new int[num]; len = num;
  for(int i=0; i < len; i++){
    dat[i] = d[i];
  }
}

// Copy Constructor
 MyArray::MyArray(const MyArray& other)  
{
   cout << "In copy constructor" << endl;
    len = other.len;
    dat = new int[len];
    for(int i=0; i < len; i++){
       dat[i] = other.dat[i];   
    }
}

MyArray::~MyArray()
{  
 cout << "In destructor" << endl;
 delete [] dat; 
}

void printVals(const MyArray& arr)
 
{
  for(int i=0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int vals[] = {9,3,7,5};
  MyArray a1(vals,4);
  MyArray a2(a1); // calls copy constructor
  MyArray a3 = a1; // calls copy constructor
  MyArray a4;  
  a4 = a1; // calls default assignment
  
  // how are the contents of a2, a3, a4
  // related to a1
  printVals(a1);
  a1[0] = 11;
  printVals(a2);
  printVals(a4);
   
  return 0;
}