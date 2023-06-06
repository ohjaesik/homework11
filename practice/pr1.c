#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    int num;
    struct list *next;
}listNode;
typedef struct header{
    struct list *head;
}headNode;
int freeList(headNode *h){
    listNode* p = h->head;
    listNode* prev = NULL;
    while(p->next != NULL){
        prev = p;
        p = p->next;
        free(prev);
    }
    free(h);
    return 0;
}
int init(headNode** h){
    if(*h != NULL){
        freeList(*h);
    }
    *h = (headNode *)malloc(sizeof(headNode));
    (*h)->head = NULL;
    return 1;
}

int insertLast(headNode *h, int key){
    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->num = key;
    node->next = NULL;

    if(h->head == NULL){
        h->head = node;
        return 0;
    }

    listNode* n = h->head;
    while(n->next != NULL){
        n=n->next;
    }
    n->next=node;
    return 0;
}
int main(){
    int n;
    headNode *header = NULL;
    scanf("%d", &n);

    init(&header);

    for(int i =1; i<=n; i++){
        insertLast(header, i);
    }

    listNode *p;
    p = header->head;

    while(p!=NULL){
        printf("%d ", p->num);
        p = p->next;
    }
    freeList(header);
}