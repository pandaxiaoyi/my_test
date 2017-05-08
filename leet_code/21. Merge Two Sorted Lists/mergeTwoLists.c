#include "string.h"

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	if (l1 == NULL && l2 == NULL)
		return NULL;
	struct ListNode *result = NULL;
	struct ListNode *tmp1;
	struct ListNode *tmp2 = result;
	
	if (l1 == NULL)/* 这里条件需要注意，两个没有依赖关系的 */
		return l2;
	else if (l2 == NULL)
		return l1;

	if (result == NULL)/* 链表头的处理应该可以简化的，归并到下面的处理中 */
	{
		if (l1->val < l2->val)
		{
			result = l1;
			l1 = l1->next;
		}
		else
		{
			result = l2;
			l2 = l2->next;
		}
	}
	tmp2 = result;
	while (l1 && l2)
	{
		tmp1 = (struct ListNode *)malloc(sizeof(struct ListNode));

		if (l1->val < l2->val)
		{
			tmp2->next = tmp1;
			tmp1->val = l1->val;
			tmp1->next = NULL;
			l1 = l1->next;
			tmp2 = tmp1;
		}
		else
		{
			tmp2->next = tmp1;
			tmp1->val = l2->val;
			tmp1->next = NULL;
			l2 = l2->next;
			tmp2 = tmp1;
		}
	}
	if (l1 == NULL)
		tmp2->next = l2;
	else
		tmp2->next = l1;

	return result;
}