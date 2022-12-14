#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator;
    int denominator;
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

public:
    Fraction()
    {
        this->numerator = 0;
        this->denominator = 0;
    }
    Fraction(int n, int d)
    {
        if (denominator == 0)
        {
            throw 404;
        }
        this->numerator = n;
        this->denominator = d;
    }
    int getNumerator()
    {
        return this->numerator;
    }
    int getDenominator()
    {
        return this->denominator;
    }
    void setDenominator(int denom)
    {
        if (denom == 0)
        {
            throw 404;
        }
        this->denominator = denom;
    }
    void lowestForm()
    {
        int commonfactor = gcd(numerator, denominator);
        numerator /= commonfactor;
        denominator /= commonfactor;
    }
    double Decimalvalue()
    {
        return static_cast<double>((numerator) / (denominator));
    }
    Fraction operator+(Fraction &other)
    {
        int newnumerator = numerator * other.denominator + other.numerator * denominator;
        int newdenominator = denominator * other.denominator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator-(Fraction &other)
    {
        int newnumerator = numerator * other.numerator;
        int newdenominator = denominator * other.denominator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator*(Fraction &other)
    {
        int newnumerator = numerator * other.denominator - other.numerator * denominator;
        int newdenominator = denominator * other.denominator;
        return Fraction(newnumerator, newdenominator);
    }
    Fraction operator/(Fraction &other)
    {
        int newnumerator = numerator * other.denominator;
        int newdenominator = denominator * other.numerator;
        return Fraction(newnumerator, newdenominator);
    }
    bool operator==(Fraction &other)
    {
        return (numerator * other.denominator == other.numerator * denominator);
    }
    bool operator!=(Fraction &other)
    {
        return !(*this == other);
    }
    bool operator<(Fraction &other)
    {
        return (numerator * other.denominator < other.numerator * denominator);
    }
    bool operator>(Fraction &other)
    {
        return (numerator * other.denominator > other.numerator * denominator);
    }
    void acceptValue()
    {
        cout << "Enter Numerator:" << endl;
        cin >> numerator;
        cout << "Enter Denominator:" << endl;
        cin >> denominator;
    }
    void PrintFraction()
    {
        cout << "Numerator :" << numerator << endl
             << "Denominator" << denominator << endl;
    }
};
int main()
{
    Fraction f1, f2, sum, sub, mult, quotient;
    while (true)
    {
        cout << "***Menu***" << endl;
        cout << "1.Accept Value" << endl;
        cout << "2.Print Value " << endl;
        cout << "3.Addition Of Fraction" << endl;
        cout << "4.subtraction Of Fraction" << endl;
        cout << "5. Multiplication Of Fraction" << endl;
        cout << "6.Quotient Of Fraction " << endl;
        cout << "7. Check wether Fraction Value Equal" << endl;
        cout << "8. Check wether Fraction  Value Not Equal" << endl;
        cout << "9. Check wether Fraction 1st Lesser than 2nd " << endl;
        cout << "10. Check wether Fraction 1st Greater than 2nd " << endl;
        cout << "11.Set Denominator" << endl;
        cout << "12.Set Numerator" << endl;
        cout << "13.EXIT" << endl;
        cout << "Enter the choice" << endl;
        int choice;
        int value;
        cin >> choice;
        switch (choice)
        {
        case 1:
            f1.acceptValue();
            f2.acceptValue();
            break;
        case 2:
            f1.PrintFraction();
            f2.PrintFraction();
            break;
        case 3:
            sum = f1 + f2;
            cout << "F1 + F2 =" << sum.getNumerator() << "/" << sum.getDenominator() << " or" << sum.Decimalvalue();
            break;
        case 4:
            sub = f1 - f2;
            cout << "F1 - F2 =" << sub.getNumerator() << "/" << sub.getDenominator() << " or" << sub.Decimalvalue();
            break;
        case 5:
            mult = f1 * f2;
            cout << "F1 * F2 =" << mult.getNumerator() << "/" << mult.getDenominator() << " or" << mult.Decimalvalue();
            break;
        case 6:
            quotient = f1 / f2;
            cout << "F1 / F2 =" << quotient.getNumerator() << "/" << quotient.getDenominator() << " or" << quotient.Decimalvalue();
            break;
        case 7:
            cout << "fraction 1 And Fraction 2 are equal " << ((f1 == f2) ? "yes" : "no") << endl;
            break;
        case 8:
            cout << "fraction 1 And Fraction 2 are not equal " << ((f1 != f2) ? "yes" : "no") << endl;
            break;
        case 9:
            cout << " Fraction 1 Lesser than Fraction 2" << ((f1 < f2) ? "yes" : "no") << endl;
            break;
        case 10:
            cout << " Fraction 1 Greater than Fraction 2" << ((f1 < f2) ? "yes" : "no") << endl;
            break;
        case 11:
            cout << " Enter Denominatir" << endl;
            cin >> value;
            try
            {
                f1.setDenominator(value);
            }
            catch (const int error)
            {
                cout << "Denominator Should Not Be Zero" << endl;
            }
            break;
        case 12:
            cout << " Enter Numerator" << endl;
            cin >> value;
            break;
        case 13:
            cout << " You Are Exiting " << endl;
            return 0;
        default:
            cout << " Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}