#include"Sort.h"


//����
void insertSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	int end = 0;
	int temp = 0;
	for (i = 0; i < n - 1; i++)
	{
		end = i;   //��end����i���Ա���ÿ�����ݶ��ɽ��бȽϲ��롣
		for(;end>=0;end--) //���ѭ���Ƚ�
		{
			//����
			if (a[end] > a[end + 1])
			{
				temp = a[end + 1];
				a[end + 1] = a[end];
				a[end] = temp;
			}
		
		}

	}
	
}

//�鲢
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	if (begin >= end)   // ��ȷ�ݹ����޽ӽ���������������ѭ��
	{
		return;
	}

	mid = (begin + end) / 2;

	int j = 0;
	int begin_1 = begin;
	int end_1 = mid;
	int begin_2 = mid + 1;
	int end_2 = end;

	//�ݹ飬�ֽ����飬������޸����飬ÿ�����麬������������

	//������
	MergeArray(a, begin_1, mid, end_1, temp);
	//������
	MergeArray(a, begin_2, mid, end_2, temp);

	int b1 = begin_1;
	int b2 = begin_2;
	int i = begin;

	//�ϲ�
	while (b1 <= end_1 && b2 <= end_2)
	{
		if (a[b1] <= a[b2])
		{
			temp[i] = a[b1];
			i++, b1++;
		}
		else
		{
			temp[i] = a[b2];
			i++, b2++;
		}
	}
    //���鲢��һ���Ǿ��ȵģ���©����Ҫ�ؼ�

	//��������©��ֱ�Ӳ��ϣ���Ϊ��������
	while (b1 <= end_1)
	{
		temp[i] = a[b1];
		i++, b1++;
	}

	//������ͬ��
	while (b2 <= end_2)
	{
		temp[i] = a[b2];
		i++, b2++;
	}

	for (; j < i; j++)
	{
		a[j] = temp[j];
	}

}

//��ֵ����
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin >= end)   // ��ȷ�ݹ����޽ӽ���������������ѭ��
	{
		return;
	}

	int mid = (begin + end) / 2; 

	int i = 0;

	int begin_1 = begin;
	int end_1 = mid;
	int begin_2 = mid + 1;
	int end_2 = end;

	int b1 = begin_1;
	int e2 = end_2;

	while (b1 < e2)
	{
		//����whileʹ��b1��e2����
		while (a[b1] <= a[mid] && b1 < mid)  
		{
			b1++;
		}
		while (a[e2] >= a[mid] && e2 > mid)
		{
			e2--; 
		}

		if (b1 < e2)
		{
			i = a[b1];
			a[b1] = a[e2];
			a[e2] = i;
		}
	}

	//��ʱb1=e2
	QuickSort_Recursion(a, begin, b1-1);  //b1-1 С���м�ֵ�����飬e2+1 �����м�ֵ�����飬�����м�ֵ����-1��+1�ᵼ����ѭ��
	QuickSort_Recursion(a, e2+1, end);    


}

//����
void CountSort(int* a, int size, int max)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = size-1;
	int n = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	int num[20000] = { 0 };
	int count[20000] = { 0 };
	int memory[20000] = { 0 };

	//int* num = (int*)malloc(max * sizeof(int));
	//if (num == NULL)
	//{
	//	printf("ʧ��\n");
	//	printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
	//	return error;
	//}
	//int* count = (int*)malloc(max * sizeof(int));
	//if (count == NULL)
	//{
	//	printf("ʧ��\n");
	//	printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
	//	return error;
	//}
	//int* memory = (int*)malloc(max * sizeof(int));
	//if (memory == NULL)
	//{
	//	printf("ʧ��\n");
	//	printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
	//	return error;
	//}

	for (i = 0; i < size  ; i++)
	{
		num[a[i]] = 1;    //���ÿ����
	}

	//ͳ�ƴ���
	for (i = 0; i < size  ; i++)
	{
		if (num[a[i]] == 1)
			count[a[i]] += 1;
	}

	//�洢����
	for (i = 0; i <= max ; i++)
	{
		while (count[i] != 0)
		{
			memory[n++] = i;
			count[i]--;
		}
		
	}
	for (i = 0; i < size; i++)
	{
		a[i] = memory[i];
	}

}

