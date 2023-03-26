#include"LQueue.h"


void meun()
{
	printf("******************* meun  *********************\n");
	printf("                                               \n");
	printf("***1.��ʼ��      \n");
	printf("***2.�Ƿ�Ϊ�գ�  \n");
	printf("***3.�õ���Ԫ��  \n");
	printf("***4.���鳤�ȼ���    \n");
	printf("***5.���        \n");
	printf("***6.����        \n");
	printf("***7.��ն���     \n");
	printf("***8.����         \n");
	printf("                                               \n");
	printf("******************* meun  *********************\n");

}

int main()
{
	int ret = 0;    //�ж������Ƿ�Ϊ����
	ElemType Data;  //�û����������
	ElemType gain;  //���top������
	int length = 0;  //���г���
	int choice = 0;
	LQueue ele;

	system("cls");
	InitLQueue(&ele);
	printf("��ʼ���ɹ�\n");

	do
	{
		meun();
		printf("��ѡ��Ҫ���еĹ���\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			system("cls");
			printf("�ɹ��˳�\n");
			break;

		case 1:
			system("cls");
			printf("�ѳ�ʼ��\n");
			break;
	
		case 2:
			system("cls");
			if (IsEmptyLQueue(&ele))
				printf("��Ϊ��\n");
			else
				printf("Ϊ��\n");
			break;

		case 3:
			system("cls");
			if (GetHeadLQueue(&ele, &gain)) 
				printf("�õ�����Ԫ��,����Ϊ%d\n", gain);
			else
				printf("��ȡʧ��\n");
			break;


		case 7:
			system("cls");
			ClearLQueue(&ele);
			printf("��ճɹ�\n");
			break;

		case 4:
			system("cls");
			if (LengthLQueue(&ele)) {
				length = LengthLQueue(&ele);
				printf("���ɹ�������Ϊ%d\n", length);
			}
			else
				printf("���鳤��Ϊ0\n");
			break;

		case 5:
			system("cls");
			printf("����������\n");
			ret = scanf("%d", &Data);
			if (ret != 1)
			{
				getchar();
				printf("�������\n");
				break;
			}
			if (EnLQueue(&ele, Data))
				printf("��ӳɹ�\n");
			else
				printf("���ʧ��\n");
			break;

		case 6:
			system("cls");
			if (DeLQueue(&ele))
				printf("�ɹ�\n");
			else
				printf("ʧ��\n");
			break;

		case 8:
			system("cls");
			if (TraverseLQueue(&ele)==0)
			{
				printf("�����ѿ�\n");
			}
			break;


		default:
			printf("��������\n");
			break;
		}
	} while (choice);

	return 0;
}