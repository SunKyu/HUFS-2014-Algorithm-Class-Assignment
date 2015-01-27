#include <iostream>

using namespace std;

int main(void){
  int n;
  int p;
  cin>>n;
  if(n==0)
    return 0;
  cin>>p;
  while(true){
    if(n==0)
      break;
    if(p<=n-p){
      if(p%2==0){
        cout<<p-1<<" "<<n-p+1<<" "<<n-p+2;
      }
      else{
        cout<<p+1<<" "<<n-p<<" "<<n-p+1;
      }
    }
    else{
      if(p%2==0){
        cout<<n-p+1<<" "<<n-p+2<<" "<<p-1;
      }
      else{
        cout<<n-p<<" "<<n-p+1<<" "<<p+1;
      }
    
    }
      cout<<endl;
      cin>>n;
      cin>>p;
  }


}
