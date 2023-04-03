#include"LinkedList.h"


void InitList(LinkedList* L)
{
	LinkedList transition = (LinkedList)malloc(sizeof(LNode)); //transition ����

	if (transition == NULL)
	{
		printf("����ʧ��\n");
		printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
	}
	else
	{
		transition->next = NULL;
		*L = transition;
		printf("���ٳɹ�\n");

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
	printf("������\n");
}

alternative AddList(LNode* p,ElemType data)
{
	LinkedList now = p;
	LinkedList newnode = (LinkedList)malloc(sizeof(LNode));


	if (newnode == NULL)
	{
		printf("ʧ��\n");
		printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
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
		printf("δ����κ�����\n");
	}
	printf("\n����:\n");
	while (transition)
	{
		printf("%7d\n", transition->data);    
		transition = transition->next;
	}

}

alternative InsertList(LNode* p, ElemType data, int count)
{ 
	int i = 0;
	int front = 0;   //����λ��ǰ�������

	LinkedList transition = p;   //���ɱ�����������front��behind
	LinkedList temp=NULL; //���ɱ�����������behind
	LinkedList newnode = (LinkedList)malloc(sizeof(LNode));

	if (newnode == NULL)
	{
		printf("ʧ��\n");
		printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
		return error;
	}
	newnode->data = data;

	printf("��ȷ�������λ�ã����ڵ�a�����ݺ͵�a+1������֮�����\n");
	scanf("%d", &front);
	if (front<count)   //��֤ȡֵ����ȡ�����һ�����ұ����������
	{
		for (i = 0; i < front; i++)   //����for�����ҵ�front��behind��λ��
		{
			transition = transition->next;
		}
		temp = transition->next;
		transition->next = newnode;

		newnode->next = temp;

	}
	else
	{
		printf("��������\n");
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
		printf("����Ϊ��\n");
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
				printf("û���������\n");
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