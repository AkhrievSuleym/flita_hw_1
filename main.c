#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
    head = temp; // Присваиваем узлу head адрес нового узла
    return temp;
}

// Задание множества
C_Node *assignment(C_Node *head) {
    int number, count;
    while (1) {
        puts("Enter the number of elements:");
        if (scanf("%d", &count) == 1) break;
        fflush(stdin);
        puts("ERROR! Count of numbers must be integer!");
    }
    for (int i = 0; i < count; i++) {
        while (1) {
            puts("Enter the element:");
            if (scanf("%d", &number) == 1) {
                head = push(head, number);
                break;
            }
            fflush(stdin);
            puts("Numbers must be integer!");
        }
    }
    return head;
}

// Вывод элемента
void printList(C_Node *head) {
    while (head) {
        printf("%d", head->value);
        head = head->next;
        printf("\n");
    }
}

// Перевод из 10СС в 2СС
long long int convert(int number) {
    long long int bin_result = 0, i = 1;
    int remain;
    while (number != 0) {
        remain = number % 2;
        number /= 2;
        bin_result += remain * i;
        i *= 10;
        }
    return bin_result;
}

int main() {
    C_Node* current_set = NULL;
    current_set = assignment(current_set);
    while (current_set) {
        printf("%d - %lld\n", current_set->value, convert(current_set->value));
        current_set = current_set->next;
        }
    return 0;
}