#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int count, i, j, swap, temp;
    int nums[10];
    time_t t;
    srand(time(&t));

    for (count = 0; count < 10; count++)
    {
        nums[count] = (rand() % 99) + 1;
        printf("%d\n", nums[count]);
    }
    
    for (j = 0; j < 9; j++)
    {
        swap = 0;
        printf("\nPass %d:\n", j + 1);
        
        for (i = j; i < 10; i++)
        {
            printf("i = %d, j = %d\n", i, j);
            
            if (nums[i] < nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                swap = 1;
            }
            
            // Print the updated array after each swap
            printf("Updated Array: ");
            for (count = 0; count < 10; count++)
            {
                printf("%d ", nums[count]);
            }
            printf("\n");
        }
        
        if (swap == 0)
        {
            break;
        }
    }

    printf("\nSorted list:\n");
    for (count = 0; count < 10; count++)
    {
        printf("%d\n", nums[count]);
    }

    return 0;
}

