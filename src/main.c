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
