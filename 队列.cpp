#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
  ElemType data[MAXSIZE];
  int front;
  int rear;
}Queue;

//��ʼ��
void initQueue(Queue *Q){
  Q->front = 0;
  Q->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *Q){
  if(Q->front == Q->rear){
    printf("�����ǿյ�\n");
    return 1;
  }
}

//����
int deQueue(Queue *Q){
  if (Q->front == Q->rear) {
    printf("�յ�");
    return 0;
  }
  ElemType e = Q->data[Q->front];
  Q->front++;
  return e;
}

//���� �������У�������ǰ�ƶ���
int queueFull(Queue *Q) {
  if (Q->front > 0) {
    int step = Q->front;  //step��frontǰ��յĸ�����
    for (int i=Q->front; i<Q->rear; ++i) {
      Q->data[i-step]=Q->data[i];
    }
    Q->front=0;
    Q->rear=Q->rear-step;
    int step2 = MAXSIZE + 1 - Q->front;
    printf("����������ɣ���ʣ%d������",step2);
    return 1;
  }
  else {
    printf("�������");
    return 0;
  }
}

//���
int equeue(Queue *Q,ElemType e) {
  if (Q->rear >= MAXSIZE) {
    if (!queueFull(Q)) {
      printf("����");
      return 0;
    }
  }
  Q->data[Q->rear] = e;
  Q->rear++;
  return 0;
}

//���� ���
int scanfEqueue(Queue *Q) {
  if (Q->rear >= MAXSIZE) {
    if (!queueFull(Q)) {
      printf("����");
      return 0;
    }
  }
  printf("���������Ԫ�أ�");
  scanf("%d",&Q->data[Q->rear]);
  Q->rear++;
  return 0;
}

//��ȡ��ͷԪ��
int getHead(Queue *Q) {
  if (Q->rear == Q->front) {
    printf("�յ�");
    return 0;
  }
  printf("��ͷԪ��Ϊ��%d",Q->data[Q->front]);
  //ElemType e = Q->data[Q->front];
  return 1;
}




int main(){
  Queue Q;
  initQueue(&Q);
  equeue(&Q,10);
  equeue(&Q,20);
  equeue(&Q,30);
  deQueue(&Q);
  getHead(&Q);
  return 0;
}