#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Linear Search
int linear(vector<int>& a, int key) {
    for(int i=0;i<a.size();i++)
        if(a[i]==key) return i;
    return -1;
}

// Binary Search
int binary(vector<int>& a, int key) {
    int l=0,r=a.size()-1;

    while(l<=r) {
        int m=(l+r)/2;

        if(a[m]==key) return m;
        if(a[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main() {
    int n=100000,key;
    vector<int> a(n);

    for(int i=0;i<n;i++)
        a[i]=i+1;

    cout<<"Enter element to search: ";
    cin>>key;

    int pos;
    auto start=high_resolution_clock::now();

    pos=linear(a,key);

    auto stop=high_resolution_clock::now();

    cout<<"\nLinear Search: ";
    cout<<(pos==-1 ? "Not Found" : "Found at index "+to_string(pos));
    cout<<"\nTime: "
        <<duration_cast<microseconds>(stop-start).count()
        <<" microseconds\n";

    start=high_resolution_clock::now();

    pos=binary(a,key);

    stop=high_resolution_clock::now();

    cout<<"\nBinary Search: ";
    cout<<(pos==-1 ? "Not Found" : "Found at index "+to_string(pos));
    cout<<"\nTime: "
        <<duration_cast<microseconds>(stop-start).count()
        <<" microseconds\n";

    return 0;
}
