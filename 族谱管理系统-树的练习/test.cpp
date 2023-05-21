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
		printf("               欢迎进入家谱管理系统             \n");
		printf("===============================================\n");
		printf("***           1 --- 展现家谱内容            ***\n");
		printf("***           2 --- 添加家庭成员            ***\n");
		printf("***           3 --- 解散局部成员            ***\n");
		printf("***           4 --- 更改家庭成员            ***\n");
		printf("***           5 --- 查找家庭成员            ***\n");
		printf("***           6 --- 计算家庭代数            ***\n");
		printf("***           7 --- 统计家庭成员            ***\n");
		printf("***           8 --- 插入家庭成员            ***\n");
		printf("***           0 --- 退出系统                ***\n");
		printf("===============================================\n");

		printf("请选择功能:");
		scanf_s("%d", &choice);

		if (choice == 0)
		{
			printf("退出成功\n");
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
			printf("请输入查找人的姓名\n");

			ret = scanf("%s", people.name);
			while (ret != 1)
			{
				printf("输入错误,请重新输入\n");
				while (getchar() != '\n');
				ret = scanf("%s", people.name);
			}

			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("查无此人,输入错误或其被除名\n");
			else
			{
				printf("查找成功,其个人信息为如下:\n");
				printf("[第%d代 |名字：%s |伴侣姓名：%s |住址：%s |年龄：%d ]\n", T.myself.peer, T.myself.name, T.myself.companion_name, T.myself.address, T.myself.age);
			}
			break;

		case 3:
			system("cls");
			printf("请输入解散该脉系的人的姓名\n");
			scanf("%s", people.name);
			
			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("查无此人,输入错误或其已被除名\n");

			else
			{
				tree_delete(root, people);
				printf("除名成功\n");
			}
			break;

		case 8:
			system("cls");
			printf("请输入孩子父亲的姓名\n");
			scanf("%s", people.name);

			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("查无此人,输入错误或其已被除名\n");
			else
			{
				tree_insert(root, people);
				printf("插入成功\n");

			}
			break;

		case 7:
			system("cls");
			tree_restore(root);
			printf("家族目前记载的人数有：%d", i);
			m = 1;
			break;

		case 4:
			system("cls");
			printf("请输入所要修改成员的姓名\n");
			scanf("%s", people.name);

			tree_find(root, people, &T);
			if (T.myself.peer == 0)
				printf("查无此人,输入错误或其已被除名\n");
			else
			{
				tree_change(root, people);
				printf("修改成功\n");
			}
			break;

		case 6:
			system("cls");
			if (m == 1)
			{
				int num = tree_pree_num(root);
				printf("家族总共有[%d]代\n", num);
			}
			else
			{
				tree_restore(root);
				int num = tree_pree_num(root);
				printf("家族总共有[%d]代\n", num);
			}
			break;

		default:
			system("cls");
			printf("输入错误，请重新输入\n");
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