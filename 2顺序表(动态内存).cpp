#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

//顺序表定义
typedef struct {
    ElemType *data;
    int length;
}SeqList;

//初始化顺序表——动态分配内存
SeqList* initList() {
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));
    L->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    return L;
}

//添加尾部元素
int appendElem(SeqList *L, ElemType e) {
    if (L->length >= MAXSIZE) {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

//遍历
void listElem(SeqList *L) {
    if (L->length == 0) {
        printf("空表。\n");
    }
    for (int i=0;i<L->length;i++)
        printf("%d ", L->data[i]);
    printf("\n");
}

//插入数据
int insertElem(SeqList *L, int pos, ElemType e) {
    if (pos >= L->length) {
        printf("表满了。\n");
        return 0;
    }
    if (pos<1||pos>L->length) {
        printf("插入位置错误");
        return 0;
    }
    if (pos<=L->length) {
        for (int i=L->length;i>=pos-1;i--) //错误的是int i = L->length-1; i >= pos-1; i--
            L->data[i+1] = L->data[i];
        L->data[pos-1] = e;
        L->length++;
    }
    return 1;
}

//删除数据
int deleteElem(SeqList *L, int pos, ElemType *e) {
    if (L->length == 0) {
        printf("空表。\n");
        return 0;
    }
    if (pos<1||pos>L->length) {
        printf("删除数据位置有误。\n");
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

//查找数据位置
int findElem(SeqList *L, ElemType e) {
    if (L->length == 0) {
        printf("空表。\n");
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
    //声明一个线性表并初始化
    SeqList *list = initList();

    printf("初始化成功，目前长度占用%d\n",list->length);
    printf("目前占用内存%zu字节\n", sizeof(list->data));
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
    printf("被删除的数据为：%d\n", delData);
    listElem(list);
    printf("%d\n", findElem(list, 40));
    return 0;
}