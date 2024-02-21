#include <stdio.h>
#include <string.h>

int main()
{
    char str[16];
    int len, i, j, k, num1, num2;
    int group_count = 0;
    
    // Input the string
    printf("Enter an integer (maximum 15 digits): ");
    scanf("%s", str);
    
    // Find the length of the string
    len = strlen(str);
    
    // Iterate through all possible groupings of the numbers
    for (i = 1; i < len; i++)
    {
        for (j = 0; j < i; j++)
        {
            // Extract the first number in the group
            num1 = 0;
            for (k = 0; k <= j; k++)
            {
                num1 = num1 * 10 + (str[k] - '0');
            }
            
            // Extract the second number in the group
            num2 = 0;
            for (k = j+1; k <= i; k++)
            {
                num2 = num2 * 10 + (str[k] - '0');
            }
            
            // Check if the numbers are in increasing order
            if (num1 < num2)
            {
                // Print the group
                if (group_count > 0)
                {
                    printf(" ");
                }
                printf("%d%d", num1, num2);
                group_count++;
            }
        }
    }
    
    // If no groups were printed, print a message
    if (group_count == 0)
    {
        printf("No groups found.");
    }
    printf("\n");
    
    return 0;
}

