#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999

int main(){

int vertex_amount,i, j;

printf("input jumlah vertex : \n");
scanf("%d",&vertex_amount);

int graph[vertex_amount][vertex_amount];

//connect graph
for (i = 0; i < vertex_amount; i++){
    for (j = i + 1; j < vertex_amount; j++){

        printf("Apakah vertex %d dan vertex %d terhubung? (bila terhubung ketik cost dari hubungan. Jika tidak 0 )\n ", i, j);
        scanf("%d", &graph[i][j]);

        int weight = graph[i][j];
        graph[j][i] = graph[i][j];

    }
  }

// dijkstra

int cost[vertex_amount][vertex_amount],distance[vertex_amount],pred[vertex_amount];
int visited[vertex_amount],count,mindistance,nextnode;
int n = vertex_amount;
int startnode;

printf("mulai dari vertex : ");
scanf("%d", &startnode);

	//pred[] stores the predecessor of each node
	//count graphives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(graph[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=graph[i][j];

	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//nextnode memberikan node pada jarak minimum
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//Cek opsi lainnya klo misal ada path yang lebih singkat lagi
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//print path keterhubungan dijkstra-nya
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
		}
return 0;
}
