//
// Created by msobral on 02/08/2021.
//

#ifndef CLIONPROJECTSLISTA_20211_LISTA_H
#define CLIONPROJECTSLISTA_20211_LISTA_H

#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H

struct Lista {
    // a área de memória ???


    // a quantidade de dados armazenados
    int n;

    // ??? ainda não sei o que vai aqui dentro ...
};

// As operações da lista

// cria uma lista inicialmente vazia
Lista lista_cria();

// destroi uma lista
void lista_destroi(Lista & l);

// Acessa o dado da frente da lista
// se lista vazia: o que acontece ????
// DISPARA EXCEÇÃO do tipo invalid_argument
int lista_frente(const Lista & l);

// Acessa o dado do final da lista
// se lista vazia: o que acontece ????
// DISPARA EXCEÇÃO do tipo invalid_argument
int lista_atras(const Lista & l);

// esvazia uma lista
void lista_limpa(Lista & l);

// remove o dado do início
// se lista vazia: DISPARA EXCEÇÃO do tipo invalid_argument
void remove_inicio(Lista & l);

// remove o dado do fim
// se lista vazia: DISPARA EXCEÇÃO do tipo invalid_argument
void remove_fim(Lista & l);

// Anexa um dado à lista
void lista_anexa(Lista & l, int dado);

// Insere um dado no início da lista
void lista_insere(Lista & l, int dado);

// Insere um dado numa posição da lista
// Se posição inálida, dispara exceção invalid_argument
void lista_insere(Lista & l, int dado, int posicao);

// Retorna o tamanho da lista
int lista_tamanho(const Lista & l);

// Verifica se lista está vazia
bool lista_vazia(const Lista & l);

// Acessa um dado de uma posição da lista
// Se posição inálida, dispara exceção invalid_argument
int lista_acessa(const Lista & l, int posicao);

#endif //CLIONPROJECTSLISTA_20211_LISTA_H
