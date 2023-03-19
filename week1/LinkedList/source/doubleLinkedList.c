#include"doubleLinkedList.h"



void InitList(LinkedList* L)
{
	LinkedList transition = (LinkedList)malloc(sizeof(struct LinkedNode));

	if (transition == NULL)
	{
		printf("����ʧ��\n");
		printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
	}
	else
	{
		transition->front = NULL;
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

alternative AddList(LNode* p,ElemType Data)
{
	LinkedList transition = p;
	LinkedList newnode = (LinkedList)malloc(sizeof(struct LinkedNode));
	if (!newnode)
	{
		printf("ʧ��\n");
		printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
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
		printf("δ����κ�����\n");
	} 
	printf("\n����:\n");
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
	LinkedList p1 = p;           //������������λ�õ�ǰ��
	LinkedList p2 = p1->next;     //������������λ�õĺ���

	if (newnode == NULL)
	{
		printf("ʧ��\n");
		printf("����ԭ��%s\n", strerror(errno)); //  �������ԭ��
		return error;
	}
	newnode->data = Data;

	printf("��ȷ�������λ�ã����ڵ�a�����ݺ͵�a+1������֮�����\n");
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
		printf("��������\n");
		return error;
	}
	return success;

}

alternative DelectList(LNode* p, ElemType Data)
{
	LinkedList transition = p->next;
	LinkedList pre = transition->front;  //pre��ɾ������λ�õ�ǰ��

	if (!transition)
	{
		printf("������û������\n");
	}
	else
	{
		while (transition->data != Data)
		{
			transition = transition->next;
			pre = transition->front;
			if (!transition)
			{
				printf("�����ݲ�����\n");
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