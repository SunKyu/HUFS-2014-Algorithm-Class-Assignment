//과제 4-2

#include <iostream>
#include <fstream>

using namespace std;
/*
 *@parm row, cloum, 2dimension arr, array
 *return the minimumcost of arr[i][j]
 */
int minimumcost(int i, int j, int** p, int *d);

int main(int argc, char *argv[]){
  fstream IN;
  IN.open(argv[1]);
  int L;
  int n;
  IN>>L>>n;

  int * tree = new int [n+2];//store input data of d
  for(int i=1; i<n+1; i++){
    IN>>tree[i];
  }
  tree[0]=0;
  tree[n+1]=L;

  int ** arr = new int* [n+2];//store minumumcost of i, j
  for(int i=0 ; i<n+2; i++)
    arr[i] = new int[n+2];
  
  for(int i =1; i<n+2; i++){
    for(int j=0; j+i<n+2 ; j++){
     arr[j][j+i]=minimumcost(j, j+i, arr, tree); 
    }
  }
  cout<<arr[0][n+1]<<endl<<endl;
}

//find minumumcost between di, dj
int minimumcost(int i, int j, int ** p,int * d){
  if(j-1==i)
    return 0;
  int min=p[i][j-1]+p[i+1][j];
  for(int k=i+1; k<j ; k++){
      if(min>p[i][k]+p[k][j])
        min=p[i][k]+p[k][j];
  }
  min+= d[j]-d[i];
  return min;
}

