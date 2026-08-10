#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// Max Heapify
void maxHeap(vector<int>& a,int n,int i)
{
    int x=i,l=2*i+1,r=2*i+2;

    if(l<n && a[l]>a[x]) x=l;
    if(r<n && a[r]>a[x]) x=r;

    if(x!=i) {
        swap(a[i],a[x]);
        maxHeap(a,n,x);
    }
}

// Min Heapify
void minHeap(vector<int>& a,int n,int i)
{
    int x=i,l=2*i+1,r=2*i+2;

    if(l<n && a[l]<a[x]) x=l;
    if(r<n && a[r]<a[x]) x=r;

    if(x!=i) {
        swap(a[i],a[x]);
        minHeap(a,n,x);
    }
}

// Max Heap Sort
void maxSort(vector<int>& a)
{
    int n=a.size();

    for(int i=n/2-1;i>=0;i--)
        maxHeap(a,n,i);

    for(int i=n-1;i>0;i--) {
        swap(a[0],a[i]);
        maxHeap(a,i,0);
    }
}

// Min Heap Sort
void minSort(vector<int>& a)
{
    int n=a.size();

    for(int i=n/2-1;i>=0;i--)
        minHeap(a,n,i);

    for(int i=n-1;i>0;i--) {
        swap(a[0],a[i]);
        minHeap(a,i,0);
    }

    reverse(a.begin(),a.end());
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> a(n),b,c;

    srand(time(0));

    for(int &x:a)
        x=rand()%100000;

    b=a;
    c=a;

    // Max Heap
    auto s=high_resolution_clock::now();
    maxSort(b);
    auto e=high_resolution_clock::now();

    cout<<"\nMax Heap Sort Time: "
        <<duration_cast<microseconds>(e-s).count()
        <<" microseconds\n";

    // Min Heap
    s=high_resolution_clock::now();
    minSort(c);
    e=high_resolution_clock::now();

    cout<<"Min Heap Sort Time: "
        <<duration_cast<microseconds>(e-s).count()
        <<" microseconds\n";

    return 0;
}
