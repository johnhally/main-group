#include "LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	if (!temp)
	{
		return ERROR;
	}
	s->top = temp;
	s->top= (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if (!s->top)
		return ERROR;
	else
		return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if (!isEmptyLStack(s))
		return ERROR;
	
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if (!isEmptyLStack(s))
		return ERROR;
	while (s->top)
	{
		LinkStackPtr temp = s->top;
		s->top = s->top->next;
		s->count = 0;
		/*free(temp);
		temp = NULL;*/
	}
	return SUCCESS;

}

//����ջ
Status destroyLStack(LinkStack *s){
	if (!isEmptyLStack(s))
		return ERROR;
	clearLStack(s);
	/*free(s);
	s = NULL;*/
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if (!isEmptyLStack(s))
		return ERROR;

	*length = s->count;

}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	if (!temp)
	{
		return ERROR;
	}
	temp->data = data;
	temp->next = s->top;
	s->top = temp;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if (!isEmptyLStack(s))
		return ERROR;

	data = s->top->data;
	LinkStackPtr temp = s->top;
	s->top = s->top->next;
	s->count--;
	/*free(temp);
	temp = NULL;*/

	return SUCCESS;
}

Status traverseLStack(LinkStack* s)
{
	if (!isEmptyLStack(s))
		return ERROR;
	LinkStackPtr temp = s->top;
	printf("���ɣ�չʾ\n");
	while (temp)
	{
		printf("%7d\n", temp->data);
		temp = temp->next;
	}

}

