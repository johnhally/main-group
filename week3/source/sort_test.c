#include"Sort.h"

void meun()
{
	printf("                             \n");
	printf("    目录\n");
	printf("0:退出排序\n");
	printf("1:插入排列\n");
	printf("2:并归排列\n");
	printf("3:计数排列\n");
	printf("4:基数排列\n");
	printf("5:中值快速排列\n");
	printf("                             \n");

}

//展示
void show(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		printf("%d ", a[j]);
	}
}

int main()
{
	meun();

	int n = 10;
	int mid = 0;
	int arr[] = {100,10,9,9,77,8,123,1233,444,12312};
	int choice = 0;
	mid = n / 2;
	int* temp = (int*)malloc(n * sizeof(int));

	do
	{
		printf("\n请输入你的选择\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insertSort(arr, n);
			show(arr, n);
			break;

		case 2:
			MergeArray(arr, 0, mid, n - 1, temp);
			show(arr, n);
			break;

		case 3:
			CountSort(arr, n, 1);
			show(arr, n);
			break;

		case 4:
			RadixCountSort(arr, n);
			show(arr, n);
			break;

		case 5:
			QuickSort_Recursion(arr, 0, n - 1);
			show(arr, n);
			break;

		case 0:
			printf("退出成功\n");
			break;

		default:
			printf("输入错误\n");
			break;
		}

	} while(choice);

}