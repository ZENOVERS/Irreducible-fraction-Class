#include <iostream>

using namespace std;


int findGCD(int x, int y);

class Fraction {
public:
	Fraction(int n, int d = 1)
		: num{ n }, den{ d } {
		setFraction(num, den);
	}

	int getNum() const {
		return num;
	}

	int getDen() const {
		return den;
	}

	void setFraction(int n, int d) {
		int gcd{ findGCD(n, d) };

		num /= gcd;
		den /= gcd;

		if ((num > 0 && den < 0) || (num < 0 && den < 0))
		{
			num *= -1;
			den *= -1;
		}

		if (num == 0)
		{
			den = 1;
		}
	}
private:
	int num;	          // numerator
	int den;		// denominator; positive integer
};


Fraction add(Fraction x, Fraction y);

Fraction subtract(Fraction x, Fraction y);

Fraction multiply(Fraction x, Fraction y);

Fraction divide(Fraction x, Fraction y);


int main()
{
	int num{ 1 }, den{ 1 };
	cout << "Enter the numerator and denominator of the first fraction: ";
	cin >> num >> den;

	Fraction fraction_1{ num, den };
	cout << "First fraction: " << fraction_1.getNum() << "/" << fraction_1.getDen() << endl;

	cout << "Enter the numerator and denominator of the second fraction: ";
	cin >> num >> den;

	Fraction fraction_2{ num, den };
	cout << "Second fraction: " << fraction_2.getNum() << "/" << fraction_2.getDen() << endl;

	Fraction fraction = add(fraction_1, fraction_2);
	cout << "(" << fraction_1.getNum() << "/" << fraction_1.getDen() << ") + (" << fraction_2.getNum() << "/" << fraction_2.getDen() << ") = ";
	cout << fraction.getNum() << "/" << fraction.getDen() << endl;

	fraction = subtract(fraction_1, fraction_2);
	cout << "(" << fraction_1.getNum() << "/" << fraction_1.getDen() << ") - (" << fraction_2.getNum() << "/" << fraction_2.getDen() << ") = ";
	cout << fraction.getNum() << "/" << fraction.getDen() << endl;

	fraction = multiply(fraction_1, fraction_2);
	cout << "(" << fraction_1.getNum() << "/" << fraction_1.getDen() << ") * (" << fraction_2.getNum() << "/" << fraction_2.getDen() << ") = ";
	cout << fraction.getNum() << "/" << fraction.getDen() << endl;

	fraction = divide(fraction_1, fraction_2);
	cout << "(" << fraction_1.getNum() << "/" << fraction_1.getDen() << ") / (" << fraction_2.getNum() << "/" << fraction_2.getDen() << ") = ";
	cout << fraction.getNum() << "/" << fraction.getDen() << endl;

	return 0;
}


int findGCD(int x, int y)
{
	if (y == 0)
		return x;

	return findGCD(y, x % y);	
}

Fraction add(Fraction x, Fraction y)
{
	Fraction fraction{ x.getNum() * y.getDen() + y.getNum() * x.getDen(), x.getDen() * y.getDen() };

	return fraction;
}

Fraction subtract(Fraction x, Fraction y)
{
	Fraction fraction{ x.getNum() * y.getDen() - y.getNum() * x.getDen(), x.getDen() * y.getDen() };

	return fraction;
}

Fraction multiply(Fraction x, Fraction y)
{
	Fraction fraction{ x.getNum() * y.getNum(), x.getDen() * y.getDen() };

	return fraction;
}

Fraction divide(Fraction x, Fraction y)
{
	Fraction fraction{ x.getNum() * y.getDen(), x.getDen() * y.getNum() };

	return fraction;
}
