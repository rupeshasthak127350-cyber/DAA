#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Iterative Factorial
unsigned long long iterative(int n) {
    unsigned long long f=1;
    for(int i=1;i<=n;i++)
        f*=i;
    return f;
}

// Recursive Factorial
unsigned long long recursive(int n) {
    if(n<=1) return 1;
    return n*recursive(n-1);
}

int main() {
    int n;

    cout<<"Enter a non-negative integer: ";
    cin>>n;

    if(n<0) {
        cout<<"Invalid input!";
        return 0;
    }

    // Iterative
    auto s=high_resolution_clock::now();
    unsigned long long a=iterative(n);
    auto e=high_resolution_clock::now();

    cout<<"\nIterative Factorial = "<<a;
    cout<<"\nIterative Time = "
        <<duration_cast<nanoseconds>(e-s).count()<<" ns\n";

    // Recursive
    s=high_resolution_clock::now();
    unsigned long long b=recursive(n);
    e=high_resolution_clock::now();

    cout<<"\nRecursive Factorial = "<<b;
    cout<<"\nRecursive Time = "
        <<duration_cast<nanoseconds>(e-s).count()<<" ns\n";

    return 0;
}
