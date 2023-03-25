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
				count--;
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
			if (count >= 2)   //�жϸ����Ƿ��㹻����������Ҫ�����ݴ��ڻ��������  ��һ��
			{
				if (head == NULL) //��������״̬ �ڶ���
				{
					printf("����Ϊ��\n");
				}
				else
				{
					printf("���������ݣ�>\n");
					scanf("%d", &num);
					if (InsertList(head, num, count))  //����Ƿ����ɹ�
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

		}
	} while (choice);


	return 0;
}