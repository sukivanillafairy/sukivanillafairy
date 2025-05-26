#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

//˳�����
typedef struct {
    ElemType *data;
    int length;
}SeqList;

//��ʼ��˳�������̬�����ڴ�
SeqList* initList() {
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));
    L->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    return L;
}

//���β��Ԫ��
int appendElem(SeqList *L, ElemType e) {
    if (L->length >= MAXSIZE) {
        printf("˳�������\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

//����
void listElem(SeqList *L) {
    if (L->length == 0) {
        printf("�ձ�\n");
    }
    for (int i=0;i<L->length;i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

//��������
int insertElem(SeqList *L, int pos, ElemType e) {
    if (pos >= L->length) {
        printf("�����ˡ�\n");
        return 0;
    }
    if (pos<1||pos>L->length) {
        printf("����λ�ô���");
        return 0;
    }
    if (pos<=L->length) {
        for (int i=L->length;i>=pos-1;i--) //�������int i = L->length-1; i >= pos-1; i--
            L->data[i+1] = L->data[i];
        L->data[pos-1] = e;
        L->length++;
    }
    return 1;
}

//ɾ������
int deleteElem(SeqList *L, int pos, ElemType *e) {
    if (L->length == 0) {
        printf("�ձ�\n");
        return 0;
    }
    if (pos<1||pos>L->length) {
        printf("ɾ������λ������\n");
        return 0;
    }
    *e=L->data[pos-1];
    if (pos<L->length) {
        for (int i=pos;i<L->length;i++) {
            L->data[i-1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}

//��������λ��
int findElem(SeqList *L, ElemType e) {
    if (L->length == 0) {
        printf("�ձ�\n");
        return 0;
    }
    for (int i=0;i<L->length;i++) {
        if (L->data[i] == e) {
            return i+1;
        }
    }
    return 0;
}

int main()
{
    //����һ�����Ա���ʼ��
    SeqList *list = initList();

    printf("��ʼ���ɹ���Ŀǰ����ռ��%d\n",list->length);
    printf("Ŀǰռ���ڴ�%zu�ֽ�\n", sizeof(list->data));
    appendElem(list, 88);
    appendElem(list, 67);
    appendElem(list, 40);
    appendElem(list, 8);
    appendElem(list, 23);
    listElem(list);
    insertElem(list, 1, 18);
    listElem(list);
    ElemType delData;
    deleteElem(list, 2, &delData);
    printf("��ɾ��������Ϊ��%d\n", delData);
    listElem(list);
    printf("%d\n", findElem(list, 40));
    return 0;
}