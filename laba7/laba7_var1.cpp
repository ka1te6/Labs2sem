#include <iostream>
#include <vector>
#include <string>
#include <future>
#include <thread>
#include <random>
#include <chrono>
#include <algorithm>
#include <mutex>
#include <condition_variable>

constexpr int DELAY_MS = 10;

std::mutex printMutex;
std::mutex cvMutex;
std::condition_variable cv;
int finishedThreads = 0;

void selectionSort(std::vector<double>& arr, int start, int end) {
    for (int i = start; i < end - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < end; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

void sortPart(std::vector<double>& arr, int start, int end, const std::string& threadName) {
    selectionSort(arr, start, end);

    for (int i = start; i < end; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_MS));

        {
            std::lock_guard<std::mutex> lock(printMutex);
            std::cout << threadName << ": " << arr[i] << std::endl;
        }
    }

    {
        std::lock_guard<std::mutex> lock(cvMutex);
        ++finishedThreads;
    }
    cv.notify_one();
}

int main() {

	setlocale(LC_ALL, "Russian");

    const int SIZE = 20;
    std::vector<double> arr(SIZE);

    std::mt19937 gen(42);
    std::uniform_real_distribution<> dis(0.0, 100.0);

    for (auto& x : arr) {
        x = dis(gen);
    }

    std::cout << "�������� ������:\n";
    for (auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    auto f1 = std::async(std::launch::async, sortPart, std::ref(arr), 0, SIZE / 2, "thread1");
    auto f2 = std::async(std::launch::async, sortPart, std::ref(arr), SIZE / 2, SIZE, "thread2");

    {
        std::unique_lock<std::mutex> lock(cvMutex);
        cv.wait(lock, [] { return finishedThreads >= 2; });
        std::cout << "������� �����: ������ 1 � 2 ��������� ����������.\n";
    }

    auto f3 = std::async(std::launch::async, sortPart, std::ref(arr), 0, SIZE, "thread3");

    {
        std::unique_lock<std::mutex> lock(cvMutex);
        cv.wait(lock, [] { return finishedThreads >= 3; });
        std::cout << "������� �����: ����� 3 �������� ��������� ����������.\n";
    }

    std::cout << "\n������� �����: ������ ���������.\n";
    return 0;
}
