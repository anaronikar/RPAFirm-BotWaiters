#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "PES2UG20CS062_H.h"

int main()
{
    int matrix[10][10] ;
    int i=0;
    int j=0;
    int startX, startY, endX, endY;
    FILE *f;

    f = fopen("input.txt", "r");
    char ch;
    node* first = NULL;
    queue* q;
    q = create_queue(q);
    
    //this segment is used to read the first two lines of the given file (input.txt)
    //and stores the coordinates - start and end coordinates
    startX = fgetc(f) - '0';
    fgetc(f);
    startY = fgetc(f) - '0';
    fgetc(f);
    endX = fgetc(f) - '0';
    fgetc(f);
    endY = fgetc(f) - '0';
    
    //this segment is used for conversion to a matrix, after reading from input.txt
    while((ch = fgetc(f)) != EOF)
    {
        if((ch != ' ') && (ch != '\n'))
        {   
            matrix[i][j] = ch - '0';
            j++;
            if(j==10)
            {
                i++;
                j = 0;
            }
        }
    }
    
    first = calc(first, matrix);
    q = find(first, q, matrix);
    store(q);
    fclose(f);

    return(0);
}
