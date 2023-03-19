#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<errno.h>

enum Function    //���ܵ�ö��
{
	exit,                    //�˳�
	init_list,               //��ʼ��
	destroy_list,            //����
	add_list,                //���
	delect_list,             //ɾ��
	search_list,             //����
	insert_list,             //����
	show_list,               //չʾ
	reverse_list,            //��ת
	recursive_reverse_list,  //�ݹ鷴ת
	find_mid_list,           //���е�
	odd_even_exchange,       //����ż������  
	judge_circle             //�жϳɻ�

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
	ElemType data;
	struct LinkedNode* next;

}LNode, *LinkedList;


void InitList(LinkedList* L);

void DestroyList(LinkedList* L);

alternative AddList(LNode* p, ElemType data);

void ShowList(LinkedList L);

alternative InsertList(LNode* p, ElemType data, int count); //�������count ��Ϊ�˱�֤ȡֵ����ȡ�����һ�����ұ����������

alternative SearchList(LNode* p, ElemType Data);

alternative DelectList(LNode* p, ElemType Data);

LinkedList ReverseList(LNode* p);

LinkedList RecursiveReverseList(LNode* p);             //����Ϊ˼·û���⣬���ǲ�֪��Ϊɶ���ʱ������ȫ����

ElemType FindMidList(LNode* p,int count,LinkedList* ele);

void OddEvenExchange(LinkedList* L, int count);        //Ϊʲô���Ե�ʱ��ȷʵ���ˣ�����show�����Ľ����û��ģ������ǲ��Ǹ�ֵ�븳ַ�����⣬�����ֲ����ǰ�����������û���֡�
                                                       
alternative JudegeCircle(LNode*p);