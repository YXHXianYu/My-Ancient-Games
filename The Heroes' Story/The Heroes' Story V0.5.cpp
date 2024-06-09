#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int i,j,n,m,score=0;
const char grass='_',coin=char(36),devil=char(15),zombie=char(20);
const char sword=char(33),double_sword=char(19),life=char(3);
const char npc=char(2),exit1=char(21);
//grass,devil,coin,zombie,sword,life,npc

char map[9][81];int bomap[9][81];//��ͼ 8*80(25*80)
int h1=4,h2=10,money=10,hp,dmg;//��ɫ����������ֵ
char hero=char(1);//��ɫ����������ֵ
char ans,pw[10];
bool bo,bodie=0,bojump=0,boexit=0;
int monster_kind,bonpc=0;

void move(char t){//                   �ƶ����� 
    if((t=='a')&&(h2!=5))
      {map[h1][h2]=grass;h2-=5;map[h1][h2]=hero;}
    if((t=='d')&&(h2!=80))
      {map[h1][h2]=grass;h2+=5;map[h1][h2]=hero;}
    if((t=='w')&&(h1!=1))
      {map[h1][h2]=grass;h1-=1;map[h1][h2]=hero;}
    if((t=='s')&&(h1!=8))
      {map[h1][h2]=grass;h1+=1;map[h1][h2]=hero;}
    if(bomap[h1][h2]==1)//coin 
      {bomap[h1][h2]=0;money++;}
    if(bomap[h1][h2]==2)//zombie
      {bomap[h1][h2]=0;monster_kind=1;}
    if(bomap[h1][h2]==3)//devil
      {bomap[h1][h2]=0;monster_kind=2;}
    if(bomap[h1][h2]==4)//life
      {bomap[h1][h2]=0;hp+=3;score+=3;}
    if(bomap[h1][h2]==5)//sword
      {bomap[h1][h2]=0;dmg++;score+=5;}
    if(h1==1 && h2==5)//Shop  ע��������Ⱥ�˳�� 
      {bomap[h1][h2]=0;bonpc=2;}
    if(bomap[h1][h2]==6)//npc ע��������Ⱥ�˳��
      {bomap[h1][h2]=0;bonpc=1;score+=5;}
    if(bomap[h1][h2]==100)//exit
      {bomap[h1][h2]=0;boexit=1;score+=100;}
    
}

void endl(int n){//                    ���к��� 
     for(i=1;i<=n;i++)
       cout<<endl;}
       
void talking_npc(){//                  npc
     cout<<"NPC:Oh!You are killing me!\n";
     cout<<"    I will die!Ahhhhhhhh~~\n";
     money-=5;
     }
     
       
void choose_hero(){
    cout<<"��ѡ��Ľ�ɫ: 1:Human   "<<char(1)<<endl;
    cout<<"              2:Fighter "<<char(38)<<endl;
    cout<<"              3:DJ      "<<char(14)<<endl;
    cout<<"              4:Angle   "<<char(12)<<endl;
    cout<<"����ע��: 1:Zombie  "<<char(20)<<endl;
    cout<<"          2:Devil   "<<char(15)<<endl;
    cout<<"����ע��: 1:NPC     "<<npc<<endl;
    cout<<"����ע��: 1:Coin    "<<coin<<endl;
    cout<<"          2:Life    "<<life<<endl;
    cout<<"          3:Sword   "<<sword<<endl;
    cout<<"������:"<<exit1<<endl;
    bo=0;
    while(bo==0){
      cin>>ans;
      switch(ans){
        case '1':hero=char(1);score+=10;hp=10;dmg=2;bo++;break;
        case '2':hero=char(38);hp=15;dmg=3;bo++;break;
        case '3':hero=char(14);score+=20;hp=10;dmg=1;bo++;break;
        case '4':hero=char(12);score+=30;hp=5;dmg=1;bo++;break;
        default:cout<<"Error!\n";}
    }
}
void birth_coin(int x,int y){//        ���ɽ�Һ���:1
     map[x][y]=coin;
     bomap[x][y]=1;}
     
void birth_life(int x,int y){//        ���ɰ��ĺ���:4
     map[x][y]=life;
     bomap[x][y]=4;}
     
void birth_sword(int x,int y){//       ���ɽ�����:5
     map[x][y]=sword;
     bomap[x][y]=5;}
     
void birth_npc(int x,int y){//         ����npc����:6
     map[x][y]=npc;
     bomap[x][y]=6;}
     
void birth_exit(int x,int y){//         ���ɴ�����:100
     map[x][y]=exit1;
     bomap[x][y]=100;}

