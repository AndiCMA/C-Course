#include "Multithreading.h"
using namespace std;

namespace Multithreading {

    // Global variables for demonstration.
    int counter = 0;
    mutex counterMutex;
    atomic<int> atomicCounter(0);

    // 1. Unsafe increment without synchronization.
    void unsafeIncrement(int times) {
        for (int i = 0; i < times; i++) {
            counter++;  // Race condition possible.
        }
    }

    // 2. Safe increment using a mutex.
    void safeIncrement(int times) {
        for (int i = 0; i < times; i++) {
            lock_guard<mutex> lock(counterMutex);
            counter++;
        }
    }

    // 3. Demonstrating thread_local storage.
    thread_local int threadLocalValue = 0;
    void setThreadLocal(int value) {
        threadLocalValue = value;
        cout << "Thread " << this_thread::get_id() << " thread_local value: " << threadLocalValue << endl;
    }

    // 4. Condition variable: Producer-Consumer demo.
    mutex cvMutex;
    condition_variable cv;
    bool ready = false;
    void waitForSignal() {
        unique_lock<mutex> lock(cvMutex);
        cv.wait(lock, []() { return ready; });
        cout << "Thread " << this_thread::get_id() << " received signal." << endl;
    }
    void signalAll() {
        {
            lock_guard<mutex> lock(cvMutex);
            ready = true;
        }
        cv.notify_all();
    }

    // 5. Async demonstration: returns square after a delay.
    int asyncFunction(int x) {
        this_thread::sleep_for(chrono::milliseconds(100));
        return x * x;
    }

    // 6. Promise demonstration: set a value after a delay.
    void promiseFunction(promise<int>& prom, int value) {
        this_thread::sleep_for(chrono::milliseconds(50));
        prom.set_value(value + 10);
    }

    // 7. Atomic counter demonstration.
    void atomicTask() {
        for (int i = 0; i < 10000; i++)
            atomicCounter++;
    }

    // Run all multithreading demos.
    void run() {
        cout << "=== Multithreading Demo ===" << endl;

        // Unsafe increment demo.
        counter = 0;
        thread t1(unsafeIncrement, 10000);
        thread t2(unsafeIncrement, 10000);
        t1.join(); t2.join();
        cout << "Unsafe counter (may not be 20000): " << counter << endl;

        // Safe increment demo.
        counter = 0;
        thread t3(safeIncrement, 10000);
        thread t4(safeIncrement, 10000);
        t3.join(); t4.join();
        cout << "Safe counter (should be 20000): " << counter << endl;

        // Thread-local storage demo.
        thread t5(setThreadLocal, 5);
        thread t6(setThreadLocal, 10);
        t5.join(); t6.join();

        // Condition variable demo.
        thread consumer1(waitForSignal);
        thread consumer2(waitForSignal);
        this_thread::sleep_for(chrono::milliseconds(100));
        signalAll();
        consumer1.join(); consumer2.join();

        // Async and future demo.
        future<int> fut = async(asyncFunction, 7);
        cout << "Async function result (7^2): " << fut.get() << endl;

        // Promise and future demo.
        promise<int> prom;
        future<int> promFuture = prom.get_future();
        thread promiseThread(promiseFunction, ref(prom), 20);
        cout << "Promise function result (20+10): " << promFuture.get() << endl;
        promiseThread.join();

        // Atomic counter demo.
        atomicCounter = 0;
        thread ta1(atomicTask);
        thread ta2(atomicTask);
        ta1.join(); ta2.join();
        cout << "Atomic counter (should be 20000): " << atomicCounter.load() << endl;
    }
}
