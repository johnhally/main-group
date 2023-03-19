#include"doubleLinkedList.h"



void InitList(LinkedList* L)
{
	LinkedList transition = (LinkedList)malloc(sizeof(struct LinkedNode));

	if (transition == NULL)
	{
		printf("开辟失败\n");
		printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
	}
	else
	{
		transition->front = NULL;
		transition->next = NULL;
		*L = transition;
		printf("开辟成功\n");

	}
}

void DestroyList(LinkedList* L)
{
	while (*L != NULL)
	{
		LinkedList transition = *L;
		*L = (*L)->next;
		free(transition);
		transition = NULL;
	}
	printf("已销毁\n");
}

alternative AddList(LNode* p,ElemType Data)
{
	LinkedList transition = p;
	LinkedList newnode = (LinkedList)malloc(sizeof(struct LinkedNode));
	if (!newnode)
	{
		printf("失败\n");
		printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
		return error;
	}

	newnode->data = Data;
	newnode->next = NULL;
	newnode->front = transition;

	while (transition->next!=NULL)
	{
		transition = transition->next;
	}                                                             
	transition->next = newnode;                                   
	newnode->front = transition;                                  

	return success;
}

void ShowList(LNode* p)
{
	LinkedList transition = p->next;

	if (transition == NULL)
	{
		printf("未添加任何数据\n");
	} 
	printf("\n链表:\n");
	while (transition)
	{
		printf("%7d\n", transition->data);
		transition = transition->next;
	}

}

alternative SearchList(LNode* p,ElemType Data)
{
	LinkedList transition = p;

	while (transition->next)
	{
		if (transition->data == Data)
		{
			return success;
		}
		transition = transition->next;
	}
	return error;
}

alternative InsertList(LNode* p, ElemType Data, int count)
{
	int i = 0;
	int front = count;

	LinkedList newnode = (LinkedList)malloc(sizeof(struct LinkedNode));
	LinkedList p1 = p;           //插入数据所在位置的前面
	LinkedList p2 = p1->next;     //插入数据所在位置的后面

	if (newnode == NULL)
	{
		printf("失败\n");
		printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
		return error;
	}
	newnode->data = Data;

	printf("请确定插入的位置，其在第a个数据和第a+1个数据之间插入\n");
	scanf("%d", &front);
	if (front < count)
	{
		for (i = 0; i < front; i++)
		{
			p1 = p1->next;
			p2 = p1->next;
		}
		p1->next = newnode;
		newnode->next = p2;
		newnode->front = p1;
		p2->front = newnode;

	}
	else
	{
		printf("错误输入\n");
		return error;
	}
	return success;

}

alternative DelectList(LNode* p, ElemType Data)
{
	LinkedList transition = p->next;
	LinkedList pre = transition->front;  //pre是删除数据位置的前面

	if (!transition)
	{
		printf("链表中没有数据\n");
	}
	else
	{
		while (transition->data != Data)
		{
			transition = transition->next;
			pre = transition->front;
			if (!transition)
			{
				printf("该数据不存在\n");
				return error;
			}
		}
		pre->next = transition->next;
		transition->next->front = pre;

		free(transition);
		transition = NULL;
		return success;
	}

}