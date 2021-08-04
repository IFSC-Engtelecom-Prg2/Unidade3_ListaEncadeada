//
// Created by msobral on 02/08/2021.
//

#include "lista.h"

Lista cria_lista() {
    Lista l = {nullptr, 0};

    return l;
}

void anexa(Lista &l, const string &dado) {
    // primeiro criar um nodo, onde será guardado o dado
    Nodo * nodo = new Nodo;
    nodo->dado = dado;
    nodo->proximo = nullptr; // não há nodo após este nodo

    // se lista estiver vazia, é mais simples !
    if (l.comprimento == 0) {
        l.primeiro = nodo;
    } else {
        // mas e se lista não estiver vazia ????
        // precisa acessar o último nodo da lista,
        // e fazê-lo apontar o novo nodo
        Nodo * ptr = l.primeiro;

        // enquanto não for o último nodo ...
        while (ptr->proximo != nullptr) {
            // aponta o próximo nodo
            ptr = ptr->proximo;
        }

        // novo nodo é agora o último nodo !
        ptr->proximo = nodo;
    }
    l.comprimento++;
}

void insere(Lista &l, const string &dado) {

}

void insere(Lista &l, int posicao, const string &dado) {

}

string acessa_inicio(Lista &l) {
    return nullptr;
}

string acessa_final(Lista &l) {
    return nullptr;
}

string acessa(Lista &l, int posicao) {
    return nullptr;
}

