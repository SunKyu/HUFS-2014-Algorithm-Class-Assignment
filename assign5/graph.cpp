#include <iostream>
#include <fstream>
#include <queue>
//#include <stack>
using namespace std;

/*
 *make Queue and check the who is below k relationship 
 *and check the array of the number of relationship of each vertexes
 *and then, recalculate the array's  element because under the k vertex will be deqeue so need check calculate 
 */
struct Node{
  int vertex;
  Node* next= NULL;
};

void dfsmatrix(bool **adjMatrix, int n, int v, bool visited[], int& size){
  visited[v]= true;
  //cout<< v<< " ";
  size++;
  for (int i = 1; i<n+1; i++){
    if(adjMatrix[v][i]&&!visited[i])
      dfsmatrix(adjMatrix, n, i, visited, size);
  }
}
/*
 * adjMatrix Border First Search
 */

void bfslist(Node** adjList, int n, int s, bool visited[], int *d,int & compo_size,int * check ){
  queue <int> Q;
  for(int i=0; i<n+1; i++){
    visited[i]=false;
    d[i]=0;
  }

  visited[s]=true;
  Q.push(s);//push start vertex
  d[s]=0;
  Node* ptr=NULL;
  while(!Q.empty()){
    int v = Q.front();
    ptr=adjList[v];
    Q.pop();
    compo_size++;//count composize
    check[v]=s;//for the distinguish each component
    while(1){
      if(ptr==NULL)
        break;
      if(visited[ptr->vertex]){
        ptr=ptr->next;
        continue;
      }
      visited[ptr->vertex]=true;
      Q.push(ptr->vertex);
      d[ptr->vertex]=  d[v]+1;
      ptr=ptr->next;
    }
  }
}
/*
 * make graph in condition K
 */
void findmax_k(bool ** adjMatrix, int n, int k){
  int rowsum;
  int temp;
  for(int i=1;i< n+1; i++){
    rowsum=0;
    temp=0;
    for(int j=1; j<n+1; j++){
      if(adjMatrix[i][j])
        rowsum++;
    }
    if(rowsum<k){
      for(int j=1; j<n+1; j++){
        if(adjMatrix[i][j]==true)
          temp=1;

        adjMatrix[i][j]=false;
        adjMatrix[j][i]=false;
      }
    }
    if(temp!=0)
      i=1;
  }
}

int main (int argc, char* argv[]){
  fstream IN;
  IN.open(argv[1]);
  int n;// the number of person. vertex
  int m;// the number of relationship, edge
  IN>>n>>m;
  int k;
  bool** arr= new bool* [n+1];//adjmatirx
  bool * visited= new bool[n+1]; 
  for(int i=0 ;i <n+1; i++)
    arr[i]=new bool [n+1];

  for(int i=1; i<n+1; i++)
    for(int j=1; j<n+1; j++)
      arr[i][j]=false;
  int *d= new int [n+1]; //for storing  distance

  Node ** list = new Node * [n+1];
  int a, b;
  for(int i=0 ; i<n+1; i++)
    list[i]=NULL;

  /*
   * make adjMatrix and adjlist
   */
  for(int i=0 ; i<m; i++){
    IN>>a>>b;
    Node* input1 = new Node;
    Node* input2 = new Node;
    input1->vertex=b;
    input1->next=list[a];
    list[a]=input1;
    input2->vertex=a;
    input2->next=list[b];
    list[b]=input2;

    arr[a][b]=1;
    arr[b][a]=1;
  }
  IN>>k;

  /*
   * problem 1 
   *
   */
  int compo_num=0; //the number of commponent
  int compo_size = 0;
  int max_size = 0;
  int sum_size = 0;
  int min_size;
  double average;
  for(int i=1; i<n+1; i++){
    if(visited[i]==true)
      continue;
    compo_size=0;
    dfsmatrix(arr, n, i, visited, compo_size);
    if(compo_size>max_size)
      max_size=compo_size;
    if(i==1)
      min_size=compo_size;
    if(compo_size<min_size)
      min_size=compo_size;
    sum_size+=compo_size;
    compo_num++;
    //cout<<endl;
  }
  average=(double)((double)sum_size/(double)compo_num);
  cout<<compo_num<<" "<<max_size<<" "<<min_size<<" "<<average<<endl;

  /*
   * problem2
   *
   */
  for(int i=1; i<n+1; i++)
    visited[i]=false;
  compo_size=0;
  max_size=0;
 
  int sum=0;
  int minsum=0;
  int* check = new int [n+1];//for distinguishing each component
    for (int j=1; j<n+1; j++)
      check[j]=0;
   int count=0;
   double avg =0;
  for(int i=1; i<n+1; i++){
    compo_size=0;
    sum=0;
    int tempsize =0;
    count=0;
    if(check[i]==0){
      bfslist(list, n, i, visited, d, tempsize, check);
      for(int w=i+1; w<n+1; w++){
        sum+=d[w];
        if(d[w]!=0)
          count++;
      }
      /*
	   * for bfs searching in same component
	   */
      compo_size=tempsize;
      tempsize=0;
      for(int j=i+1; j< n+1; j++){
        if(check[j]==check[i]){
          bfslist(list, n, j, visited, d, tempsize, check);
          for(int w=j; w<n+1; w++){
            sum+=d[w];
            if(d[w]!=0)
              count++;
          }
         }
      }
    }
    if(minsum==0)
      minsum=sum;
  //  cout<<"size : "<<compo_size<<endl;
    double tempavg=double((double)sum/(double)count);
    if(max_size<compo_size){
      max_size=compo_size;
      minsum=sum;
      avg=tempavg;
    }
    else if(max_size==compo_size &&avg>tempavg )
      avg=tempavg;
  }
  cout<<avg<<endl;

  /*
   * problem 3
   */

  for(int i=1; i<n+1; i++)
    visited[i]=false;

  findmax_k(arr, n, k);//make graph for condition k
  max_size=0;
  for(int i=1; i<n+1; i++){
    if(visited[i]==true)
      continue;
    compo_size=0;
    dfsmatrix(arr, n, i, visited, compo_size);
    if(compo_size>max_size)
      max_size=compo_size;
    //cout<<endl;
  }
  cout<<max_size<<endl;
  cout<<endl;
}
