#include"LinkedList.h"


void InitList(LinkedList* L)
{
	LinkedList transition = (LinkedList)malloc(sizeof(LNode)); //transition 过渡

	if (transition == NULL)
	{
		printf("开辟失败\n");
		printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
	}
	else
	{
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

alternative AddList(LNode* p,ElemType data)
{
	LinkedList now = p;
	LinkedList newnode = (LinkedList)malloc(sizeof(LNode));


	if (newnode == NULL)
	{
		printf("失败\n");
		printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
		return error;
	}
	newnode->data = data;
	newnode->next = NULL;
	while (now->next!= NULL)
	{
		now = now->next;
	}
	now->next = newnode;

	return success;

}

void ShowList(LinkedList L)
{
	LinkedList transition = L->next;

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

alternative InsertList(LNode* p, ElemType data, int count)
{ 
	int i = 0;
	int front = 0;   //插入位置前面的数据

	LinkedList transition = p;   //过渡变量，运用找front和behind
	LinkedList temp=NULL; //过渡变量，运用找behind
	LinkedList newnode = (LinkedList)malloc(sizeof(LNode));

	if (newnode == NULL)
	{
		printf("失败\n");
		printf("错误原因：%s\n", strerror(errno)); //  输出错误原因
		return error;
	}
	newnode->data = data;

	printf("请确定插入的位置，其在第a个数据和第a+1个数据之间插入\n");
	scanf("%d", &front);
	if (front<count)   //保证取值不会取到最后一个，且避免错误输入
	{
		for (i = 0; i < front; i++)   //两个for用于找到front和behind的位置
		{
			transition = transition->next;
		}
		temp = transition->next;
		transition->next = newnode;

		newnode->next = temp;

	}
	else
	{
		printf("错误输入\n");
		return error;
	}

	return success;

}

alternative SearchList(LNode* p,ElemType Data)
{
	while (p !=NULL)
	{
		if (p->data == Data)
		{
			return success;
		}
		p = p->next;
	}
	return error;
}

alternative DelectList(LNode* p, ElemType Data)
{
	LinkedList frontnode = p;
	LinkedList node = p->next;
	if (node == NULL)
	{
		printf("链表为空\n");
		return error;
	}
	else
	{
		while (node->data != Data)
		{
			frontnode = node;
			node = node->next;
			if (node == NULL)
			{
				printf("没有这个数据\n");
				return error;
			}
		}
		frontnode->next = node->next;
		free(node);
		return success;
	}
}

LinkedList ReverseList(LNode* p)
{
	LinkedList p1 = p->next;
	LinkedList p2 = p1->next;
	p1->next = NULL;
	LinkedList firstnode = p1;

	while (p2 != NULL)  
	{
		p1 = p2;
		p2 = p2->next;
		p1->next = firstnode;
		firstnode = p1;
	}
	p->next = p1;

	return p;

}

LinkedList RecursiveReverseList(LNode* p)
{
	if (p == NULL || p->next == NULL)
	{
		return p;
	}
	else
	{
		LinkedList newnode = p->next;
		newnode->next = p;
		p->next = NULL;
		return RecursiveReverseList(p->next);
	}
}

ElemType FindMidList(LNode* p,int count, LinkedList* ele)
{
	int i = 0;
	LinkedList temp = NULL;
	for (i = 0; i < count / 2; i++)
	{
		p = p->next;
	}
	temp = p->next;
	if (count % 2 != 0)
	{
		return temp->data;
	}
	else if (count % 2 == 0)
	{
		*ele = p;
		return temp->data;
	}


}

void OddEvenExchange(LinkedList* L, int count)
{
	int i = 0;
	LinkedList p1 = (*L)->next;
	LinkedList p2 = (*L)->next->next;
	LinkedList temp = NULL;
	temp = p2;
	p2 = p1;
	p1 = temp;
	for (i = 1; i < count / 2; i++)
	{
		p1 = p1->next;
        p2 = p1->next;
		temp = p2;
		p2 = p1;
		p1 = temp;
	}

}

alternative JudegeCircle(LNode* p)
{
	LinkedList slow = p;
	LinkedList fast = p;
	while (slow->next != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == NULL)
		{
			return error;
		}
		else if (fast == slow)
		{
			return success;
		}
	}
	return error;
}