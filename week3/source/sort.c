#include"Sort.h"


//插入
void insertSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	int end = 0;
	int temp = 0;
	for (i = 0; i < n - 1; i++)
	{
		end = i;   //将end等于i，以便于每个数据都可进行比较插入。
		for(;end>=0;end--) //向后循环比较
		{
			//交换
			if (a[end] > a[end + 1])
			{
				temp = a[end + 1];
				a[end + 1] = a[end];
				a[end] = temp;
			}
		
		}

	}
	
}

//归并
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	if (begin >= end)   // 明确递归无限接近的条件，避免死循环
	{
		return;
	}

	mid = (begin + end) / 2;

	int j = 0;
	int begin_1 = begin;
	int end_1 = mid;
	int begin_2 = mid + 1;
	int end_2 = end;

	//递归，分解数组，变成有限个数块，每个数块含左右两个区域

	//左数块
	MergeArray(a, begin_1, mid, end_1, temp);
	//右数块
	MergeArray(a, begin_2, mid, end_2, temp);

	int b1 = begin_1;
	int b2 = begin_2;
	int i = begin;

	//合并
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
    //数块并不一定是均匀的，遗漏了需要回加

	//左数块遗漏，直接补上，因为本就有序
	while (b1 <= end_1)
	{
		temp[i] = a[b1];
		i++, b1++;
	}

	//右数块同理
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

//中值快速
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin >= end)   // 明确递归无限接近的条件，避免死循环
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
		//两个while使得b1与e2靠近
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

	//此时b1=e2
	QuickSort_Recursion(a, begin, b1-1);  //b1-1 小于中间值的数块，e2+1 大于中间值的数块，留下中间值。不-1或+1会导致死循环
	QuickSort_Recursion(a, e2+1, end);    


}

//计数
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
	//	printf("失败\n");
	//	printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
	//	return error;
	//}
	//int* count = (int*)malloc(max * sizeof(int));
	//if (count == NULL)
	//{
	//	printf("失败\n");
	//	printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
	//	return error;
	//}
	//int* memory = (int*)malloc(max * sizeof(int));
	//if (memory == NULL)
	//{
	//	printf("失败\n");
	//	printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
	//	return error;
	//}

	for (i = 0; i < size  ; i++)
	{
		num[a[i]] = 1;    //标记每个数
	}

	//统计次数
	for (i = 0; i < size  ; i++)
	{
		if (num[a[i]] == 1)
			count[a[i]] += 1;
	}

	//存储排序
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

//基数
void RadixCountSort(int* a, int size)
{
	int value = 0;     //存储数据，用来重新存储数据
	int min = 0;       //最小位数，其原本的值，不是最小值的意思
	int max = 0;       //找到最大值，从而找到最大位次
	int min_unit = 0;  //最小的位数
	int count = size;  
	int n = 1;         //n代表着10的n次方

	int num = 0;      // 最大的数据是num位数

	int num_x = 0;    // 减少位次的个数   ,在后面先让其等于num，每次 max/10 便减一 
	int num_y = 0;    // 用来记录需要进行多少次Data->data/10，以得到个，十，百，千。。。等位次上的数
	                  // 比如个位数，便是0次，十位数便是1次，百位数需进行两次
	                  // 但num_x + num_y == num ，用此关系来保证进行 Data->data/10 的次数，即 num_y =num - num_x
	                  // 即进行完个位数时，便到10位数，只进行一次 Data->data/10
	                  // 得到10位时，便到百位 ， 原数据需要进行 2 次；


	LinkedList Data = NULL;
	LinkedList unit = NULL;


	//寻最大值
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	//计数最大位次，num
	while (1)
	{
		max = max / 10;
		num++;
		if (max == 0)
			break;
	}

	num_x = num;

	//初始化链表
	InitList(&Data);
	InitList(&unit);


	//存入数据
	for (int i = 0; i < size; i++)
	{
		AddList(Data, a[i]);
	}

	//初始化中间变量
	LinkedList temp;
	InitList(&temp);


	while (num_x >= 1)   //当num_x小于1时，num_y==num 已经将所有 ？位数排序完成
	{
		while (count)  //count=size，用来判断一轮是否结束
		{

			//判断，排序的依据是个位数还是个位以上
			if (num_y == 0)//个位
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
				
				AddList(unit, min);  //添加进链表
				DelectList(Data, min);  //弹出
				count--;
			}
			else //个位以上
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
				
				AddList(unit, min);  //添加进链表
				DelectList(Data, min);  //弹出
				count--;
			}
		}

		//销毁
		DestroyList(&Data);
		//重建
		InitList(&Data);

		max = max / 10; //无实际作用，象征意义，即位次发生变化
		num_x--;
		num_y = num - num_x;

		n = 1;
		//10的n次方，因为用 pow函数 会报错，所以被迫采用for循环
		for (int i = 0; i < num_y; i++)
		{
			n *= 10;
		}



		if (num_y != num) //防止当排序结束后，结果链表仍然向后，使得unit指向NULL,无法被解读
		{
			//重新存入数据
			unit = unit->next;
			for (int i = 0; i < size; i++)
			{
				value = unit->data;
				AddList(Data, value);
				unit = unit->next;
			}
		}
		count = size;

		if (num_y == num)  //判断是否结束,读取数据
		{
			unit = unit->next;
			for (int i = 0; i < size; i++)
			{
				a[i] = unit->data;
				unit = unit->next;
			}
		}
		//销毁
		DestroyList(&unit);
		//重建
		InitList(&unit);
		
	}


	
}









#define MAXLEN 10240  

//读取文件filename的内容到dest数组，最多可以读maxlen个字节  
//成功返回文件的字节数，失败返回 0  
// 
// 
//int read_file(const char* filename, int* arr, int maxlen)
//{
//	FILE* file;
//	int pos, temp, i;
//
//	//打开文件  
//	file = fopen(filename, "r");
//	if (NULL == file)
//	{
//		printf("open error,可能是文件地址错误\n");
//		return 0;
//	}
//
//	pos = 0;
//
//	//循环读取文件中的内容  
//	for (i = 0; i < MAXLEN - 1; i++)
//	{
//		temp = fgetc(file);
//		if (EOF == temp)
//			break;
//		arr[pos++] = temp;
//	}
//
//	//关闭文件
//	fclose(file);
//
//	return pos;
//
//}
//
//
