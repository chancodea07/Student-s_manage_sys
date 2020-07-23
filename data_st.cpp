#include "data_st.h"
struct Node *createList()
{
    //�б�ͷ������ͷ�ڵ㲻�洢����
    //�ޱ�ͷ������ͷ�ڵ�洢����
    //����һ���ṹ����� -> ��ʼ��һ������
    struct Node *listHeadNode = (struct Node *)malloc(sizeof(struct Node));
    listHeadNode->next = NULL;
    return listHeadNode;
}
//����һ���µĽڵ�
struct Node *createNode(struct student data)
{
    //����һ���ṹ����� -> ��ʼ��һ������
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//����ڵ㲢ָ������λ�ú�ֵ
void insertNodeByHead(struct Node *listHeadNode, struct student data)
{
    struct Node *newNode = createNode(data);
    newNode->next = listHeadNode->next;
    listHeadNode->next = newNode;
}
//��ӡ����
void printList(struct Node *listHeadNode)
{
    struct Node *pMove = listHeadNode->next;
    printf("����\t���\t����\t�绰\t\tסַ\n");

    while (pMove != NULL)
    {
        printf("%s\t%s\t%d\t%s\t\t%s\t\n", pMove->data.name, pMove->data.number, pMove->data.age, pMove->data.tel, pMove->data.addr);
        pMove = pMove->next;
    }
    printf("\n");
}
//ɾ��ָ��λ�õ�����ڵ㣬ע�⻭ͼ��⣡
void deleteNodeByAppoinName(struct Node *listHeadNode, char *name)
{
    struct Node *posFrontNode = listHeadNode;
    struct Node *posNode = listHeadNode->next;
    if (posNode == NULL)
    {
        printf("��������ݣ��޷�ɾ��\n");
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
                printf("��������ݣ��޷�ɾ��\n");
                return;
            }
        }
        posFrontNode->next = posNode->next;
        free(posNode);
    }
}
//���ҽڵ�
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
    return pMove;
}
//��ӡ��ǰ�ڵ�����
void printNode(struct Node *currenNode)
{
    printf("����\t���\t����\t�绰\t\tסַ\n");
    printf("%s\t%s\t%d\t%s\t\t%s\t\n", currenNode->data.name, currenNode->data.number, currenNode->data.age, currenNode->data.tel, currenNode->data.addr);
}
//�ļ����������ļ��ж���ѧ������
void readInfoFromFile(char *fileName, struct Node *listHeadNode)
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) //��ֹ�ļ�������
    {
        fp = fopen(fileName, "w");
    }
    //��ʽ����ȡ
    struct student tempData;
    while (fscanf(fp, "%s\t%s\t%d\t%s\t%s", tempData.name, tempData.number, &tempData.age, tempData.tel, tempData.addr) != EOF)
    {
        insertNodeByHead(listHeadNode, tempData);
        memset(&tempData, 0, sizeof(tempData));
    }
    fclose(fp);
}
//�ļ���������ѧ�����ݱ��浽�ļ���
void saveInfoToFile(char *fileName, struct Node *listHeadNode)
{
    FILE *fp = fopen(fileName, "w+");
    struct Node *pMove = listHeadNode->next;
    while (pMove != NULL)
    {
        fprintf(fp, "%s\t%s\t%d\t%s\t\t%s\t\n", pMove->data.name, pMove->data.number, pMove->data.age, pMove->data.tel, pMove->data.addr);
        pMove = pMove->next;
    }
    fclose(fp);
}
