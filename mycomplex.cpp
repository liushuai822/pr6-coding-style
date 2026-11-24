#include <cmath>
#include <iostream>
#include <string>

#include "mycomplex.h"

Complex::Complex(double re, double im) : re_(re), im_(im) {
}

Complex::Complex(const Complex& other)
    : re_(other.re_), im_(other.im_) {
}

Complex::~Complex() {
    re_ = 0.0;
    im_ = 0.0;
}

void Complex::set(double re, double im) {
    re_ = re;
    im_ = im;
}

Complex::operator double() const {
    return abs();
}

double Complex::abs() const {
    return std::sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::operator+(const Complex& other) const {
    Complex result;
    result.re_ = re_ + other.re_;
    result.im_ = im_ + other.im_;
    return result;
}

Complex Complex::operator-(const Complex& other) const {
    Complex result;
    result.re_ = re_ - other.re_;
    result.im_ = im_ - other.im_;
    return result;
}

Complex Complex::operator+(double value) const {
    Complex result;
    result.re_ = re_ + value;
    result.im_ = im_;
    return result;
}

Complex Complex::operator-(double value) const {
    Complex result(*this);
    result.re_ = re_ - value;
    return result;
}

Complex Complex::operator*(const Complex& other) const {
    Complex result;
    result.re_ = re_ * other.re_ - im_ * other.im_;
    result.im_ = re_ * other.im_ + im_ * other.re_;
    return result;
}

Complex Complex::operator*(double value) const {
    Complex result;
    result.re_ = re_ * value;
    result.im_ = im_ * value;
    return result;
}

Complex Complex::operator/(double value) const {
    Complex result;
    result.re_ = re_ / value;
    result.im_ = im_ / value;
    return result;
}

Complex& Complex::operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double tmp_re = re_;
    re_ = re_ * other.re_ - im_ * other.im_;
    im_ = im_ * other.re_ + tmp_re * other.im_;
    return *this;
}

Complex& Complex::operator+=(double value) {
    re_ += value;
    return *this;
}

Complex& Complex::operator-=(double value) {
    re_ -= value;
    return *this;
}

Complex& Complex::operator*=(double value) {
    re_ *= value;
    im_ *= value;
    return *this;
}

Complex& Complex::operator/=(double value) {
    re_ /= value;
    im_ /= value;
    return *this;
}

Complex& Complex::operator=(const Complex& other) {
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}

Complex& Complex::operator=(double value) {
    re_ = value;
    im_ = 0.0;
    return *this;
}

std::istream& operator>>(std::istream& stream, Complex& value) {
    std::string tmp;
    stream >> value.re_ >> value.im_ >> tmp;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Complex& value) {
    stream << value.re_;
    if (!(value.im_ < 0)) {
        stream << '+';
    }
    stream << value.im_ << 'i';
    return stream;
}

Complex operator+(double left, const Complex& right) {
    Complex result;
    result.re_ = left + right.re_;
    result.im_ = right.im_;
    return result;
}

Complex operator-(double left, const Complex& right) {
    Complex result;
    result.re_ = left - right.re_;
    result.im_ = -right.im_;
    return result;
}

Complex operator*(double left, const Complex& right) {
    Complex result;
    result.re_ = left * right.re_;
    result.im_ = left * right.im_;
    return result;
}
