#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Função para criar a lista (cabeça)
Node* cria_lista() {
    if()
    return NULL; // Lista inicialmente vazia
}

// Função para inserir no início
Node* insere_inicio(Node* lista, int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

// Função para inserir no final
Node* insere_fim(Node* lista, int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo; // Caso a lista esteja vazia
    }

    Node* aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return lista;
}

// Função para exibir a lista
void exibe_lista(Node* lista) {
    Node* aux = lista;
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

// Função para liberar (desalocar) a lista
Node* libera_lista(Node* lista) {
    Node* aux;
    while (lista != NULL) {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
    return NULL;
}

// Função para remover do início
Node* remove_inicio(Node* lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return lista;
    }
    Node* aux = lista;
    lista = lista->prox;
    free(aux);
    return lista;
}

// Função para remover do fim
Node* remove_fim(Node* lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return lista;
    }
    if (lista->prox == NULL) {
        free(lista);
        return NULL;
    }
    Node* aux = lista;
    Node* anterior = NULL;
    while (aux->prox != NULL) {
        anterior = aux;
        aux = aux->prox;
    }
    anterior->prox = NULL;
    free(aux);
    return lista;
}

// Função principal para teste
int main() {
    Node* lista = cria_lista();

    lista = insere_inicio(lista, 10);
    lista = insere_inicio(lista, 20);
    lista = insere_fim(lista, 30);

    exibe_lista(lista); // Deve exibir: 20 -> 10 -> 30 -> NULL

    lista = remove_inicio(lista);
    exibe_lista(lista); // Deve exibir: 10 -> 30 -> NULL

    lista = remove_fim(lista);
    exibe_lista(lista); // Deve exibir: 10 -> NULL

    lista = libera_lista(lista);
    exibe_lista(lista); // Deve exibir: NULL

    return 0;
}
