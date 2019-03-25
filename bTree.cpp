//
// Created by Michael on 3/14/2019.
//

#include "bTree.h"
#include<iostream>
using namespace std;

bTree::bTree(){
    root = NULL;
}

bTree::~bTree(){
}

void bTree::insert(int value)
{
    if(root == NULL)
    {
        root = new node;
        root->data=value;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        insert2(value,root);
    }
}

void bTree::insert2(int value, node * root)
{
    if(value < root->data){
        if(root->left != NULL){
            insert2(value, root->left);
        }else{
            root->left = new node;
            root->left->data = value;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    }else if(value >= root->data){
        if(root->right != NULL){
            insert2(value, root->right);
        }else{
            root->right = new node;
            root->right->data = value;
            root->right->right = NULL;
            root->right->left = NULL;
        }
    }
}


void bTree::insertLeft(int *arr, int start, int end) {
    node * temp = new node;
    temp = insertInorder(arr,start,end);
    root->left = temp;
}

void bTree::insertRight(int *arr, int start, int end) {
    node * temp = new node;
    temp = insertInorder(arr,start,end);
    root->right = temp;
}


node * bTree::insertInorder(int *arr, int start, int end) {
    if (start == end)
        return NULL;
    int highest = start;
    for (int i = start; i < end; i++)
    {
         if(arr[i] > arr[highest])
             highest = i;
    }
    node * temp = new node;
    temp->data=arr[highest];
    temp->left = insertInorder(arr, start, highest);
    temp->right = insertInorder(arr, highest+1, end);
    return temp;
}

//----------------------------------------------------------------

void bTree::display(){
    inorderDisplay(root);
    cout << "\n";
}

void bTree::inorderDisplay(node * root){
    if(root != NULL){
        inorderDisplay(root->left);
        cout << root->data << ",";
        inorderDisplay(root->right);
    }
}

