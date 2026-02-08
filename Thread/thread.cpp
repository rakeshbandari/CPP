#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex evenMutex;
std::mutex oddMutex;
std::condition_variable evenCV;
std::condition_variable oddCV;
int currentNumber = 1;
const int maxNumber = 20;

void printEven() {
    while (currentNumber <= maxNumber) {
        std::unique_lock<std::mutex> lock(evenMutex);
        evenCV.wait(lock, []() { return currentNumber % 2 == 0; });
        std::cout << "Even Thread: " << currentNumber << std::endl;
        ++currentNumber;
        lock.unlock();
        oddCV.notify_one();
    }
}

void printOdd() {
    while (currentNumber <= maxNumber) {
        std::unique_lock<std::mutex> lock(oddMutex);
        oddCV.wait(lock, []() { return currentNumber % 2 != 0; });
        std::cout << "Odd Thread: " << currentNumber << std::endl;
        ++currentNumber;
        lock.unlock();
        evenCV.notify_one();
    }
}

int main() {
    std::thread evenThread(printEven);
    std::thread oddThread(printOdd);

    evenThread.join();
    oddThread.join();

    return 0;
}

