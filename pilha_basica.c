#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char dados[50];
    int topo;
} PilhaChar;

void inicializar(PilhaChar* p) {
    p->topo = -1;
}

bool pushChar(PilhaChar* p, char c) {
    if (p->topo >= 49) return false;
    p->dados[++(p->topo)] = c;
    return true;
}

char popChar(PilhaChar* p) {
    if (p->topo < 0) return '\0';
    return p->dados[(p->topo)--];
}

char topChar(PilhaChar* p) {
    if (p->topo < 0) return '\0';
    return p->dados[p->topo];
}

bool vazia(PilhaChar* p) {
    return p->topo == -1;
}

void exibir(PilhaChar* p) {
    for (int i = 0; i <= p->topo; i++) {
        printf("%c ", p->dados[i]);
    }
    printf("\n");
}

// Teste
int main() {
    PilhaChar pilha;
    inicializar(&pilha);

    pushChar(&pilha, 'A');
    pushChar(&pilha, 'B');
    pushChar(&pilha, 'C');
    pushChar(&pilha, 'D');

    exibir(&pilha);

    while (!vazia(&pilha)) {
        printf("Pop: %c\n", popChar(&pilha));
    }

    return 0;
}
