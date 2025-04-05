#include <iostream>
#include <stdexcept>
#include <string>

class PointOutOfRangeException : public std::out_of_range {
private:
    double x, y, z;

public:
    PointOutOfRangeException(const std::string& message, double x, double y, double z)
        : std::out_of_range(message), x(x), y(y), z(z) {}

    void printDetails() const {
        std::cout << "Ошибка: " << what() << "\n";
        std::cout << "Недопустимые координаты: (" << x << ", " << y << ", " << z << ")\n";
    }
};

class PointInCube {
private:
    double x, y, z;

public:
    PointInCube(double x, double y, double z) : x(x), y(y), z(z) {
        if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1) {
            throw PointOutOfRangeException("Координаты вне диапазона [0, 1]", x, y, z);
        }
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
};

int main() {

	setlocale(LC_ALL, "Russian");

    try {
        PointInCube p1(0.5, 0.3, 0.7);
        std::cout << "Точка создана: ("
            << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")\n";
    }
    catch (const PointOutOfRangeException& e) {
        e.printDetails();
    }

    try {
        PointInCube p2(1.2, 0.5, -0.1);
        std::cout << "Точка создана: ("
            << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")\n";
    }
    catch (const PointOutOfRangeException& e) {
        e.printDetails();
    }

    return 0;
}
