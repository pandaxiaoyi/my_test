#include "string.h"
struct ListNode {
	int val;
	struct ListNode *next;
};
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *current1;
	struct ListNode *current2;
	int value1;
	int value2;
	int sum;
	int inter = 0;
	current1 = l1;
	current2 = l2;
	struct ListNode *result = NULL;
	struct ListNode *tmp;
	struct ListNode *tmp2;
	while (current1 != NULL && current2 != NULL)
	{
		tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (result == NULL)
		{
			tmp2 = tmp;
		}
		else
		{
			result->next = tmp;
		}
		result = tmp;
		value1 = current1->val;
		value2 = current2->val;
		sum = value1 + value2 + inter;
		if (sum >= 10)
		{
			inter = 1;
			sum -= 10;
		}
		else
		{
			inter = 0;
		}
		tmp->val = sum; 
		tmp->next = NULL;
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 != NULL)
	{
		tmp->next = current1;
	}
	else
	{
		tmp->next = current2;
	}
	while (inter != 0)
	{
		if (tmp->next == NULL)
		{
			tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			tmp->next->val = 1;
			tmp->next->next = NULL;
			inter = 0;
		}
		else
		{
			tmp->next->val += 1;
			inter = 0;
			if (tmp->next->val >= 10)
			{
				inter = 1;
				tmp->next->val -= 10;
			}
			tmp = tmp->next;
		}
	}
	return tmp2;
}