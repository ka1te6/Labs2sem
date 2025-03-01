#include "Vector.h"
#include <fstream>

int main() {

    std::ifstream input("input.txt");
    unsigned size;
    input >> size;

    double* arr = new double[size];
    for (unsigned i = 0; i < size; ++i) {
        input >> arr[i];
    }

    Vector vec1(size, arr);
    Vector vec2(size, arr);

    Vector vec3 = vec1 + arr;

    std::ofstream output("output.txt");
    output << "Vector 1: " << vec1 << std::endl;
    output << "Vector 2: " << vec2 << std::endl;
    output << "Vector 3 (Vector 1 + arr): " << vec3 << std::endl;

    delete[] arr;
    return 0;
}
