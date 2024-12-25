#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

// ������������� �����
void initialize(Stack* s) {
    s->top = -1;
}

// ��������, ���� �� ����
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// ��������, �������� �� ����
bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

// ���������� �������� � ����
bool push(Stack* s, int value) {
    if (isFull(s)) {
        return false; // ���� ��������
    }
    s->arr[++s->top] = value;
    return true;
}

// �������� �������� �� �����
bool pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        return false; // ���� ����
    }
    *value = s->arr[s->top--];
    return true;
}

// ��������� �������� �������� ����� ��� ��� ��������
bool peek(Stack* s, int* value) {
    if (isEmpty(s)) {
        return false; // ���� ����
    }
    *value = s->arr[s->top];
    return true;
}

int main() {
    Stack s;
    initialize(&s);

    // ���� 1: �������� ������� �����
    printf("���� 1: �������� ������� �����\n");
    if (isEmpty(&s)) {
        printf("���� ����. ���� �������.\n");
    }
    else {
        printf("���� �� ����. ���� �� �������.\n");
    }

    // ���� 2: ���������� ��������� � ����
    printf("\n���� 2: ���������� ��������� � ����\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    int value;
    if (peek(&s, &value)) {
        printf("������� �������: %d. ���� �������.\n", value);
    }
    else {
        printf("�� ������� �������� ������� �������. ���� �� �������.\n");
    }

    // ���� 3: �������� ��������� �� �����
    printf("\n���� 3: �������� ��������� �� �����\n");
    if (pop(&s, &value)) {
        printf("��������� �������: %d. ���� �������.\n", value);
    }
    else {
        printf("�� ������� ������� �������. ���� �� �������.\n");
    }
    if (peek(&s, &value)) {
        printf("������� �������: %d. ���� �������.\n", value);
    }
    else {
        printf("�� ������� �������� ������� �������. ���� �� �������.\n");
    }

    // ���� 4: �������� ������������� �����
    printf("\n���� 4: �������� ������������� �����\n");
    for (int i = 0; i < MAX; i++) {
        if (!push(&s, i)) {
            printf("���� ��������. ���� �������.\n");
            break;
        }
    }
    if (isFull(&s)) {
        printf("���� ��������. ���� �������.\n");
    }
    else {
        printf("���� �� ��������. ���� �� �������.\n");
    }

    // ���� 5: �������� ���� ��������� �� �����
    printf("\n���� 5: �������� ���� ��������� �� �����\n");
    while (!isEmpty(&s)) {
        if (pop(&s, &value)) {
            printf("��������� �������: %d\n", value);
        }
        else {
            printf("�� ������� ������� �������. ���� �� �������.\n");
            break;
        }
    }
    if (isEmpty(&s)) {
        printf("���� ����. ���� �������.\n");
    }
    else {
        printf("���� �� ����. ���� �� �������.\n");
    }

    return 0;
}
