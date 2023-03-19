#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<errno.h>

//注释：代码中，我用了很多变量transition.其中文有过渡的意思。在代码中，我常赋予其head的位置
//      temp,p1,p2也是相同意味，即过渡变量，用来找某个数据的地址

enum Function    //功能的枚举
{
	exit,                    //退出
	init_list,               //初始化
	destroy_list,            //销毁
	add_list,                //添加
	delect_list,             //删除
	search_list,             //查找
	insert_list,             //插入
	show_list                //展示
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
	struct LinkedNode* front;
	ElemType data;
	struct LinkedNode* next;

}LNode,*LinkedList;



void InitList(LinkedList* L);

void DestroyList(LinkedList* L);

alternative AddList(LNode* p,ElemType Data);

void ShowList(LNode* p);

alternative SearchList(LNode* p, ElemType Data);

alternative InsertList(LNode* p, ElemType Data, int count);

alternative DelectList(LNode* p, ElemType Data);