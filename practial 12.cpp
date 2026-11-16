#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

// Linear Search: O(n)
int linearSearch(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == key) return (int)i;
    }
    return -1;
}

// Binary Search (array must be sorted): O(log n)
int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = (int)arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   // avoids overflow

        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Times any search function, averaged over several runs
template <typename Func>
double measureNs(Func search, const vector<int>& arr, int key, int &pos, int runs = 1000) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < runs; i++) {
        pos = search(arr, key);
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count() / (double)runs;
}

void report(const string& name, int pos, double ns) {
    cout << "\n" << name << ": "
         << (pos == -1 ? "Not Found" : "Found at index " + to_string(pos))
         << "\nAverage time: " << ns << " ns\n";
}

int main() {
    const int n = 100000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;   // sorted: 1..n

    int key;
    cout << "Enter element to search (1 to " << n << "): ";
    if (!(cin >> key)) {
        cout << "Invalid input.\n";
        return 1;
    }

    int pos;

    double t1 = measureNs(linearSearch, arr, key, pos);
    report("Linear Search", pos, t1);

    double t2 = measureNs(binarySearch, arr, key, pos);
    report("Binary Search", pos, t2);

    if (t2 > 0)
        cout << "\nBinary search was about " << t1 / t2 << "x faster.\n";

    return 0;
}
