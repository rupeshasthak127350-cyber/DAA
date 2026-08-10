#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// Bubble Sort
void bubble(vector<int>& a) {
    for(int i=0;i<a.size()-1;i++)
        for(int j=0;j<a.size()-i-1;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

// Selection Sort
void selection(vector<int>& a) {
    for(int i=0;i<a.size()-1;i++) {
        int p=i;
        for(int j=i+1;j<a.size();j++)
            if(a[j]<a[p]) p=j;
        swap(a[i],a[p]);
    }
}

// Insertion Sort
void insertion(vector<int>& a) {
    for(int i=1;i<a.size();i++) {
        int x=a[i],j=i-1;
        while(j>=0 && a[j]>x) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

// Merge Sort
void mergeSort(vector<int>& a,int l,int r) {
    if(l>=r) return;

    int m=(l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);

    vector<int> t;
    int i=l,j=m+1;

    while(i<=m && j<=r)
        t.push_back(a[i]<a[j]?a[i++]:a[j++]);

    while(i<=m) t.push_back(a[i++]);
    while(j<=r) t.push_back(a[j++]);

    for(int k=0;k<t.size();k++)
        a[l+k]=t[k];
}

// Quick Sort
int partition(vector<int>& a,int l,int r) {
    int p=a[r],i=l;

    for(int j=l;j<r;j++)
        if(a[j]<p)
            swap(a[i++],a[j]);

    swap(a[i],a[r]);
    return i;
}

void quick(vector<int>& a,int l,int r) {
    if(l<r) {
        int p=partition(a,l,r);
        quick(a,l,p-1);
        quick(a,p+1,r);
    }
}

int main() {
    int n=100;
    vector<int> a(n),b;
    
    srand(time(0));
    for(int &x:a) x=rand()%1000;

    cout<<"Elements = "<<n<<"\n\n";

    auto test=[&](string name, auto sort) {
        b=a;
        auto s=high_resolution_clock::now();
        sort(b);
        auto e=high_resolution_clock::now();
        cout<<name<<" : "
            <<duration_cast<microseconds>(e-s).count()
            <<" microseconds\n";
    };

    test("Bubble Sort",[](auto& x){bubble(x);});
    test("Selection Sort",[](auto& x){selection(x);});
    test("Insertion Sort",[](auto& x){insertion(x);});
    test("Merge Sort",[](auto& x){mergeSort(x,0,x.size()-1);});
    test("Quick Sort",[](auto& x){quick(x,0,x.size()-1);});

    return 0;
}
