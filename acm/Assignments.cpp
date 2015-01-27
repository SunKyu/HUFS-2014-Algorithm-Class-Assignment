#include <iostream>
using namespace std;

double data[100][3];
int result[50];
int main(){
  auto T=0;
  cin>>T;
  int N;
  double D;
  int count=0;
 int temp = 0;
  while(T--){
    cin>>N>>D;
    count=0;
    for(int i =0;i<N; i++){
        cin>>data[i][0]>>data[i][1]>>data[i][2];
    }
    for(int i =0; i<N ; i++){
      double div;
      div=data[i][1]/data[i][2];
      if(D/data[i][0]<=div)
        count++;
    }
    result[temp]=count;
    temp++;
  }
  for(int i =0 ; i<temp; i++)
    cout<<result[i]<<endl;


}