void birth_monster(int x,int y,int z){//���ɹ��ﺯ��
     if(z==1){
     map[x][y]=zombie;//              zombie:2
     bomap[x][y]=2;}
     if(z==2){
     map[x][y]=devil;//               devil:3
     bomap[x][y]=3;}
     }
     
void shop(){//                         �̵꺯�� 
     endl(1);
     cout<<"Welcome to <Dead-Glassland Shop>\n";
     endl(1);
     cout<<"NPC:�������ֹ������.\n";
     cout<<"1.Sword:5$   2.Life:3$   3.Double_Sword=9$   4.Exit.\n";
     endl(5);
     
     bo=0;
     while(bo==0){
     cin>>ans;
     switch(ans){
       case '1':money-=5;dmg++;score-=2;bo++;break;
       case '2':money-=3;hp+=3;bo++;break;
       case '3':money-=9;dmg+=2;score-=5;bo++;break;
       case '4':bo++;break;
       default:cout<<"Error\n";
       }
     }
     
     }
     
void monster_fight(int kind){
     if(kind==0);
     else{
     int mhp=0,mdmg,mm=0; 
     if(kind==1){mhp=5;mdmg=1;mm=3;}//Zombie
     if(kind==2){mhp=6;mdmg=2;mm=5;}//devil
     while(mhp>0){
       mhp-=dmg;
       hp-=mdmg;
       score--;
       if(hp<=0){bodie=1;boexit=1;score-=5;break;}
       }
     money+=mm;
     score+=10;
     }
     }
     
void birth(){//ע��:��������Ϊ5�ı���
     for(i=1;i<=4;i++)//        �����̵� 
       map[2][i]=char(35);//    �����̵�
     map[1][4]='|';//           �����̵�
     birth_exit(8,80);//        ���ɴ����� 
     birth_coin(3,20);//        ���ɽ��
     birth_coin(5,60);//        ���ɽ��
     birth_coin(3,50);//        ���ɽ��
     birth_life(8,10);//        ���ɰ���
     birth_life(2,60);//        ���ɰ���
     birth_sword(7,55);//       ���ɰ���
     birth_monster(7,30,1);//   ���ɹ���
     birth_monster(7,40,1);//   ���ɹ���
     birth_monster(7,35,1);//   ���ɹ���
     birth_monster(6,40,1);//   ���ɹ���
     birth_monster(5,40,1);//   ���ɹ���
     birth_monster(4,40,1);//   ���ɹ��� 
     birth_monster(2,10,2);//   ���ɹ��� 
     //birth_npc(1,5);//          ����npc
     birth_npc(1,1);//          ����npc
     birth_npc(1,3);//          ����npc
     
     
}
       

int main(){
    system("title The Heroes' Story");
    cout<<"<The Heroes' Story>[Alpha 5]\n";
    cout<<"<C> ��Ȩ���� 2016-2020 YXH_XianYu\n";
    cout<<"����QQ:2943003\n\n";
    cout<<"WASD���Ʒ���,Enterȷ��\n";
    system("pause");
    cout<<"Enter your name.\n";
    cin.getline(cname,15);
    endl(25);
    memset(map,'_',sizeof(map));
    memset(bomap,0,sizeof(bomap));
    choose_hero();//                   ѡ��hero 
    map[h1][h2]=hero;//                ����hero 
    birth();//                         ���ɵ���,���� 
    
    while(boexit==0){
    endl(2);
    for(i=1;i<=8;i++)
      for(j=1;j<=80;j++)
        cout<<map[i][j]; 
    monster_fight(monster_kind);
    monster_kind=0;
    cout<<"money:"<<money<<endl;
    cout<<"   HP:"<<hp<<endl;
    cout<<"  DMG:"<<dmg<<endl;
    cout<<"score:"<<score<<endl;
    switch(bonpc){//                   �̵�npc 
      case 1:endl(2);talking_npc();
             bonpc=0;endl(7);break;
      case 2:shop();bojump=1;bonpc=0;break;
      default:endl(11);break;
      } 
    if(bojump==1)bojump=0;
    else{
    cin>>ans;
    move(ans);}
    
    }
    endl(25);
    if(bodie==1)
    cout<<"                     You Died!"<<endl;
    cout<<"          ---Thank You For your play---"<<endl;
    cout<<"                   "<<cname<<endl;
    cout<<"                     Score:"<<score+hp<<endl;
    fcout();
    for(i=1;i<=12;i++){
      _sleep(1000);cout<<endl;}
    _sleep(5000);
    return 0;}
