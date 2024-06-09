#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int i,j,n,m;
const char grass='_',coin='$';
char map[9][81];int bomap[9][81];//地图 8*80(25*80)
int h1=4,h2=10,money=10,hp,dmg;//角色参数、基础值
char hero=char(1);//角色参数、基础值
char ans,pw[10];
bool bo;

void move(char t){//                   移动函数 
    if((t=='a')&&(h2!=1))
      {map[h1][h2]=grass;h2-=1;map[h1][h2]=hero;}
    if((t=='d')&&(h2!=80))
      {map[h1][h2]=grass;h2+=1;map[h1][h2]=hero;}
    if((t=='w')&&(h1!=1))
      {map[h1][h2]=grass;h1-=1;map[h1][h2]=hero;}
    if((t=='s')&&(h1!=8))
      {map[h1][h2]=grass;h1+=1;map[h1][h2]=hero;}
    if(bomap[h1][h2]==1)
      {bomap[h1][h2]=0;money++;}
}

void endl(int n){//                    换行函数 
     for(i=1;i<=n;i++)
       cout<<endl;}
       
void choose_hero(){
    cout<<"挑选你的角色: 1:Human   "<<char(1)<<endl;
    cout<<"              2:Fighter "<<char(38)<<endl;
    cout<<"              3:DJ      "<<char(14)<<endl;
    cout<<"              4:Angle   "<<char(3)<<endl;
    bo=0;
    while(bo==0){
      cin>>ans;
      switch(ans){
        case '1':hero=char(1);hp=10;dmg=2;bo++;break;
        case '2':hero=char(38);hp=15;dmg=3;bo++;break;
        case '3':hero=char(14);hp=10;dmg=1;bo++;break;
        case '4':hero=char(3);hp=5;dmg=1;bo++;break;
        default:cout<<"Error!\n";}
    }
}
void birth_money(int x,int y){
     map[x][y]=coin;
     bomap[x][y]=1;}
       

int main(){
    memset(map,'_',sizeof(map));
    memset(bomap,0,sizeof(bomap));
    choose_hero();//   选择hero 
    map[h1][h2]=hero;//生成hero 
    birth_money(3,20);//   生成金币
    birth_money(5,60);//   生成金币
    birth_money(3,50);//   生成金币 
    
    bool o=0;
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
