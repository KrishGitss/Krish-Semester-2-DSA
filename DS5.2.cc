#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct {
    int stArr[MAXSIZE];
    int top;
} STACK;

void create(STACK *s) { s->top = -1; }
bool isFull(STACK *s) { return s->top == MAXSIZE - 1; }
bool isEmpty(STACK *s) { return s->top == -1; }

void push(STACK *s, int data) {
    if (isFull(s)) { printf("Stack full. Cannot push %d.\n", data); return; }
    s->stArr[++(s->top)] = data;
    printf("%d pushed.\n", data);
}

int pop(STACK *s) {
    if (isEmpty(s)) { printf("Stack empty. Cannot pop.\n"); return -1; }
    return s->stArr[(s->top)--];
}

int peek(STACK *s) {
    if (isEmpty(s)) { printf("Stack empty. No element to peek.\n"); return -1; }
    return s->stArr[s->top];
}

int main() {
    STACK s;
    create(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Top: %d\n", peek(&s));

    printf("Empty? %s\n", isEmpty(&s) ? "Yes" : "No");
    printf("Full? %s\n", isFull(&s) ? "Yes" : "No");

    return 0;
}