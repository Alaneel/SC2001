// Heap Sort

#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

typedef struct btnode {
    int key;
    struct btnode *left;
    struct btnode *right;
} BTNode;

BTNode *newNode(int value);
BTNode *insertNode(BTNode *root, int value);
void fixHeap(BTNode *H, int k);
void heapifying(BTNode *H);
void constructHeap(int slot[], BTNode *H);
void deleteMax(BTNode *H);
void heapSort(int slot[], int n);
void fixHeap_iter(BTNode *H, int k);

int main()
{
    int slot[SIZE] = {77, 15, 96, 89, 42, 80, 93};
    int k;

    printf("Before sorting:\n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    heapSort(slot, SIZE);

    printf("After sorting: \n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    return 0;
}

BTNode *newNode(int value)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BTNode *insertNode(BTNode *root, int value)
{
    BTNode *cur = root;
    if (root == NULL) return newNode(value);
    else
    {
        if (root->key > value)
        {
            cur = insertNode(root->left, value);
            root->left = cur;
        }
        else 
        {
            cur = insertNode(root->right, value);
            root->right = cur;
        }
    }

    return root;
}

void fixHeap(BTNode *H, int k) // recursive
{
    BTNode *largestSubHeap = NULL;

    if (H->left == NULL && H->right == NULL)
    {
        // insert k in root of H
        H->key = k;
    }
    else
    {
        if (H->left == NULL) largestSubHeap = H->right;
        else if (H->right == NULL) largestSubHeap = H->left;
        // compare left child with right child, and largestSubHeap = the larget child of H
        else largestSubHeap = (H->left->key > H->right->key) ? H->left : H->right;

        // if (k >= key of root(largetSubHeap)) insert k in root of H
        if (k >= largestSubHeap->key) H->key = k;
        // else
        // {
            // insert root(largestSubHeap) in root of H
            // fixHeap(largestSubHeap, k)
        // }
        else
        {
            H->key = largestSubHeap->key;
            fixHeap(largestSubHeap, k);
        }
    }
}

void heapifying(BTNode *H)
{
    int k = 0;

    if (H->left != NULL || H->right != NULL)
    {
        if (H->left != NULL) heapifying(H->left);
        if (H->right != NULL) heapifying(H->right);
        k = H->key;
        fixHeap(H, k);
    }
}

void constructHeap(int slot[], BTNode *H)
{
    int i = 0;
    BTNode *cur = H, *next = H;
    H->key = 0;
    H->left = NULL;
    H->right = NULL;

    // put all elements of array into a heap structure H in arbitrary order
    for (i=0; i<SIZE; i++)
    {
        next = insertNode(cur, slot[i]);
        cur = next;
    }
    H = cur;
    heapifying(H);
}

void deleteMax(BTNode *H)
{
    int k = 0;

    // copy the rightmost element at the lowest level to k
    k = H->key;
    // delete the rightmost element at the lowest level
    H->key = 0;
    fixHeap(H, 0);
}

void heapSort(int slot[], int n)
{
    BTNode H;
    int i = 0, curMax = 0;

    constructHeap(slot, &H);
    for (i=n-1; i>=0; i--)
    {
        curMax = H.key;
        deleteMax(&H); // as a result, H has i-1 elements
        slot[i] = curMax; // insert curMax in sorted list
    }
}