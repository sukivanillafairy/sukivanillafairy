#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
  ElemType *data;
  int top;
}Stack;

//��ʼ��
Stack *initStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
  s->top = -1;
  return s;
}

//�ж��Ƿ�Ϊ��
int isempty(Stack *s) {
  if (s->top == -1) {
    printf("ջ�ǿյ�\n");
    return 1;
  }
  else {
    printf("ջ���ǿյ�\n");
    return 0;
  }
}

//��ջ
int push(Stack *s, ElemType e) {
  if (s->top == MAXSIZE - 1) {
    printf("����");
    return 0;
  }
  s->top++;
  s->data[s->top] = e;
  return 1;
}

//���� ��ջ
int scanfPush(Stack *s) {
  if (s->top == MAXSIZE - 1) {
    printf("����");
    return 0;
  }
  printf("�������ջԪ�أ�", s->data[s->top]);
  s->top++;
  scanf("%d", &s->data[s->top]);
  return 1;
}

//��ջ
int pop(Stack *s,ElemType *e) {
  if (s->top == -1) {
    printf("�յ�");
    return 0;
  }
  *e=s->data[s->top];
  s->top--;
  return 1;
}

//��ȡջ��Ԫ��
int getTop(Stack *s,ElemType *e) {
  if (s->top == -1) {
    printf("�յ�");
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
  printf("��ջԪ����%d\n",e);
  getTop(s,&e);
  printf("ջ��Ԫ����%d\n",e);
  return 0;
}