#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
void check(int first, int last, int a[], int sum[]){
  if(first==last){
    return;
  }
  if (last-first==1)
  {
    if(sum[first]>0&&sum[last]>0)
      sum[last]+=sum[first];
    if(sum[first]>0&&sum[last]<=0){
      if (sum[first]+sum[last]>0)
      {
        sum[last]+=sum[first];
      }
    }
    return;
  }
  int mid1= (first+last)/2;
  check(first, mid1, a, sum);
  check(mid1+1, last, a, sum);
  
    int mid = (first+last)/2;
    int com = sum[mid];
    if(com<0)
      return;

    for (int i = mid+1; i < last+1; ++i)
    {
      if(sum[i-1]+a[i]>=0)
        sum[i]=a[i]+sum[i-1];
      else{
        sum[i]=a[i];
        break;
      }
    }
  }

  void build(int a[], int sum[], int size){
    int first=0;
    int last=size-1;
    int mid= (first+last)/2;
    for(int i=0 ;i<size ; i++ ){
      sum[i]=a[i];
    }
    check(first, last, a, sum);
  }

  int main (int argc, char* argv[]){
    fstream IN;
    IN.open(argv[1]);
    clock_t start;//start time
    clock_t end;//endtime
    auto n=0;//input num
    auto sum=0;//sum
    IN >> n;
    int count=0;
    int finalcount=0;
    int value[n];//input value
    int * qsum= new int[n];
    int maxSum=qsum[0];
    for (auto i = 0; i < n; i++){
      IN >> value[i];
    }
    start = clock();
    build(value, qsum, n);
    
    
    for (int i=0; i<n; i++) {
      if (qsum[i]>0)
      {
        count++;
      }
      else
        count=0;
      if (maxSum<qsum[i]) {
        maxSum=qsum[i];
        finalcount=count;
      }
    }
    cout<<finalcount<<" "<<maxSum<<endl;
    end = clock();
    printf("%lf \n",((double)(end - start))/CLOCKS_PER_SEC);
    delete [] qsum;
    cout<<endl;
  }
