#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int x;
    struct tnode *next;
    struct tnode *prev;
} *head, *tail, *curr;

void push_front(int value)
{
    struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    
    if (head == NULL)
    {
        head = tail = node;
        node->next = node->prev = NULL;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
        head->prev = NULL;
    }
}

void push_back(int value)
{
    struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    
    if (head == NULL)
    {
        head = tail = node;
        node->next = node->prev = NULL;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = NULL;
    }
}

void push_mid(int value, int searchKey)
{
    struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    
    curr = head;
    while (curr != NULL)
    {
        if (curr->x == searchKey)
        {
            if (curr == tail)
            {
                push_back(value);
            }
            else
            {
                node->next = curr->next;
                node->prev = curr;
                curr->next->prev = node;
                curr->next = node;
            }
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found\n", searchKey);
    free(node);
}

void pop_head()
{
    if (head == NULL) return;
    struct tnode *temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    else tail = NULL;
    free(temp);
}

void pop_tail()
{
    if (tail == NULL) return;
    struct tnode *temp = tail;
    tail = tail->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    free(temp);
}

void pop_mid(int searchKey)
{
    curr = head;
    while (curr != NULL)
    {
        if (curr->x == searchKey)
        {
            if (curr == head)
            {
                pop_head();
            }
            else if (curr == tail)
            {
                pop_tail();
            }
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found\n", searchKey);
}

void clearData()
{
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        free(curr);
    }
    tail = NULL;
}

void printList()
{
    if (head == NULL)
    {
        printf("There is No Data\n");
        return;
    }
    
    curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    push_front(11);
    push_back(90);
    push_front(78);
    push_back(50);
    push_mid(22, 90);
    push_mid(18, 78);
    
    printList();
    
    pop_head();
    printList();
    
    pop_tail();
    printList();
    
    pop_mid(90);
    printList();
    
    clearData();
    printList();
    
    return 0;
}
