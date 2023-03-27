#include"calculate.h"

//(  ,  )  ,  *  ,  +  ,  -  ,  /  ,  <  ,  =  ,  > 
//40    41    42    43    45    47    60    61    62

int main()
 {
	LinkStack ele;
	initLStack(&ele);  //初始化栈


	// 输入数据

	int num = 0;  //字符数
	char arr[128] = { 0 };  //存储字符的变量
	char arr_gain[128] = { 0 }; //存储出栈字符的变量

	printf("请输入表达式\n");
	scanf("%s", arr);
	num = strlen(arr);
	




	//判断位数
	int count = num; // 决定是否循环，其大小为字符的数目
	char temp = 0;   //  多位数的值，用于存入栈
	char gain = 0;   //  用来回收，出栈的值
	int n = 0;      //  入栈变量的下标序列
	int j = 0;      //  中间变量的下标，防止改变下标      用于多位数的判断，但是无法解决如何将多位数无用了，
	int k = 0;      // 在多位数判断中，用来计算10的次方数  用于多位数的判断，但是无用了
	int a = 0;      //出栈变量的下标序列
	int b = 0;


	while (count > 0)
	{

		if (arr[n] > '0' && arr[n] <= '9' && arr[n + 1] >= '0' && arr[n + 1] <= '9')     // 表达式为多位数字   
		{
			j = n;   //  中间变量的下标，防止改变下标
			while (arr[n + 1] >= '0' && arr[n + 1] <= '9')   //用来判断 输入的是几位数
			{
				n++;
				k++;
			}
			while (j <= n)
			{
				int h = pow(10, k);    // h为10^k次方
				temp += (arr[j] - 48) * h;
				k--;
				j++;
				count--;
			}
			k = 0;
			n++;
			pushLStack(&ele, temp); //数入栈
			popLStack(&ele, &gain);  //出栈

			arr_gain[a] = gain;
			a++;
			temp = 0;
		}
		else if (arr[n] > '0' && arr[n] <= '9')   //  为单位数
		{
			pushLStack(&ele,arr[n]);   //数入栈
			count--;
			n++;
			popLStack(&ele, &gain);   //出栈

			arr_gain[a] = gain;
			a++;

		}
		else if (arr[n] == '+' || arr[n] == '-' || arr[n] == '*' || arr[n] == '(' || arr[n] == ')' || arr[n] == '/')  //表达式为操作符
		{
			pushLStack(&ele, arr[n]);  // 操作符入栈
			n++;
			count--;
		}

	}

	//操作符出栈
	for (; a < num; a++)
	{
		popLStack(&ele, &gain);
		arr_gain[a] = gain;
		traverseLStack(&ele);  //遍历
	}
	printf("表达式变成:\n");
	for ( b = 0; b < a; b++)
	{
		printf("%c ", arr_gain[b]);
	}



	int ret = 0;
	b = 0;
	a = 0;
	for (b = 0; b <num ; b++)
	{
		ret = is_priority(arr[b]);
		temp = is_priority(arr[b + 1]);
	
		if (ret > temp || ret == temp )                               //如果优先级相同（全为数字也认定为优先级相同）或 优先级更高，入栈
		{                                                             
			pushLStack(&ele, arr_gain[b]);
		}
		else
		{
			popLStack(&ele, &gain);                      //如果优先级低，top先出栈，再入栈
			pushLStack(&ele, arr_gain[b]);

		}
		pushLStack(&ele, arr_gain[b]);

	}






	return 0;
}
 
