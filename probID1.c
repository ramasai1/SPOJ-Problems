//
// Created by Ramasai Tadepalli on 12/2/16.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scanner = 0;
    int i = 0;
    int array[100];
    int x;
    while(stdin != EOF)
    {
        scanf("%d", &x);
        array[scanner] = x;
        if (x == 42)
        {
            for (; i < scanner; i++)
                printf("%d\n", array[i]);
        }
        scanner++;
    }
}