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
    int number, count;
    puts("Enter the number of elements:");
    while (!scanf("%d", &count)) {
        fflush(stdin);
        puts("ERROR! Count of numbers must be integer!");
        puts("Enter the number of elements:");
    }
    for (int i = 0; i < count; i++) {
        puts("Enter the element:");
        while (!scanf("%d", &number)) {
            fflush(stdin);
            puts("Numbers must be integer!");
            puts("Enter the element:");
        }
        head = push(head, number);
    }
    return head;
}

// Вывод элемента
void printList(C_Node *head) {
    while (head) {
        printf("%d", head->value);
        head = head->next;
        putchar('\n');
    }
}

// Перевод из 10СС в 2СС
char* convert(int number) {
    int i = 0;
    char *bin_number = (char *)malloc(LEN * sizeof(char));
    while (number > 0) {
        bin_number[i++] = (number & 1) + '0';
        number >>= 1;
    }
    bin_number[i] = '\0';
    strrev(bin_number);
    return bin_number;
}

int main() {
    C_Node* current_set = NULL;
    current_set = assignment(current_set);
    while (current_set) {
        printf("%d - %s\n", current_set->value, convert(current_set->value));
        current_set = current_set->next;
    }
    return 0;
}
