#ifndef MYCOMPLEX_H_
#define MYCOMPLEX_H_

#include <iostream>

class Complex {
public:
    explicit Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex& other);
    ~Complex();

    void set(double re, double im = 0.0);
    explicit operator double() const;
    double abs() const;

    friend std::istream& operator>>(std::istream& stream,
                                    Complex& value);
    friend std::ostream& operator<<(std::ostream& stream,
                                    const Complex& value);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator+(double value) const;
    Complex operator-(double value) const;
    Complex operator*(const Complex& other) const;
    Complex operator*(double value) const;
    Complex operator/(double value) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator+=(double value);
    Complex& operator-=(double value);
    Complex& operator*=(double value);
    Complex& operator/=(double value);
    Complex& operator=(const Complex& other);
    Complex& operator=(double value);

    friend Complex operator+(double left, const Complex& right);
    friend Complex operator-(double left, const Complex& right);
    friend Complex operator*(double left, const Complex& right);

private:
    double re_;
    double im_;
};

#endif  // MYCOMPLEX_H_
