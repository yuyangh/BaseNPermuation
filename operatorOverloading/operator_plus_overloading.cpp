#include <iostream>
using namespace std;

class Complex
{
 public:
  Complex() { real_ = 0; imag_ = 0; };
  Complex(double r, double i) { real_ = r; imag_ = i; }
  double getReal() const { return real_; }
  double getImag() const { return imag_; }

  Complex operator+(const Complex& b);
private:
  double real_;
  double imag_;
};

Complex Complex::operator+ (const Complex& b){
   return Complex(this->real_+b.real_,this->imag_+b.imag_);
}

int main()
{
  Complex c1(2,3);
  Complex c2(4,5);

  // Write a function to allow this to compile
  Complex c3 = c1 + c2;

  cout << c3.getReal() << "+" << c3.getImag() << "j" << endl;

  return 0;
}