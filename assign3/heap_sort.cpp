//heapsort

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

/*
 *rebuildheap start from lastlevel-1 nodes
*/
void rebuildHeap(double a[], int root, int n){
  int i, lagerchild;
  double x=a[root];
  int current = root;

  while(2*current+1<n)
  {
    int leftchild = 2*current+1;
    int rightchild = leftchild+1;
    int lagerchild;
    if(rightchild<=n && (a[rightchild]>a[leftchild]))
      lagerchild=rightchild;
    else
      lagerchild=leftchild;

    if(x<a[lagerchild]){
      a[current]=a[lagerchild];
      current=lagerchild;
    }
    else
      break;
  }
  a[current]=x;
}
/*
* delete root node, root node is max
*/
double deleteMax(double a[], int size){
  int n= size-1;
  if(n<1){//when heap size less than 2
    return a[0];
  }
  double max=a[0];
  
  a[0]=a[n];
  a[n]=max;
  n=n-1;
  rebuildHeap(a, 0, n);
  return max;
}
int main(int argc, char*argv[]){
  clock_t start;//start time
    clock_t end;//endtime
  int n;
  fstream IN;
  IN.open(argv[1]);
  IN>>n;
  double *arr= new double [n];
  for(int i=0; i<n; i++)
    IN>>arr[i];

  start = clock();
  /*
  *using rebuildheap function, make heap 
  */
  for(int root=n/2-1; root>=0; root--)
    rebuildHeap(arr, root, n);
  
  int count=0;//check count of all num
  int maxcount=0;//store max counted num's frequency
  int max=0;//check value of num
  int tempmax=arr[0];//check temporay value of num during the finding max
  int finalmax=arr[0]; //final most high frequency value
  /*
   *using deletemax function 
   *count the most high frequency num
   */
  for(int i=n; i>0; i--){
     max=deleteMax(arr, i);
     if(tempmax==max)
      count++;
     else{
      count=1;
      tempmax=max;
     }
     if(count>maxcount){//change finalmax and maxcount
       maxcount=count;
        finalmax=max;
     }

  }
  end = clock();
    
  cout<<finalmax<<" "<<maxcount<<endl;
  printf("%lf \n",((double)(end - start))/CLOCKS_PER_SEC);
  cout<<endl;
  IN.close();
}
