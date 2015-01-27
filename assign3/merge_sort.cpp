//merge sort
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void Merge(int first, int mid, int last,double a[]){
  int indexA, indexB, indexC;
  indexA=indexB=indexC=0;
  int k=mid-first+1;
  int m=last-mid;
  /*
   *need modification
   *use only 2 array 
   can save the memeory and copy time`
   */
  double *A= new double[k];
  double *B= new double[m];
  double *C= new double[k+m];

  for(int i=0; i<k; i++)
    A[i]=a[first+i];
  for(int i=0; i<m; i++)
    B[i]=a[mid+i+1];

  while(indexA<k&&indexB<m){
    if(A[indexA]<B[indexB]){
      C[indexC]=A[indexA];
      indexA++;
    }
    else{
      C[indexC]=B[indexB];
      indexB++;
    }
    indexC++;
  }
  if(indexA<k){
    for( ;indexA<k; indexA++){
      C[indexC] = A[indexA];
      indexC++;
    }
  }
  else{
    for( ; indexB<m; indexB++){
      C[indexC] = B[indexB];
      indexC++;
    }
  }
  for(int i=0; i<k+m; i++){
    a[first+i]=C[i];
  }


}

void MergeSort(int first, int last, double a[] ){
  if(first < last){
    int mid = (first + last)/2;
    MergeSort(first, mid, a);//divide and conqure
    MergeSort(mid+1, last, a);
    Merge(first, mid, last, a);
  }
}
int main(int argc, char* argv[]){
  int n;
  clock_t start;//start time
    clock_t end;//endtime
  fstream IN;
  IN.open(argv[1]);
  IN>>n; 
  double *arr = new double[n];
  double *sorted = new double[n];
  for(int i=0; i<n; i++)
    IN>>arr[i];
  start = clock();
  MergeSort(0, n-1, arr);
  int count = 0;//check count of all num
  int value = arr[0];//check value of num
  int maxvalue =0;//store max counted num's value
  int maxcount = 0;  //store max counted num's frequency
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
}
