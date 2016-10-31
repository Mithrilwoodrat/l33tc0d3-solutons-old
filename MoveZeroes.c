/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 */

int int_cmp(void *a, void *b)
{
    return *(int *)a == 0?1:0;
}

void moveZeroes(int *nums, int numSize)
{
    qsort(nums, numSize, sizeof(int), int_cmp);
}
