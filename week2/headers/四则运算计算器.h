#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<malloc.h>


enum str
{
	

};


typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ
Status traverseLStack(LinkStack* s);//����