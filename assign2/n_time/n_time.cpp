#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
  fstream IN;//fillstream
  IN.open(argv[1]);//use terminal and script
  clock_t start;//for the starttime
  clock_t end;//for the endtime
  auto n=0;//input num
  IN>>n;
  int value[n], Sum[n]; //input value and sum
  int count[n];//each index's count
  /*
   *check count when Sum value up 
   */
  for (auto i = 0; i < n; i++)
    IN >> value[i];
  Sum[0] = value[0];
  start = clock();
  count[0]=1;
  for (int i = 1; i < n; i++)
    if (Sum[i-1] > 0){
      Sum[i] = Sum[i-1] + value[i];
      count[i]=count[i-1]+1;//check count
    }
    else{
      Sum[i] = value[i];
      count[i]=1;//reset count
    }
  int index=0;//find maxSum index
  int maxSum = Sum[0];
  for (int i = 1; i < n; i++){
    if (maxSum < Sum[i]){
      index=i;
      maxSum = Sum[i]; 
    }
    else if(maxSum==Sum[i]&&count[index]>count[i]){
      index=i;
    }
  }

  end = clock();
  cout<<count[index]<<" "<<maxSum<<endl;
  printf("%lf \n ", ((double)(end - start))/CLOCKS_PER_SEC);
  //calculate time  
  cout<<endl;
}
