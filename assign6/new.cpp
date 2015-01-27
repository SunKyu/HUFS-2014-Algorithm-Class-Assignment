#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
/*
 * give a index to each input vertecies
 * and make adjMatrix graph using by giving index
 * @pram adjMatrix, string array, number of router, int count, filestream file
 * retrun void
 */
void inputprocess(int ** adjMatrix, string * arr, int router_num, int& count, fstream & IN){
  string st;
  string dt; 
  IN>>st;
  IN>>dt;
  int stindex=-1;
  int dtindex=-1;
  for(int i = 0 ; i<count ; i++){
    if(arr[i].compare(st)==0){
      stindex=i;
    }
    if(arr[i].compare(dt)==0){
      dtindex=i;
    }
  }
  if(stindex==-1){
    arr[count++]=st;
    stindex=count-1;
  }
  if(dtindex==-1){
    arr[count++]=dt;
    dtindex=count-1;
  }
  int cost;
  IN>>cost;
  adjMatrix[stindex][dtindex]=cost;
  adjMatrix[dtindex][stindex]=cost;
}
/*
 * Dijkstra Algorithm implementation
 *
 */
void Dijkstra (int **adjMatrix, int *parent, int *d,int n, int s){
  bool * check = new bool [n];
  /*
   * intialize parent, check. distance arraies
   */
  for(int i=0; i<n; i++){
    parent[i]=-1;
    check[i]=false;
    d[i]=99999;
  }
  check[s]=true;//add the start vertex to check set
  for(int i=0; i<n; i++){
    if(adjMatrix[s][i]!=0){//find adjency vertecies's distance from start vertex
      d[i] = adjMatrix[s][i];
      parent[i] = s;
    }
  }
  int count = 1;
  int min = d[0];
  int index=0;
  while(count!=n){
    count++;
    min = 99999;
    for(int i= 0 ; i<n; i++){
      if(d[i]<min&&check[i]==false){//find minimum distacne vertex that is not chekced vertex
        min=d[i];
        index=i;
      }
    }
    check[index]=true;//check found index
    int v = index;
    for(int w=0; w<n; w++){
      if(check[w]==true)//if that vertex check continue
        continue;
      if(d[w]>(d[v]+adjMatrix[v][w])&&adjMatrix[v][w]!=0)//calculate the minimum distace in given state
      {
        d[w]=d[v]+adjMatrix[v][w];
        if(parent[v]==s)
          parent[w]=v;
        else
          parent[w]=v[parent];
      }
    }
  }
}


int main (int argc, char** argv){
  int router_num;
  int link_num;
  fstream IN;
  IN.open(argv[1]);
  IN>>router_num;
  IN>>link_num;
  int * d = new int [router_num];// store distance of each vertex from strat vertex
  int * parent = new int [router_num]; //store parent vertex
  int ** adjMatrix = new int * [router_num]; //adjMatrix graph
  for(int i =0 ; i< router_num; i++)
    adjMatrix[i]=new int [router_num];
  for(int i=0; i<router_num; i++)
    for(int j=0; j<router_num; j++)
      adjMatrix[i][j]=0;
  string * arr = new string [router_num];// store input string 
  int count = 0;
  /*
   * For the input process use function inputprocess
   * @pram adjMatrix, string array, number of router, int count, filestream file
   */
  for(int i=0 ; i<link_num; i++){
    inputprocess(adjMatrix, arr, router_num, count, IN);
  }

  int checknum ;
  IN>>checknum;
  string input;
  while(checknum--){
    IN>>input;
    int index;
    for(int i=0; i<router_num; i++){
      if(input.compare(arr[i])==0)
        index=i;
    }
    Dijkstra(adjMatrix, parent, d, router_num, index);
    /*
     * print the result
     */
    cout<<setw(9)<<"Destination"<<setw(9)<<"NEXT"<<setw(9)<<"Cost"<<endl;
    cout<<setw(9)<<arr[index]<<setw(9)<<"-"<<setw(9)<<"0"<<endl;
    for(int i=0; i<router_num; i++){
      if(i==index){
        continue;
      }
      else if(parent[i] == index)
        cout<<setw(9)<<arr[i]<<setw(9)<<arr[i]<<setw(9)<<d[i]<<endl;
      else
         cout<<setw(9)<<arr[i]<<setw(9)<<arr[parent[i]]<<setw(9)<<d[i]<<endl;
    }
  }
}
