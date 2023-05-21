#include"tree.h"

pMemberTree arr[MAX_SIZE] = { 0 };  //ȫ���������������Աȫ����¼��ȥ
int all = 0; //ȫ�ֱ��������ڱ��������У�ʹ�õ����printf����\n�������µ�һ��Ҫ���о�
int i = 0;   //ȫ�ֱ�����������¼��ϵ������
int m = 0;

int JudgeR(MemberNode* T)
{
	int ret = 0;
	int relation = 0;
	printf("\n");

	printf("������[ %s ]����Ů�ĸ�����Ϣ������仹��������Ů��������1��,�������������Ϣ��\n",T->myself.name);
	printf("�����������������Ů����Ϣ����˵������Ů�������κ����ּ��˳�\n");

	ret = scanf("%d", &relation);
	while (ret != 1)
	{
		printf("�������,����������\n");
		while (getchar() != '\n');
		ret = scanf("%d", &relation);
	}
	return relation;
}

int ageshow(MemberNode* T)
{
	time_t tmp_time;
	struct tm* ptime;
	struct tm* tmp;
	tmp_time = time(NULL);//��ȡ��ǰʱ��
	ptime = localtime(&tmp_time);

	tmp = localtime(&tmp_time);
	int year = (1900 + tmp->tm_year) - (T->myself.birthday / 10000);

	return year;
}

void InfoAdd_1(MemberNode* Node)
{
	Node->myself.peer = 1;

	printf("�����룬��ϸ��������ڵĸ�����Ϣ\n");
	printf("����        ��������        ��������      סַ          �Ƿ����(1/0)    ����״̬(1/0) \n");

	scanf("%s %s %d %s %d %d", Node->myself.name, Node->myself.companion_name, &(Node->myself.birthday),
		Node->myself.address, &(Node->myself.wedding), &(Node->myself.health));

	Node->myself.age = ageshow(Node);


	/*printf("%s\t %s\t        %s\t %s\t%d \t  %d\t    %d\t      %d\n", Node->myself.name, Node->myself.companion_name, Node->myself.birthday,
		Node->myself.address, Node->myself.age, Node->myself.peer,
		Node->myself.wedding, Node->myself.health);*/
}

void InfoAdd_2(MemberNode* Node)
{
	Node->myself.peer = Node->parent->myself.peer + 1;

	printf("�����������Ϣ\n");
	printf("����        ��������        ��������      סַ          �Ƿ����(1/0)    ����״̬(1/0) \n");

	scanf("%s %s %d %s %d %d", Node->myself.name, Node->myself.companion_name,&(Node->myself.birthday),
		Node->myself.address, &(Node->myself.wedding), &(Node->myself.health));

	Node->myself.age = ageshow(Node);


}

pMemberTree tree_init(MemberNode* root)
{
	root = (MemberNode*)malloc(sizeof(struct MemberNode));
	if (root == NULL)
	{
		return NULL;
	}
	InfoAdd_1(root);
	root->parent = NULL;
	root->nextsibling = NULL;
	root->first_child = NULL;

	return root;

}

void tree_assign(MemberNode* T)
{
	if (T == NULL)
	{
		return;
	}

	int ret = 0;
	int relation = 0;
	MemberNode* temp = (MemberNode*)malloc(sizeof(MemberNode));
	if (!temp)
	{
		return;
	}
	temp->first_child = NULL;
	temp->nextsibling = NULL;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (!T->parent)
	{
		temp->parent = T;
		printf("����������һ�����ӵĸ�����Ϣ\n");
		InfoAdd_2(temp);
		T->first_child = temp;
	}

	while (1)
	{
		MemberNode* temp_2 = (MemberNode*)malloc(sizeof(MemberNode));
		if (!temp_2)
		{
			return;
		}
		temp_2->first_child = NULL;
		temp_2->nextsibling = NULL;

		MemberNode* temp_3 = (MemberNode*)malloc(sizeof(MemberNode));
		if (!temp_3)
		{
			return;
		}
		temp_3->first_child = NULL;
		temp_3->nextsibling = NULL;

		ret = JudgeR(T);
		if (ret == 1 && T->first_child == NULL)
		{
			temp_3->parent = T;
			InfoAdd_2(temp_3);
			T->first_child = temp_3;
		}

		else if (ret == 1 && T->first_child != NULL)
		{
			temp_3->parent = T;
			InfoAdd_2(temp_3);
			temp_2 = T->first_child;
			while (temp_2->nextsibling)
			{
				temp_2 = temp_2->nextsibling;
			}
			temp_2->nextsibling = temp_3;
		}
		else
			break;
	}

	tree_assign(T->first_child);
	tree_assign(T->nextsibling);

}

