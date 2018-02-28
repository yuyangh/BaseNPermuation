#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a list of prime factors generate all the products 
that can be made from any subset of the factors and return those products in a vector 
For example, given the prime factors:
2 3 7
there are $2^n$ subsets of these factors:
{ {}, {2}, {3}, {7}, {2,3}, {2,7}, {3,7}, {2,3,7} }
Which would yield the products:
{ 1, 2, 3, 7, 6, 14, 21, 42 }
Use recursion to help generate these products. 
Each recursive call should be responsible for 1 factor and choose to either:
Include it's factor and multiply it times the current product
Not include it's factor and just pass long the current product
*/
// add a helper function here if needed

//here is the code
void allNumProducts(const vector<int>& primes, int n, int product, vector<int>& result){
   if(n>=primes.size()){
      result.push_back(product);
   }else{
      allNumProducts(primes, n+1, product*primes[n], result) ;
      allNumProducts(primes, n+1, product*1, result) ;
   }
}

//here is the code
vector<int> allProducts(const vector<int>& primes) 
{

   vector<int> result;
   allNumProducts(primes, 0, 1,result);
   return result;
}


void sortAndPrint(vector<int> nums){
   sort(nums.begin(), nums.end());
   for(unsigned int i=0; i < nums.size(); i++){
      cout << nums[i] << " ";  
   }
   cout << endl;

}

int main(int argc, char* argv[]) {
   // Answers go in this vector
   vector<int> products;
   
   vector<int> primes1;
   products = allProducts(primes1);
   sortAndPrint(products);
   
   products.clear();
   vector<int> primes2;
   primes2.push_back(2); primes2.push_back(5);
   products = allProducts(primes2);
   sortAndPrint(products);

   products.clear();
   vector<int> primes3;
   primes3.push_back(2); primes3.push_back(3); primes3.push_back(7); 
   products = allProducts(primes3);
   sortAndPrint(products);

   products.clear();
   vector<int> primes4;
   primes4.push_back(2); primes4.push_back(3); primes4.push_back(5); primes4.push_back(11);
   products = allProducts(primes4);
   sortAndPrint(products);

   return 0;   
}