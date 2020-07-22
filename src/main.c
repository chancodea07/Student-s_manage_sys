/*
	1. C语言基础语法与编程逻辑
	2. C语言结构体
	3. 数据结构基础：链表
	4. C语言文件操作
----------------------------------------------------------------
	固定流程
	0.登录界面：登陆验证
	1.菜单设计
	2.按键交互
	3.设计数据
	4.选择存储数据的方式/结构：
	数组结构
	数组：结构体数组
	链式结构
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void systemMenu(void)
{
	//几个菜单通常情况下就是几个函数
	//菜单--功能
	//隐藏功能：同步文件
	printf("----------------------[学生管理系统]-----------------------\n");
	printf("\t\t\t0.退出系统\n");
	printf("\t\t\t1.插入信息\n");
	printf("\t\t\t2.浏览信息\n");
	printf("\t\t\t3.删除信息\n");
	printf("\t\t\t4.修改信息\n");
	printf("\t\t\t5.查找信息\n");
	// printf("\t\t6.保存到文件"); 默认所有操作都是保存到文件中
	printf("-----------------------------------------------------------\n");
	printf("请输入相关功能序号(0-5):");
	/* 需要给出交互的提示 */
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
