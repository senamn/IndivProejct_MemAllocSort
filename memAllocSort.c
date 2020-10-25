#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i=0, n = 1;
    int *pt;
    char *s = malloc(100);

// Print error message when memroy allocation fails
    if(!(pt=(int*)malloc(sizeof(int)))) 
    {
        printf("Memory allocation error"); 
        exit(1);
    }
    printf("Enter sequence of integers one per line (empty line indicates termination of the sequence): \n");

    while (n == 1)
    {
// Read in values
        //n = scanf("%[0-9]s", s);
        n = scanf("%[^\n]s", s);
// If there's no value input, break
        if (n == 0)
            break;
// Otherwise, continue
        i++;
        
        //printf("%s %d %d\n", s, i, x);
        if(!(pt = (int *) realloc(pt, i*sizeof(int)))) 
        {
            exit(0);
        }
        
        pt[i-1]=atoi(s);
        //*(pt+i-1) = x;
    // Clear input buffer
    scanf("%c", s);

// Clear buffer
    fflush(stdin);

    }

// Index array, arrays dinamically allocated
    int *pi[i];
    
// Sorting alg
    for (int k=0;k<i;k++)
    {
        pi[k] = pt + k;
        for (int m = k; m > 0; m--)
        {
            pi[m]=pt+k;
            // Compare value of current address and previous address
            if(*(pi[m])<*(pi[m-1])) 
            { 
                int *a = pi[m];
                pi[m]=pi[m-1];
                pi[m-1]=a;
            }
            else
            {
                break;
            }
        }
    }
// Print result
    for(int k=0;k<i;k++)
    {
        printf("%p %d\n", pi[k], *(pi[k]));
    }

    return 0;
}