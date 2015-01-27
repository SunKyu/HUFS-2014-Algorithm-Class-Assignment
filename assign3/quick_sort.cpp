//quick sort
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

/*
*use quick sort algorithm
*/
void quicksort2(int first, int last, double a[]){
  int left=first+1;
  int right=last;
  srand( (unsigned)time( NULL ) );
  if(first>=last)return;
  int pivot=rand()%(last-first+1)+first;
  double temp=a[pivot];
  a[pivot]=a[first];
  a[first]=temp;
  while(left<=right){
    while(left<=last&&a[left]<a[first])
      left++;
    while(right>=first+1&&a[right]>=a[first])
      right--;
    if(left<=right){
      double temp=a[left];
      a[left]=a[right];
      a[right]=temp;
      left++;
      right--;
    }
  }
  temp=a[first];
  a[first]=a[right];
  a[right]=temp;
  quicksort2(first, right-1, a);//divide and conqure
  quicksort2(right+1, last, a);
}



int main (int argc, char *argv[]){
  int n;
  clock_t start;//start time
    clock_t end;//endtime
  fstream IN;
  IN.open(argv[1]);
  IN>>n;
  double *arr = new double [n];

  for(int i =0 ; i<n; i++)
    IN>>arr[i];
start = clock();
  quicksort2(0, n-1, arr);//use quicksort function
  int count = 0;//check count of all num
  int value = arr[0];//check value of num
  int maxvalue =0; //store max counted num's value
  int maxcount = 0;//store max counted num's frequency
  /*
  *array is sorted 
  *than find most high frequency num
  */
  for(int i=0; i<n; i++){
    if(arr[i]==value){
      count++;
    }
    else{
      value=arr[i];
      count=1;
    }
    if(count>maxcount){
      maxcount=count;
      maxvalue=value;
    }
    else if(count==maxcount){
      if(maxvalue<value)
        maxvalue=value;
    }
  }
  end = clock();
    
  cout<<maxvalue<<" "<<maxcount<<endl;
  printf("%lf \n",((double)(end - start))/CLOCKS_PER_SEC);
  cout<<endl;
  IN.close();

}
