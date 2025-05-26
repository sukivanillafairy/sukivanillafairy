#include <stdio.h>
#include <stdlib.h>

#define stacksize 10

typedef struct sqstack {
    int data[stacksize];
    int top;
} SqStackTp;

typedef struct linked_queue {
    int data;
    struct linked_queue* next;
} LqueueTp;

typedef struct {
    LqueueTp* front;
    LqueueTp* rear;
} QueptrTp;

SqStackTp* init_stack() {
    SqStackTp* s = (SqStackTp*)malloc(sizeof(SqStackTp));
    s->top = -1;
    return s;
}

QueptrTp* init_queue() {
    QueptrTp* q = (QueptrTp*)malloc(sizeof(QueptrTp));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(QueptrTp* q, int x) {
    LqueueTp* new_node = (LqueueTp*)malloc(sizeof(LqueueTp));
    new_node->data = x;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(QueptrTp* q) {
    if (q->front == NULL) return -1;
    LqueueTp* temp = q->front;
    int value = temp->data;
    q->front = temp->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return value;
}

void car_leave(SqStackTp* park, SqStackTp* temp, QueptrTp* wait, int carnum) {
    int found = 0;
    temp->top = -1;

    while (park->top != -1) {
        int car = park->data[park->top--];
        if (car == carnum) {
            found = 1;
            printf("�� %d �뿪ͣ������\n", carnum);
            break;
        } else {
            temp->data[++temp->top] = car;
        }
    }

    if (!found) {
        printf("�� %d ����ͣ������\n", carnum);
        while (temp->top != -1) {
            park->data[++park->top] = temp->data[temp->top--];
        }
        return;
    }

    while (temp->top != -1) {
        park->data[++park->top] = temp->data[temp->top--];
    }

    if (wait->front != NULL && park->top < stacksize - 1) {
        int newcar = dequeue(wait);
        park->data[++park->top] = newcar;
        printf("�Ⱥ� %d ����ͣ������\n", newcar);
    }
}

int main() {
    SqStackTp* park = init_stack();
    SqStackTp* temp = init_stack();
    QueptrTp* wait = init_queue();

    int num;

    printf("��ӭʹ��ͣ��������ϵͳ��������������������������0 �˳�����\n");
    while (1) {
        printf("�����복�ţ�");
        scanf("%d", &num);
        if (num == 0) {
            printf("ϵͳ�˳���\n");
            break;
        } else if (num > 0) {
            if (park->top < stacksize - 1) {
                park->data[++park->top] = num;
                printf("�� %d ��ͣ��ͣ������\n", num);
            } else {
                enqueue(wait, num);
                printf("ͣ������������ %d �Ⱥ��ڱ����\n", num);
            }
        } else {
            int leavenum = -num;
            car_leave(park, temp, wait, leavenum);
        }
    }

    free(park);
    free(temp);
    while (wait->front != NULL) {
        LqueueTp* tmp = wait->front;
        wait->front = tmp->next;
        free(tmp);
    }
    free(wait);

    return 0;
}