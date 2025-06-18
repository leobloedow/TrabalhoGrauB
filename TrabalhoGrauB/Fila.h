#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class Fila {
private:
    Node<T>* inicio;
    Node<T>* fim;
    int tamanho;
public:
    Fila();
    void push(T data);
    void pop();
    Node<T>* getInicio();
    bool find(int anum);
    int getTamanho();
    void setInicio(Node<T>* newInicio) { inicio = newInicio; }
    void setFim(Node<T>* newFim) { fim = newFim; }
    void setTamanho(int newTamanho) { tamanho = newTamanho; }
};

//cpp

template <class T>
Fila<T>::Fila() {
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
}

template <class T>
int Fila<T>::getTamanho() {
    return tamanho;
}

template <class T>
Node<T>* Fila<T>::getInicio() {
    return inicio;
}

template <class T>
void Fila<T>::push(T data) {
    Node<T>* novo = new Node<T>(data);
    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
    }
    tamanho++;
}

template <class T>
void Fila<T>::pop() {
    if (inicio == nullptr) {
        cout << "fila vazia!" << endl;
        return;
    }
    Node<T>* temp = inicio;
    inicio = inicio->proximo;
    if (inicio != nullptr) {
        inicio->anterior = nullptr;
    } else {
        fim = nullptr;
    }
    delete temp;
    tamanho--;
}

template <class T>
bool Fila<T>::find(int anum) {
    Node<T>* atual = fim;
    while (atual != nullptr) {
        if (atual->data.getNum() == anum) {
            return true;
        }
        atual = atual->anterior;
    }
    return false;
}
