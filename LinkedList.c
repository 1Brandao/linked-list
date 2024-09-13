#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
typedef struct Node {
    int valor;
    struct Node* prox;
} node;

// Função para criar a lista (cabeça)
node* cria_lista() {
    if()
    return NULL; // Lista inicialmente vazia
}

// Função para inserir no início
node* insere_inicio(node* lista, int valor) {
    node* novo = (node*) malloc(sizeof(node));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

// Função para inserir no final
node* insere_fim(node* lista, int valor) {
    node* novo = (node*) malloc(sizeof(node));
    if (!novo) {
        printf("Erro ao alocar memória\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo; // Caso a lista esteja vazia
    }

    node* aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return lista;
}

// Função para exibir a lista
void exibe_lista(node* lista) {
    node* aux = lista;
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

// Função para liberar (desalocar) a lista
node* libera_lista(node* lista) {
    node* aux;
    while (lista != NULL) {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
    return NULL;
}

// Função para remover do início
node* remove_inicio(node* lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return lista;
    }
    node* aux = lista;
    lista = lista->prox;
    free(aux);
    return lista;
}

// Função para remover do fim
node* remove_fim(node* lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return lista;
    }
    if (lista->prox == NULL) {
        free(lista);
        return NULL;
    }
    node* aux = lista;
    node* anterior = NULL;
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
    node* lista = cria_lista();

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
