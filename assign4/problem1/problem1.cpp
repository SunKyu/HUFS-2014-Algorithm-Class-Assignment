//과제 4-1

#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char *argv[])
{
  fstream IN;
  IN.open(argv[1]);
  int m;
  int n;
  IN>>m>>n;
  int temp[n];//store one cloums sum
  int sum[n];//for the finding contiuous max sum
  int maxsum=0;
  int casesum= 0;

  int ** arr = new int* [m];
  for(int i=0; i<m ; i++){
    arr[i]= new int [n];
  }
  for(int i=0 ; i<m; i++){
    for(int j=0 ; j<n; j++){
      IN>>arr[i][j];
    }
  }
  for (int i= 0; i<n; i++)
    temp[i]=0;
  int first=0;
  int last=0;
  while(1){  
    if(last==m){//select two row first and last
      first++;
      last=first;
    }
    if(first==m)
      break;

    sum[0]=0;
    maxsum=sum[0];
    for(int j=0; j<n; j++){
      if(first!=last)//add the last rows value
        temp[j]+=arr[last][j];
      else{//last == first 
          temp[j]=arr[first][j];
      }
      if(j==0)
        sum[j]=temp[0];
      else{
        if(sum[j-1]+temp[j]>0&&sum[j-1]>0){
          sum[j]=sum[j-1]+temp[j];
        }
        else
          sum[j]=temp[j];
      }
      if(maxsum<sum[j])
        maxsum=sum[j];//store max sum
    }
    if(casesum<maxsum)
      casesum=maxsum;//store the whole maxsum

    last++; 
  }

  cout<<casesum<<endl;
  cout<<endl;

  return 0;
}
