#include "string.h"
int if_equal(char* haystack, char* needle)
{
	if (*haystack != *needle)//如果开头不相等则直接返回，节省时间
		return 0;
	int num = strlen(needle);
	for (int i = 0; i < num; i++)
	{
		if (*(haystack + i) != *(needle + i))
			return 0;
	}
	return -1;
}
int strStr(char* haystack, char* needle) {
	if (*needle == '\0')
		return 0;
	int result = -1;
	int len = strlen(haystack);//首先将长度取出，否则下面是动态变化的
	do{
		result = result + 1;
		if (if_equal(haystack, needle) == -1)
		{
			return result;
		}
		if (result > len - strlen(needle))
			break;
		haystack = haystack + 1;
	} while (*haystack != '\0');
	return -1;
}
void main()
{
	char *str1 = "mississippi";
	char *str2 = "pi";

	printf("%d", strStr(str1, str2));
	return;
}