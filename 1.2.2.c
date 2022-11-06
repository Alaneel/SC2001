#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *next;
} ListNode;

typedef struct linkedlist {
    int size;
    struct node *head;
} LinkedList;

ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

int main()
{
    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;

    ListNode *pt;
    int a = 0;

    insertNode(&ll, 0, 2);
    insertNode(&ll, 0, 5);
    insertNode(&ll, 1, 4);
    insertNode(&ll, 2, 6);

    printf("Enter the number to be found: \n");
    scanf("%d", &a);

    pt = ll.head;
    while (pt->item < a || pt->item > a)
    {
        pt = pt->next;
        if (pt == NULL) break;
    }

    if (pt == NULL) printf("Not found!\n");
    else printf("Found!\n");

    return 0;
}

ListNode *findNode(LinkedList *ll, int index)
{
    ListNode *tmp = ll->head;

    if (tmp == NULL || index < 0) return NULL;

    while (index > 0)
    {
        tmp = tmp->next;
        if (tmp == NULL) return NULL;
        index--;
    }
    return tmp;
}

int insertNode(LinkedList *ll, int index, int value)
{
    ListNode *pre, *cur;

    if (ll->head == NULL || index == 0)
    {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        (ll->size)++;
        return 0;
    }

    if (findNode(ll, index-1) != NULL)
    {
        pre = findNode(ll, index-1);
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        (ll->size)++;
        return 0;
    }
    return -1;
}

int removeNode(LinkedList *ll, int index)
{
    ListNode *pre, *cur;

    if (ll->head->next == NULL || index == 0)
    {
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        (ll->size)--;
        return 0;
    }

    if (findNode(ll, index-1) != NULL)
    {
        pre = findNode(ll, index-1);
        cur = pre->next->next;
        free(pre->next);
        pre->next = cur;
        (ll->size)--;
        return 0;
    }
    return -1;
}