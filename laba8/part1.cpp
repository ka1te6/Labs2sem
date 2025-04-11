#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Student {
    string name;
    vector<int> grades;
public:
    Student(const string& name, const vector<int>& grades)
        : name(name), grades(grades) {
    }

    void print() const {
        cout << name << ", оценки: ";
        for (int g : grades) cout << g << " ";
        cout << endl;
    }

    bool hasScholarship() const {
        for (int g : grades)
            if (g <= 3) return false;
        return true;
    }
};

template<class T>
class MyUnique {
    T* p;
public:
    explicit MyUnique(T* p = nullptr) : p(p) {}
    ~MyUnique() { delete p; }

    MyUnique(const MyUnique&) = delete;
    MyUnique& operator=(const MyUnique&) = delete;

    MyUnique(MyUnique&& other) noexcept : p(other.p) {
        other.p = nullptr;
    }
    MyUnique& operator=(MyUnique&& other) noexcept {
        if (this != &other) {
            delete p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }

    T* get() const { return p; }
    T& operator*() { return *p; }
    T* operator->() { return p; }
};

template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
    return MyUnique<T>(new T(forward<Args>(args)...));
}

int main() {

	setlocale(LC_ALL, "Russian");

    // Демонстрация MyUnique
    MyUnique<Student> uniqueStudent = Make_MyUnique<Student>("Алиса", vector<int>{5, 5, 3});
    uniqueStudent->print();
    cout << "Стипендия: " << (uniqueStudent->hasScholarship() ? "Да" : "Нет") << endl;

    MyUnique<Student> movedStudent = move(uniqueStudent);
    if (!uniqueStudent.get())
        cout << "uniqueStudent стал пустым после перемещения" << endl;
    movedStudent->print();

    return 0;
}
