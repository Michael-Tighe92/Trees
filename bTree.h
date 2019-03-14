//
// Created by Michael on 3/14/2019.
//
#include "node.h"
#ifndef QUESTION8_BTREE_H
#define QUESTION8_BTREE_H


class bTree {
public:
    bTree();
    ~bTree();
    void insert(int value);
    void insert2(int value, node * root);
    void displayTree();
    void display();
    void inorderDisplay(node * root);
private:
    node * root;
};


#endif //QUESTION8_BTREE_H
