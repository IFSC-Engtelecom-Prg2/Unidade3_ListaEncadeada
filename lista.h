//
// Created by msobral on 02/08/2021.
//

#ifndef CLIONPROJECTSLISTA_20211_LISTA_H
#define CLIONPROJECTSLISTA_20211_LISTA_H

#include <string>

using std::string;

// um nodo (a caixinha)
template <typename T> struct Nodo {
    // um dado armazenado
    T dado;

    // isto indica qual o próximo nodo da sequência
    // e tb seu antecessor
    Nodo * proximo, * anterior;
};

template <typename T> struct Lista {
    // o primeiro nodo da lista
    Nodo<T> guarda;

    // o comprimento da lista (quantos nodos existem)
    int comprimento;
};

// operações da lista: cada operação é uma função

// cria uma lista inicialmente vazia
template <typename T> Lista<T> cria_lista();

// acrescenta um dado ao final da lista
template <typename T> void anexa(Lista<T> & l, const T & dado);

// insere um dado no início da lista
void insere(Lista & l, const string & dado);

// insere um dado em uma posição qualquer
void insere(Lista & l, int posicao, const string & dado);

// acessa um dado no início da lista
template <typename T> T & acessa_inicio(Lista<T> & l);

// acessa um dado no final da lista
string & acessa_final(Lista & l);

// acessa um dado em posição qualquer da lista
string & acessa(Lista & l, int posicao);

// remove o dado do início da lista
void remove_inicio(Lista & l);

// remove o dado do final da lista
void remove_final(Lista & l);

// remove o dado de uma posição qualquer
void remove(Lista & l, int pos);

#include <lista-impl.h>

#endif //CLIONPROJECTSLISTA_20211_LISTA_H
