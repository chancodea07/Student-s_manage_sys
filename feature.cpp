#include "feature.h"
#include "data_st.h"
void systemMenu(void)
{
	//�����˵�ͨ������¾��Ǽ�������
	//�˵�--����
	//���ع��ܣ�ͬ���ļ�
	printf("----------------------[ѧ������ϵͳ]-----------------------\n");
	printf("\t\t\t0.[�˳�ϵͳ]\n");
	printf("\t\t\t1.[������Ϣ]\n");
	printf("\t\t\t2.[�����Ϣ]\n");
	printf("\t\t\t3.[ɾ����Ϣ]\n");
	printf("\t\t\t4.[�޸���Ϣ]\n");
	printf("\t\t\t5.[������Ϣ]\n");
	// printf("\t\t6.���浽�ļ�"); Ĭ�����в������Ǳ��浽�ļ���
	printf("-----------------------------------------------------------\n");
	printf("��������ع������(0-5):");
	/* ��Ҫ������������ʾ */
}
void keyDown(struct Node *list)
/* �û����뽻�� */
{
	int userKey;
	struct student tempData;
	struct Node *currenNode;
	scanf("%d", &userKey);
	currenNode = searchNodeByAppoinNum(list, tempData.number);
	switch (userKey)
	{
	case 0:
		printf("\t\t\t0.[�˳�ϵͳ]\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("\t\t\t1.[������Ϣ]\n");
		printf("������������ѧ�ţ����䣬�绰��סַ��");
		scanf("%s%s%d%s%s", tempData.name, tempData.number, &tempData.age, tempData.tel, tempData.addr);
		insertNodeByHead(list, tempData);
		saveInfoToFile("student.txt", list);
		break;
	case 2:
		printf("\t\t\t2.[�����Ϣ]\n");
		printList(list);
		break;
	case 3:
		printf("\t\t\t3.[ɾ����Ϣ]\n");
		printf("������Ҫɾ����ѧ��������");
		scanf("%s", tempData.name);
		deleteNodeByAppoinName(list, tempData.name);
		saveInfoToFile("student.txt", list);
		break;
	case 4:
		printf("\t\t\t4.[�޸���Ϣ]\n");
		printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
		scanf("%s", tempData.number);
		if (currenNode == NULL)
		{
			printf("δ�ҵ������Ϣ��");
		}
		else
		{
			printf("�������µ�ѧ����Ϣ:\n");
			printf("������������ѧ�ţ����䣬�绰��סַ��");
			scanf("%s%s%d%s%s", currenNode->data.name, currenNode->data.number, &currenNode->data.age, currenNode->data.tel, currenNode->data.addr);
			saveInfoToFile("student.txt", list);
		}
		break;
	case 5:
		printf("\t\t\t5.[������Ϣ]\n");
		printf("��������ҵ�ѧ�ţ�");
		scanf("%s", tempData.number);
		if (searchNodeByAppoinNum(list, tempData.number) == NULL)
		{
			printf("δ�ҵ������Ϣ��");
		}
		else
		{
			printNode(searchNodeByAppoinNum(list, tempData.number));
		}
		break;
	default:
		printf("\t\t\t[����������������룡]\n");
		break;
	}
}
