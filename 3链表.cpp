#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;  // int �� char

typedef struct node{
  ElemType data;
  struct node *next;
}Node;

//��ʼ������
Node* initList() {
  Node *head = (Node*)malloc(sizeof(Node));
  head->data = 0;
  head->next = NULL;
  return head;
}

//��ʼ���ڵ㣨���ڵ������������
Node* initListWithElem(ElemType e)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->data = e;
  node->next = NULL;
  return node;
}

//ͷ�巨 ����
int insertHead(Node* L,ElemType e) {
  Node *p =  (Node*)malloc(sizeof(Node));
  p->data = e;
  p->next = L->next;
  L->next = p;
  return 1;
}

//����
void listNode(Node* L) {
  Node *p = L->next;
  while (p!=NULL) {
    printf("%c ",p->data);  //%d �� %c
    p = p->next;
  }
  printf("\n");
}

//��ȡβ�ڵ�
Node *get_tail(Node* L) {
  Node *p = L;
  while (p->next!=NULL) {
    p = p->next;
  }
  return p;
}

//β�巨 ����
Node *insertTail(Node* tail,ElemType e) {
  Node *p = (Node*)malloc(sizeof(Node));
  p->data = e;
  tail->next = p;
  p->next = NULL;
  return p;
}

//β�巨���ڵ㣩
Node* insertTailWithNode(Node *tail, Node *node)
{
  tail->next = node;
  node->next = NULL;
  return node;
}

//ָ��λ�ò���
int insertNode(Node* L,int pos,ElemType e) {
  //������������ǰ��ϵ�ڵ�
  Node *p = L;
  int i = 0;

  //���������ҵ�����λ�õ�ǰ���ڵ�
  while (i<pos-1) {
    p = p->next;
    i++;
    if (p==NULL) {
      return 0;
    }
  }

  //Ҫ������½ڵ�
  Node *q = (Node*)malloc(sizeof(Node));
  q->data = e;
  q->next = p->next;
  p->next = q;
  return 1;
}

//ָ��λ��ɾ��
int deleteNode(Node* L,int pos) {
  //Ҫɾ���ڵ��ǰ��
  Node *p = L;
  int i = 0;

  //���������ҵ�ɾ���ڵ��ǰ��
  while (i<pos-1) {
    p = p->next;
    i++;
    if (p==NULL) {
      return 0;
    }
  }
  if (p->next == NULL) {
    printf("Ҫɾ���Ľڵ����\n");
    return 0;
  }

  //qָ��Ҫɾ���Ľڵ�
  Node *q = p->next;
  //��Ҫɾ���ڵ��ǰ��ָ��Ҫɾ���ڵ�ĺ��
  p->next = q->next;
  //�ͷ�Ҫɾ���ڵ���ڴ�ռ�
  free(q);
  return 1;
}

//��ȡ������
int listLength(Node *L) {
  Node *p = L;
  int len=0;
  while (p!=NULL) {
    p=p->next;
    len++;
  }
  return len-1; //ͷ�ڵ�Ҳ��һ������
}

//�ͷ�����
void freeList(Node* L) {
  Node *p = L->next;
  Node *q;

  while(p!=NULL) {
    q=p->next;
    free(p);
    p=q;
  }
  L->next = NULL;
}

//���ҵ�����k���ڵ㣨����ָ�룩
int findNodeFS(Node *L, int k) {
  Node *fast = L->next;
  Node *slow = L->next;

  for (int i = 0; i<k;i++) {
    fast = fast->next;
  }
  while (fast!=NULL) {
    fast = fast->next;
    slow = slow->next;
  }
  printf("������%d���ڵ��ֵΪ��%d��\n",k,slow->data);
  return 1;
}

//���������ڵ㹲ͬ��׺����ʼλ��
Node* findIntersectionNode(Node *headA, Node *headB) {
  if (headA==NULL || headB==NULL) {
    return NULL;
  }

  Node *p = headA;
  int lenA = 0;
  int lenB = 0;

  //����A����ȡA�ĳ���
  while (p!=NULL) {
    p=p->next;
    lenA++;
  }
  //��������B����ȡ����B�ĳ���
  p=headB;
  while(p != NULL)
  {
    p = p->next;
    lenB++;
  }

  Node *fast;
  Node *slow;
  int step;//��������֮�������Ĳ�ֵ���������ڿ�ָ�����ߵĲ���
  if (lenA>lenB) {
    step = lenA-lenB;
    fast = headA;
    slow = headB;
  }
  else {
    step = lenB-lenA;
    fast = headB;
    slow = headA;
  }
  //�ÿ�ָ������step��
  for (int i = 0; i<step; i++) {
    fast = fast->next;
  }
  //����ָ��ͬ���ߣ�ֱ��ָ��ͬһ���ڵ��˳�ѭ��
  while (fast!=slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}




int main(){
  /*
  Node *list = initList();        //������Ϊ list
  Node *tail = get_tail(list);
  tail = insertTail(tail,10);
  tail = insertTail(tail,20);
  tail = insertTail(tail,30);
  listNode(list);
  insertNode(list,2,15);
  listNode(list);
  printf("%d\n",listLength(list));
  deleteNode(list,3);
  listNode(list);
  printf("%d\n",listLength(list));
  //freeList(list);
  //printf("%d\n",listLength(list));
  tail  = insertTail(tail, 30);
  tail  = insertTail(tail, 40);
  tail  = insertTail(tail, 50);
  tail  = insertTail(tail, 60);
  tail  = insertTail(tail, 70);
  listNode(list);
  findNodeFS(list,3);
  return 0;
  */
  Node *listA = initList();
  Node *listB = initList();
  Node *tailA = get_tail(listA);
  Node *tailB = get_tail(listB);
  tailA = insertTail(tailA, 'l');
  tailA = insertTail(tailA, 'o');
  tailA = insertTail(tailA, 'a');
  tailA = insertTail(tailA, 'd');
  tailB = insertTail(tailB, 'b');
  tailB = insertTail(tailB, 'e');

  Node *nodeI = initListWithElem('i');
  tailA = insertTailWithNode(tailA, nodeI);
  tailB = insertTailWithNode(tailB, nodeI);
  Node *nodeN = initListWithElem('n');
  tailA = insertTailWithNode(tailA, nodeN);
  tailB = insertTailWithNode(tailB, nodeN);
  Node *nodeG = initListWithElem('g');
  tailA = insertTailWithNode(tailA, nodeG);
  tailB = insertTailWithNode(tailB, nodeG);

  listNode(listA);
  listNode(listB);

  printf("%c\n",findIntersectionNode(listA,listB)->data);
  return 0;

}