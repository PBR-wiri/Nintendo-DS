#include <stdio.h>

#define MAX_SIZE 100

typedef struct ArrayList
{
    int list[MAX_SIZE];
    int length;
}ArrayList;

void init(ArrayList *L)
{
    L->length=0;
}

void add(ArrayList *L,int target, int val)
{
    if(target-1>=0 && target-1<=L->length)
    {
        for(int i=L->length-1; i>=target-1; i--)
        {
            L->list[i+1]=L->list[i];
        }
        L->list[target-1]=val;
        L->length++;
    }
}

void delete(ArrayList *L,int target)
{
    if(target>=0 && target<=L->length)
    {
        for(int i=target-1; i<(L->length-1); i++)
        {
            L->list[i]=L->list[i+1];
        }
    }
    L->length--;
}

void replace(ArrayList *L, int target, int val)
{
    if(target<= L->length)
    {
        L->list[target-1]=val;
    }
}

void findVal(ArrayList *L, int val)
{
    int total=0;
    for(int i=L->length-1; i>=0; i--)
    {
        if(L->list[i]==val)
        {
            printf("find %d at %d", val, i);
            break;
        }
        total++;
    }
    if(total==L->length)
    {
        printf("can't find %d",val);
    }
}

void search(ArrayList *L, int target)
{
    if(target<= L->length)
    {   
        printf("%d\n",L->list[target-1]);
    }
    else
    {
        printf("out of range\n");
    }
}

void clear(ArrayList *L)
{
    L->length =0;
}

void printList(ArrayList*L)
{
    printf("%d\n",L->length);
    for(int i=0;i<L->length;i++)
    {
        printf("%d %d\n",i,L->list[i]);
    }
}

int main()//타겟 입력은 1부터 시작
{
    ArrayList list1;
    init(&list1);
    add(&list1,1,5);
    add(&list1,1,4);
    add(&list1,1,3);
    add(&list1,1,2);
    add(&list1,1,1);
    add(&list1,3,10);
    delete(&list1,1);
    replace(&list1,5,10);
    printList(&list1);
    search(&list1,55);
    findVal(&list1,55);
}