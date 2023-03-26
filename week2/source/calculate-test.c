#define _CRT_SECURE_NO_WARNINGS 1
#include"calculate.h"

//(  ,  )  ,  *  ,  +  ,  -  ,  /  ,  <  ,  =  ,  > 
//40    41    42    43    45    47    60    61    62

int main()
 {
	LinkStack ele;
	initLStack(&ele);  //初始化栈


	// 输入数据

	int i = 0;    //用于循环
	int num = 0;  //字符数
	char arr[128] = { 0 };  //存储字符的变量
	char arr_gain[128] = { 0 }; //存储出栈字符的变量

	printf("请确认你输入的表达式总共有多少个字符\n");
	printf("骗兄弟可以，真别骗自己\n");
	scanf_s("%d", &num);
	printf("请按顺序一位一位地输入字符,切勿一次性输入多位数\n");
	getchar();

	for (int i = 0; i < num; i++)
	{
		arr[i] = getchar();
		printf("输入的数据再次呈现：%c  \n", arr[i]);
		getchar();
	}
	printf("%s\n", arr);



	//判断位数

	int count = num; // 决定是否循环，其大小为字符的数目
	int ret = 0;    //  单位数的值，用于存入栈
	int temp = 0;   //  多位数的值，用于存入栈
	int gain = 0;   //  用来回收，出栈的值
	int n = 0;      //  入栈变量的下标序列
	int j = 0;      //  中间变量的下标，防止改变下标
	int k = 0;      // 在多位数判断中，用来计算10的次方数

	int a = 0;      //出栈变量的下标序列


	while (count>0)
	{

		if (arr[n] > '0' && arr[n] <= '9' && arr[n + 1] >= '0' && arr[n + 1] <= '9')     // 表达式为多位数字   
		{
			j = n;   //  中间变量的下标，防止改变下标
			while (arr[n+1] >= '0' && arr[n+1] <= '9')   //用来判断 输入的是几位数
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
			traverseLStack(&ele);
			popLStack(&ele, &gain);  //出栈

			arr_gain[a] = gain;
			a++;
			temp = 0;
		}
		else if (arr[n] > '0' && arr[n] <= '9')   //  为单位数
		{
			ret = arr[n] - 48;
			pushLStack(&ele, ret);   //数入栈
			count--;
			n++;
			traverseLStack(&ele);     //遍历
			popLStack(&ele, &gain);   //出栈

			arr_gain[a] = gain;
			a++;

		}
		else if (arr[n] == '+' || arr[n] == '-' || arr[n] == '*' || arr[n] == '(' || arr[n] == ')' || arr[n] == '/')  //表达式为操作符
		{
			int a = arr[n];     //用ASCII码值代替操作符
			pushLStack(&ele, a);  // 操作符入栈
			n++;
			count--;
			traverseLStack(&ele);  //遍历
		}

	}

	//操作符出栈
	for (; a < num; a++)
	{
		popLStack(&ele, &gain); 
		arr_gain[a] = gain;
		a++;
	}
	for (int b = 0; b < a; b++)
	{
		putchar(arr_gain[b]);  //中缀表达式
	}




	return 0;
}
 








	
		
