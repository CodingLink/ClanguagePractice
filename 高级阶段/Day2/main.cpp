//�������ͼ���ڽӱ��ʼ�������������ȱ�����������ȱ���

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

//ͼ�Ľṹ�壬������ͼ�����㣬����ı�
// �ڽӱ��б��Ӧ������Ķ���
typedef struct _ENode
{
    int ivex;                   // �ñ���ָ��Ķ����λ��,��������±�
    struct _ENode* next_edge;   // ָ����һ������ָ��
}ENode, * PENode;

// �ڽӱ��б�Ķ���
typedef struct _VNode
{
    char data;              // ������Ϣ
    ENode* first_edge;      // ָ���һ�������ö���Ļ�
}VNode;

// �ڽӱ�
typedef struct _LGraph
{
    int vexnum;             // ͼ�Ķ������Ŀ
    int edgnum;             // ͼ�ıߵ���Ŀ
    VNode vexs[MAX];        // ͼ�Ķ�����7��
}LGraph;

//���ض�Ӧ������±�
static int get_position(LGraph g, char ch)
{
    int i;
    for (i = 0; i < g.vexnum; i++)//ȥ����ṹ�������б���ÿ������0-6
        if (g.vexs[i].data == ch)
            return i;//���ص��Ƕ�Ӧ������±�
    return -1;
}

static void link_last(ENode* list, ENode* node)
{
    ENode* p = list;

    //�ҵ����һ���ڵ�
    while (p->next_edge)
    {
        p = p->next_edge;
    }
    //���ӵ����һ���ڵ�
    p->next_edge = node;
}

LGraph* CreateGraphDirected()
{
    //ͼ�ĳ�ʼ�����������飬�ߵĶ�ά���飬����������ߵĸ���
    char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };//��������
    char edges[][2] = {{'A', 'B'},{'B', 'C'},{'B', 'E'},{'B', 'F'},{'C', 'E'},
                        {'D', 'C'},{'E', 'B'},{'E', 'D'},{'F', 'G'} };//�ߵĶ�ά����
    int vlen = sizeof(vexs) / sizeof(vexs[0]);//�������
    int elen = sizeof(edges) / sizeof(edges[0]);//�ߵĸ���

    //��������ͼ�������ڽӱ��洢
    int i;//����ѭ��
    int p1, p2;//p1,�����±� p2 �յ���±�
    char c1, c2;//c1���ߵ���� c2���ߵ��յ�
    ENode* node;
    LGraph* pG;


    pG = (LGraph*)malloc(sizeof(LGraph));//Ϊͼ����ռ�
    memset(pG, 0, sizeof(LGraph));//�ռ�����ֵ��ʼ��Ϊ0

    // ��ʼ��"������"��"����"
    pG->vexnum = vlen;//7
    pG->edgnum = elen;//9
    // ��ʼ��"�ڽӱ�"�Ķ���
    for (i = 0; i < pG->vexnum; i++)//0-6
    {
        pG->vexs[i].data = vexs[i];
        pG->vexs[i].first_edge = NULL;
    }

    // ��ʼ��"�ڽӱ�"�ı�
    for (i = 0; i < pG->edgnum; i++)//0-8
    {
        // ��ȡ�ߵ���ʼ����ͽ�������
        c1 = edges[i][0];//A
        c2 = edges[i][1];//B

        p1 = get_position(*pG, c1);//0
        p2 = get_position(*pG, c2);//1

        // ��ʼ��node��node���Ƕ��������еĽڵ� A->B node��B; B->C->E->F node��C��E��F
        node = (ENode*)calloc(1, sizeof(ENode));
        node->ivex = p2;
        // ��node1���ӵ�"p1���������ĩβ"
        if (pG->vexs[p1].first_edge == NULL)
        {
            pG->vexs[p1].first_edge = node;
        }
        else//��Ϊ�գ����ӵ����һ��
        {
            link_last(pG->vexs[p1].first_edge, node);
        }
    }
    return pG;
}

 //���������������ͼ�ĵݹ�ʵ��
static void DFS(LGraph G, int i, int visited[])
{
    ENode* node;

    visited[i] = 1;//Ҫ���ʵ�ǰ����ˣ����Դ�ӡ
    printf("%2c", G.vexs[i].data);
    node = G.vexs[i].first_edge;//�õ�ǰ����ĺ���һ������,��ʱΪB
    while (node != NULL)
    {
        if (!visited[node->ivex])//ֻҪ��Ӧ����û�з��ʹ������뵽��һ���������
            DFS(G, node->ivex, visited);
        node = node->next_edge;//ĳ���������һ���ߣ�B<-E->D ,B�����ʹ���nodeΪD��������һ����
    }
}
//���������������ͼ
//˼�룺���ʵ����һλ�����˵��з�֧�Ľڵ㣬�������ʣ�ֱ��ȫ������
void DFSTraverse(LGraph G)
{
    int i;
    int visited[MAX];       // ������ʱ�ǣ�1���Ѿ�������

    // ��ʼ�����ж��㶼û�б�����
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    //�Ӷ���A��ʼ������ȱ���
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])//0Ϊ�٣���0Ϊ��
        {
            DFS(G, i, visited);
        }     
    }
    printf("\n");
}


//����������������������Ĳ�α�����
void BFS(LGraph G)
{
    int head = 0;       //��������ͷ
    int rear = 0;       //��������β
    int queue[MAX];     // �������
    int visited[MAX];   // ������ʱ��
    int i, j, k;
    ENode* node;

    //ÿ������δ������
    for (i = 0; i < G.vexnum; i++)//0-6
        visited[i] = 0;

    //����Ŷ��㿪ʼ����
    for (i = 0; i < G.vexnum; i++)//��ÿ����ͬ����������һ��BFS
    {
        if (!visited[i])//���û���ʹ����ʹ�ӡ��ͬʱ���,�����A
        {
            visited[i] = 1;//����Ѿ����ʹ�
            printf("%2c", G.vexs[i].data);
            queue[rear] = i;  // �����
            rear++;             //head=0��rear=1
        }
        while (head != rear) //��һ����������A������A��ÿһ����
        {
            j = queue[head];  // ������
            head++;             //head=1��rear=1
            node = G.vexs[j].first_edge;  //B
            while (node != NULL)    
            {
                k = node->ivex;         //B�ı�����һ���ڵ���±�
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%2c", G.vexs[k].data);
                    queue[rear] = k;//���������Ĳ�α�������������ͬʱ���
                    rear++;
                }
                node = node->next_edge;
            }
        }
    }
    printf("\n");
}

int main()
{
    LGraph* pG;//����ͼ
    //pG�洢���ǵ�ַ *pG�ṹ��

    pG = CreateGraphDirected();//��������ͼ
    DFSTraverse(*pG);//������ȱ���
    BFS(*pG);//������ȱ���
    return 0;
}