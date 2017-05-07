#include "string.h"

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {
	int loop;
	int index = 0;
	int *result;
	result = (int *)malloc(2 * sizeof(int));
	while (index < numsSize - 1){
		for (loop = 0; loop < numsSize; loop++)
		{
			if (loop == index)
				continue;
			if (nums[index] + nums[loop] == target)
			{
				result[0] = index;
				result[1] = loop;
				return result;
			}
			if (loop == numsSize - 1)
				index += 1;
		}
	}
	return NULL;
}

