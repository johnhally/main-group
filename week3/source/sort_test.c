#include"Sort.h"

void meun()
{
	printf("                             \n");
	printf("    Ŀ¼\n");
	printf("0:�˳�����\n");
	printf("1:��������\n");
	printf("2:��������\n");
	printf("3:��������\n");
	printf("4:��������\n");
	printf("5:��ֵ��������\n");
	printf("                             \n");

}

//չʾ
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
		printf("\n���������ѡ��\n");
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
			printf("�˳��ɹ�\n");
			break;

		default:
			printf("�������\n");
			break;
		}

	} while(choice);

}