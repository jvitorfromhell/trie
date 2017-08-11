// Nao se preocupem com isso
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ALFABETO 26
#define OFFSET 97
#define true 1
#define false 0
#define bool int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados
struct Nodo {
    struct Nodo * prox[ALFABETO];
};

typedef struct Nodo Nodo;

// Inicializa trie vazia
Nodo * init_trie() {
    Nodo * trie = (Nodo *) malloc(sizeof(Nodo));

    for (int i = 0; i < ALFABETO; i++){
        trie->prox[i] == NULL;
    }

    return trie;
}

// Insere palavra na trie efetivamente. Utilizada em combinacao com insere, quando se sabe onde se deve inserir
// @param pos : atual posicao da palavra de entrada, usado para nao precisar copiar a substring atual
bool insere_novo(Nodo * trie, char * palavra, int pos) {
    // IMPLEMENTACAO AQUI
}

// Insere elemento na trie : retorna true se elemento inserido, false se ja existe
// @param pos : atual posicao da palavra de entrada, usado para nao precisar copiar a substring atual
bool insere(Nodo * trie, char * palavra, int pos) {
    // IMPLEMENTACAO AQUI
}

// Procura palavra na trie : retorna true se encontrou, false se nao
bool procura(Nodo * trie, char * palavra, int pos) {
    // IMPLEMENTACAO AQUI
}

// Destroi trie, liberando memoria
void * destroi_trie(Nodo * trie) {
    if (trie != NULL) {
        for (int i = 0; i < ALFABETO; i++) {
            destroi_trie(trie->prox[i]);
        }

        free(trie);
    }
    return NULL;
}

int main () {
    
    Nodo * trie = init_trie();

    printf("---Testes de Validacao---\n\n");
    
    printf("1. Teste de busca com a arvore vazia\n");
    if(!procura(trie, "algoritmo", 0)) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("2. Teste de insercao\n");
    if(insere(trie, "algoritmo", 0)) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("3. Teste de busca de palavra inserida\n");
    if(procura(trie, "algoritmo", 0)) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("4. Teste de busca de palavra ausente\n");
    if(!procura(trie, "dado", 0)) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("5. Teste de multiplas insercoes\n");
    if (insere(trie, "algarismo", 0)) {
        if (insere(trie, "dado", 0)) {
            if (insere(trie, "palavra", 0)) {
                if (!insere(trie, "dado", 0)) {
                    printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
                }
                else {
                    printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
                }
            }     
            else {
                printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
            }
        }
        else {
            printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
        }
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("6. Teste de multiplas buscas\n");
    if (procura(trie, "algarismo", 0)) {
        if (!procura(trie, "data", 0)) {
            if (!procura(trie, "parabola", 0)) {
                printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
            }
            else {
                printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
            }
        }
        else {
            printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
        }
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    trie = destroi_trie(trie);

    return 0;

}