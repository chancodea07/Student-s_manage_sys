/*
	1. C���Ի����﷨�����߼�
	2. C���Խṹ��
	3. ���ݽṹ����������
	4. C�����ļ�����
----------------------------------------------------------------
	�̶�����
	0.��¼���棺��½��֤
	1.�˵����
	2.��������
	3.�������
	4.ѡ��洢���ݵķ�ʽ/�ṹ��
	����ṹ
	���飺�ṹ������
	��ʽ�ṹ
 */
#include"../include/singleList.h"
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
void keyDown()
/* �û����뽻�� */
{
	int userKey;
	scanf("%d", &userKey);
	switch (userKey)
	{
		case 0:
			printf("\t\t\t0.[�˳�ϵͳ]\n");
			break;
		case 1:
			printf("\t\t\t1.[������Ϣ]\n");
			break;
		case 2:
			printf("\t\t\t2.[�����Ϣ]\n");
			break;
		case 3:
			printf("\t\t\t3.[ɾ����Ϣ]\n");
			break;
		case 4:
			printf("\t\t\t4.[�޸���Ϣ]\n");
			break;
		case 5:
			printf("\t\t\t5.[������Ϣ]\n");
			break;
		default:
			printf("\t\t\t[����������������룡]\n");
			break;
		}
}
int main(int argc, char const *argv[])
{
	struct Node node1 = {1, NULL};
	struct Node node2 = {2, NULL};
	struct Node node3 = {3, NULL};
	
	while (1)
	{
		systemMenu();
		keyDown();
		system("pause");
		system("cls");
		/* ���õ��û����� */
	}

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val = NULL;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val != NULL)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}
