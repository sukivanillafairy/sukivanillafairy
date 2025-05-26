#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
  ElemType *data;
  int top;
}Stack;

//初始化
Stack *initStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
  s->top = -1;
  return s;
}

//判断是否为空
int isempty(Stack *s) {
  if (s->top == -1) {
    printf("栈是空的\n");
    return 1;
  }
  else {
    printf("栈不是空的\n");
    return 0;
  }
}

//进栈
int push(Stack *s, ElemType e) {
  if (s->top == MAXSIZE - 1) {
    printf("满了");
    return 0;
  }
  s->top++;
  s->data[s->top] = e;
  return 1;
}

//输入 进栈
int scanfPush(Stack *s) {
  if (s->top == MAXSIZE - 1) {
    printf("满了");
    return 0;
  }
  printf("请输入进栈元素：", s->data[s->top]);
  s->top++;
  scanf("%d", &s->data[s->top]);
  return 1;
}

//出栈
int pop(Stack *s,ElemType *e) {
  if (s->top == -1) {
    printf("空的");
    return 0;
  }
  *e=s->data[s->top];
  s->top--;
  return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e) {
  if (s->top == -1) {
    printf("空的");
    return 0;
  }
  *e=s->data[s->top];
  return 1;
}

int main()
{
  Stack *s = initStack();
  //push(s, 10);
  //push(s, 20);
  //push(s, 30);

  scanfPush(s);
  scanfPush(s);
  scanfPush(s);
  ElemType e;
  pop(s, &e);
  printf("出栈元素是%d\n",e);
  getTop(s,&e);
  printf("栈顶元素是%d\n",e);
  return 0;
}