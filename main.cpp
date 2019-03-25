//main.cpp
#include<iostream>
#include "bTree.h"
using namespace std;


// main function
int main()
{
    bTree test;
    int size, maximum;
    cout<<"Please enter the size of the array!: "<<endl;
    cin>>size;
    int * arr= new int[size];
    int * leftOfMax=new int[size];
    int * rightOfMax=new int[size];
    for(int i =0;i<size;i++)
    {
        cout<<"Please enter the value for element # "<<i<<": ";
        cin>>arr[i];
    }
    //Gets maximum to insert into root
    //-------------------------------
    maximum = arr[0];
    for(int i=1;i<size;i++)
    {
        if(maximum<arr[i])
            maximum=arr[i];
    }
    test.insert(maximum);
    //--------------------------------


    //Gets elements from both the left and right side of maximum
    //---------------------------------
    int leftCounter=0, rightCounter=0;
    for(int i=0;i<size;i++)
    {
        if(maximum==arr[i])
            break;
        else
        {
            leftOfMax[i]=arr[i];
            leftCounter++;
        }
    }
    int counter=0;

    int remaining = (size-1)-leftCounter;

    for(int i=size-remaining;i<size;i++)
    {
        if(maximum==arr[i])
            break;
        else{
            rightOfMax[counter]=arr[i];
            rightCounter++;
            counter++;
        }
    }
    //----------------------------------


    //Inserts both the left and right sides of maximum to their respective sides.
    //----------------------------------
    for(int i=0;i<leftCounter;i++)
    {
        test.insertLeft(leftOfMax,0,leftCounter);
    }

    for(int i =0;i<rightCounter;i++)
    {
        test.insertRight(rightOfMax,0,rightCounter);
    }
    //----------------------------------

    test.display();
    return 0;
}