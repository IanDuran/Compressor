//
// Created by Ian on 10-Jan-18.
//

#ifndef COMPRESSOR_HUFFTREE_H
#define COMPRESSOR_HUFFTREE_H

#include "PriorityQueue.h"

#include <map>
#include <string>
#include <utility>
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
    void deleteNode(TreeNode<T>*);
    void storeCodes(TreeNode*, std::string,std::map<std::string, T*>*);
public:
    explicit HuffTree(T*);
    HuffTree(T*, HuffTree<T>*, HuffTree<T>*);
    virtual ~HuffTree();
    T* getRootValue();
    TreeNode<T>* getRoot();
    void storeCodes(std::map<std::string, T*>*);
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
HuffTree<T>::~HuffTree() {
    this->deleteNode(root);
}

template<class T>
void HuffTree<T>::deleteNode(TreeNode<T> *currentNode) {
    if(currentNode != 0) {
        if (currentNode->leftChild != 0)
            this->deleteNode(currentNode->leftChild);

        if (currentNode->rightChild != 0)
            this->deleteNode(currentNode->rightChild);

        delete currentNode;
    }
}

template<class T>
T* HuffTree<T>::getRootValue() {
    return this->root->value;
}


template<class T>
TreeNode<T> *HuffTree<T>::getRoot() {
    return this->root;
}

template<class T>
void HuffTree<T>::storeCodes(std::map<std::string, T *> *codeMap) {
    this->storeCodes(this->root, "",codeMap);
}

template<class T>
void HuffTree<T>::storeCodes(TreeNode * currentNode, std::string currentCode, std::map<std::string, T *> *codeMap) {
    if(currentNode->rightChild == 0 && currentNode->leftChild == 0){
        codeMap->insert(std::pair<std::string, T*>(currentCode, currentNode->value));
    }else{
        if(currentNode->leftChild != 0)
            this->storeCodes(currentNode->leftChild, currentCode + "0", codeMap);

        if(currentNode->rightChild != 0)
            this->storeCodes(currentNode->rightChild, currentCode + "1", codeMap);

    }
}

#endif //COMPRESSOR_HUFFTREE_H
