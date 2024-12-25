#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Инициализация стека
void initialize(Stack* s) {
    s->top = -1;
}

// Проверка, пуст ли стек
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Проверка, заполнен ли стек
bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Добавление элемента в стек
bool push(Stack* s, int value) {
    if (isFull(s)) {
        return false; // Стек заполнен
    }
    s->arr[++s->top] = value;
    return true;
}

// Удаление элемента из стека
bool pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        return false; // Стек пуст
    }
    *value = s->arr[s->top--];
    return true;
}

// Получение верхнего элемента стека без его удаления
bool peek(Stack* s, int* value) {
    if (isEmpty(s)) {
        return false; // Стек пуст
    }
    *value = s->arr[s->top];
    return true;
}

int main() {
    Stack s;
    initialize(&s);

    // Тест 1: Проверка пустого стека
    printf("Тест 1: Проверка пустого стека\n");
    if (isEmpty(&s)) {
        printf("Стек пуст. Тест пройден.\n");
    }
    else {
        printf("Стек не пуст. Тест не пройден.\n");
    }

    // Тест 2: Добавление элементов в стек
    printf("\nТест 2: Добавление элементов в стек\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    int value;
    if (peek(&s, &value)) {
        printf("Верхний элемент: %d. Тест пройден.\n", value);
    }
    else {
        printf("Не удалось получить верхний элемент. Тест не пройден.\n");
    }

    // Тест 3: Удаление элементов из стека
    printf("\nТест 3: Удаление элементов из стека\n");
    if (pop(&s, &value)) {
        printf("Удаленный элемент: %d. Тест пройден.\n", value);
    }
    else {
        printf("Не удалось удалить элемент. Тест не пройден.\n");
    }
    if (peek(&s, &value)) {
        printf("Верхний элемент: %d. Тест пройден.\n", value);
    }
    else {
        printf("Не удалось получить верхний элемент. Тест не пройден.\n");
    }

    // Тест 4: Проверка заполненности стека
    printf("\nТест 4: Проверка заполненности стека\n");
    for (int i = 0; i < MAX; i++) {
        if (!push(&s, i)) {
            printf("Стек заполнен. Тест пройден.\n");
            break;
        }
    }
    if (isFull(&s)) {
        printf("Стек заполнен. Тест пройден.\n");
    }
    else {
        printf("Стек не заполнен. Тест не пройден.\n");
    }

    // Тест 5: Удаление всех элементов из стека
    printf("\nТест 5: Удаление всех элементов из стека\n");
    while (!isEmpty(&s)) {
        if (pop(&s, &value)) {
            printf("Удаленный элемент: %d\n", value);
        }
        else {
            printf("Не удалось удалить элемент. Тест не пройден.\n");
            break;
        }
    }
    if (isEmpty(&s)) {
        printf("Стек пуст. Тест пройден.\n");
    }
    else {
        printf("Стек не пуст. Тест не пройден.\n");
    }

    return 0;
}
