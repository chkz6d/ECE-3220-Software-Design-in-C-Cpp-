#include <iostream>

using namespace std;

class Complex{
    private :
        double real, imag; //real and imaginary part of complex number
    public :
        Complex (): real (0.0), imag(0.0) //Default Constructor
        {}
        Complex (const double r, const double i): real (r), imag (i)
        {}
        ~Complex() //Destructor
        {}
        /*
         * NB: additional function declarations go in here!
         */
        friend Complex operator + (const Complex a,const Complex b);
        friend Complex operator - (const Complex a,const Complex b);
        friend istream& operator >> (istream& a, Complex& b);
        friend ostream& operator << (ostream& a, Complex& b);
};

Complex operator + (const Complex a,const Complex b) // Operation overload for +
{
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    
    return c;
}

Complex operator - (const Complex a,const Complex b) // Operation overload for -
{
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    
    return c;
}

istream& operator >> (istream& a, Complex& b) // Operation overload for input
{
    a >> b.real;
    a >> b.imag;
    
    return a;
}

ostream& operator << (ostream& a, Complex& b) // Operation overload for output
{
    if(b.imag >= 0)
    {
        a << b.real << " + " << b.imag << "i" << endl;
    }
    else
    {
        a << b.real << " " << b.imag << "i" << endl;
    }
    
    return a;
}
int main()
{
    Complex num1,num2; 
    Complex result;
    
    cin >> num1;
    cin >> num2;
    
    result = num1 + num2;
    
    cout << num1;
    cout << num2;
    cout << result << endl;
    
    cin >> num1;
    cin >> num2;
    
    result = num1 - num2;
    
    cout << num1;
    cout << num2;
    cout << result;
    
    return 0;
}

