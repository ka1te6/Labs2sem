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
class MyShared {
    T* ptr;
    int* count;

public:
    explicit MyShared(T* p = nullptr) : ptr(p), count(new int(1)) {}

    MyShared(const MyShared& other) : ptr(other.ptr), count(other.count) {
        ++(*count);
    }

    MyShared& operator=(const MyShared& other) {
        if (this != &other) {
            if (--(*count) == 0) {
                delete ptr;
                delete count;
            }
            ptr = other.ptr;
            count = other.count;
            ++(*count);
        }
        return *this;
    }

    ~MyShared() {
        if (--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    T* get() const { return ptr; }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    int use_count() const { return *count; }
};

template<typename T, typename... Args>
MyShared<T> Make_MyShared(Args&&... args) {
    return MyShared<T>(new T(forward<Args>(args)...)); // Исправлено
}

int main() {
    setlocale(LC_ALL, "Russian");

    MyShared<Student> sharedStudent = Make_MyShared<Student>("Боб", vector<int>{4, 4, 3});
    cout << "Счетчик ссылок: " << sharedStudent.use_count() << endl; // 1

    MyShared<Student> sharedCopy = sharedStudent;
    cout << "Счетчик ссылок: " << sharedStudent.use_count() << endl; // 2

    sharedCopy->print();
    cout << "Стипендия: " << (sharedCopy->hasScholarship() ? "Да" : "Нет") << endl;

    {
        MyShared<Student> anotherCopy = sharedCopy;
        cout << "Счетчик ссылок: " << anotherCopy.use_count() << endl; // 3
    }
    cout << "Счетчик ссылок после выхода из области видимости: " << sharedStudent.use_count() << endl; // 2

    return 0;
}
