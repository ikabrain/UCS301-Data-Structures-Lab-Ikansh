// TODO: Make it for both directed AND undirected!

#include <stdio.h>

#define MAX 10

int is_undirected = 0;

void initialiseGraph(int graph[MAX][MAX], int nodes);
void insertEdge(int graph[MAX][MAX], int from, int to);
void deleteEdge(int graph[MAX][MAX], int from, int to);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
int findInDegree(int graph[MAX][MAX], int total, int node);
int findOutDegree(int graph[MAX][MAX], int total, int node);
int findTotalDegree(int graph[MAX][MAX], int total, int node);
void printAdjacent(int graph[MAX][MAX], int total);
int findNumEdges(int graph[MAX][MAX], int total);

int main(void)
{
	int i, j, n, e;
	printf("Enter total number of nodes: ");
	scanf("%d", &n);
	if (n > MAX)
	{
		printf("Exceeded maximum capacity.");
		return 1;
	}
	
	int graph[n][n];
	initialiseGraph(graph, n);
	
	printf("How many edges do you wish to insert?: ");
	scanf("%d", &e);
	
	for (i = 0; i < e; i++)
	{
		int u, v;
		printf("Enter edge %d (`0 1` == Edge goes from node 0 to 1): ", i+1);
		scanf("%d %d", &u, &v);
		if (u > n-1 || v > n-1)
		{
			printf("Incorrect node numbers.\n");
			i--;
			continue;
		}
		insertEdge(graph, u, v);
	}
	
	printf("\nHow many edges do you wish to delete?: ");
	scanf("%d", &e);
	
	for (i = 0; i < e; i++)
	{
		int u, v;
		printf("Enter edge %d (`0 1` == Delete edge from node 0 to 1): ", i+1);
		scanf("%d %d", &u, &v);
		deleteEdge(graph, u, v);
	}
	
	printMatrix(graph, n, n);
	
	int node;
	printf("\nEnter node to find it's in/out degrees: ");
	scanf("%d", &node);
	printf("   In-degree = %d\n", findInDegree(graph, n, node));
	printf("  Out-degree = %d\n", findOutDegree(graph, n, node));
	printf("Total degree = %d\n", findTotalDegree(graph, n, node));
	
	printf("\nAdjacent Vertices are:-");
	printAdjacent(graph, n);
	
	printf("\nTotal number of directed edges = %d\n", findNumEdges(graph, n));
	
	return 0;
}

void initialiseGraph(int graph[MAX][MAX], int nodes)
{
	int i, j;
	for (i = 0; i < nodes; i++)
	{
		for (j = 0; j < nodes; j++)
		{
			graph[i][j] = 0;
		}
	}
}

void insertEdge(int graph[MAX][MAX], int from, int to)
{
	// For directed graph
	graph[from][to] = 1;
}

void deleteEdge(int graph[MAX][MAX], int from, int to)
{
	// For directed graph
	graph[from][to] = 0;
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols)
{
	printf("\n");
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf(" %d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int findInDegree(int graph[MAX][MAX], int total, int node)
{
	// Number of nodes going into n = All rows in the column where it is NOT 0!
	int count = 0, i;
	for (i = 0; i < total; i++)
	{
		if (graph[i][node])
			count++;
	}
	return count;
}

int findOutDegree(int graph[MAX][MAX], int total, int node)
{
	// Number of nodes going out of n = All cols in the row where it is NOT 0!
	int count = 0, j;
	for (j = 0; j < total; j++)
	{
		if (graph[node][j])
			count++;
	}
	return count;
}

int findTotalDegree(int graph[MAX][MAX], int total ,int node)
{
	return findInDegree(graph, total, node) + findOutDegree(graph, total, node);
}

void printAdjacent(int graph[MAX][MAX], int total)
{
//	printf("\n");
//	int i, j;
//	for (i = 0; i < total; i++)
//	{
//		for (j = i; )
//	}
}

int findNumEdges(int graph[MAX][MAX], int total)
{
	int count = 0, i, j;
	for (i = 0; i < total; i++)
	{
		for (j = 0; j < total; j++)
		{
			if (graph[i][j])
				count++;
		}
	}
	return count;
}
