#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int main (int argc , char *argv[]){
  fstream IN;
  IN.open(argv[1]);//use terminal and script
  clock_t start;//start time
  clock_t end;//end time
  double maxSum=0;//store maxSum
  int n;//input num
  IN>>n;
  double value[n];//input value
  int count;
  start = clock();
  for(int i = 0; i < n; i++){
    IN >> value[i];
  }
  maxSum = value[0];
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
    { 
      float sum = 0;
      int temp =0; //for the each count
      for (int k = i; k <=  j; k++){
        sum = sum + value[k];
        temp++;
      }
      if (maxSum <sum ){
        maxSum = sum;
        count=temp;
      }
      /*
      * find smaller count when maxsum equivalate
      */
      else if (maxSum==sum&&temp<count)
      {
        count=temp;
      }
    }
  end = clock();
  cout<<count<<" "<<maxSum<<endl;
  printf("%lf\n", ((double)(end-start))/CLOCKS_PER_SEC);
  //calculate time
  cout<<endl;
}
