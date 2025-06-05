#include "STL.h"
using namespace std;

namespace STL {

    void run() {
        cout << "=== STL Demonstration ===" << endl;

        // Date/Time: Get current time using <chrono>
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        cout << "Current time: "
            << put_time(localtime(&now_time), "%F %T") << endl << endl;

        // Container: vector
        vector<int> vec = { 5, 3, 9, 1, 7 };
        cout << "Original vector: ";
        for (auto v : vec) {
            cout << v << " ";
        }
        cout << endl;

        // Algorithm: sort using iterators
        sort(vec.begin(), vec.end());
        cout << "Sorted vector: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl << endl;

        // Container: list
        list<string> names = { "Alice", "Bob", "Charlie" };
        cout << "Names list: ";
        for (const auto& name : names)
            cout << name << " ";
        cout << endl << endl;

        // Container: map
        map<string, int> ageMap = { {"Alice", 30}, {"Bob", 25}, {"Charlie", 35} };
        cout << "Map of ages:" << endl;
        for (const auto& entry : ageMap)
            cout << entry.first << ": " << entry.second << endl;
        cout << endl;

        // Container: set (automatically removes duplicates)
        set<int> uniqueNumbers = { 5, 3, 9, 1, 7, 3, 5 };
        cout << "Unique numbers in set: ";
        for (const auto& num : uniqueNumbers)
            cout << num << " ";
        cout << endl << endl;

        // Algorithm: transform to square each element in vector
        vector<int> squared(vec.size());
        transform(vec.begin(), vec.end(), squared.begin(), [](int x) { return x * x; });
        cout << "Squared vector: ";
        for (auto v : squared)
            cout << v << " ";
        cout << endl;

        // Algorithm: count_if to count even numbers in vector
        int evenCount = count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
        cout << "Even numbers count in vector: " << evenCount << endl;
    }
}
