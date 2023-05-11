#include <stdio.h>
#include <malloc.h>
#define MaxSons 10
#define MaxSize 100
typedef struct node{
    char data;
    struct node *sons[MaxSize];
}TsonNode ;
TsonNode *CreatTree(const char*str){
    struct {
        TsonNode*nodep;
        int num;
    }St[MaxSize];
}

void DispTree(TsonNode*t){
    int i;
    if(t!=NULL){
        printf("c",t->data);
        if(t->sons[0]!=NULL){
            printf("(");
            for ( i = 0; i < MaxSons; i++)
            {
                DispTree(t->sons[i]);
                if(t->sons[i+1]!=NULL){
                    
                }
            }
            
        }
    }
}

void DispTree(TSonNode* t)//输出孩子链存储结构
{
int i;
if (t != NULL)
{
printf("%c", t->data);
if (t->sons[0] != NULL)//t节点至少有一个孩子
{
printf("(");//输出一个左括号
for (i = 0; i < MaxSons; i++)
{
DispTree(t->sons[i]);
if (t->sons[i + 1] != NULL)//如果有下一个孩子
printf(",");//输出一个','
else//如果没有下一个孩子
break;//退出循环
}
printf(")");//输出一个右括号
}
}
}
void DestroryTree(TSonNode*& t)//销毁树t
{
int i;
if (t != NULL)
{
for (i = 0; i < MaxSons; i++)
{
if (t->sons[i] != NULL)//有子树
DestroryTree(t->sons[i]);//销毁该子树
else//再没有子树
break;//退出循环
}
free(t);//释放根节点
}
}
int TreeHeight1(TSonNode* t)//求树t高度
{
TSonNode* p;
int i, h, maxh = 0;
if (t == NULL) return 0;//空树返回高度0
else//处理非空树
{
for (i = 0; i < MaxSons; i++)
{
p = t->sons[i];//p指向t的第i-1个孩子节点
if (p != NULL)//若存在第i-1个孩子
{
h = TreeHeight1(p);//求出对应子树的高度
if (maxh < h) maxh = h;//求所有子树的最大高度
}
}
return(maxh + 1);//返回maxh+1
}
}

int main()
{
TSonNode* t;
t = CreateTree("A(B,C(E,F,G),D)");
printf("t:"); DispTree(t);
printf("\n树t的高度:%d\n", TreeHeight1(t));
DestroryTree(t);
return 1;
}