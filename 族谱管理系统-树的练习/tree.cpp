#include"tree.h"

pMemberTree arr[MAX_SIZE] = { 0 };  //全局数组变量，将成员全部记录进去
int all = 0; //全局变量，用在遍历函数中，使得当输出printf（“\n”）后，新的一脉要有行距
int i = 0;   //全局变量，用来记录脉系的人数
int m = 0;

int JudgeR(MemberNode* T)
{
	int ret = 0;
	int relation = 0;
	printf("\n");

	printf("请输入[ %s ]的子女的个人信息，如果其还有其他子女则在输入1后,再输入其个人信息。\n",T->myself.name);
	printf("如果输入完其所有子女的信息或者说其无子女，输入任何数字键退出\n");

	ret = scanf("%d", &relation);
	while (ret != 1)
	{
		printf("输入错误,请重新输入\n");
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
	tmp_time = time(NULL);//获取当前时间
	ptime = localtime(&tmp_time);

	tmp = localtime(&tmp_time);
	int year = (1900 + tmp->tm_year) - (T->myself.birthday / 10000);

	return year;
}

void InfoAdd_1(MemberNode* Node)
{
	Node->myself.peer = 1;

	printf("请输入，脉细中最大祖宗的个人信息\n");
	printf("姓名        伴侣姓名        出生日期      住址          是否婚配(1/0)    健康状态(1/0) \n");

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

	printf("请输入个人信息\n");
	printf("姓名        伴侣姓名        出生日期      住址          是否婚配(1/0)    健康状态(1/0) \n");

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
		printf("请输入他第一个孩子的个人信息\n");
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

	printf("[第%d代 |名字：%s |伴侣姓名：%s |住址：%s |年龄：%d ]\n", T->myself.peer, T->myself.name, T->myself.companion_name,T->myself.address, T->myself.age);
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
		printf("请输入孩子的个人信息");
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
		printf("请输入你要修改的信息\n");
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