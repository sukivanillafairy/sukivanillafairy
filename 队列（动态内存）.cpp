#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
  ElemType *data;
  int front;
  int rear;
}Queue;

//初始化
Queue *initQueue(){
  Queue *Q = (Queue*)malloc(sizeof(Queue));
  Q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
  Q->front = 0;
  Q->rear = 0;
  return Q;
}

//判断队列是否为空
int isQueueEmpty(Queue *Q) {
  if (Q->front == Q->rear) {
    printf("空的\n");
    return 1;
  }
  else {
    printf("不是空的");
    return 0;
  }
}

//出队
int deQueue(Queue *Q) {
  if (Q->front == Q->rear) {
    printf("空的");
    return 0;
  }
  ElemType e = Q->data[Q->front];
  Q->front++;
  return e;
}

//队满 调整队列（依次往前移动）
int queueFull(Queue *Q) {
  if (Q->front > 0) {
    int step = Q->front;  //step是front前面空的格子数
    for (int i=Q->front; i<Q->rear; ++i) {
      Q->data[i-step] = Q->data[i];
    }
    Q->front = 0;
    Q->rear = Q->rear - step;
    int step2 = MAXSIZE + 1 - Q->front;
    printf("调整队列完成，还剩%d个格子",step2);
  }
  else {
    printf("真的满了");
    return 0;
  }
}

//入队
int equeue(Queue *Q, ElemType e) {
  if (Q->rear >= MAXSIZE) {
    if (!isQueueEmpty(Q)) {
      printf("真的满了");
    }
  }
  Q->data[Q->rear] = e;
  Q->rear++;
  return 1;
}

//输入 入队
int scanfEqueue(Queue *Q) {
  if (Q->rear >= MAXSIZE) {
    if (!isQueueEmpty(Q)) {
      printf("真的满了");
    }
  }
  printf("请输入进队元素：");
  scanf("%d",&Q->data[Q->rear]);
  Q->rear++;
  return 1;
}

//获取队头元素
int getHead(Queue *Q) {
  if (Q->rear == Q->front) {
    printf("空的");
    return 0;
  }
  printf("对头元素是：%d",Q->data[Q->front]);
  return 1;
}

int main(){
  Queue *Q = initQueue();
  //equeue(Q,10);
  //equeue(Q,20);
  //equeue(Q,30);

  scanfEqueue(Q);
  scanfEqueue(Q);
  scanfEqueue(Q);
  printf("出队元素是：%d\n",deQueue(Q));
  getHead(Q);
  return 0;
}