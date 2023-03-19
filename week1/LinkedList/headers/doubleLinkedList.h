#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<errno.h>

//ע�ͣ������У������˺ܶ����transition.�������й��ɵ���˼���ڴ����У��ҳ�������head��λ��
//      temp,p1,p2Ҳ����ͬ��ζ�������ɱ�����������ĳ�����ݵĵ�ַ

enum Function    //���ܵ�ö��
{
	exit,                    //�˳�
	init_list,               //��ʼ��
	destroy_list,            //����
	add_list,                //���
	delect_list,             //ɾ��
	search_list,             //����
	insert_list,             //����
	show_list                //չʾ
};

enum Consequence  //���0��1�����ֻ�
{
	error,
	success
};

typedef int ElemType;
typedef int alternative;  //alternative ��ѡ���


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