#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//写数据结构
//死方法
//1.抽象单一个体 切分
//2.描述最初状态：初始化变量
//3.插入、修改、删除
//4.打印遍历（查找）
struct student
{
    char name[20];
    char number[15];
    int age;
    char tel[20];
    char addr[20];
};
struct Node
{
    struct student data;
    struct Node *next;
};
/*
    - 明确链表的含义：结构体变量和结构体变量连接在一起
    - 指针变成变量的常用方式：动态内存申请
    - 用第一个节点（头节点）表示整个链表
 */
struct Node *createList()
{
    //有表头的链表：头节点不存储数据
    //无标头的链表：头节点存储数据
    //产生一个结构体变量 -> 初始化一个变量
    struct Node *listHeadNode = (struct Node *)malloc(sizeof(struct Node));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//创建一个新的节点
struct Node *createNode(struct student data)
{
    //产生一个结构体变量 -> 初始化一个变量
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//插入节点并指定插入位置和值
void insertNodeByHead(struct Node *listHeadNode, struct student data)
{
    struct Node *newNode = createNode(data);
    newNode->next = listHeadNode->next;
    listHeadNode->next = newNode;
}
//打印链表
void printList(struct Node *listHeadNode)
{
    struct Node *pMove = listHeadNode->next;
    printf("姓名\t编号\t年龄\t电话\t\t住址\n");

    while (pMove != NULL)
    {
        printf("%s\t%s\t%d\t%s\t\t%s\t\n", pMove->data.name, pMove->data.number, pMove->data.age, pMove->data.tel, pMove->data.addr);
        pMove = pMove->next;
    }
    printf("\n");
}
//删除指定位置的链表节点，注意画图理解！
void deleteNodeByAppoinName(struct Node *listHeadNode, char *name)
{
    struct Node *posFrontNode = listHeadNode;
    struct Node *posNode = listHeadNode->next;
    if (posNode == NULL)
    {
        printf("无相关内容，无法删除\n");
        return;
    }
    else
    {
        while (strcmp(posNode->data.name, name))
        {
            posFrontNode = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("无相关内容，无法删除\n");
                return;
            }
        }
        posFrontNode->next = posNode->next;
        free(posNode);
    }
}
//查找节点
struct Node *searchNodeByAppoinNum(struct Node *listHeadNode, char *num)
{
    struct Node *pMove = listHeadNode->next;
    if (pMove == NULL)
    {
        return pMove;
    }
    else
    {
        while (strcmp(pMove->data.number, num))
        {
            pMove = pMove->next;
            if (pMove == NULL)
            {
                break;
            }
            return pMove;
        }
    }
}
//打印当前节点数据
void printNode(struct Node *currenNode)
{
    printf("姓名\t编号\t年龄\t电话\t\t住址\n");
    printf("%s\t%s\t%d\t%s\t\t%s\t\n", currenNode->data.name, currenNode->data.number, currenNode->data.age, currenNode->data.tel, currenNode->data.addr);
}
//文件操作，从文件中读入学生数据
void readInfoFromFile(char *fileName, struct Node *listHeadNode)
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) //防止文件不存在
    {
        fp = fopen(fileName, "w");
    }
    //格式化读取
    struct student tempData;
    while (fscanf(fp, "%s\t%s\t%d\t%s\t%s", tempData.name, tempData.number, &tempData.age, tempData.tel, tempData.addr) != EOF)
    {
        insertNodeByHead(listHeadNode, tempData);
        memset(&tempData, 0, sizeof(tempData));
    }
    fclose(fp);
}
//文件操作，将学生数据保存到文件中
void saveInfoToFile(char *fileName, struct Node *listHeadNode)
{
    FILE *fp = fopen(fileName, "w+");
    struct Node *pMove = listHeadNode->next;
    while (pMove != NULL)
    {
        fprintf(fp,"%s\t%s\t%d\t%s\t\t%s\t\n", pMove->data.name, pMove->data.number, pMove->data.age, pMove->data.tel, pMove->data.addr);
        pMove = pMove->next;
    }
    fclose(fp);
}
