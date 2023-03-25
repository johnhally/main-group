#include"LinkStack.h"


void meun()
{
	printf("                                               \n");
	printf("******************* meun  *********************\n");
	printf("****************** 0.Exit *********************\n");
	printf("***1.init_stack     ****  2.isEmpty_LStack  ***\n");
	printf("***3.get_TopLStack  ****  4.clear_LStack    ***\n");
	printf("***5.destroy_LStack ****  6.LStack_Length   ***\n");
	printf("***7.push_LStack    ****  8.pop_LStack      ***\n");
	printf("************** 9.traverse_LStack  *************\n");
	printf("******************* meun  *********************\n");
	printf("                                               \n");

}


int main()
{
	int ret = 0;    //�ж������Ƿ�Ϊ����
	ElemType Data;  //�û����������
	ElemType gain;  //���top������
	int lenth = 0;  //ջ����
	int choice = 0;
	LinkStack ele;

	do
	{
		meun();
		printf("��ѡ��Ҫ���еĹ���\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case Exit:
			system("cls");
			printf("�ɹ��˳�\n");
			break;

		case init_stack:
			system("cls");
			if (initLStack(&ele))
				printf("��ʼ���ɹ�\n");
			else
				printf("��ʼ��ʧ��\n");
			break;

		case isEmpty_LStack:
			system("cls");
			if (isEmptyLStack(&ele))
				printf("ջ��Ϊ��\n");
			else
				printf("ջΪ��\n");
			break;

		case get_TopLStack:
			system("cls");
			if (getTopLStack(&ele, &gain))
				printf("�õ�����Ԫ��,����Ϊ%d\n", gain);
			else
				printf("��ȡʧ��\n");
			break;


		case clear_LStack:
			system("cls");
			if (clearLStack(&ele))
				printf("��ճɹ�\n");
			else
				printf("���ʧ��\n");
			break;

		case destroy_LStack:
			system("cls");
			if (destroyLStack(&ele))
				printf("���ٳɹ�\n");
			else
				printf("����ʧ��\n");
			break;

		case LStack_Length:
			system("cls");
			if (LStackLength(&ele, &lenth))
				printf("���ɹ�������Ϊ%d\n", lenth);
			else
				printf("����Ϊ0\n");
			break;

		case push_LStack:
			system("cls");
			printf("����������\n");
			ret = scanf("%d", &Data);
			if(ret!=1)
			{
				getchar();
				printf("�������\n");
				break;
			}
			if (pushLStack(&ele, Data))
				printf("��ջ�ɹ�\n");
			else
				printf("��ջʧ��\n");
			break;

		case pop_LStack:
			system("cls");
			if (popLStack(&ele, &Data))
				printf("��ջ�ɹ�����ջ������Ϊ%d\n", Data);
			else
				printf("��ջʧ��\n");
			break;

		case traverse_LStack:
			system("cls");
			traverseLStack(&ele);
			break;

		default:
				printf("��������\n");
			break;
		}
	} while (choice);

	return 0;
}