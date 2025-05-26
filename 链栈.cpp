#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct stack{
  ElemType data;
  struct stack *next;
}Stack;

//��ʼ��
Stack *initStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = 0;
  s->next = NULL;
  return s;
}

//�ж��Ƿ�Ϊ��
int isEmptyStack(Stack *s) {
  if (s->next == NULL) {
    printf("�յ�");
    return 1;
  }
  else {
    printf("���ǿյ�");
    return 0;
  }
}

//��ջ��ͷ�巨��
int push(Stack *s, ElemType e) {
  Stack *p = (Stack *)malloc(sizeof(Stack));
  p->data = e;
  p->next = s->next;
  s->next = p;
  return 1;
}

//���� ��ջ
int scanfPush(Stack *s) {
  Stack *p = (Stack *)malloc(sizeof(Stack));
  printf("�������ջԪ�أ�");
  scanf("%d",&p->data);
  p->next = s->next;
  s->next = p;
  return 1;
}

//��ջ
int pop(Stack *s,ElemType *e) {
  if (s->next == NULL) {
    printf("�յ�");
    return 0;
  }
  *e= s->next->data;
  //printf("��ջԪ���ǣ�%d",e);
  Stack *q = s->next;
  s->next = q->next;
  free(q);
  return 1;
}

//��ȡջ��Ԫ��
int getTop(Stack *s,ElemType *e) {
  if (s->next == NULL) {
    printf("�յ�");
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
  printf("��ջԪ���ǣ�%d\n",e);
  getTop(s,&e);
  printf("ջ��Ԫ���ǣ�%d\n",e);
  return 0;
}