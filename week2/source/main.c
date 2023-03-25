#include"LinkStack.h"


void meun()
{
	printf("                                               \n");
	printf("******************* meun  *********************\n");
	printf("****************** 0.Exit *********************\n");
	printf("***1.init_stack     ****  2.isEmpty_LStack  ***\n");
	printf("***3.get_TopLStack  ****  4.clear_LStack    ***\n");
	printf("***5.destroy_LStack ****  6.LStack_Length   ***\n");
	printf("***7.push_LStack    ****  8.pop_LStack      ***\n");
	printf("************** 9.traverse_LStack  *************\n");
	printf("******************* meun  *********************\n");
	printf("                                               \n");

}


int main()
{
	int ret = 0;    //判断输入是否为整数
	ElemType Data;  //用户输入的数据
	ElemType gain;  //获得top的数据
	int lenth = 0;  //栈长度
	int choice = 0;
	LinkStack ele;

	do
	{
		meun();
		printf("请选择将要进行的功能\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case Exit:
			system("cls");
			printf("成功退出\n");
			break;

		case init_stack:
			system("cls");
			if (initLStack(&ele))
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;

		case isEmpty_LStack:
			system("cls");
			if (isEmptyLStack(&ele))
				printf("栈不为空\n");
			else
				printf("栈为空\n");
			break;

		case get_TopLStack:
			system("cls");
			if (getTopLStack(&ele, &gain))
				printf("得到顶层元素,数据为%d\n", gain);
			else
				printf("获取失败\n");
			break;


		case clear_LStack:
			system("cls");
			if (clearLStack(&ele))
				printf("清空成功\n");
			else
				printf("清空失败\n");
			break;

		case destroy_LStack:
			system("cls");
			if (destroyLStack(&ele))
				printf("销毁成功\n");
			else
				printf("销毁失败\n");
			break;

		case LStack_Length:
			system("cls");
			if (LStackLength(&ele, &lenth))
				printf("检测成功，长度为%d\n", lenth);
			else
				printf("长度为0\n");
			break;

		case push_LStack:
			system("cls");
			printf("请输入数据\n");
			ret = scanf("%d", &Data);
			if(ret!=1)
			{
				getchar();
				printf("输入错误\n");
				break;
			}
			if (pushLStack(&ele, Data))
				printf("入栈成功\n");
			else
				printf("入栈失败\n");
			break;

		case pop_LStack:
			system("cls");
			if (popLStack(&ele, &Data))
				printf("出栈成功，出栈的数据为%d\n", Data);
			else
				printf("出栈失败\n");
			break;

		case traverse_LStack:
			system("cls");
			traverseLStack(&ele);
			break;

		default:
				printf("错误输入\n");
			break;
		}
	} while (choice);

	return 0;
}