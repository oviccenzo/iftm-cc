#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um n 
typedef struct Node {
    int data; // Dado
    struct Node* next; // Ponteiro para o pr ximo n 
} Node;

// Fun  o para inicializar a lista (ponteiro para a cabe a da lista)
void initializeList(Node** head) {
    *head = NULL;
}

// Fun  o para criar um novo n 
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun  o para inserir um n  no in cio da lista
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Fun  o para inserir um n  no final da lista
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fun  o para inserir um n  de forma ordenada na lista
void inserirOrdenado(Node** head, int data) {
    Node* newNode = createNode(data);

    // Caso 1: A lista está vazia ou o novo n  deve ser inserido no in cio
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Caso 2: Percorrer a lista para encontrar a posi  o correta
    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Inserir o novo n 
    newNode->next = current->next;
    current->next = newNode;
}

// Fun  o para remover um n  no in cio da lista
void removeFromBeginning(Node** head) {
    if (*head == NULL) {
        printf("Erro: Lista esta vazia!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Fun  o para remover um n  no final da lista
void removeFromEnd(Node** head) {
    if (*head == NULL) {
        printf("Erro: Lista esta vazia!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Fun  o para exibir os elementos da lista
void displayList(Node* head) {
    if (head == NULL) {
        printf("Lista esta vazia.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fun  o para buscar um valor na lista
Node* search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp; // Elemento encontrado
        }
        temp = temp->next;
    }
    return NULL; // Elemento n o encontrado
}

// Fun  o principal para testar as opera  es
int main() {
    Node* head;
    initializeList(&head);

    // Demonstrando a nova função: inserção ordenada
    printf("Testando a insercao ordenada na lista: \n");
    inserirOrdenado(&head, 25);
    displayList(head);
    inserirOrdenado(&head, 15);
    displayList(head);
    inserirOrdenado(&head, 35);
    displayList(head);
    inserirOrdenado(&head, 5);
    displayList(head);
    inserirOrdenado(&head, 30);
    displayList(head);

    // Testando as funções existentes
    printf("\nTestando as outras operacoes: \n");
    insertAtBeginning(&head, 100);
    printf("Lista apos insertAtBeginning(100): ");
    displayList(head);

    insertAtEnd(&head, 200);
    printf("Lista apos insertAtEnd(200): ");
    displayList(head);
    
    removeFromBeginning(&head);
    printf("Lista apos removeFromBeginning: ");
    displayList(head);
    
    removeFromEnd(&head);
    printf("Lista apos removeFromEnd: ");
    displayList(head);

    Node* found = search(head, 25);
    if (found) {
        printf("Elemento 25 encontrado na lista.\n");
    } else {
        printf("Elemento 25 nao encontrado na lista.\n");
    }

    found = search(head, 50);
    if (found) {
        printf("Elemento 50 encontrado na lista.\n");
    } else {
        printf("Elemento 50 nao encontrado na lista.\n");
    }

    return 0;
}
