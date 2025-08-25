//Al_Hasan khaled Qarmash 1210611

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_CITIES 15
#define MAX_LINE_LENGTH 200
#define LONNUMBER 9999
int sizeArrayBfs=0;
int sizeArrayDijkstra=0;
void bfs(int start, int end,int A[]);
int distances[MAX_CITIES][MAX_CITIES];
char city_list[MAX_CITIES][20] = {
    "Akka", "Haifa", "Nazareth", "Jenin", "Bethlehem", "Hebron", "Jerusalem",
    "Jaffa", "Jericho", "Tulkarem", "Qalqilya", "Ramallah", "Nablus", "Tubas",
    "Salfit"
};
int queue[MAX_CITIES];
bool visited[MAX_CITIES];
int prev[MAX_CITIES];

void initialize() {
    for (int i = 0; i < MAX_CITIES; i++) {
        visited[i] = false;
        prev[i] = -1;
    }
}

int getCityIndex(const char city[20]) {
    for (int i = 0; i < MAX_CITIES; i++) {
        if (strcmp(city_list[i], city) == 0) {
            return i;
        }
    }
    return -1; // City not found
}

void loadCities() {
    FILE* file = fopen("C:\\Users\\qarma\\Desktop\\testProj\\FinalTest\\Cities.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            distances[i][j] = 0;
        }
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char city1[20], city2[20];
        int distance;
        sscanf(line, "%s %s %d", city1, city2, &distance);

        int index1 = getCityIndex(city1);
        int index2 = getCityIndex(city2);

        if (index1 != -1 && index2 != -1) {
            distances[index1][index2] = distance;
            distances[index2][index1] = distance;
        }
    }

    fclose(file);

    printf("Cities loaded from file.\n");
}

