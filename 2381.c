#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* x;
    struct Node* next;
} Node;

void insere_inicio(Node** root, char* value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(3);
    }

    new_node->x = malloc(strlen(value) + 1);
    if (new_node->x == NULL) {
        exit(3);
    }
    strcpy(new_node->x, value);

    new_node->next = *root;
    *root = new_node;
}

void insere_depois(Node* node, char* value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(4);
    }

    new_node->x = malloc(strlen(value) + 1);
    if (new_node->x == NULL) {
        exit(4);
    }
    strcpy(new_node->x, value);

    new_node->next = node->next;
    node->next = new_node;
}

void insere_organizado(Node** root, char* value) {
    if (*root == NULL || strcmp((*root)->x, value) >= 0) {
        insere_inicio(root, value);
        return;
    }

    Node* curr = *root;
    while (curr->next != NULL) {
        if (strcmp(curr->next->x, value) >= 0) {
            insere_depois(curr, value);
            return;
        }
        curr = curr->next;
    }

    insere_depois(curr, value);
}

void deallocate(Node** root) {
    Node* curr = *root;
    while (curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux->x);
        free(aux);
    }
    *root = NULL;
}

int main() {
    int N, K, j;
    char nome[20];
    Node* root = NULL;

    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < N; i++) {
        scanf("%19s", nome);
        insere_organizado(&root, nome);
    }

    Node* curr = root;
    for (j = 0; j < K - 1 && curr != NULL; j++) {
        curr = curr->next;
    }

    if (curr != NULL) {
        printf("%s\n", curr->x);
    } else {
        printf("K-ésimo nome não encontrado.\n");
    }

    deallocate(&root);

    return 0;
}
