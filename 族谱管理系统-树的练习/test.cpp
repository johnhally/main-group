#include"tree.h"

enum function
{
};

void meun(MemberNode* root)
{
	int ret = 0;
	extern int i;
	extern int m;
	char choice = 0;
	Info people = { 0 };
	MemberNode T = { 0 };

	while (1)
	{
		printf("               ��ӭ������׹���ϵͳ             \n");
		printf("===============================================\n");
		printf("***           1 --- չ�ּ�������            ***\n");
		printf("***           2 --- ��Ӽ�ͥ��Ա            ***\n");
		printf("***           3 --- ��ɢ�ֲ���Ա            ***\n");
		printf("***           4 --- ���ļ�ͥ��Ա            ***\n");
		printf("***           5 --- ���Ҽ�ͥ��Ա            ***\n");
		printf("***           6 --- �����ͥ����            ***\n");
		printf("***           7 --- ͳ�Ƽ�ͥ��Ա            ***\n");
		printf("***           8 --- �����ͥ��Ա            ***\n");
		printf("***           0 --- �˳�ϵͳ                ***\n");
		printf("===============================================\n");

		printf("��ѡ����:");
		scanf_s("%d", &choice);

		if (choice == 0)
		{
			printf("�˳��ɹ�\n");
			break;
		}
		switch (choice)
		{

		case 2:
			system("cls");
			root = tree_init(root);
			printf("\n");
			getchar();

			tree_assign(root);
			printf("\n");
			getchar();
			break;

		case 1:
			system("cls");
			tree_pre_order(root);
			getchar();
			break;

		case 5:
			system("cls");
			printf("����������˵�����\n");

			ret = scanf("%s", people.name);
			while (ret != 1)
			{
				printf("�������,����������\n");
				while (getchar() != '\n');
				ret = scanf("%s", people.name);
			}

			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("���޴���,���������䱻����\n");
			else
			{
				printf("���ҳɹ�,�������ϢΪ����:\n");
				printf("[��%d�� |���֣�%s |����������%s |סַ��%s |���䣺%d ]\n", T.myself.peer, T.myself.name, T.myself.companion_name, T.myself.address, T.myself.age);
			}
			break;

		case 3:
			system("cls");
			printf("�������ɢ����ϵ���˵�����\n");
			scanf("%s", people.name);
			
			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("���޴���,�����������ѱ�����\n");

			else
			{
				tree_delete(root, people);
				printf("�����ɹ�\n");
			}
			break;

		case 8:
			system("cls");
			printf("�����뺢�Ӹ��׵�����\n");
			scanf("%s", people.name);

			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("���޴���,�����������ѱ�����\n");
			else
			{
				tree_insert(root, people);
				printf("����ɹ�\n");

			}
			break;

		case 7:
			system("cls");
			tree_restore(root);
			printf("����Ŀǰ���ص������У�%d", i);
			m = 1;
			break;

		case 4:
			system("cls");
			printf("��������Ҫ�޸ĳ�Ա������\n");
			scanf("%s", people.name);

			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("���޴���,�����������ѱ�����\n");
			else
			{
				tree_change(root, people);
				printf("�޸ĳɹ�\n");
			}
			break;

		case 6:
			system("cls");
			if (m == 1)
			{
				int num = tree_pree_num(root);
				printf("�����ܹ���[%d]��\n", num);
			}
			else
			{
				tree_restore(root);
				int num = tree_pree_num(root);
				printf("�����ܹ���[%d]��\n", num);
			}
			break;

		default:
			system("cls");
			printf("�����������������\n");
			break;
		}
	}
	return;
}

int main()
{
	MemberNode* root = NULL;
	meun(root);

	return 0;
}