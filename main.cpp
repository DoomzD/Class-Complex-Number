#include <cmath>
#include <iostream>

class Complex {
private:
    double re_, im_;

public:
    Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) { }

    double Re() const { return re_; }
    double Im() const { return im_; }

    Complex operator+(const Complex& other) const;
    Complex operator+(const double d) const;
    friend Complex operator+(const double d, const Complex& other);

    Complex operator-(const Complex& other) const;
    Complex operator-(const double d) const;
    friend Complex operator-(const double d, const Complex& other);

    Complex operator*(const Complex& other) const;
    Complex operator*(const double d) const;
    friend Complex operator*(const double d, const Complex& other);

    Complex operator/(const Complex& other) const;
    Complex operator/(const double d) const;
    friend Complex operator/(const double d, const Complex& other);

    Complex operator+() const;
    Complex operator-() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
};

Complex Complex::operator+(const Complex &other) const {
    return {re_ + other.re_, im_ + other.im_};
}

Complex Complex::operator+(const double d) const {
    return {re_ + d, im_};
}

Complex operator+(const double d, const Complex &other) {
    return {other.re_ + d, other.im_};
}

Complex Complex::operator-(const Complex &other) const {
    return {re_ - other.re_, im_ - other.im_};
}

Complex Complex::operator-(const double d) const {
    return {re_ - d, im_};
}

Complex operator-(const double d, const Complex &other) {
    return {d - other.re_, -other.im_};
}

Complex Complex::operator*(const Complex &other) const {
    return {re_ * other.re_ - im_ * other.im_, other.re_ * im_ + other.im_ * re_};
}

Complex Complex::operator*(const double d) const {
    return {re_ * d, im_ * d};
}

Complex operator*(const double d, const Complex &other) {
    return {d * other.re_, d * other.im_};
}

Complex Complex::operator/(const Complex &other) const {
    return {(re_ * other.re_ + im_ * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_)
            , (im_ * other.re_ - re_ * other.im_) / (other.re_ * other.re_+ other.im_ * other.im_)};
}

Complex Complex::operator/(const double d) const {
    return {(re_ * d) / (d * d), (im_ * d) / (d * d)};
}

Complex operator/(const double d, const Complex &other) {
    return {(d * other.re_) / (other.re_ * other.re_ + other.im_ * other.im_)
            , (-d * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_)};
}

Complex Complex::operator+() const {
    return {re_, im_};
}

Complex Complex::operator-() const {
    return {-re_, -im_};
}

bool Complex::operator==(const Complex &other) const {
    return (re_ == other.re_ && im_ == other.im_);
}

bool Complex::operator!=(const Complex &other) const {
    return !(re_ == other.re_ && im_ == other.im_);
}

double abs(const Complex& current) {
    return std::sqrt(current.Re() * current.Re() + current.Im() * current.Im());
}

int main() {
    Complex r(3, 4), q(5, 2);
    r = r * 3 + 2 * q;
    std::cout << r.Re() << " " << r.Im() << '\n' << q.Re() << " " << q.Im() << '\n';
}
