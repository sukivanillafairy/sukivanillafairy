#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct{
  ElemType data[MAXSIZE];
  int top;
}Stack;

//��ʼ��
void initStack(Stack *s)
{
  s->top=-1;
}

//�ж��Ƿ�Ϊ��
int isStackEmpty(Stack *s){
  if(s->top==-1)
  {
    printf("ջ�ǿյ�\n");
    return 1;
  }
  else{
    return 0;
  }
}

//��ջ
int push(Stack *s,ElemType e) {
  if(s->top >= MAXSIZE-1) {
    printf("ջ����");
    return 0;
  }
  s->top++;
  s->data[s->top]=e; // Ҳ����ɾ�� ��s->top++�� ; �ĳ� ��++s->top��
  return 1;
}

//��ջ
int pop(Stack *s,ElemType *e) {
  if(s->top == -1) {
    printf("ջ��");
    return 0;
  }
  *e=s->data[s->top];
  s->top--;
  return 1;
}

//��ȡջ��Ԫ��
int getTop(Stack *s,ElemType *e) {
  if(s->top == -1) {
    printf("�յ�");
    return 0;
  }
  *e=s->data[s->top];
  return 1;
}

int main(){
  Stack s;
  initStack(&s);
  push(&s,10);
  push(&s,20);
  push(&s,30);
  ElemType e;
  pop(&s,&e);
  printf("%d\n",e);
  getTop(&s,&e);
  printf("%d\n",e);

  return 0;
}