#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main (void){
  srand((unsigned int)time(NULL));

  int m,n;
  cout<<"matrix size n m : ";
  cin>>n>>m;
  int** pa;
  pa=new int*[n];
  int** pb;
  pb =new int*[n];
  for(int i=0;i<m;++i)
  {
    pa[i]=new int[m];
    pb[i]=new int[m];
  }
  int r=rand()%29+1;

  cout<<"***** RANDOM MATRIX A *****"<<endl;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
      pa[i][j]=r;
      r=rand()%29+1;
      cout<<pa[i][j]<<" ";
    }

    cout<<endl;
  }
  cout<<endl<<"***** RANDOM MATRIX B *****"<<endl;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m;++j)
    {
      pb[i][j]=r;
      r=rand()%29+1;
      cout<<pb[i][j]<<" ";
    }
    cout<<endl;
  }
}
