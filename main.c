#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100

typedef struct Node {
    int value; // Значение узла (элемента) списка
    struct Node *next; // Указатель на следующий элемент списка
} C_Node;

// Добавление элемента
C_Node *push(C_Node *head, int number) {
    // Создаём новый узел
    C_Node *temp = (C_Node*) malloc(sizeof(C_Node));
    temp->value = number; // Присваиваем ему значение
    temp->next = head; // Присваиваем указателю temp адрес предыдущего узла
    return temp;
}


// Задание множества
C_Node *assignment(C_Node *head) {
    char input[16];
    while ((strcmp(input, "stop") != 0)) {
        puts("Enter the element:");
        scanf("%s", input);
        int number = atoi(input);
        if (number != 0 || *input == '0'){
            head = push(head, number);
        }
    }
    return head;
}

// Перевод из 10СС в 2СС
char* convert(int number) {
    int i = 0;
    if (number == 0) return "0";
    char *bin_number = (char *)malloc(LEN * sizeof(char));
    for (;number > 0; number >>= 1) {
        bin_number[i++] = (number & 1) + '0';
    }
    bin_number[i] = '\0';
    strrev(bin_number);
    return bin_number;
}

void printList(C_Node *head) {
    while (head) {
        printf("%d - %s\n", head->value, convert(head->value));
        head = head->next;
    }
}

int main() {
    C_Node* current_set = NULL;
    current_set = assignment(current_set);
    printList(current_set);
    return 0;
}

