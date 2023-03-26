#include"calculate.h"


//初始化栈
Status initLStack(LinkStack* s) {
	LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	if (!temp)
	{
		return ERROR;
	}
	s->top = temp;
	s->top = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (!s->top)
		return ERROR;
	else
		return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
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

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	if (!isEmptyLStack(s))
		return ERROR;

	*data = s->top->data;
	LinkStackPtr temp = s->top;
	s->top = s->top->next;
	s->count--;
	/*free(temp);
	temp = NULL;*/

	return SUCCESS;
}

//遍历
Status traverseLStack(LinkStack* s)
{
	if (!isEmptyLStack(s))
		return ERROR;
	LinkStackPtr temp = s->top;
	printf("来吧，展示\n");
	while (temp)
	{
		printf("%7d\n", temp->data);
		temp = temp->next;
	}

}


