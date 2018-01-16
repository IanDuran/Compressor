//
// Created by Ian on 10-Jan-18.
//

#ifndef COMPRESSOR_HUFFTREE_H
#define COMPRESSOR_HUFFTREE_H

template <class T>
struct Node{
    T* value;
    Node* leftChild;
    Node* rightChild;
};

template <class T>
class HuffTree{
private:
    Node<T>* root;
    int size;
public:
    explicit HuffTree(T*);
    HuffTree(HuffTree<T>, HuffTree<T>);
    int getTreeFrequency();

};
#endif //COMPRESSOR_HUFFTREE_H
