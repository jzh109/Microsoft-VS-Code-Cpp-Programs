#include <iostream>
using namespace std;

class Complex
{
private:
    double Real;
    double Imag;

public:
    Complex(double, double);
    void SetReal(double);
    void SetImag(double);
    double GetReal();
    double GetImag();
    Complex operator+(Complex &);
    Complex operator*(Complex &);
};

Complex::Complex(double Real = 0, double Imag = 0)
{
    this->Imag = Imag;
    this->Real = Real;
}

void Complex::SetReal(double a)
{
    this->Real = a;
}

void Complex::SetImag(double b)
{
    this->Imag = b;
}

double Complex::GetReal()
{
    return this->Real;
}

double Complex::GetImag()
{
    return this->Imag;
}

Complex Complex::operator+(Complex &a)
{
    Complex res;
    res.SetReal(a.GetReal() + this->GetReal());
    res.SetImag(a.GetImag() + this->GetImag());
    return res;
}

Complex Complex::operator*(Complex &a)
{
    Complex res;
    res.SetReal(a.GetReal() * this->GetReal() - a.GetImag() * this->GetImag());
    res.SetImag(a.GetReal() * this->GetImag() + this->GetReal() * a.GetImag());
    return res;
}

int main(int argc, const char **argv)
{
    double a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Complex *a = new Complex(a1, b1);
    Complex *b = new Complex(a2, b2);
    Complex res;
    res = *a + *b;
    cout << res.GetReal() << " " << res.GetImag() << endl;
    res = (*a) * (*b);
    cout << res.GetReal() << " " << res.GetImag() << endl;
    return 0;
}