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

//队列用于遍历，实现代代展示
typedef struct node
{
	Info data;                   //数据域指针
	struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node* front;                   //队头
	Node* rear;                    //队尾
	size_t length;            //队列长度
} LQueue;

//判断关系
int JudgeR(MemberNode* T);

//日期输出
int ageshow(MemberNode* T);

//输出函数
void InfoAdd_1(MemberNode* Node);
void InfoAdd_2(MemberNode* Node);

///////////////////////////////////////////////

pMemberTree tree_init(MemberNode* root);  //初始化

void tree_assign(MemberNode* T);  //添加

void tree_pre_order(MemberNode* T);  //遍历

void tree_find(MemberNode* root,Info people, MemberNode* T);

void tree_restore(MemberNode* T);  //记录该脉细的人数

void tree_insert(MemberNode* root, Info people);

void tree_delete(MemberNode* root, Info people);

void tree_change(MemberNode* root, Info people);

int tree_pree_num(MemberNode* root);

#endif

