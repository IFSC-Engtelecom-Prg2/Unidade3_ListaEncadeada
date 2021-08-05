#include <iostream>
#include "lista.h"

using namespace std;

int main() {
    Lista l1 = cria_lista();

    anexa(l1, "algo");
    insere(l1, "coisa");

    return 0;
}
