
#define N 6

void partition(int *array, int start, int end)
{
	int index;
	if (start < end)
	{
		index = quick_sort(array, start, end);
		partition(array, start, index - 1);
		partition(array, index + 1, end);
	}
}

int quick_sort(int *array,int start, int end)
{
	int result = start;
	int standard = array[end];
	int loop;
	int tmp;
	for (loop = start; loop < end; loop++)
	{
		if (array[loop] <= standard)
		{
			tmp = array[loop];
			array[loop] = array[result];
			array[result] = tmp;
			result++;
		}
	}
	array[end] = array[result];
	array[result] = standard;
	return result;
}
int main(void){
	int i;
	int arr[N] = { 32, 12, 7, 78, 23, 45 };
	printf("ÅÅĞòÇ° \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	partition(arr, 0, N - 1);
	printf("\n ÅÅĞòºó \n");
	for (i = 0; i<N; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}