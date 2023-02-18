#include <stdio.h>
int parent[9];
int rank[9];
void makeSet(int x)
{
parent[x] = x;
rank[x] = 0;
}
int findSet(int x)
{
if(x != parent[x])
parent[x] = findSet(parent[x]);
return(parent[x]);
}
void link(int x, int y)
{
if(rank[x] > rank[y])
parent[y] = x;
else
{
parent[x] = y;
if(rank[x] == rank[y])
rank[y] = rank[y] + 1;
}
}
void unionSet(int x, int y)
{
x = findSet(x);
y = findSet(y);
link(x, y);
}
int main()
{
int i;
makeSet(0);
makeSet(1);
makeSet(2);
makeSet(3);
makeSet(4);
makeSet(5);
makeSet(6);
makeSet(7);
makeSet(8);
unionSet(2, 1);
unionSet(4, 3);
unionSet(6, 5);
unionSet(3, 1);
unionSet(5, 1);
unionSet(8, 7);
unionSet(7, 1);
for(i=1;i<9;i++)
{
printf("Parent of %d is %d.",i,parent[i]);
printf("Rank of %d is %d.\n",i,rank[i]);
}
return 0;
}
 73  
kruskal.c
@@ -0,0 +1,73 @@
#include <stdio.h>
#include <limits.h>
#define V 5
int parent[V];
// Find set of vertex i
int find(int i)
{
while (parent[i] != i)
i = parent[i];
return (i);
}
// Does union of i and j. It returns
// false if i and j are already in same
// set.
void setUnion(int i, int j)
{
int a = find(i);
int b = find(j);
parent[a] = b;
}
// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V])
{
int mincost = 0; // Cost of min MST.
// Initialize sets of disjoint sets.
for (int i = 0; i < V; i++)
parent[i] = i;
// Include minimum weight edges one by one
int edge_count = 0;
while (edge_count < V - 1)
{
int min = INT_MAX, a = -1, b = -1;
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
if (find(i) != find(j) && cost[i][j] < min)
{
min = cost[i][j];
a = i;
b = j;
}
}
}
setUnion(a, b);
printf("Edge %d:(%d, %d) cost:%d \n",
edge_count++, a, b, min);
mincost += min;
}
printf("\n Minimum cost= %d \n", mincost);
}
void main()
{
/* Let us create the following graph
2 3
(0)--(1)--(2)
| /\ |
6| 8/ \5 |7
| / \ |
(3)-------(4)
9 */
int cost[][V] =
{
{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
{ 2, INT_MAX, 3, 8, 5 },
{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
{ 6, 8, INT_MAX, INT_MAX, 9 },
{ INT_MAX, 5, 7, 9, INT_MAX },
};
// Print the solution
kruskalMST(cost);
return (0);
}
 69  
prims.c
@@ -0,0 +1,69 @@
#include<stdio.h>

#define MAX 10

int main(){
	int vertex_array[MAX],counter;
	int vertex_count=0;
	int row,column;
	int cost_matrix[MAX][MAX];
	int visited[MAX]={0};
	int edge_count=0,count=1;
	int sum_cost=0,min_cost=0;
	int row_no,column_no,vertex1,vertex2;

	printf("Total no of vertex :: ");
	scanf("%d",&vertex_count);

	printf("\n-- Enter vertex -- \n\n");
	for(counter=1;counter<=vertex_count;counter++){
		printf("vertex[%d] :: ",counter);
		scanf("%d",&vertex_array[counter]);
	}

	printf("\n--- Enter Cost matrix of size %d x %d  ---\n\n",vertex_count,vertex_count);
	printf("\n\t-- format is --\n");
	for(row=1;row<=vertex_count;row++){
		for(column=1;column<=vertex_count;column++){
			printf("x ");
		}
		printf("\n");
	}
	printf("\n-- MATRIX --\n\n");
	//Get edge weight matrix from user	
	for(row=1;row<=vertex_count;row++){
		for(column=1;column<=vertex_count;column++){
			scanf("%d",&cost_matrix[row][column]);
			if(cost_matrix[row][column] == 0){
				cost_matrix[row][column] = 999;
			}
		}
	}

	printf("\n");
	visited[1]=1;
	edge_count = vertex_count-1;

	while(count <= edge_count){
		for(row=1,min_cost=999;row<=vertex_count;row++){
			for(column=1;column<=vertex_count;column++){
				if(cost_matrix[row][column] < min_cost){
					if(visited[row] != 0){
						min_cost = cost_matrix[row][column];
						vertex1 = row_no = row;
						vertex2 = column_no = column;
					}
				}
			}
		}

		if(visited[row_no] == 0 || visited[column_no] ==0){
			printf("\nEdge %d is (%d -> %d) with cost : %d ",count++,vertex_array[vertex1],vertex_array[vertex2],min_cost);
			sum_cost = sum_cost + min_cost;
			visited[column_no]=1;
		}
		cost_matrix[vertex1][vertex2] = cost_matrix[vertex2][vertex1] = 999;
	}
	printf("\n\nMinimum cost=%d",sum_cost); 
	return 0;
}