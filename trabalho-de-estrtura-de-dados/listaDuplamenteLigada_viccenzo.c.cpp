#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista duplamente ligada
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Estrutura da lista duplamente ligada
typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Fun  o para inicializar a lista
void initializeList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Fun  o para criar um novo n 
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de alocacao de memoria!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fun  o para inserir um n  no in cio da lista
void insertAtBeginning(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) { // Se a lista estiver vazia
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Fun  o para inserir um n  no final da lista
void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) { // Se a lista estiver vazia
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Fun  o adicional: Remover um n  em uma posi  o espec fica
void removerPorPosicao(DoublyLinkedList* list, int position) {
    if (list->head == NULL) {
        printf("Erro: Lista esta vazia!\n");
        return;
    }

    Node* temp = list->head;
    int i = 0;

    // Percorre a lista at  a posi  o desejada
    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    // Verifica se a posi  o   v lida
    if (temp == NULL) {
        printf("Erro: Posicao fora dos limites da lista!\n");
        return;
    }

    // Se o n  a ser removido   a cabe a
    if (temp->prev == NULL) {
        removeFromBeginning(list);
        return;
    }

    // Se o n  a ser removido   a cauda
    if (temp->next == NULL) {
        removeFromEnd(list);
        return;
    }

    // Caso geral: n  do meio
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}


// Fun  o para remover o primeiro n  da lista
void removeFromBeginning(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("Erro: Lista esta vazia!\n");
        return;
    }
    Node* temp = list->head;
    if (list->head == list->tail) { // Se houver apenas um elemento
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(temp);
}

// Fun  o para remover o  ltimo n  da lista
void removeFromEnd(DoublyLinkedList* list) {
    if (list->tail == NULL) {
        printf("Erro: Lista esta vazia\n");
        return;
    }
    Node* temp = list->tail;
    if (list->head == list->tail) { // Se houver apenas um elemento
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(temp);
}

// Fun  o para buscar um valor na lista
Node* search(DoublyLinkedList* list, int value) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == value) {
            return temp; // Valor encontrado
        }
        temp = temp->next;
    }
    return NULL; // Valor n o encontrado
}

// Fun  o para exibir a lista do in cio ao fim
void displayForward(DoublyLinkedList* list) {
    Node* temp = list->head;
    printf("Lista (cabeca para cauda): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Fun  o para exibir a lista do fim ao in cio
void displayBackward(DoublyLinkedList* list) {
    Node* temp = list->tail;
    printf("Lista (cauda para cabeca): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Programa principal
int main() {
    DoublyLinkedList list;
    initializeList(&list);

    // Inserindo valores na lista para teste
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    insertAtEnd(&list, 40);
    insertAtEnd(&list, 50);

    printf("Lista Duplamente Ligada! \n\n");
    printf("Lista inicial: ");
    displayForward(&list);

    // Testando a nova opera  o: remover um nó na posi  o 2 (o valor 30)
    printf("\nRemovendo no na posicao 2 (o terceiro elemento):\n");
    removerPorPosicao(&list, 2);
    printf("Lista apos remocao: ");
    displayForward(&list);

    // Testando a remo  o do primeiro nó
    printf("\nRemovendo o primeiro no:\n");
    removeFromBeginning(&list);
    printf("Lista apos remocao: ");
    displayForward(&list);

    // Testando a remo  o do  ltimo n 
    printf("\nRemovendo o ultimo no:\n");
    removeFromEnd(&list);
    printf("Lista apos remocao: ");
    displayForward(&list);

    return 0;
}
