#pragma once

#include "22_1_图的表示.h"


#define TYPE VNode*
#include "../第10章 基本数据结构/10_1_栈和队列.h"

#define TYPE VNode*



void PrintPath(LGraph *G, VNode *s, VNode *v)
{
	if (v == s)
		printf("%c", s->data);
	else if (v->pre == NULL)
		printf("no path from s to v exists");
	else
	{
		PrintPath(G, s, v->pre);
		printf("%c", v->data);
	}
}

//广度优先遍历  雨露均沾
void BFS(LGraph* G, VNode* s)
{
	VNode* u;
	int i;	
	for (int i = 1; i <= G->vexnum; i++)
	{
		G->vexs[i]->color = white;
		G->vexs[i]->d = INT_MAX;
		G->vexs[i]->pre = NULL;
	}
	s->color = gray;
	s->pre = NULL;
	s->d = 0;
	printf("%c ",s->data);
	struct Queue queue;
	InitQueue(&queue);
	EnQueue(&queue, s);
	while (queue.head != queue.tail)  //队列非空
	{
		DeQueue(&queue, &u);
		ENode *edge = u->first_edge;
		while (edge!=NULL)
		{
			if (G->vexs[edge->ivex]->color == white)
			{
				printf("%c ", G->vexs[edge->ivex]->data);
				G->vexs[edge->ivex]->color = gray;
				G->vexs[edge->ivex]->d = u->d + 1;
				G->vexs[edge->ivex]->pre = u;
				EnQueue(&queue, G->vexs[edge->ivex]);
			}
			edge = edge->next_edge;
		}
		u->color = black;
	}

 }

//递归版本
void __BFS(LGraph* G, VNode* s, int i)
{
	if (i == 0)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->vexs[j]->color = white;
			G->vexs[j]->d = INT_MAX;
			G->vexs[j]->pre = NULL;
		}
		s->pre = NULL;
	}

	s->d = i;
	s->color = gray;
	printf("%c ", s->data);

	ENode *edge = s->first_edge;
	while (edge != NULL)
	{
		if (G->vexs[edge->ivex]->color == white)
		{
			__BFS(G,G->vexs[edge->ivex], i + 1);
			G->vexs[edge->ivex]->pre = s;
		}
		edge = edge->next_edge;
	}
	s->color = black;
}


void _test()
{
	/*
		r  --  s      t  --  u
		|      |   /  |   /  |
		v      w  --  x  --  y
	
		 s 开始。
	*/

	

}
