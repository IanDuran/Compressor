//
// Created by Ian on 10-Jan-18.
//

#ifndef COMPRESSOR_HUFFTREE_H
#define COMPRESSOR_HUFFTREE_H

#include "PriorityQueue.h"

template <class T>
struct TreeNode{
    T* value;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

template <class T>
class HuffTree{
private:
    TreeNode<T>* root;
    int size;
public:
    explicit HuffTree(T*);
    HuffTree(T*, HuffTree<T>*, HuffTree<T>*);
    T* getRootValue();
    TreeNode<T>* getRoot();
    //void storeCodes();
};

template<class T>
HuffTree<T>::HuffTree(T *root) {
    this->root = root;
}

template<class T>
HuffTree<T>::HuffTree(T* rootValue, HuffTree<T>* firstTree, HuffTree<T>* secondTree) {
    this->root = new TreeNode<T>();
    this->root->value = rootValue;
    this->root->leftChild = firstTree->getRoot();
    this->root->rightChild = secondTree->getRoot();
}

template<class T>
T* HuffTree<T>::getRootValue() {
    return this->root->value;
}


template<class T>
TreeNode<T> *HuffTree<T>::getRoot() {
    return this->root;
}

#endif //COMPRESSOR_HUFFTREE_H
