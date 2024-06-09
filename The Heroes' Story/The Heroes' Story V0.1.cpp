#include<iostream>
using namespace std;
int i,j,n,m,money=0;
char q='_',a='&',w='$',ans;//80*25 -8-2
void move(char a){
    if(ans=='a'){n--;m++;}
    if(ans=='d'){n++;m--;}
    if(ans=='w'){n-=80;m+=80;}
    if(ans=='s'){n+=80;m-=80;}
     }

void endl(int n){
     for(i=1;i<=n;i++)
       cout<<endl;}

int main(){
    n=140;m=499;
    bool o=0;
    while(o==0){
    for(i=1;i<=n;i++)
      cout<<q;
    cout<<a;
    for(i=1;i<=m;i++)
      cout<<q;
    cout<<"You have "<<money<<" money.\n";
    endl(14);
    cin>>ans;
    move(ans);
    cout<<endl;
    
    }
    return 0;} 
