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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void systemMenu(void)
{
	//�����˵�ͨ������¾��Ǽ�������
	//�˵�--����
	//���ع��ܣ�ͬ���ļ�
	printf("----------------------[ѧ������ϵͳ]-----------------------\n");
	printf("\t\t\t0.�˳�ϵͳ\n");
	printf("\t\t\t1.������Ϣ\n");
	printf("\t\t\t2.�����Ϣ\n");
	printf("\t\t\t3.ɾ����Ϣ\n");
	printf("\t\t\t4.�޸���Ϣ\n");
	printf("\t\t\t5.������Ϣ\n");
	// printf("\t\t6.���浽�ļ�"); Ĭ�����в������Ǳ��浽�ļ���
	printf("-----------------------------------------------------------\n");
	printf("��������ع������(0-5):");
	/* ��Ҫ������������ʾ */
}
int main(int argc, char const *argv[])
{
	systemMenu();
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
