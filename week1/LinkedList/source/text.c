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
	int count = 0;  //���������е����ݸ���
	LinkedList head = NULL;
	int choice = 0;
	ElemType num = 0;
	LinkedList ele = NULL; //�������м�ֵ
	do
	{
	    meun();
		printf("��ѡ��Ҫ���еĹ���\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case exit:
			printf("�˳��ɹ�\n");
			break;


		case init_list:
			InitList(&head);
			break;


		case destroy_list:
			DestroyList(&head);
			printf("���ٳɹ�\n");
			count = 0;
			break;


		case add_list:
			if (head == NULL)
			{
				printf("����Ϊ��\n");
			}
			else
			{
				printf("���������ݣ�>\n");
				scanf("%d", &num);
				if (AddList(head, num))
				{
					count++;
					printf("��ӳɹ�\n");
				}
				else
				{
					printf("���ʧ��\n");
				}
			}
			break;


		case delect_list:

				printf("��������Ҫɾ��������,������:>\n");
				scanf("%d", &num);
				if (DelectList(head, num))
				{
					printf("ɾ���ɹ�\n");
				}
				else
				{
					printf("ɾ��ʧ��\n");
				}
				break;


		case search_list:
			printf("��������ҪѰ�ҵ�����,�����룺>\n");
			scanf("%d", &num);
			if (SearchList(head, num))
			{
				printf("��Ҫ�ҵ����ݴ���\n");
			}
			else
			{
				printf("���ݲ�����\n");
			}
			break;

		case insert_list:
			if (count>=2)   //�жϸ����Ƿ��㹻����������Ҫ�����ݴ��ڻ��������  ��һ��
			{
				if (head == NULL) //��������״̬ �ڶ���
				{
					printf("����Ϊ��\n");
				}
				else
				{
					printf("������������ݣ�>\n");
					scanf("%d", &num);
					if (InsertList(head, num,count))  //����Ƿ����ɹ�
					{
							count++;
							printf("����ɹ�\n");
					}
					else
					{
							printf("����ʧ��\n");
					}
				}
			}
			else
			{
				printf("�������ݲ������޷���������Ҫ��\n");
			}
			break;


		case show_list:
			if (head == NULL)
			{
				printf("��������\n");
				count = 0;
			}
			else
			{
				ShowList(head);
			}
			printf("���������ݸ���Ϊ%d\n", count);
			break;


		case reverse_list:
			if (head == NULL)
			{
				printf("��������\n");
			}
			else
			{
				printf("��ת�ɹ�\n");
				ReverseList(head);
			}
			break;


		case recursive_reverse_list:
			if (head == NULL)
			{
				printf("��������\n");
			}
			else
			{
				printf("��ת�ɹ�\n");
				RecursiveReverseList(head);
			}
			break;


		case find_mid_list:
			if (head == NULL)
			{
				printf("��������\n");
			}
			else
			{
				if (count % 2 == 0)
				{
					printf("�ҵ���������:>\n");
					printf("%d\n", ele->data);
					printf("%d\n", FindMidList(head, count, &ele));
				}
				else
				{
					printf("�ҵ�������:>\n");
					printf("%d\n", FindMidList(head, count, &ele));
				}
				break;
			}


		case odd_even_exchange:
			if (head == NULL)
			{
				printf("��������\n");
			}
			else
			{
				printf("�����ɹ�,������ת\n");
				OddEvenExchange(&head,count);
			}
			break;

		case judge_circle:
			if (head == NULL)
			{
				printf("��������\n");
			}
			else
			{
				if (JudegeCircle(head) && count>2)  //countȷ�����������ϵ�����
				{
					printf("����ɻ�\n");
				}
				else
				{
					printf("�����ɻ�\n");
				}
			}
			break;


		default:
			break;
		}

	} while (choice);
	

	return 0;
}