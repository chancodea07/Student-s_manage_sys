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
#include "../include/singleList.h"

void systemMenu(void)
{
	//几个菜单通常情况下就是几个函数
	//菜单--功能
	//隐藏功能：同步文件
	printf("----------------------[学生管理系统]-----------------------\n");
	printf("\t\t\t0.[退出系统]\n");
	printf("\t\t\t1.[插入信息]\n");
	printf("\t\t\t2.[浏览信息]\n");
	printf("\t\t\t3.[删除信息]\n");
	printf("\t\t\t4.[修改信息]\n");
	printf("\t\t\t5.[查找信息]\n");
	// printf("\t\t6.保存到文件"); 默认所有操作都是保存到文件中
	printf("-----------------------------------------------------------\n");
	printf("请输入相关功能序号(0-5):");
	/* 需要给出交互的提示 */
}
void keyDown(struct Node *list)
/* 用户输入交互 */
{
	int userKey;
	struct student tempData;
	scanf("%d", &userKey);
	switch (userKey)
	{
	case 0:
		printf("\t\t\t0.[退出系统]\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("\t\t\t1.[插入信息]\n");
		printf("请输入姓名，学号，年龄，电话，住址：");
		scanf("%s%s%d%s%s", tempData.name, tempData.number, &tempData.age, tempData.tel, tempData.addr);
		insertNodeByHead(list, tempData);
		break;
	case 2:
		printf("\t\t\t2.[浏览信息]\n");
		printList(list);
		break;
	case 3:
		printf("\t\t\t3.[删除信息]\n");
		printf("请输入要删除的学生姓名：");
		scanf("%s", tempData.name);
		deleteNodeByAppoinName(list, tempData.name);
		break;
	case 4:
		printf("\t\t\t4.[修改信息]\n");
		printf("请输入需要修改的学生的学号：");
		scanf("%s", tempData.number);
		struct Node *currenNode = searchNodeByAppoinNum(list, tempData.number);//查找信息并记录节点指针
		if (currenNode == NULL)
		{
			printf("未找到相关信息！");
		}
		else
		{
			printf("请输入新的学生信息:\n");
			printf("请输入姓名，学号，年龄，电话，住址：");
			scanf("%s%s%d%s%s", currenNode->data.name, currenNode->data.number, &currenNode->data.age, currenNode->data.tel, currenNode->data.addr);
		}
		break;
	case 5:
		printf("\t\t\t5.[查找信息]\n");
		printf("请输入查找的学号：");
		scanf("%s", tempData.number);
		if (searchNodeByAppoinNum(list, tempData.number) == NULL)
		{
			printf("未找到相关信息！");
		}
		else
		{
			printNode(searchNodeByAppoinNum(list, tempData.number));
		}
		break;
	default:
		printf("\t\t\t[输入错误，请重新输入！]\n");
		break;
	}
}
int main(int argc, char const *argv[])
{

	struct Node *list = createList();

	while (1)
	{
		systemMenu();
		keyDown(list);
		system("pause");
		system("cls");
		/* 良好的用户交互 */
	}

	return 0;
}
