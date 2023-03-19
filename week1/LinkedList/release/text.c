#include"LinkedList.h"


void meun()
{
	printf("                                        \n");
	printf("**************** meun  *****************\n");
	printf("*************** 0.exit *****************\n");
	printf("***1.init_list   ****  2.destroy_list***\n");
	printf("***3.add_list    ****  4.delect_list ***\n");
	printf("***5.search_list ****  6.insert_list ***\n");
	printf("***7.show_list   ****  8.reverse_list***\n");
	printf("****     9.recursive_reverse_list   ****\n");
	printf("****     10.find_mid_listm          ****\n");
	printf("****     11.odd_even_exchange       ****\n");
	printf("****     12.judge_circle            ****\n");
	printf("**************** meun  *****************\n");
	printf("                                        \n");

}



int main()
{
	int count = 0;  //计算链表中的数据个数
	LinkedList head = NULL;
	int choice = 0;
	ElemType num = 0;
	LinkedList ele = NULL; //用于找中间值
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
			if (count>=2)   //判断个数是否足够来满足插入的要求即数据大于或等于两个  第一层
			{
				if (head == NULL) //检验链表状态 第二层
				{
					printf("链表为空\n");
				}
				else
				{
					printf("请输入插入数据：>\n");
					scanf("%d", &num);
					if (InsertList(head, num,count))  //检测是否插入成功
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


		case reverse_list:
			if (head == NULL)
			{
				printf("链表不存在\n");
			}
			else
			{
				printf("反转成功\n");
				ReverseList(head);
			}
			break;


		case recursive_reverse_list:
			if (head == NULL)
			{
				printf("链表不存在\n");
			}
			else
			{
				printf("反转成功\n");
				RecursiveReverseList(head);
			}
			break;


		case find_mid_list:
			if (head == NULL)
			{
				printf("链表不存在\n");
			}
			else
			{
				if (count % 2 == 0)
				{
					printf("找到啦，是两:>\n");
					printf("%d\n", ele->data);
					printf("%d\n", FindMidList(head, count, &ele));
				}
				else
				{
					printf("找到啦，是:>\n");
					printf("%d\n", FindMidList(head, count, &ele));
				}
				break;
			}


		case odd_even_exchange:
			if (head == NULL)
			{
				printf("链表不存在\n");
			}
			else
			{
				printf("操作成功,两级反转\n");
				OddEvenExchange(&head,count);
			}
			break;

		case judge_circle:
			if (head == NULL)
			{
				printf("链表不存在\n");
			}
			else
			{
				if (JudegeCircle(head) && count>2)  //count确保有两个以上的数据
				{
					printf("链表成环\n");
				}
				else
				{
					printf("链表不成环\n");
				}
			}
			break;


		default:
			break;
		}

	} while (choice);
	

	return 0;
}