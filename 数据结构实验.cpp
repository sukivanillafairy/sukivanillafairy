#include <stdio.h>
#define MAX_VERTEX_NUM 10             /*��ඥ�����*/
#define INFINITY 32768             /*��ʾ����ֵ������*/
#define True 1
#define False 0
#define Error -1
#define Ok 1

typedef enum{DG, DN, UDG, UDN} GraphKind;  /*ͼ�����ࣺDG��ʾ����ͼ, DN��ʾ������, UDG��ʾ����ͼ, UDN��ʾ������*/
typedef char VertexData;    /*���趥������Ϊ�ַ���*/

typedef struct ArcNode
{
//	AdjType adj;   /*������Ȩͼ����1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����*/
//	OtherInfo info;
	int adj;
} ArcNode;

typedef struct
{
	VertexData vexs[MAX_VERTEX_NUM];                        /*��������*/
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   /*�ڽӾ���*/
	int vexnum,arcnum;          /*ͼ�Ķ������ͻ���*/
	GraphKind kind;                 /*ͼ�������־*/
}AdjMatrix;      /*(Adjacency Matrix Graph)*/
//void DefaultCreateGraph(AdjMatrix &G);
int LocateVertex(AdjMatrix *G,VertexData v)    /*�󶥵�λ�ú���*/
{
	int j=Error,k;
	for(k=0;k<G->vexnum;k++)
		if(G->vexs[k]==v)
		{
			j=k;
			break;
		}
	return(j);
}

int CreateDN(AdjMatrix *G)  /*����һ��������*/
{
	int i,j,k,weight;
	VertexData v1,v2;
	printf("����ͼ�Ļ����Ͷ�����\n");
	fflush(stdin);
    scanf("%d,%d",&G->arcnum,&G->vexnum); /*����ͼ�Ķ������ͻ���*/
    for(i=0;i<G->vexnum;i++)       /*��ʼ���ڽӾ���*/
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j].adj=INFINITY;
    for(i=0;i<G->vexnum;i++)
	{
        printf("����ͼ�Ķ���\n");
		fflush(stdin);
		scanf("%c",&G->vexs[i]);  /* ����ͼ�Ķ���*/
	}
	for(k=0;k<G->arcnum;k++)
	{
		printf("����һ�������������㼰Ȩֵ\n");
		fflush(stdin);
		scanf("%c,%c,%d",&v1,&v2,&weight);//����һ�������������㼰Ȩֵ
		i=LocateVertex(G,v1);
	    j=LocateVertex(G,v2);
	    G->arcs[i][j].adj=weight;  //������
		G->arcs[j][i].adj=weight;  //������
	}
//	DefaultCreateGraph(G);
	return(Ok);

}

/*����ķ�㷨�������£�*/
struct
{
	VertexData adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];   /* ����С������ʱ�ĸ�������*/

void MiniSpanTree_Prim(AdjMatrix &gn,VertexData u)
/*�Ӷ���u������������ķ�㷨������ͨ��gn ����С���������������������ÿ����*/
{
//	closedge c[gn.vexnum];
	int k=LocateVertex(&gn, u);
	closedge[k].lowcost=0;   /*��ʼ����U={u} */
	for(int i=0;i<gn.vexnum;i++)
		if (i!=k)    /*��V-U�еĶ���i����ʼ��closedge[i]*/
		{
			closedge[i].adjvex=u;
			closedge[i].lowcost=gn.arcs[k][i].adj;
		}
	for(int e=1;e<=gn.vexnum-1;e++)    /*��n-1����(n= gn.vexnum) */
	{
		int k0,i,j,min;
		char u0,v0;
	//	k0=Minium(closedge);     /* closedge[k0]�д��е�ǰ��С�ߣ�u0,v0������Ϣ*/
		 for(i=1;i<gn.vexnum;i++)    /*ѭ������С�������еĸ�����*/
          {   min=INFINITY;
        for(j=0;j<gn.vexnum;j++)   /*ѡ��õ�һ��������С�ı�*/
            if(closedge[j].lowcost!=0&&closedge[j].lowcost<min)
               {
                min=closedge[j].lowcost;
                k0=j;
               }
           }
		u0=closedge[k0].adjvex;   /* u0��U*/
		v0=gn.vexs[k0];          /* v0��V-U*/
		printf("%c,%c  ",u0, v0);    /*����������ĵ�ǰ��С�ߣ�u0,v0��*/
		closedge[k0].lowcost=0;     /*������v0����U����*/
		for(i=0;i<gn.vexnum;i++)    /*�ڶ���v0����U֮�󣬸���closedge[i]*/
			if(gn.arcs[k0][i].adj<closedge[i].lowcost)
		{
				closedge[i].lowcost=gn.arcs[k0][i].adj;
				closedge[i].adjvex=v0;
			}
	}
}
//����������
int main()
{
    AdjMatrix g1;
    CreateDN(&g1);
	VertexData u='a';
    MiniSpanTree_Prim(g1,u);
    return 0;
 }
