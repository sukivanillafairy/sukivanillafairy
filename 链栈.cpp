#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct stack{
  ElemType data;
  struct stack *next;
}Stack;

//初始化
Stack *initStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = 0;
  s->next = NULL;
  return s;
}

//判断是否为空
int isEmptyStack(Stack *s) {
  if (s->next == NULL) {
    printf("空的");
    return 1;
  }
  else {
    printf("不是空的");
    return 0;
  }
}

//进栈（头插法）
int push(Stack *s, ElemType e) {
  Stack *p = (Stack *)malloc(sizeof(Stack));
  p->data = e;
  p->next = s->next;
  s->next = p;
  return 1;
}

//输入 进栈
int scanfPush(Stack *s) {
  Stack *p = (Stack *)malloc(sizeof(Stack));
  printf("请输入进栈元素：");
  scanf("%d",&p->data);
  p->next = s->next;
  s->next = p;
  return 1;
}

//出栈
int pop(Stack *s,ElemType *e) {
  if (s->next == NULL) {
    printf("空的");
    return 0;
  }
  *e= s->next->data;
  //printf("出栈元素是：%d",e);
  Stack *q = s->next;
  s->next = q->next;
  free(q);
  return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e) {
  if (s->next == NULL) {
    printf("空的");
    return 0;
  }
  *e = s->next->data;
  return 1;
}

int main(){
  Stack *s = initStack();
  //push(s,10);
  //push(s,20);
  //push(s,30);

  scanfPush(s);
  scanfPush(s);
  scanfPush(s);

  ElemType e;
  pop(s,&e);
  printf("出栈元素是：%d\n",e);
  getTop(s,&e);
  printf("栈顶元素是：%d\n",e);
  return 0;
}