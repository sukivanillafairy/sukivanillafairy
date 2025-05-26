#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
  ElemType data[MAXSIZE];
  int front;
  int rear;
}Queue;

//初始化
void initQueue(Queue *Q){
  Q->front = 0;
  Q->rear = 0;
}

//判断队列是否为空
int isQueueEmpty(Queue *Q){
  if(Q->front == Q->rear){
    printf("队列是空的\n");
    return 1;
  }
}

//出队
int deQueue(Queue *Q){
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
      Q->data[i-step]=Q->data[i];
    }
    Q->front=0;
    Q->rear=Q->rear-step;
    int step2 = MAXSIZE + 1 - Q->front;
    printf("调整队列完成，还剩%d个格子",step2);
    return 1;
  }
  else {
    printf("真的满了");
    return 0;
  }
}

//入队
int equeue(Queue *Q,ElemType e) {
  if (Q->rear >= MAXSIZE) {
    if (!queueFull(Q)) {
      printf("满了");
      return 0;
    }
  }
  Q->data[Q->rear] = e;
  Q->rear++;
  return 0;
}

//输入 入队
int scanfEqueue(Queue *Q) {
  if (Q->rear >= MAXSIZE) {
    if (!queueFull(Q)) {
      printf("满了");
      return 0;
    }
  }
  printf("请输入入队元素：");
  scanf("%d",&Q->data[Q->rear]);
  Q->rear++;
  return 0;
}

//获取对头元素
int getHead(Queue *Q) {
  if (Q->rear == Q->front) {
    printf("空的");
    return 0;
  }
  printf("对头元素为：%d",Q->data[Q->front]);
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