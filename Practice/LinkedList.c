#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int val;
} Node;

void addNode(Node *target, int _val)
{
    Node *newNode=malloc(sizeof(Node));
    newNode->next=target->next;
    newNode->val=_val;
    target->next=newNode;
}

void removeNode(Node *target)
{
    Node *removeNode=target->next; // head의 다음 노드 를 저장
    target->next=removeNode->next; // 
    free(removeNode);
}

Node *findNode(Node *head, int _val)
{
    Node *curr=head->next;
    while(curr!=NULL)
    {
        if(curr->val==_val)
        {
            return curr;
        }
        curr=curr->next;
    }
    return NULL;
}

int main()
{
    int findNum;
    Node *head = malloc(sizeof(Node));

    Node *node1=malloc(sizeof(Node));
    head->next=node1;
    node1->val=1;

    Node *node2=malloc(sizeof(Node));//malloc =new, free= delete
    node1->next=node2;
    node2->val=2;

    Node *node3=malloc(sizeof(Node));
    node2->next=node3;
    node3->val=3;

    node3->next=NULL;

    addNode(head,10);
    addNode(node1,20);//head -> newNode -> node1 -> newNode -> node2 -> node3
    removeNode(head);//head -> node1 -> newNode ->node2 -> node3

    Node *curr=head->next;

    scanf("%d",&findNum);
    if(findNode(head,findNum)!=NULL)
    {
        printf("find val %d",findNode(head,findNum)->val);
    }
    else
    {
        printf("don't find val");
    }
    /*while(curr!=NULL)          //test print LinkList
    {
        printf("%d\n",curr->val);
        curr=curr->next;
    }*/

    free(node3);
    removeNode(node1);
    free(node2);
    free(node1);
    free(head);
    free(curr);

    return 0;
}