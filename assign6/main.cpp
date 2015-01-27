#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct edge{
  char* dist;
  int weight;
  edge * next=NULL;
};
struct vertex{
  char* name;
  edge* link = NULL;
};

void makegraph(int **adjMatrix, vertex** router, int n){
  cout<<__LINE__<<endl;
  edge * a = NULL;  
  for(int i=0;i<n; i++){
    cout<<__LINE__<<endl;
    a=router[i]->link;
    cout<<__LINE__<<endl;
      while(1){
        if(a==NULL)
          break;
        else{
          cout<<n<<endl;
          for(int j=0; j<n; j++){
            if(strcmp(router[j]->name, a->dist)==0){
              cout<<__LINE__<<endl;
              adjMatrix[i][j]=a->weight;
              cout<<__LINE__<<endl;
            }
          }
          a= a->next;
        }
      }
    }
}

int main (int argc, char * argv []){
  int router_num;
  int link_num;
  bool * check= new bool [router_num];
  int count = 0;
  for(int i =0; i<router_num; i++)
    check[i]= false;

  cin>>router_num>>link_num;

  int ** adjMatrix = new int * [router_num];
  for(int i=0 ; i<router_num; i++)
    adjMatrix[i]=new int [router_num];
  vertex ** router = new vertex* [router_num];
  for(int i =0 ; i< link_num; i++){
    char* start = NULL;
    char* dest = NULL;
    string a;
    string b;
    int cost;
    cin>>a>>b>>cost;
    start = &a[0];
    dest = &b[0];
    bool startflag = true;
    bool destfalg = true;
    int num = 0;
    edge * input = new edge;
    input->weight=cost;
    for(int j = 0 ; j < count; j++){
      if(router[i]->name==start){
        input->dist=dest;
        input->next=router[i]->link;
        router[i]->link=input;
        startflag=false;
        continue;
      }
      if(router[i]->name==dest){
        input->dist=start;
        input->next=router[i]->link;
        router[i]->link=input;
        destfalg=false;
        continue;
      }
    }
    if(startflag==true){
      vertex * stvertex = new vertex;
      stvertex->name=start;
      input->dist=dest;
      stvertex->link=input;
      router[count++]=stvertex;
    }
    if(destfalg==true){
      vertex * dtvertex = new vertex;
      dtvertex->name=dest;
      input->dist=dest;
      dtvertex->link=input;
      router[count++]=dtvertex;
    }
  }
  cout<<__LINE__<<endl;
  makegraph(adjMatrix, router, router_num);

  for(int i =0 ; i<router_num; i++){
    for(int j = 0; j<router_num ; j++){
      cout<<adjMatrix[i][j]<< " ";
    }
    cout<<endl;
  }

   



}

