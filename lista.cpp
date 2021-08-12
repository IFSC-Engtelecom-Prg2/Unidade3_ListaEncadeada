//
// Created by msobral on 02/08/2021.
//

#include "lista.h"
#include <exception>

// funções privativas da lista: somente para uso interno
Nodo * localiza_nodo(Lista & l, int pos) {
    if (pos >= l.comprimento) throw std::exception();

    Nodo * ptr;

    // localiza o nodo na primeira ou na segunda metade da lista
    if (pos < l.comprimento/2) { // está na 1a metade
        // precisa localizar o nodo que está na posição "pos"
        ptr = l.guarda.proximo;

        for (; pos > 0; pos--, ptr = ptr->proximo);
    } else { // está na 2a metade
        pos = (l.comprimento - 1) - pos;
        ptr = l.guarda.anterior;

        for (; pos > 0; pos--, ptr = ptr->anterior);
    }

    return ptr;
}

void desconecta_nodo(Lista & l, Nodo * ptr) {
    // identifica o sucessor e antecessor do nodo a remover
    Nodo * ant = ptr->anterior;
    Nodo * succ = ptr->proximo;

    // desconecta o nodo da lista
    ant->proximo = succ;
    succ->anterior = ant;
}

Nodo * cria_nodo(const string & dado) {
    Nodo * p_nodo = new Nodo;
    p_nodo->dado = dado;
    p_nodo->proximo = nullptr; // não há nodo após este nodo
    p_nodo->anterior = nullptr; // não há nodo após este nodo

    return p_nodo;
}

Lista cria_lista() {
    Lista l;

    l.comprimento = 0;
    // lista vazia: guarda aponta si próprio
    l.guarda.proximo = &l.guarda;
    l.guarda.anterior = &l.guarda;

    return l;
}

void anexa(Lista &l, const string &dado) {
    // primeiro criar um nodo, onde será guardado o dado
    Nodo * p_nodo = cria_nodo(dado);

    // 1 e 2) encaixar o novo nodo na lista ...
    p_nodo->proximo = &l.guarda;
    p_nodo->anterior = l.guarda.anterior;

    // 3) torná-lo sucessor do último nodo (atual) da lista
    Nodo * ultimo = l.guarda.anterior;
    ultimo->proximo = p_nodo;

    // 4) torná-lo antecessor do nodo guarda
    l.guarda.anterior = p_nodo;

    l.comprimento++;
}

// acrescenta dado ao inicio da lista
void insere(Lista &l, const string &dado) {
    // cria nodo para armazenar o dado
    Nodo * p_nodo = cria_nodo(dado);

    // encaixar o novo nodo na lista
    // 1) definir o sucessor do novo nodo, que deve ser o
    // primeiro nodo atual da lista
    p_nodo->proximo = l.guarda.proximo;
    p_nodo->anterior = &l.guarda;

    // 3) torná-lo antecessor do primeiro nodo atual da lista
    Nodo * ptr = l.guarda.proximo; // este é o 1o nodo atual
    ptr->anterior = p_nodo;

    // 4) torná-lo o sucessor do guarda
    l.guarda.proximo = p_nodo;

    l.comprimento++;
}

// insere dado numa posição qualquer
// se posicao >= comprimento: funciona como o anexa
// se posicao == 0: funciona como insere no inicio
void insere(Lista &l, int pos, const string &dado) {
    // cria um novo nodo
    Nodo * p_nodo = cria_nodo(dado);

    if (pos >= l.comprimento) {
        anexa(l, dado);
    } else {
        // 1) localizar o nodo que está na posição de inserção
        Nodo * ptr = l.guarda.proximo;
        for (; pos > 0; pos--) {
            ptr = ptr->proximo;
        }

        // 1) o nodo na posição atual deve ser o sucessor do novo nodo
        p_nodo->proximo = ptr;
        // 2) antecessor do novo nodo deve ser o antecessor do
        // nodo da posição atual
        p_nodo->anterior = ptr->anterior;
        // 3) antecessor do nodo na posição atual deve ser novo nodo
        ptr->anterior = p_nodo;
        // 4) sucessor do nodo antecessor da posição atual deve ser
        // novo nodo .. quer dizer, novo nodo se torna o nodo
        // da posição desejada
        p_nodo->anterior->proximo = p_nodo;

        l.comprimento++;
    }
}

// retorna o primeiro dado da lista
// se lista estiver vazia, dispara uma exceção !
string & acessa_inicio(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    Nodo * ptr = l.guarda.proximo;
    return ptr->dado;
}

// retorna o último dado da lista
// se lista estiver vazia, dispara uma exceção !
string & acessa_final(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    // localizar o último nodo, e então
    // retornar o dado lá contido
    Nodo * ptr = l.guarda.anterior;

    return ptr->dado;
}

string & acessa(Lista &l, int pos) {
    Nodo * ptr = localiza_nodo(l, pos);

    // retorna o dado contido nesse nodo
    return ptr->dado;
}

void remove_inicio(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    // este é o nodo a ser removido
    Nodo * ptr = l.guarda.proximo;

    desconecta_nodo(l, ptr);

    // 3) destruir o nodo removido
    delete ptr;

    l.comprimento--;
}

void remove_final(Lista &l) {
    if (l.comprimento == 0) throw std::exception();

    // este é o nodo a ser removido
    Nodo * ptr = l.guarda.anterior;

    desconecta_nodo(l, ptr);

    // destroi o nodo removido
    delete ptr;

    l.comprimento--;
}

void remove(Lista &l, int pos) {
    Nodo * ptr = localiza_nodo(l, pos);

    desconecta_nodo(l, ptr);

    // destroi o nodo
    delete ptr;

    l.comprimento--;
}

