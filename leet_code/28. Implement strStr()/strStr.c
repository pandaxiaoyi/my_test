#include "string.h"
int if_equal(char* haystack, char* needle)
{
	if (*haystack != *needle)//�����ͷ�������ֱ�ӷ��أ���ʡʱ��
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
	int len = strlen(haystack);//���Ƚ�����ȡ�������������Ƕ�̬�仯��
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