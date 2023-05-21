#define _CRT_SECURE_NO_WARNINGS 1

#ifndef TREE_H
#define TREE_H

#define MAX_SIZE 500

#include<malloc.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>

enum judge
{
	No,
	Yes
};


typedef struct Information   
{
	char name[20];
	char companion_name[20];
	char address[30];
	int age;
	int peer;
	int wedding;
	int health;
	int birthday;

}Info;

typedef struct MemberNode   
{
	Info myself;
	MemberNode* parent;
	MemberNode* nextsibling;
	MemberNode* first_child;

}MemberNode, *pMemberTree;

//�������ڱ�����ʵ�ִ���չʾ
typedef struct node
{
	Info data;                   //������ָ��
	struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node* front;                   //��ͷ
	Node* rear;                    //��β
	size_t length;            //���г���
} LQueue;

//�жϹ�ϵ
int JudgeR(MemberNode* T);

//�������
int ageshow(MemberNode* T);

//�������
void InfoAdd_1(MemberNode* Node);
void InfoAdd_2(MemberNode* Node);

///////////////////////////////////////////////

pMemberTree tree_init(MemberNode* root);  //��ʼ��

void tree_assign(MemberNode* T);  //���

void tree_pre_order(MemberNode* T);  //����

void tree_find(MemberNode* root,Info people, MemberNode* T);

void tree_restore(MemberNode* T);  //��¼����ϸ������

void tree_insert(MemberNode* root, Info people);

void tree_delete(MemberNode* root, Info people);

void tree_change(MemberNode* root, Info people);

int tree_pree_num(MemberNode* root);

#endif

