#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <chrono>
#include <atomic>
#include <iostream>

namespace Multithreading {

    // Global variable declarations (to be defined in Multithreading.cpp).
    extern int counter;
    extern std::mutex counterMutex;
    extern std::atomic<int> atomicCounter;
    extern thread_local int threadLocalValue;  // Declaration for thread-local variable.

    // Function declarations.
    void unsafeIncrement(int times);
    void safeIncrement(int times);
    void setThreadLocal(int value);
    void waitForSignal();
    void signalAll();
    int asyncFunction(int x);
    void promiseFunction(std::promise<int>& prom, int value);
    void atomicTask();
    void run();
}

#endif // MULTITHREADING_H
