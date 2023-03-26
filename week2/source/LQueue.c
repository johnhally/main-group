#include "LQueue.h" 


void InitLQueue(LQueue *Q){
	Node* temp = (Node*)malloc(sizeof(LQueue));

	temp->next = NULL;
	temp->data = 0;
	Q->front = temp;
	Q->rear = temp;
	Q->length = 0;

}


void DestoryLQueue(LQueue *Q){
	

}


Status IsEmptyLQueue(LQueue *Q){
	if (Q->front == Q->rear)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

Status GetHeadLQueue(LQueue *Q,ElemType *data){
	if (!IsEmptyLQueue(Q))
		return FALSE;
	else
		*data = Q->front->next->data;
	
	return TRUE;

}


int LengthLQueue(LQueue *Q){
	
	return Q->length;
}


Status EnLQueue(LQueue *Q, ElemType data){

	if (Q->length==0)
	{
		Q->front = Q->rear;           //相当于初始化的作用，当清空一次后，使得rear与front回到一起
	}

	Node* temp = (Node*)malloc(sizeof(LQueue));
	if (!temp)
	{
		return  FALSE;
	}
	temp->next = NULL;
	temp->data = data;
	Q->rear->next = temp;
	Q->rear = temp;
	Q->length += 1;

}


Status DeLQueue(LQueue *Q){
	if (Q->front==NULL)
	{
		return FALSE;
	}

	Node* temp = Q->front;
	Q->front = temp->next;
	Q->length--;
	return TRUE;
}


void ClearLQueue(LQueue *Q){

	Node* temp = Q->front->next;
	while (temp)
	{
		Q->front = temp->next;
		free(temp);
		temp = Q->front;
	}
	Q->length = 0;

}


int TraverseLQueue (LQueue *Q){

	if (Q->front==NULL)
	{
		return FALSE;
	}

	Node* temp = Q->front->next;
	printf("展示\n");
	while (temp)
	{
		printf("%7d\n", temp->data);
		temp = temp->next;
	}
	return Q->length;
}
