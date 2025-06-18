#pragma once

template <typename T>
class Node {
public:
    T data;
    Node<T>* proximo;
    Node<T>* anterior;
    
    Node(T val) : data(val), proximo(nullptr), anterior(nullptr) {}
};
