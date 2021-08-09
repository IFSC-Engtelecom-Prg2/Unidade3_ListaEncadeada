//
// Created by msobral on 02/08/2021.
//

#include "lista.h"
#include <exception>

Nodo * cria_nodo(const string & dado) {
    Nodo * p_nodo = new Nodo;
    p_nodo->dado = dado;
    p_nodo->proximo = nullptr; // não há nodo após este nodo

    return p_nodo;
}

Lista cria_lista() {
    Lista l = {nullptr, 0};

    return l;
}

void anexa(Lista &l, const string &dado) {
    // primeiro criar um nodo, onde será guardado o dado
    Nodo * p_nodo = cria_nodo(dado);

    // se lista estiver vazia, é mais simples !
    if (l.comprimento == 0) {
        l.primeiro = p_nodo;
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
        ptr->proximo = p_nodo;
    }
    l.comprimento++;
}

// acrescenta dado ao inicio da lista
void insere(Lista &l, const string &dado) {
    // cria nodo para armazenar o dado
    Nodo * p_nodo = cria_nodo(dado);

    // agora insere-o no início da lista
    // ele deve se tornar o primeiro nodo !

    // passo 1) copiar o ponteiro "primeiro" para o ponteiro "proximo"
    // do novo nodo
    p_nodo->proximo = l.primeiro;

    // passo 2) copiar o ponteiro do novo "nodo" para o ponteiro "primeiro"
    l.primeiro = p_nodo;

    l.comprimento++;
}

// insere dado numa posição qualquer
// se posicao >= comprimento: funciona como o anexa
// se posicao == 0: funciona como insere no inicio
void insere(Lista &l, int pos, const string &dado) {
    // cria um novo nodo
    Nodo * p_nodo = cria_nodo(dado);

    if (pos >= l.comprimento) anexa(l, dado);
    else if (pos == 0) insere(l, dado);
    else {
        // precisa localizar o nodo que está na posição "pos-1"
        Nodo * ptr = l.primeiro;
        for (int i=0; i < pos-1; i++) {
            // avança para próximo nodo
            ptr = ptr->proximo;
        }

        // agora encaixa o novo nodo na frente do nodo apontado por "ptr"
        // 1) novo nodo deve apontar o nodo que está atualente na posição

        // indicada por "pos"
        p_nodo->proximo = ptr->proximo;

        // passo 2) antecessor deve apontar o novo nodo
        ptr->proximo = p_nodo;

        // atualizar o comprimento da lista
        l.comprimento++;
    }
}

// retorna o primeiro dado da lista
// se lista estiver vazia, dispara uma exceção !
string & acessa_inicio(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    Nodo * ptr = l.primeiro;
    return ptr->dado;
}

// retorna o último dado da lista
// se lista estiver vazia, dispara uma exceção !
string & acessa_final(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    // localizar o último nodo, e então
    // retornar o dado lá contido
    Nodo * ptr = l.primeiro;

    for (; ptr->proximo != nullptr; ptr = ptr->proximo);

    return ptr->dado;
}

string & acessa(Lista &l, int pos) {
    if (l.comprimento == 0) throw std::exception();

    // precisa localizar o nodo que está na posição "pos"
    Nodo * ptr = l.primeiro;
//    for (int i=0; i < pos; i++) {
//        // avança para próximo nodo
//        ptr = ptr->proximo;
//    }

    for (; pos > 0; pos--, ptr=ptr->proximo);

    // retorna o dado contido nesse nodo
    return ptr->dado;
}

void remove_inicio(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    // 1) desconectar o primeiro nodo da lista
    Nodo * ptr = l.primeiro;
    l.primeiro = ptr->proximo;

    // 2) liberar a área de memória alocada para o primeiro nodo
    delete ptr;

    // 3) decrementar o comprimento da lista
    l.comprimento--;
}

void remove_final(Lista &l) {

}

void remove(Lista &l, int pos) {

}

