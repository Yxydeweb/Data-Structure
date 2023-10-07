#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int data[1000];
    int rear, top;
}*Stack,stack;
Stack Create_stack() {
    Stack stack = (Stack)malloc(sizeof(stack));
    stack->rear = 0;
    stack->top = stack->rear;
}
void Push(Stack stack,int n) {
    stack->data[stack->top++] = n;
}
int Pop(Stack stack) {
    int n = stack->data[stack->top - 1];
    stack->top--;
    return n;
}
int Empty(Stack stack) {
    if (stack->rear == stack->top)return 1;
    else return 0;
}
int main() {
    Stack stack = Create_stack();
    int m;
    long long n;
    scanf("%lld%d", &n, &m);
    if (n == 0)Push(stack, n);
    else
        while (n) {
            Push(stack, n % m);
            n = n / m;
        }
    while (!Empty(stack)) {
        printf("%d ",Pop(stack) );
    }
}
