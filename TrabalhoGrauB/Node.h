#pragma once

template <typename T>
class Node {
public:
    T data;
    Node<T>* proximo;
    Node<T>* anterior;
};
