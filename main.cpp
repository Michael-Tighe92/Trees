//main.cpp
#include<iostream>
#include "bTree.h"
using namespace std;
int main()
{
    bTree test;
    int size;
    cout<<"Please enter the size of the array!: "<<endl;
    cin>>size;
    int * arr= new int[size];
    for(int i =0;i<size;i++)
    {
        cout<<"Please enter the value for element # "<<i<<": ";
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        test.insert(arr[i]);
    }
    test.display();
    return 0;
}