void tree_pre_order(MemberNode* T)
{
	if (T == NULL)
	{
		return;
	}

	if (all == 8)
	{
		int cou = T->myself.peer - 1;

		while (cou--)
		{
			printf("   ");
		}
	}

	all = 1;

	printf("[��%d�� |���֣�%s |����������%s |סַ��%s |���䣺%d ]\n", T->myself.peer, T->myself.name, T->myself.companion_name,T->myself.address, T->myself.age);
	int count = T->myself.peer;

	if (T->first_child == NULL && T->nextsibling != NULL)
	{
		count = count - 1;
		while (count--)
		{
			printf("   ");
		}
	}
	else if (T->first_child == NULL && T->nextsibling == NULL)
	{
		printf("\n");
		all = 8;
	}
	else
	{
		while (count--)
		{
			printf("   ");
		}
	}

	tree_pre_order(T->first_child);
	tree_pre_order(T->nextsibling);
}

void tree_find(MemberNode* root,Info people, MemberNode* T)
{
	if (!root)
	{
		return;
	}
	if (strcmp(root->myself.name, people.name) == 0)
	{
		*T = *root;
		return;
	}

	tree_find(root->first_child, people, T);
	tree_find(root->nextsibling, people, T);

}

void tree_insert(MemberNode* root,Info people)
{
	if (!root)
	{
		return;
	}
	if (strcmp(root->myself.name, people.name) == 0)
	{
		printf("�����뺢�ӵĸ�����Ϣ");
		MemberNode* temp = (MemberNode*)malloc(sizeof(MemberNode));
		if (!temp)
		{
			return;
		}
		temp->first_child = NULL;
		temp->nextsibling = NULL;

		if (root->first_child == NULL)
		{
			temp->parent = root;
			InfoAdd_2(temp);
			root->first_child = temp;
		}
		else if (root->first_child != NULL)
		{
			temp->parent = root;
			InfoAdd_2(temp);
			root->first_child->nextsibling = temp;
		}
		return;
	}

	tree_insert(root->first_child, people);
	tree_insert(root->nextsibling, people);

}

void tree_restore(MemberNode* T)
{
	if (!T)
	{
		return;
	}
	arr[i] = T;
	i++;
	tree_restore(T->first_child);
	tree_restore(T->nextsibling);

}

void tree_delete(MemberNode* root, Info people)
{
	m++;
	if (!root)
	{
		return;
	}

	if (strcmp(root->myself.name, people.name) == 0)
	{
		root = NULL;
		free(root);
	}

		tree_delete(root->first_child, people);
		tree_delete(root->nextsibling, people);
}

void tree_change(MemberNode* root, Info people)
{
	if (!root)
	{
		return;
	}

	if (strcmp(root->myself.name, people.name) == 0)
	{
		printf("��������Ҫ�޸ĵ���Ϣ\n");
		InfoAdd_2(root);
	}

	tree_change(root->first_child, people);
	tree_change(root->nextsibling, people);
}

int tree_pree_num(MemberNode* root)
{
	int j = 0;
	int max = 0;
	for (j = 0; j < i; j++)
	{
		if (arr[j]->myself.peer > max)
		{
			max = arr[j]->myself.peer;
		}
	}

	return max;
}