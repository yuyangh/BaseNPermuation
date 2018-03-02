#include <iostream>
using namespace std;

class Complex
{
 public:
  Complex() { real_ = 0; imag_ = 0; };
  Complex(double r, double i) { real_ = r; imag_ = i; }
  double getReal() const { return real_; }
  double getImag() const { return imag_; }
  Complex operator+(const Complex& rhs) const;
  Complex operator+(int r) const;   
  friend Complex operator+(int lhs, const Complex& rhs); 
   friend ostream& operator<< (ostream& out, const Complex& c);
 private:
  double real_;
  double imag_;
};

   
ostream& operator<< (ostream& out, const Complex& c){
   out<<c.getReal()<<"+"<<c.getImag()<<"j";
   return out;
}

   
int main()
{
  Complex c1(2,3);
  Complex c2(4,5);
   
  // Translates to: 
  //  cout.operator<<(c1).operator<<(" and ").operator<<(c2)...
  cout << c1 << " and " << c2 << endl;

  return 0;
}