void dijkstraForm_1(int start, int end,int B[]) {
    int dist[MAX_CITIES];
    sizeArrayDijkstra=0;

    for (int i = 0; i < MAX_CITIES; i++) {
        dist[i] = INT_MAX;
    }

    dist[start] = 0;
    prev[start] = -1;

    for (int count = 0; count < MAX_CITIES -1; count++) {
        int minDist = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < MAX_CITIES; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;

        for (int v = 0; v < MAX_CITIES; v++) {
            if (!visited[v] && distances[minIndex][v] && dist[minIndex] + distances[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + distances[minIndex][v];
                prev[v] = minIndex;
            }
        }
    }

    if (dist[end] != INT_MAX) {
        printf("Shortest path (Dijkstra): ");
        int path[MAX_CITIES];
        int pathIndex = 0;
        int node = end;

        while (node != -1) {
            B[pathIndex]=node;
            sizeArrayDijkstra++;
            path[pathIndex++] = node;
            node = prev[node];
        }

        for (int i = pathIndex - 1; i >= 0; i--) {
            printf("->%s ", city_list[path[i]]);
        }

        printf("\n");
        printf("Total shortest cost by (Dijkstra) method: %d km\n", dist[end]);
    } else {
        printf("No path found from source to destination.\n");
    }
}

void bfs(int start, int end,int A[]) {
    int front = 0;
    int rear = 0;
    sizeArrayBfs=0;
    initialize();
    visited[start] = true;
    queue[rear++] = start;
    int totalDistance = 0;

    while (front < rear) {
        int current = queue[front++];

        if (current == end) {
            printf("Shortest path by (BFS) method: ");
            int path[MAX_CITIES];
            int pathIndex = 0;
            int node = end;
            while (node != -1) {
                sizeArrayBfs++;
                A[pathIndex]=node;
                path[pathIndex++] = node;
                node = prev[node];
            }
            for (int i = pathIndex - 1; i >= 0; i--) {
                printf("->%s ", city_list[path[i]]);
            }
            printf("\n");

            // Calculate sum of distances
            totalDistance = 0;
            for (int i = pathIndex - 1; i > 0; i--) {
                totalDistance += distances[path[i]][path[i - 1]];
            }
            printf("Total distance: %d km\n", totalDistance);
        }

        for (int neighbor = 0; neighbor < MAX_CITIES; neighbor++) {
            if (!visited[neighbor] && distances[current][neighbor] > 0) {
                visited[neighbor] = true;
                prev[neighbor] = current;
                queue[rear++] = neighbor;
            }
        }



    }
        //printf("No path found from source to destination.\n");

}
void dijkstra(int ArrayOFNameCitise[MAX_CITIES][MAX_CITIES],int NumberofCities,int sourseNode,int destinationIndex)
{
int pathDestination[MAX_CITIES];
int prePath[MAX_CITIES];
int costpath[MAX_CITIES][MAX_CITIES],dist[MAX_CITIES],preDecessor[MAX_CITIES];
int visited[MAX_CITIES],counter,mindistance,nextnode,i,j;
//preDecessor[] stores the predecessor of each node
//counter gives the number of nodes seen so far
//create the cost matrix
   for(i=0;i<NumberofCities;i++)
   {
      for(j=0;j<NumberofCities;j++)
      {
        if(ArrayOFNameCitise[i][j]==0)
        {

          costpath[i][j]=LONNUMBER;
        }

        else
           {
             costpath[i][j]=ArrayOFNameCitise[i][j];
           }
      }

   }
//initialize preDecessor[],distance[] and visited[]
     for(i=0;i<NumberofCities;i++)
      {
        dist[i]=costpath[sourseNode][i];
        preDecessor[i]=sourseNode;
        visited[i]=0;
      }
    dist[sourseNode]=0;
    visited[sourseNode]=1;
     counter=1;
      while(counter<NumberofCities-1)
       {
           mindistance=LONNUMBER;
         //nextnode gives the node at minimum distance
        for(i=0;i<NumberofCities;i++)
        {
          if(dist[i]<mindistance&&!visited[i])
            {
               mindistance=dist[i];
                nextnode=i;
            }

        }
//check if a better path exists through nextnode
visited[nextnode]=1;
     for(i=0;i<NumberofCities;i++)
         if(!visited[i])
           if(mindistance+costpath[nextnode][i]<dist[i])
            {

               dist[i]=mindistance+costpath[nextnode][i];
               preDecessor[i]=nextnode;
            }
            counter++;
        }

//print the path and distance of each node
for(i=0;i<NumberofCities;i++)
{

if(i!=sourseNode)
{
printf("\nDistance of node %s =%d ",city_list[i],dist[i]);
printf("Path=%s",city_list[i]);
j=i;
do
{
j=preDecessor[j];
printf("<-%s",city_list[j]);
}while(j!=sourseNode);
}
}
printf("\n");

}





void printShortestPathToFile(int A[], int B[]) {
    int i=0;
    FILE* file = fopen("shortest_distance.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "\n---------------------------------\n");
        fprintf(file, "shortest path by BFS method\n");
    for (i = 0; i <sizeArrayBfs; i++) {
        fprintf(file,"-> %s",city_list[A[i]]);
        //fprintf(file, "Home Address: %s\n", students[i].homeAddress);
       // fprintf(file, "Class ID: %d\n", students[i].classID);
       // fprintf(file, "Date of Enrollment: %s\n\n", students[i].dateOfEnrollment);
    }
        fprintf(file, "\n---------------------------------\n");
        fprintf(file, "\n---------------------------------\n");
        fprintf(file, "shortest path by Dijkstra method\n");
     for (i = 0; i <sizeArrayDijkstra; i++) {
        fprintf(file,"-> %s",city_list[B[i]]);
        //fprintf(file, "Home Address: %s\n", students[i].homeAddress);
       // fprintf(file, "Class ID: %d\n", students[i].classID);
       // fprintf(file, "Date of Enrollment: %s\n\n", students[i].dateOfEnrollment);
    }
     fprintf(file, "\n---------------------------------\n");

    fclose(file);
}

int main() {


 int  A[15];
 int  B[15];
 int i=0;
 char resultBfs[40];
 int sourceIndex = -1;
    int destinationIndex = -1;

    while (true) {


    printf("\n\n////////////////////////                      { WELCOM BACK IN Google Maps }              //////////////////////////////\n\n\n");
    printf("                                      Enter your choice:\t\n\n");
    printf("                          1.Read From File\n");
    printf("                          2.Enter source\n");
    printf("                          3.Enter destination\n");
    printf("                          4.Exit and print shortest path\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            loadCities();
        } else if (choice == 2) {
            char source[20];
            printf("Enter the source city: ");
            scanf("%s", source);
            sourceIndex = getCityIndex(source);
            if (sourceIndex == -1) {
                printf("Invalid source city.\n");
            }
            else
            {
            }
        } else if (choice == 3) {
            printf("\nFor This Cities choice one of them\n");
            for(i=0;i<MAX_CITIES;i++)
            {
            printf("%s ",city_list[i]);
            if(i==3)
            {
            printf("\n");
            }
            }
            printf("\n");
            char destination[20];
            printf("Enter the destination city: ");
            scanf("%s", destination);

            destinationIndex = getCityIndex(destination);

            if (destinationIndex == -1) {
                printf("Invalid destination city.\n");
            }
            else
            {
                printf("\n------------------------------------\n");
                dijkstra(distances,15,sourceIndex,destinationIndex);
                printf("\n------------------------------------\n");
                dijkstraForm_1(sourceIndex, destinationIndex,B);
                printf("\n------------------------------------\n");
                bfs(sourceIndex, destinationIndex,A);
               printf("\n------------------------------------\n");
            }
        } else if (choice == 4) {
            if (sourceIndex == -1 || destinationIndex == -1) {
                printf("Source and/or destination city not set.\n");
            } else {
                printf("\n-------------------------------------------------------\n");
                printf("Done :check your  file");
                printf("\n-------------------------------------------^-Good by Data Structure projects-^----------------------------------------\n");
                printShortestPathToFile(A,B);
                break;
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

