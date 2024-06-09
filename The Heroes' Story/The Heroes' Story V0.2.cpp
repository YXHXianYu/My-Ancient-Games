#include<iostream>
using namespace std;
int i,j,n,m;
const char grass='_',w='$';
char map[9][81];//               地图 80*25
char hero=char(1);int h1=4,h2=10,money=0;//角色参数、基础值 
char ans;

void move(char t){//                   移动函数 
    if(t=='a')
      if(h2!=1)
        {map[h1][h2]=grass;h2-=1;map[h1][h2]=hero;}
    
    if(t=='d')
      if(h2!=80)
        {map[h1][h2]=grass;h2+=1;map[h1][h2]=hero;}
    
    if(t=='w')
      if(h1!=1)
        {map[h1][h2]=grass;h1-=1;map[h1][h2]=hero;}
    
    if(t=='s')
      if(h1!=8)
        {map[h1][h2]=grass;h1+=1;map[h1][h2]=hero;}
    
     }

void endl(int n){//                    换行函数 
     for(i=1;i<=n;i++)
       cout<<endl;}
       

int main(){
    memset(map,'_',sizeof(map));
    bool o=0;
    map[h1][h2]=hero;
    
    while(o==0){
    
    for(i=1;i<=8;i++)
      for(j=1;j<=80;j++)
        cout<<map[i][j];
     
    cout<<"You have "<<money<<" money.\n";
    endl(14);
    cin>>ans;
    move(ans);
    endl(1);
    
    }
    for(i=1;i<=30;i++) cout<<" ";
    cout<<"---The Game Is Over---"<<endl;
    cin>>i;
    return 0;}
