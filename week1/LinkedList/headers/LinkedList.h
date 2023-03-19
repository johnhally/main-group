#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<errno.h>

enum Function    //功能的枚举
{
	exit,                    //退出
	init_list,               //初始化
	destroy_list,            //销毁
	add_list,                //添加
	delect_list,             //删除
	search_list,             //查找
	insert_list,             //插入
	show_list,               //展示
	reverse_list,            //反转
	recursive_reverse_list,  //递归反转
	find_mid_list,           //找中点
	odd_even_exchange,       //奇数偶数调换  
	judge_circle             //判断成环

};
enum Consequence  //结果0和1的文字化
{
	error,
	success
};

typedef int ElemType;
typedef int alternative;  //alternative 可选择的

typedef struct LinkedNode
{
	ElemType data;
	struct LinkedNode* next;

}LNode, *LinkedList;


void InitList(LinkedList* L);

void DestroyList(LinkedList* L);

alternative AddList(LNode* p, ElemType data);

void ShowList(LinkedList L);

alternative InsertList(LNode* p, ElemType data, int count); //函数里的count 是为了保证取值不会取到最后一个，且避免错误输入

alternative SearchList(LNode* p, ElemType Data);

alternative DelectList(LNode* p, ElemType Data);

LinkedList ReverseList(LNode* p);

LinkedList RecursiveReverseList(LNode* p);             //我认为思路没问题，但是不知道为啥输出时，数据全无了

ElemType FindMidList(LNode* p,int count,LinkedList* ele);

void OddEvenExchange(LinkedList* L, int count);        //为什么调试的时候确实换了，但是show出来的结果是没变的，我想是不是赋值与赋址的问题，但发现并不是啊？或者是我没发现。
                                                       
alternative JudegeCircle(LNode*p);