#define _CRT_SECURE_NO_WARNINGS 1
#include"calculate.h"

//(  ,  )  ,  *  ,  +  ,  -  ,  /  ,  <  ,  =  ,  > 
//40    41    42    43    45    47    60    61    62

int main()
 {
	LinkStack ele;
	initLStack(&ele);  //��ʼ��ջ


	// ��������

	int i = 0;    //����ѭ��
	int num = 0;  //�ַ���
	char arr[128] = { 0 };  //�洢�ַ��ı���
	char arr_gain[128] = { 0 }; //�洢��ջ�ַ��ı���

	printf("��ȷ��������ı��ʽ�ܹ��ж��ٸ��ַ�\n");
	printf("ƭ�ֵܿ��ԣ����ƭ�Լ�\n");
	scanf_s("%d", &num);
	printf("�밴˳��һλһλ�������ַ�,����һ���������λ��\n");
	getchar();

	for (int i = 0; i < num; i++)
	{
		arr[i] = getchar();
		printf("����������ٴγ��֣�%c  \n", arr[i]);
		getchar();
	}
	printf("%s\n", arr);



	//�ж�λ��

	int count = num; // �����Ƿ�ѭ�������СΪ�ַ�����Ŀ
	int ret = 0;    //  ��λ����ֵ�����ڴ���ջ
	int temp = 0;   //  ��λ����ֵ�����ڴ���ջ
	int gain = 0;   //  �������գ���ջ��ֵ
	int n = 0;      //  ��ջ�������±�����
	int j = 0;      //  �м�������±꣬��ֹ�ı��±�
	int k = 0;      // �ڶ�λ���ж��У���������10�Ĵη���

	int a = 0;      //��ջ�������±�����


	while (count>0)
	{

		if (arr[n] > '0' && arr[n] <= '9' && arr[n + 1] >= '0' && arr[n + 1] <= '9')     // ���ʽΪ��λ����   
		{
			j = n;   //  �м�������±꣬��ֹ�ı��±�
			while (arr[n+1] >= '0' && arr[n+1] <= '9')   //�����ж� ������Ǽ�λ��
			{
				n++;
				k++; 
			}
			while (j <= n)
			{
				int h = pow(10, k);    // hΪ10^k�η�
				temp += (arr[j] - 48) * h;
				k--;
				j++;
				count--;
			}
			k = 0;
			n++;
			pushLStack(&ele, temp); //����ջ
			traverseLStack(&ele);
			popLStack(&ele, &gain);  //��ջ

			arr_gain[a] = gain;
			a++;
			temp = 0;
		}
		else if (arr[n] > '0' && arr[n] <= '9')   //  Ϊ��λ��
		{
			ret = arr[n] - 48;
			pushLStack(&ele, ret);   //����ջ
			count--;
			n++;
			traverseLStack(&ele);     //����
			popLStack(&ele, &gain);   //��ջ

			arr_gain[a] = gain;
			a++;

		}
		else if (arr[n] == '+' || arr[n] == '-' || arr[n] == '*' || arr[n] == '(' || arr[n] == ')' || arr[n] == '/')  //���ʽΪ������
		{
			int a = arr[n];     //��ASCII��ֵ���������
			pushLStack(&ele, a);  // ��������ջ
			n++;
			count--;
			traverseLStack(&ele);  //����
		}

	}

	//��������ջ
	for (; a < num; a++)
	{
		popLStack(&ele, &gain); 
		arr_gain[a] = gain;
		a++;
	}
	for (int b = 0; b < a; b++)
	{
		putchar(arr_gain[b]);  //��׺���ʽ
	}




	return 0;
}
 








	
		
