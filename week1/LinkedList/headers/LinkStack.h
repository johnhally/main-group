#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<malloc.h>
#include<stdio.h>
#include <stdlib.h>


enum function      //功能枚举
{
	Exit,          //退出                
	init_stack,    //初始化栈
	isEmpty_LStack,//判断栈是否为空
	get_TopLStack, //得到栈顶元素
	clear_LStack,  //清空栈
	destroy_LStack,//销毁栈
	LStack_Length, //检测栈长度
	push_LStack,   //入栈
	pop_LStack,    //出栈
	traverse_LStack//遍历
	 
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



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
Status traverseLStack(LinkStack* s);//遍历

#endif 
