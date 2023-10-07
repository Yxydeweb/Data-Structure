#define  _CRT_SECURE_NO_WARNINGS
#define Init_Max_Size 10
#define Increasement 20
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    char data[Init_Max_Size];
    int top, rear;
}Stack;
Stack* InitStack() {
    Stack *stack= (Stack*)malloc(sizeof(Stack));
    stack->rear = 0;
    stack->top = 0;
    return stack;
}
void Push(Stack* stack,char data) {
        stack->data[stack->top++] = data;
}
void Pop(Stack* stack) {
    if (!Empty(stack)) stack->top--;
    else printf("栈为空，无法出栈！\n");
}
void Print(Stack* stack) {
    if (Empty(stack)) printf("栈为空，无法打印！\n");
    else
    {
        for (int i = stack->rear; i < stack->top; i++)
            printf("%c\n", stack->data[i]);
    }
}
int Empty(Stack* stack) {
    if (stack->rear == stack->top) return 1;
    else return 0;
}
char GetTop(Stack* stack) {
    if (!Empty(stack)) return stack->data[stack->top - 1];
    else printf("栈为空，无栈顶元素！\n");
}
void Khpp(char s[]) {
    Stack* stack = InitStack();
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            Push(stack, s[i]);
        }
        else if (s[i] == ')' && GetTop(stack) == '(') {
            Pop(stack);
        }
        else {
            printf("匹配失败！\n");
            return;
        }
        
    }
    if (Empty(stack)) {
        free(stack);
        printf("匹配成功！\n");
    }
    else printf("匹配失败！\n");
}
int main() {
    
    char s[100];
    scanf("%s", s);
    Khpp(s);
    return 0;
}
