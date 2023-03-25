#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<malloc.h>
#include<stdio.h>
#include <stdlib.h>


enum function      //����ö��
{
	Exit,          //�˳�                
	init_stack,    //��ʼ��ջ
	isEmpty_LStack,//�ж�ջ�Ƿ�Ϊ��
	get_TopLStack, //�õ�ջ��Ԫ��
	clear_LStack,  //���ջ
	destroy_LStack,//����ջ
	LStack_Length, //���ջ����
	push_LStack,   //��ջ
	pop_LStack,    //��ջ
	traverse_LStack//����
	 
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
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ
Status traverseLStack(LinkStack* s);//����

#endif 
