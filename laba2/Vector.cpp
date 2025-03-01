#include "Vector.h"
#include <cstring> 

Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector(unsigned n, const double* arr) : size(n) {
    data = new double[n];
    if (arr) {
        std::memcpy(data, arr, n * sizeof(double));
    }
    else {
        std::memset(data, 0, n * sizeof(double));
    }
}

Vector::Vector(const Vector& other) : size(other.size) {
    data = new double[size];
    std::memcpy(data, other.data, size * sizeof(double));
}

Vector::Vector(Vector&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

Vector::~Vector() {
    delete[] data;
}

double& Vector::operator[](unsigned index) {
    return data[index];
}

const double& Vector::operator[](unsigned index) const {
    return data[index];
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new double[size];
        std::memcpy(data, other.data, size * sizeof(double));
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

Vector Vector::operator+(const double* other) const {
    Vector result(size);
    for (unsigned i = 0; i < size; ++i) {
        result[i] = data[i] + other[i];
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    for (unsigned i = 0; i < vec.size; ++i) {
        os << vec.data[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    for (unsigned i = 0; i < vec.size; ++i) {
        is >> vec.data[i];
    }
    return is;
}

unsigned Vector::getSize() const {
    return size;
}
