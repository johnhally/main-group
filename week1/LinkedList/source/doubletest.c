#include"doubleLinkedList.h"


void meun()
{
	printf("                                        \n");
	printf("**************** meun  *****************\n");
	printf("*************** 0.exit *****************\n");
	printf("***1.init_list   ****  2.destroy_list***\n");
	printf("***3.add_list    ****  4.delect_list ***\n");
	printf("***5.search_list ****  6.insert_list ***\n");
	printf("*************  7.show_list  ************\n");
	printf("**************** meun  *****************\n");
	printf("                                        \n");

}

int main()
{
	ElemType num = 0;
	int count = 0;
	int choice = 0;
	LinkedList head = NULL;

	do
	{
		meun();
		printf("请选择将要进行的功能\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case exit:
			printf("退出成功\n");
			break;


		case init_list:
			InitList(&head);
			break;


		case destroy_list:
			DestroyList(&head);
			printf("销毁成功\n");
			count = 0;
			break;

		case add_list:
			if (head == NULL)
			{
				printf("链表为空\n");
			}
			else
			{
				printf("请输入数据：>\n");
				scanf("%d", &num);
				if (AddList(head, num))
				{
					count++;
					printf("添加成功\n");
				}
				else
				{
					printf("添加失败\n");
				}
			}
			break;
		
		case delect_list:
			printf("请输入你要删除的数据,请输入:>\n");
			scanf("%d", &num);
			if (DelectList(head, num))
			{
				count--;
				printf("删除成功\n");
			}
			else
			{
				printf("删除失败\n");
			}
			break;

		case search_list:
			printf("请输入你要寻找的数据,请输入：>\n");
			scanf("%d", &num);
			if (SearchList(head, num))
			{
				printf("你要找的数据存在\n");
			}
			else
			{
				printf("数据不存在\n");
			}
			break;


		case insert_list:
			if (count >= 2)   //判断个数是否足够来满足插入的要求即数据大于或等于两个  第一层
			{
				if (head == NULL) //检验链表状态 第二层
				{
					printf("链表为空\n");
				}
				else
				{
					printf("请输入数据：>\n");
					scanf("%d", &num);
					if (InsertList(head, num, count))  //检测是否插入成功
					{
						count++;
						printf("插入成功\n");
					}
					else
					{
						printf("插入失败\n");
					}
				}
			}
			else
			{
				printf("链表数据不够，无法满足插入的要求\n");
			}
			break;
			break;


		case show_list:
			if (head == NULL)
			{
				printf("链表不存在\n");
				count = 0;
			}
			else
			{
				ShowList(head);
			}
			printf("链表中数据个数为%d\n", count);
			break;

		}
	} while (choice);


	return 0;
}