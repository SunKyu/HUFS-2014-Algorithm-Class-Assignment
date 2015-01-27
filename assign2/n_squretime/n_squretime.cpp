#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int main (int argc, char* argv[]){
  fstream IN;
  IN.open(argv[1]);
  clock_t start;//start time
  clock_t end;//endtime
  auto n=0;//input num
  auto sum=0;//sum
  auto count =0;
  IN >> n;
  double value[n];//input value
  for (auto i = 0; i < n; i++)
    IN >> value[i];
  float maxSum = value[0];//maxsum intializing
  start = clock();
  
  for (auto i = 0; i < n; i++) 
  {
    float sum = 0;
    for (auto j = i; j < n; j++) 
    {
      sum = sum + value[j];
      if (maxSum < sum){
        maxSum = sum;
        count = j-i+1;
      }
      if (maxSum==sum&&(j-i+1)<count)
      {
        count=(j-i+1);
      }
    }     
  }

  cout<<count<<" "<<maxSum<<endl;
  end = clock();
  printf("%lf \n",((double)(end - start))/CLOCKS_PER_SEC);
  //calculate time
  cout<<endl;
}
