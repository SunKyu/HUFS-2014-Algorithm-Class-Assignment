//insert sort
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

/*
* insertsort algorithm
* 
*/
void insertsort(double arr[], int i){
  double temp=arr[i];
  int k=0;
  for( k=i-1; k>=0; k--){
    if(arr[k]>temp)
      arr[k+1]=arr[k];
    else
      break;
  }
  arr[k+1]=temp;
}

int main(int argc, char* argv[]){
  int n;
  fstream IN;
  clock_t start;//start time
    clock_t end;//endtime
  IN.open(argv[1]);
  IN>>n;
  double *input = new double[n];
  int count=0; //check count of all num
  int maxcount=0; //store max counted num's frequency
  int value;  //check value of num
  int maxvalue; //store max counted num's value

  for(int i=0 ; i<n; i++)
    IN>>input[i];

  start = clock();
  /*
  *using insertsort function, do insertsort 
  */
  for(int i=0; i<n; i++)
    insertsort(input, i);


  value=input[0];
  /*
  *array is sorted 
  *than find most high frequency num
  */
  for(int i=0; i<n; i++){
    if(input[i]==value){
      count++;
    }
    else{
      value=input[i];
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
