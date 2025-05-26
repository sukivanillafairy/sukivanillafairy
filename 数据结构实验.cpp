#include <stdio.h>
#define MAX_VERTEX_NUM 10             /*最多顶点个数*/
#define INFINITY 32768             /*表示极大值，即∞*/
#define True 1
#define False 0
#define Error -1
#define Ok 1

typedef enum{DG, DN, UDG, UDN} GraphKind;  /*图的种类：DG表示有向图, DN表示有向网, UDG表示无向图, UDN表示无向网*/
typedef char VertexData;    /*假设顶点数据为字符型*/

typedef struct ArcNode
{
//	AdjType adj;   /*对于无权图，用1或0表示是否相邻；对带权图，则为权值类型*/
//	OtherInfo info;
	int adj;
} ArcNode;

typedef struct
{
	VertexData vexs[MAX_VERTEX_NUM];                        /*顶点向量*/
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   /*邻接矩阵*/
	int vexnum,arcnum;          /*图的顶点数和弧数*/
	GraphKind kind;                 /*图的种类标志*/
}AdjMatrix;      /*(Adjacency Matrix Graph)*/
//void DefaultCreateGraph(AdjMatrix &G);
int LocateVertex(AdjMatrix *G,VertexData v)    /*求顶点位置函数*/
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

int CreateDN(AdjMatrix *G)  /*创建一个有向网*/
{
	int i,j,k,weight;
	VertexData v1,v2;
	printf("输入图的弧数和顶点数\n");
	fflush(stdin);
    scanf("%d,%d",&G->arcnum,&G->vexnum); /*输入图的顶点数和弧数*/
    for(i=0;i<G->vexnum;i++)       /*初始化邻接矩阵*/
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j].adj=INFINITY;
    for(i=0;i<G->vexnum;i++)
	{
        printf("输入图的顶点\n");
		fflush(stdin);
		scanf("%c",&G->vexs[i]);  /* 输入图的顶点*/
	}
	for(k=0;k<G->arcnum;k++)
	{
		printf("输入一条弧的两个顶点及权值\n");
		fflush(stdin);
		scanf("%c,%c,%d",&v1,&v2,&weight);//输入一条弧的两个顶点及权值
		i=LocateVertex(G,v1);
	    j=LocateVertex(G,v2);
	    G->arcs[i][j].adj=weight;  //建立弧
		G->arcs[j][i].adj=weight;  //建立弧
	}
//	DefaultCreateGraph(G);
	return(Ok);

}

/*普里姆算法描述如下：*/
struct
{
	VertexData adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];   /* 求最小生成树时的辅助数组*/

void MiniSpanTree_Prim(AdjMatrix &gn,VertexData u)
/*从顶点u出发，按普里姆算法构造连通网gn 的最小生成树，并输出生成树的每条边*/
{
//	closedge c[gn.vexnum];
	int k=LocateVertex(&gn, u);
	closedge[k].lowcost=0;   /*初始化，U={u} */
	for(int i=0;i<gn.vexnum;i++)
		if (i!=k)    /*对V-U中的顶点i，初始化closedge[i]*/
		{
			closedge[i].adjvex=u;
			closedge[i].lowcost=gn.arcs[k][i].adj;
		}
	for(int e=1;e<=gn.vexnum-1;e++)    /*找n-1条边(n= gn.vexnum) */
	{
		int k0,i,j,min;
		char u0,v0;
	//	k0=Minium(closedge);     /* closedge[k0]中存有当前最小边（u0,v0）的信息*/
		 for(i=1;i<gn.vexnum;i++)    /*循环求最小生成树中的各条边*/
          {   min=INFINITY;
        for(j=0;j<gn.vexnum;j++)   /*选择得到一条代价最小的边*/
            if(closedge[j].lowcost!=0&&closedge[j].lowcost<min)
               {
                min=closedge[j].lowcost;
                k0=j;
               }
           }
		u0=closedge[k0].adjvex;   /* u0∈U*/
		v0=gn.vexs[k0];          /* v0∈V-U*/
		printf("%c,%c  ",u0, v0);    /*输出生成树的当前最小边（u0,v0）*/
		closedge[k0].lowcost=0;     /*将顶点v0纳入U集合*/
		for(i=0;i<gn.vexnum;i++)    /*在顶点v0并入U之后，更新closedge[i]*/
			if(gn.arcs[k0][i].adj<closedge[i].lowcost)
		{
				closedge[i].lowcost=gn.arcs[k0][i].adj;
				closedge[i].adjvex=v0;
			}
	}
}
//测试主函数
int main()
{
    AdjMatrix g1;
    CreateDN(&g1);
	VertexData u='a';
    MiniSpanTree_Prim(g1,u);
    return 0;
 }
