#include <stdio.h>
#include <stdlib.h>

void rotate(int nums[], int n, int k) {
    int i;
    k = k%n;
    printf("k=%d\n",k);
    int *a,*b;
    a = malloc((n-k)*sizeof(int));
    b = malloc((k)*sizeof(int));
    for (i=0;i<n-k;i++)
    {
        a[i] = nums[i];
        printf("a[%d]=%d\n",i,a[i]);
    }
    printf("\n");
    for (i=0;i<k;i++)
    {
        b[i] = nums[i+n-k];
        printf("b[%d]=%d\n",i,b[i]);
    }
    for (i=0;i<n;i++)
    {
        if (i<k)
            nums[i] = b[i];
        else
            nums[i] = a[i];
    }
    free(a);
    free(b);
}

int main()
{
    int i;
    int nums[] = {1,2};
    rotate(nums,2,1);
    for (i=0;i<2;i++)
        printf("%d ",nums[i]);
    return 0;
}

