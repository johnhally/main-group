#include"LQueue.h"


void meun()
{
	printf("******************* meun  *********************\n");
	printf("                                               \n");
	printf("***1.初始化      \n");
	printf("***2.是否为空？  \n");
	printf("***3.得到首元素  \n");
	printf("***4.队伍长度计算    \n");
	printf("***5.入队        \n");
	printf("***6.出队        \n");
	printf("***7.清空队列     \n");
	printf("***8.遍历         \n");
	printf("                                               \n");
	printf("******************* meun  *********************\n");

}

int main()
{
	int ret = 0;    //判断输入是否为整数
	ElemType Data;  //用户输入的数据
	ElemType gain;  //获得top的数据
	int length = 0;  //队列长度
	int choice = 0;
	LQueue ele;

	system("cls");
	InitLQueue(&ele);
	printf("初始化成功\n");

	do
	{
		meun();
		printf("请选择将要进行的功能\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			system("cls");
			printf("成功退出\n");
			break;

		case 1:
			system("cls");
			printf("已初始化\n");
			break;
	
		case 2:
			system("cls");
			if (IsEmptyLQueue(&ele))
				printf("不为空\n");
			else
				printf("为空\n");
			break;

		case 3:
			system("cls");
			if (GetHeadLQueue(&ele, &gain)) 
				printf("得到顶层元素,数据为%d\n", gain);
			else
				printf("获取失败\n");
			break;


		case 7:
			system("cls");
			ClearLQueue(&ele);
			printf("清空成功\n");
			break;

		case 4:
			system("cls");
			if (LengthLQueue(&ele)) {
				length = LengthLQueue(&ele);
				printf("检测成功，长度为%d\n", length);
			}
			else
				printf("队伍长度为0\n");
			break;

		case 5:
			system("cls");
			printf("请输入数据\n");
			ret = scanf("%d", &Data);
			if (ret != 1)
			{
				getchar();
				printf("输入错误\n");
				break;
			}
			if (EnLQueue(&ele, Data))
				printf("入队成功\n");
			else
				printf("入队失败\n");
			break;

		case 6:
			system("cls");
			if (DeLQueue(&ele))
				printf("成功\n");
			else
				printf("失败\n");
			break;

		case 8:
			system("cls");
			if (TraverseLQueue(&ele)==0)
			{
				printf("队伍已空\n");
			}
			break;


		default:
			printf("错误输入\n");
			break;
		}
	} while (choice);

	return 0;
}