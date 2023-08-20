#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int src = 1, dst = 0;
    while (src < numsSize)
    {
        if (nums[src] == nums[dst])
        {
            src++;
        }
        else
        {
            dst++;
            nums[dst] = nums[src];
        }
    }
    return dst;
}

int main()
{
	int arr[4] = { 1, 1, 2, 2 };
    removeDuplicates(arr, 4);
}