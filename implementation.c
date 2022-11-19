#include<stdio.h>
#include<stdlib.h>

#include "PES2UG20CS062_H.h"

queue* create_queue()
{
    queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->first = q->last = NULL;
    return q;
}

void rightNode(node** start, int x, int y, int value)
{
    node *new, *temp;
    new = *start;

    if(new == NULL)
    {
        new = malloc(sizeof(node));
        new->x = x;
        new->y = y;
        new->value = value;
        *start = new;       
    }

    else
    {
        while(new->right != NULL)
        {
            new = new->right;
        }
        temp = malloc(sizeof(node));
        temp->x = x;
        temp->y = y;
        temp->value = value;
        new->right = temp;
        temp->right = NULL;
    }
}

void downNode(node* start)
{
    node* d_first = start;
    node* d_second = d_first->right;   
    while(d_first->x < 9)
    {
        while(d_second->y != d_first->y)
        {
            d_second = d_second->right;
            if(d_second == NULL)
                break;
        }
        d_first->down = d_second;
        d_first = d_first->right;
        d_second = d_first->right;  
    } 
}

node* calc(node* start, int matrix[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(matrix[i][j] == 0)
            { 
                rightNode(&start, i, j, 0);             
            }  
            
        }
    }
    downNode(start);
    return start;
}


queue* find(node* start, queue *q, int matrix[10][10])
{
    int i = 0;
    node* d_begin = start;

    for(int j=1; j<=10; j++)
    {


        if (q->last == NULL)
        {
            q->first = q->last = d_begin;
        }

        else
        {
            q->last->right = d_begin;
            q->last = d_begin;
        }
        

        if(matrix[i][j] == 1 || (matrix[i+1][j] == 1 && matrix[i][j+1] == 1))
        {
            d_begin = d_begin->down;
            i++;
            j--;
        }
        
        else
        {
            d_begin = d_begin->right;
        }
    }
    return q;
}

void store(queue *q)
{

    FILE* f_final = fopen("output.txt", "w");
    node *d1;

    if(q->first == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        d1 = q->first;
        while(d1!= NULL)
        {
            fprintf(f_final, "%d %d\n", d1->x, d1->y);
            d1 = d1->right;
        }
    }
}