#include <iostream>
#include <stack>


using namespace std;
int map[100][100];
int main(){
  auto T=0;
  int N, K, M;
  int u, v, d;
  stack<int> input;
  bool check[100];
  while (T--){
    cin>>N>>K>>M;
    for(int i =0; i<M; i++){
      cin>>u>>v>>d;
      map[u][v]=d;
      map[v][u]=d;
    }
    while(ture){
      for(int i=0; i<M; i++){
        input.push_back(i);
        check[i]=true;
        for(int q=0; q<M; q++){
          if(map[i][q]!=0&&check[q]==false)
            {
              check[q]=true;
              input.push_back(q);
            }

        }


      }
      


    }
  }

}
