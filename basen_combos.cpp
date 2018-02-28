#include <iostream>
#include <string>
using namespace std;
/*
Complete the following program to print out all possible combinations 
of a given base and number of digits. E.g. ./bincombos With input 2 3 it should print out
000
001
010
011
100
101
110
111
*/
void basen_combos(int base, string prefix, int len) {
   // Code for base case (i.e. end of array)
   //   When do we know there are no more digits to show
   //   and what should we do if that is the case
   if(prefix.size()==len){
      cout<<prefix<<endl;
      return;
   }

   // Code for recursive case
   //   If we're not at the last digit, then set that
   //   digit location to each of its possible values and
   //   each time you change the value use recursion to 
   //   generate all the combinations of digits after it
   //   
   // Remember to make the char version of digit x, use '0'+x
   for (int i=0;i<base;++i){
      basen_combos(base, prefix+(char)('0'+i),len);
   }


}

int main() {
   // read target, n, then n sorted inputs
   int base, numDigits;
   cin >> base >> numDigits;

   // allocate an array to hold the current combo + null char
   string pre;
   
   // Call the function to generate all binary combos
   basen_combos(base, pre, numDigits);

   return 0;
}