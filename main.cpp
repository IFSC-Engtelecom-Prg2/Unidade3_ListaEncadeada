#include <iostream>
#include "lista.h"

// programa inicial de teste ...

int main() {
    Lista l = lista_cria();

    cout << "Tamanho (deve ser zero): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser true)=" << lista_vazia(l) << endl;

    lista_anexa(l, 5);
    lista_anexa(l, 7);
    cout << "Tamanho (deve ser dois): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser false)=" << lista_vazia(l) << endl;
    cout << "Valor do início (deve ser 5): " << lista_frente(l) << endl;
    cout << "Valor do fim (deve ser 7): " << lista_atras(l) << endl;

    lista_insere(l, 2);
    lista_insere(l, 4);
    cout << "Tamanho (deve ser quatro): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser false)=" << lista_vazia(l) << endl;
    cout << "Valor do início (deve ser 4): " << lista_frente(l) << endl;
    cout << "Valor do fim (deve ser 7): " << lista_atras(l) << endl;

    // insere 8 na posição 2
    lista_insere(l, 8, 2);
    cout << "Tamanho (deve ser cinco): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser false)=" << lista_vazia(l) << endl;
    cout << "Valor do início (deve ser 4): " << lista_frente(l) << endl;
    cout << "Valor do fim (deve ser 7): " << lista_atras(l) << endl;

    lista_remove_inicio(l);
    cout << "Tamanho (deve ser quatro): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser false)=" << lista_vazia(l) << endl;
    cout << "Valor do início (deve ser 2): " << lista_frente(l) << endl;
    cout << "Valor do fim (deve ser 7): " << lista_atras(l) << endl;

    lista_remove_fim(l);
    cout << "Tamanho (deve ser três): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser false)=" << lista_vazia(l) << endl;
    cout << "Valor do início (deve ser 2): " << lista_frente(l) << endl;
    cout << "Valor do fim (deve ser 5): " << lista_atras(l) << endl;

    // iterar a lista ???
    for (int pos=0; pos < lista_tamanho(l); pos++) {
        cout << lista_acessa(l, pos) << endl;
    }

    // e limpá-la ...
    lista_limpa(l);
    cout << "Tamanho (deve ser zero): " << lista_tamanho(l) << endl;
    cout << "Vazia (deve ser true)=" << lista_vazia(l) << endl;

    lista_destroi(l);

    return 0;
}