//����
void RadixCountSort(int* a, int size)
{
	int value = 0;     //�洢���ݣ��������´洢����
	int min = 0;       //��Сλ������ԭ����ֵ��������Сֵ����˼
	int max = 0;       //�ҵ����ֵ���Ӷ��ҵ����λ��
	int min_unit = 0;  //��С��λ��
	int count = size;  
	int n = 1;         //n������10��n�η�

	int num = 0;      // ����������numλ��

	int num_x = 0;    // ����λ�εĸ���   ,�ں������������num��ÿ�� max/10 ���һ 
	int num_y = 0;    // ������¼��Ҫ���ж��ٴ�Data->data/10���Եõ�����ʮ���٣�ǧ��������λ���ϵ���
	                  // �����λ��������0�Σ�ʮλ������1�Σ���λ�����������
	                  // ��num_x + num_y == num ���ô˹�ϵ����֤���� Data->data/10 �Ĵ������� num_y =num - num_x
	                  // ���������λ��ʱ���㵽10λ����ֻ����һ�� Data->data/10
	                  // �õ�10λʱ���㵽��λ �� ԭ������Ҫ���� 2 �Σ�


	LinkedList Data = NULL;
	LinkedList unit = NULL;


	//Ѱ���ֵ
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	//�������λ�Σ�num
	while (1)
	{
		max = max / 10;
		num++;
		if (max == 0)
			break;
	}

	num_x = num;

	//��ʼ������
	InitList(&Data);
	InitList(&unit);


	//��������
	for (int i = 0; i < size; i++)
	{
		AddList(Data, a[i]);
	}

	//��ʼ���м����
	LinkedList temp;
	InitList(&temp);


	while (num_x >= 1)   //��num_xС��1ʱ��num_y==num �Ѿ������� ��λ���������
	{
		while (count)  //count=size�������ж�һ���Ƿ����
		{

			//�жϣ�����������Ǹ�λ�����Ǹ�λ����
			if (num_y == 0)//��λ
			{
				temp = Data->next;
				min_unit = temp->data % 10;
				min = temp->data;

				for (int i = 0; i < count; i++)
				{
					if (temp->data % 10 < min_unit)
					{
						min = temp->data;
						min_unit = min % 10;
					}
					temp = temp->next;
				}
				
				AddList(unit, min);  //��ӽ�����
				DelectList(Data, min);  //����
				count--;
			}
			else //��λ����
			{
				temp = Data->next;
				min_unit = (temp->data / n) % 10;
				min = temp->data;

				for (int i = 0; i < count; i++)
				{
					if ((temp->data / n) % 10 < min_unit)
					{
						min = temp->data;
						min_unit = (temp->data / n) % 10;
					}
					temp = temp->next;
				}
				
				AddList(unit, min);  //��ӽ�����
				DelectList(Data, min);  //����
				count--;
			}
		}

		//����
		DestroyList(&Data);
		//�ؽ�
		InitList(&Data);

		max = max / 10; //��ʵ�����ã��������壬��λ�η����仯
		num_x--;
		num_y = num - num_x;

		n = 1;
		//10��n�η�����Ϊ�� pow���� �ᱨ�����Ա��Ȳ���forѭ��
		for (int i = 0; i < num_y; i++)
		{
			n *= 10;
		}



		if (num_y != num) //��ֹ����������󣬽��������Ȼ���ʹ��unitָ��NULL,�޷������
		{
			//���´�������
			unit = unit->next;
			for (int i = 0; i < size; i++)
			{
				value = unit->data;
				AddList(Data, value);
				unit = unit->next;
			}
		}
		count = size;

		if (num_y == num)  //�ж��Ƿ����,��ȡ����
		{
			unit = unit->next;
			for (int i = 0; i < size; i++)
			{
				a[i] = unit->data;
				unit = unit->next;
			}
		}
		//����
		DestroyList(&unit);
		//�ؽ�
		InitList(&unit);
		
	}


	
}









#define MAXLEN 10240  

//��ȡ�ļ�filename�����ݵ�dest���飬�����Զ�maxlen���ֽ�  
//�ɹ������ļ����ֽ�����ʧ�ܷ��� 0  
// 
// 
//int read_file(const char* filename, int* arr, int maxlen)
//{
//	FILE* file;
//	int pos, temp, i;
//
//	//���ļ�  
//	file = fopen(filename, "r");
//	if (NULL == file)
//	{
//		printf("open error,�������ļ���ַ����\n");
//		return 0;
//	}
//
//	pos = 0;
//
//	//ѭ����ȡ�ļ��е�����  
//	for (i = 0; i < MAXLEN - 1; i++)
//	{
//		temp = fgetc(file);
//		if (EOF == temp)
//			break;
//		arr[pos++] = temp;
//	}
//
//	//�ر��ļ�
//	fclose(file);
//
//	return pos;
//
//}
//
//
