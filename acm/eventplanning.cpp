#include <iostream>
using namespace std;
int main (void){
  int N;
  int B, H , W;
  cin>>N>>B>>H>>W;
  int a[15];
  int price;
  int qwe=9886765;
  int minprice=8786756;
  for(int i=0; i<H; i++){
    cin>>price;
    if(N*price<=B){
      for(int j=0; j<W; j++){
        cin>>a[j];
        if(a[j]>=N){
          qwe=N*price;
        }
        if(qwe<minprice){
            minprice=qwe;
        }
      }
    }
  }
  if(minprice>B)
    cout<<"stay home"<<endl;
  else
    cout<<minprice<<endl;

}

