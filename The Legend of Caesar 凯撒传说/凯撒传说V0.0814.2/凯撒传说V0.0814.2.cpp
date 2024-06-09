#include<algorithm>
#include<windows.h>
#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<cmath>
#include<ctime>
#include"Color.h"
#include"Pos.h"
using namespace std;
#define PAUSE system("pause")                         //��ͣ 
#define CLS system("cls")                             //���� 
//#define Pos_Set(x,y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y})
#define COLOR_Basic system("color f5")                //��ʼ����ɫ
#define TITLE_Basic system("title ������˵                                                                                  by.YXH����") 
#define MODE_Basic system("mode con cols=80 lines=25")//��ʼ������ 1��80���ַ� 1��25���ַ� 
#define MODE_Up system("mode con cols=157 lines=36"); //��ʼ������ 1��80���ַ� 1��36���ַ� 
#define FIGHT_Basic Fight_ChuShiHua(1)                //��ʼ��ս��ϵͳ
#define FIGHT_Up Fight_ChuShiHua(2)                   //��ʼ��ս��ϵͳ
#define D20 Random(1,20)
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

struct player{
	int money,
		hp,
		hp_max,
		sp,
		sp_max,
		ac,
		dmg,
		speed,
		food,
		wood,
		gold,
		stone;
	bool skill[101];
	int	skill_sum,
		level,
		exp;
	char name[20];
	int name_len;
	int Kind;       //ע��Ϊ��д"K" Ϊ�˺�"kind"���� 
}Hero;

struct monster{
	int money,
		hp,
		ac,
		dmg,
		speed;
	char name[100];
};

bool had_demo=0,               //Demo�Ƿ���  
	 bought_z1=1,              //�Ƿ����˵�һ�� 
	 bought_z2=0,              //�Ƿ����˵ڶ��� 
	 had_R18=0;                //0 �ر�   1 ���� 
int Story_End=1; 

void Play();                    //��ʼ��Ϸ 

void end(int n);                //���� 
void space(int n);              //�ո�
void check();                   //��麯��
void Loading();                 //���ؽ��� 
int Random(int low,int high);   //�������
int Change_a_little(int n);     //���Ե���ֵ[3r] 
void Skill();                   //���� 
void Fight(int kind);           //ս�� 
void Check_Body(monster m);

void Fight_ChuShiHua(int kind); //ս����ʼ�� 
void CG(int n,int a);           //����CG 
void Demo();                    //Demoֹͣ 
void Bought_z();                //�빺��ʣ���½� 
void Input_Name();              //�������� 
void Output_Name();             //������� 
void Hide_Cur();                //���ع�� 

void Menu();                    //�˵�
void Map();                     //�鿴��ͼ 
void Maker_List();              //���������� 
void Setting();

void CG_0();                    //����CG 
void CG_0_Maze();               //����Maze
void CG_1();                    //��һ��CG 
void CG_1_Maze();               //��һ��Maze
void CG_2();                    //�ڶ���CG 
void CG_2_1();                  //�ڶ���Ȫˮ��֧ 
void CG_2_2();                  //�ڶ��¶�Ѩ��֧ 
void CG_2_3();                  //�ڶ�������֧ 


int main(){
	
	COLOR_Basic;
	TITLE_Basic;
	MODE_Basic;
	Hide_Cur();
	Menu();
	PAUSE;
	
	return 0;
	}

void Play(){
	FIGHT_Basic;                                      //ս����ʼ��[Basic] 
	CG_0();                                           //�������� 
	if(Hero.hp<=0)
		return;
	if(had_demo){Demo();return;}                      //Demo
	MODE_Up;                                          //���ڳ�ʼ��[Up] 
	FIGHT_Up;                                         //ս����ʼ��[Basic]
	if(!bought_z1){MODE_Basic;Bought_z();return;}     //�빺��ʣ���½�
	CG_1();                                           //���ŵ�һ��
	if(Hero.hp<=0)
		return;
	if(!bought_z2){MODE_Basic;Bought_z();return;}     //�빺��ʣ���½� 
	CG_2();                                           //���ŵڶ��� 
	MODE_Basic;                                       //���ڳ�ʼ��[Basic]
	}

void end(int n){
	for(int i=1;i<=n;i++)
		cout<<endl;
	}

void space(int n){
	for(int i=1;i<=n;i++)
		cout<<" ";
	}

void check(string a,string b){
	CLS;
	cout<<" �������bug!!!\n(���ƺ����������ߵİ���)\n";
	cout<<" �����������߻㱨\n";
	cout<<" �������:\" "<<a<<" "<<b<<" \"\n";
	cout<<" ����������������ѯ�ʣ�֧����Ϸ��";
	/*
	0001 0001 luck����
	
	
	*/
	PAUSE;
	}

void Loading(){
	CLS;
	end(13);
	space(15);
	for(int i=1;i<=50;i++){
		cout<<"#";
		Sleep(5);
		}
	}

int Random(int low,int high){
	srand(time(NULL));
	int t=rand()%(high-low)+low;
	return t;
	}

int Change_a_little(int n){
	return n/2-5;
	}

inline void Skill(monster * m,bool * if_out,int kind){
	char in;
	while(in != '1' && in != '2' && in!='3' && in!='4'){
		CLS;
		end(1);
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//

		
		for(int i=1;i<=25;i++){
			cout<<"-    *";	
			space(65);
			switch(i){
				case 1:{
					cout<<"1.����ն";
					space(7);
					break;
					}
				/*
				case 2:{
					cout<<"2.�ķ�ն";
					space(7);
					break;
					}
				*/
				case 2:{
					cout<<"2.����";
					space(9);
					break;
					}
				case 3:{
					cout<<"3.ȡ��";
					space(9);
					break;
					}
				default:{
					space(15);
					break;
					};
				}
			space(63);
			cout<<"*    -"<<endl;//
			}
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		in=_getch();
		switch(in){
				case '1':{
					if(Hero.sp<=0){
						CG(21,0);
						*if_out=true;
						return;
						}
					Hero.sp--;
					int hurts=double(Hero.dmg)*5/2+Random(10,15);
					if(kind==2)	
						CG(22,hurts);
					if(kind==3)
						CG(28,hurts);
					m -> hp -= hurts; 
					return;
					}
				/*
				case '2':{
					if(Hero.Kind==1){
						CG(20,0); 
						} 
					if(Hero.sp<=2){
						CG(21,0);
						break;
						}
					Hero.sp-=3;
					int hurts=Hero.dmg*5+Random(10,20);
					CG(12,hurts);
					m -> hp -= hurts;
					return;
					}
				*/
				case '2':{
					Hero.sp+=1;
					CG(1,0);
					return;
					}
				case '3':{
					*if_out=true;
					return;
					}
				}
		}
	}

void Skill_Basic(monster * m,bool * if_out){
	char in;
	while(in != '1' && in != '2'){
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		
		for(int i=1;i<=12;i++){
			cout<<"-   *";	
			space(27);
			switch(i){
				case 1:{
					cout<<"1.����ն";
					space(7);
					break;
					}
				case 2:{
					cout<<"2.ȡ��";
					space(9);
					break;
					}
				default:{
					space(15);
					break;
					};
				}
			space(27);
			cout<<"*   -"<<endl;//
			}
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		in=_getch();
		switch(in){
				case '1':{
					if(Hero.sp<=0){
						CG(3,0);
						break;
						}
					Hero.sp--;
					int hurts=Hero.dmg*5+Random(10,20);
					CG(12,hurts);
					m -> hp -= hurts;
					return;
					}
				case '2':{
					*if_out=true;
					return;
					}
				}
		}
	}

inline void Fight(int kind){
	monster m;
	if(kind==1){//Skeleton Fighter
		m.ac=100;
		m.dmg=150;
		m.speed=3;
		m.hp=800;
		}
	if(kind==2){//Elf Hunter
		m.ac=0;
		m.dmg=10;
		m.speed=5;
		m.hp=30;
		}
	if(kind==3){//Slime
		m.ac=5;
		m.dmg=9;
		m.speed=1;
		m.hp=80;
		}
	char in;
	do{
		//Fight
		if(kind==1){//Skeleton Fighter
			CLS;
			end(1);
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                       *** ^                 -"<<endl;//
			cout<<"-                                                       *** |                 -"<<endl;//
			cout<<"-               ***                                 __   *  |                 -"<<endl;//
			cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
			cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
			cout<<"-                *  /                               \\/  ***                   -"<<endl;//
			cout<<"-               **-+-                                   * *                   -"<<endl;//
			cout<<"-                **                                     * *                   -"<<endl;//
			cout<<"-                *                                                            -"<<endl;//
			cout<<"-               * *                                                           -"<<endl;//
			cout<<"-              *  *                                                           -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *    1.����    2.����    HP:"<<Hero.hp<<"\t                                  *   -"<<endl;//
			cout<<"-   *    3.����              SP:"<<Hero.sp<<"\t                                  *   -"<<endl;// 
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			}
		if(kind==2){//Elf Hunter
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
			cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
			cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
			cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
			cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
			cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
			cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
			cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
			cout<<"-                             ***    *   /                                                             | *****                                             -"<<endl;//
			cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
			cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
			cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
			cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
			cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
			cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
			cout<<"-                           *     *                                                                        *                                               -"<<endl;//
			cout<<"-                          *      *                                                                        *                                               -"<<endl;//
			cout<<"-                         *       *                                                                                                                        -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *    1.����\t2.����\t\tHP:"<<Hero.hp<<"\tElf Hunter HP:"<<m.hp<<"                                                                                     *     -"<<endl;//
			cout<<"-    *    3.����\t4.״̬\t\tSP:"<<Hero.sp<<"                                                                                                         *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			}
		if(kind==3){//Slime
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                *****************                                         -"<<endl;//
			cout<<"-                                                                                           *                         *                                    -"<<endl;//
			cout<<"-                                                                                        *                               *                                 -"<<endl;//
			cout<<"-                                        / / /                                         *                                   *                               -"<<endl;//
			cout<<"-                                       /   / /                                      *                                       *                             -"<<endl;//
			cout<<"-                           *******    /   /   /                                   *                                           *                           -"<<endl;//
			cout<<"-                          *********  /   /   /                                   *          ###                  ###           *                          -"<<endl;//
			cout<<"-                          *       * /   /   /                                   *                                               *                         -"<<endl;//
			cout<<"-                          *       */   /   /                                   *                                                 *                        -"<<endl;//
			cout<<"-                           *******/   /   /                                   *                                                   *                       -"<<endl;//
			cout<<"-                              * *    /   /                                    *                                                   *                       -"<<endl;//
			cout<<"-                             ***    *   /                                     *                                                   *                       -"<<endl;//
			cout<<"-                            ********    *                                      *                                                 *                        -"<<endl;//
			cout<<"-                              **  /                                             *                                               *                         -"<<endl;//
			cout<<"-                              *  *                                               *                                             *                          -"<<endl;//
			cout<<"-                              *                                                   **                                         **                           -"<<endl;//
			cout<<"-                             ***                                                    **                                     **                             -"<<endl;//
			cout<<"-                            *   *                                                     *************************************                               -"<<endl;//
			cout<<"-                           *     *                                                                                                                        -"<<endl;//
			cout<<"-                          *      *                                                                                                                        -"<<endl;//
			cout<<"-                         *       *                                                                                                                        -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *    1.����\t2.����\t\tHP:"<<Hero.hp<<"\tSlime HP:"<<m.hp<<"                                                                                         *     -"<<endl;//
			cout<<"-    *    3.����\t4.״̬\t\tSP:"<<Hero.sp<<"                                                                                                         *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			
			}
		in=_getch();
		int luck;
		if(kind==1)
			luck=D20;
		else
			luck=Random(11,20);
		int hurts;
		switch(in){
			case '1':{
				if(luck>18 && luck<=20){
					hurts=Change_a_little(Random(9,14))+Hero.dmg;
					if(hurts<0) hurts=0;
					if(kind==1)
						CG(4,hurts*2);
					if(kind==2)
						CG(18,hurts*2);
					if(kind==3)
						CG(27,hurts*2);
					m.hp-=hurts*2;
					}
				if(luck>10 && luck<=18){
					hurts=Change_a_little(Random(9,14))+Hero.dmg;
					if(hurts<0) hurts=0;
					if(kind==1)
						CG(8,hurts);
					if(kind==2)
						CG(17,hurts);
					if(kind==3)
						CG(26,hurts);
					m.hp-=hurts;
					}
				if(luck<=10 && luck>=0){
					hurts=Change_a_little(Random(9,14))+Hero.dmg-m.ac;
					if(hurts<0) hurts=0;
					if(kind==1)
						CG(9,hurts);
					m.hp-=hurts;
					}
				if(luck>20 || luck<0){
					check("0001","0001");
					cout<<luck<<endl;
					PAUSE;
					}
				if(m.hp<=0)
					break;
				hurts=Change_a_little(Random(9,14))+m.dmg;
				if(hurts<0) hurts=0;
				if(kind==1)
					CG(7,hurts);
				if(kind==2)
					CG(20,hurts);
				if(kind==3)
					CG(23,hurts);
				Hero.hp-=hurts;
				break;
				}
			case '2':{
				if(kind==2){
					CG(19,0);
					break;
					}
				if(kind==3){
					CG(25,0);
					break;
					}
				int hurts=Change_a_little(Random(9,14))-Hero.ac+m.dmg;
				if(hurts<0) hurts=0;
				if(kind==1)
					CG(5,hurts);	
				Hero.hp-=hurts;
				Hero.sp++;
				break;
				}
			case '3':{
				bool if_out=0;
				if(Hero.skill_sum==0)
					CG(3,0);
				else{
					if(kind==1)
						Skill_Basic(&m,&if_out);
					else
						Skill(&m,&if_out,kind);
					}
				if(m.hp<=0)
					break;
				if(if_out)
					break;
				hurts=Change_a_little(Random(9,14))+m.dmg;
				if(hurts<0) hurts=0;
				if(kind==1)
					CG(7,hurts);
				if(kind==2)
					CG(20,hurts);
				if(kind==3)
					CG(23,hurts);
				Hero.hp-=hurts;
				break;
				}
			case '4':{
				if(kind==1)
					break;
				Check_Body(m);
				break;
				}
			case '5':{
				break;
				}
			}
		if(m.hp<=0){
			if(kind==1)
				CG(0,1);
			else
				CG(0,0);
			Hero.exp++;
			Hero.hp=Hero.hp_max;
			Hero.sp=Hero.sp_max;
			return;
			}
		if(Hero.hp<=0){
			MODE_Basic;
			CG(11,0);
			CG(10,0);
			return;
			}
	}while(1);
	
	}

void Check_Body(monster m){
	CLS;
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                                                                                                                            "<<endl;//
	cout<<"                                                              ���Ѫ��      : "<<Hero.hp<<"/"<<Hero.hp_max<<endl;//
	cout<<"                                                              �������      : "<<Hero.sp<<"/"<<Hero.sp_max<<endl;//
	cout<<"                                                              ��Ĺ�����    : "<<Hero.dmg<<endl;//
	cout<<"                                                              ��ķ�����    : "<<Hero.ac<<endl;//
	cout<<"                                                              ����ٶ�      : "<<Hero.speed<<endl;//
	cout<<"                                                              ��ĵȼ�      : "<<Hero.level<<endl;//
	cout<<"                                                              ��ľ���ֵ    : "<<Hero.exp<<endl;//
	end(1);
	end(1);
	cout<<"                                                              �����Ѫ��    : "<<m.hp<<endl;//
	cout<<"                                                              ���������    : "<<0<<endl;//
	cout<<"                                                              ����Ĺ�����  : "<<m.dmg<<endl;//
	cout<<"                                                              ����ķ�����  : "<<m.ac<<endl;//
	end(14);
	PAUSE;
	}

inline void Menu(){
	int p=1,max_p=8;
	char ch=0;
	while(1){
		//Pos_Set(1,1);py0
		
		CLS;
		//end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                 __                          -"<<endl;//
		cout<<"-                                                |  |                         -"<<endl;//
		cout<<"-                 *******************************|  |                         -"<<endl;//
		cout<<"-               **                               |  |_______#                 -"<<endl;//
		cout<<"-             **        -------------------------|   _______##                -"<<endl;// 
		cout<<"-               **                               |  |       #                 -"<<endl;//
		cout<<"-                 *******************************|  |                         -"<<endl;//
		cout<<"-                                                |__|                         -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		for(int i=1;i<=8;i++){
			cout<<"-";
			space(27);
			if(p==i){
				cout<<"->   ";
				}
			else
				cout<<"     ";
			switch (i){
				case 1:
					cout<<" ��ʼ��Ϸ";
					space(7); 
					break;
				case 2:
					cout<<" �ۿ���ͼ/�����";
					//space(0);
					break;
				/*
				case 3:
					cout<<" ����";
					space(11);
					break;
				*/
				case 3:
					cout<<" ����������";
					space(5);
					break;
				case 4:
					cout<<" �˳���Ϸ";
					space(7);
					break;
				default:
					space(16);
					break;
				}
			space(29);
			cout<<"-";
			cout<<endl;
			}
		
		cout<<"-                                                                             -"<<endl;// 
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   W S ����Enter ���вٿ�                                 ������:MS Studio   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		ch=_getch();
		if( (ch=='w' || ch==72)&&(p>=2) )
			p--;
		if( (ch=='s' || ch==80)&&(p<=max_p-1) )
			p++;
		if( ch=='\r' ){
			switch(p){
				case 1:
					Play();
					break;
				case 2:
					Map();
					break;
				/*
				case 3:
					Setting();
					break;
				*/
				case 3:
					CLS;
					Maker_List();
					COLOR_Basic;
					break;
				case 4:
					return; 
					break;
				case 8:
					FIGHT_Up;
					MODE_Up;
					CG_1_Maze();
					MODE_Basic;
				default:
					break;
				}
			}
		}
	
	PAUSE;
	}

void Map(){
	//Map
	CLS;
	end(1);
	cout<<"-------------------------------------------------------------------------------"<<endl;// 
	cout<<"-                                       *                                     -"<<endl;//[phiya]��[�����۹�]���׶������������ҵĺ��ġ�
	cout<<"-  ������½��ͼ                        *                                      -"<<endl;//
	cout<<"-                                    **                                       -"<<endl;//[Godigun]��һ��Ҫ������ǽ�ޱȵļ�̡�
	cout<<"-    ~                          *****                                         -"<<endl;//��Ԫǰ168���[ʥս]��<��ħ>���ִ�½��[Godigun]���������ķ��ߣ� 
	cout<<"-        ~             ~   *****                                              -"<<endl;//֮����< Ken.Caesar>���쵼�£�������[Godigun]Ϊ��أ��ɹ�����<��ħ>�� 
	cout<<"-   ~            ~        *     #Godigun       @Phiya                         -"<<endl;//
	cout<<"-            ~           *                                                    -"<<endl;//[Sealidge]��[�����۹�]��Ϊ���ٵĳ��С� 
	cout<<"-        *               *                                                    -"<<endl;//��������������м���ĲƸ��� 
	cout<<"-  ~  * *         ~      ********   #Sealidge          / / / / /              -"<<endl;//��ʱ��ʱ��������Ҳ���ܵ����˺�<��ħ>�Ĺ�����
	cout<<"-      ***      ~        *   ~   *                / / / / / / / /             -"<<endl;//
	cout<<"-       * *     ~       * ~    ~  *            / / / / / / / / / /            -"<<endl;//[Me City]��[ʥս]ǰ��������½���ĳ��У� 
	cout<<"-      *                 ~    ~ ~ *           / / / / / / / / / / /           -"<<endl;//����[ʥս]����ʧ���أ�����ֻʣ�²�ԫ�ϱڡ� 
	cout<<"-  ~          ~      ~            *            / / / / / / / / / /            -"<<endl;//�����޸�����Me City��Χ����һЩ���� 
	cout<<"-      ~~         ~      *  ~  ~  *             / / / / / / / /               -"<<endl;//
	cout<<"-   ~                    ***     *                       / /                  -"<<endl;//[Wild City]������������[������½]������ҵĵط��� 
	cout<<"-        ~     ~         * ******                         /   #Wild City      -"<<endl;//���������ڴ�������<�۹�������>���޷�Լ������ 
	cout<<"-                   ~     *     #Me City                                      -"<<endl;//
	cout<<"-  @ �׶�       ~          **                                                 -"<<endl;//[Ken City]��[ʥս]��<Ken.Caesar>�Ĺ��硣 
	cout<<"-  # ���ĳ���         ~      ******              #Ken City                    -"<<endl;//
	cout<<"-  ~ ��           ~      ~         *                                          -"<<endl;//
	cout<<"-  / ɳĮ   ~                        *                                         -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Map
	CLS;
	end(1);
	cout<<"-------------------------------------------------------------------------------"<<endl;// 
	cout<<"-                                       *                                     -"<<endl;//
	cout<<"-  ������½��ͼ                        *          [phiya]��[�����۹�]���׶��� -"<<endl;//
	cout<<"-                                    **                  ���������ҵĺ��ġ�   -"<<endl;//
	cout<<"- [Godigun]��һ��Ҫ����         *****                                         -"<<endl;// 
	cout<<"- ��ǽ�ޱȵļ�̡���Ԫ     *****                                              -"<<endl;// 
	cout<<"- ǰ168���[ʥս]��<��ħ> *     #Godigun       @Phiya                         -"<<endl;//
	cout<<"- ���ִ�½��[Godigun] �� *                                                    -"<<endl;// 
	cout<<"- �������ķ��ߣ�֮���� *                     [Sealidge]��[�����۹�]��Ϊ���� -"<<endl;// 
	cout<<"- <Ken.Caesar>���쵼�£� ********   #Sealidge  �ĳ��С���������������м���� -"<<endl;//
	cout<<"- ������[Godigun]Ϊ��أ�*       *             �Ƹ�����ʱ��ʱ��������Ҳ���ܵ� -"<<endl;//
	cout<<"- �ɹ�����<��ħ>��      *         *            ���˺�<��ħ>�Ĺ�����           -"<<endl;// 
	cout<<"-                                 *                                           -"<<endl;//
	cout<<"- [Me City]��[ʥս]ǰ��           *   [Wild City]����������                   -"<<endl;//
	cout<<"- ������½���ĳ��У�   *        *   ��[������½]������ҵĵط���            -"<<endl;//
	cout<<"- ����[ʥս]����ʧ���أ� ***     *                                            -"<<endl;// 
	cout<<"- ����ֻʣ�²�ԫ�ϱڡ�   * ******                             #Wild City      -"<<endl;//���������ڴ�������<�۹�������>���޷�Լ������ 
	cout<<"-                         *     #Me City                                      -"<<endl;//
	cout<<"-  @ �׶�                  **                                                 -"<<endl;// 
	cout<<"-  # ����                    ******              #Ken City                    -"<<endl;//
	cout<<"-  ~ ��                            *     [Ken City]��[ʥս]��               -"<<endl;//
	cout<<"-  / ɳĮ                           *        <Ken.Caesar>�Ĺ��硣             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	if(0){
		//Big_Map
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//1
		cout<<"-                                                                                                                                                          -"<<endl;//2
		cout<<"-                                                                                                                                                          -"<<endl;//3
		cout<<"-                                                                                                                                                          -"<<endl;//4
		cout<<"-                                                                                                                                                          -"<<endl;//5
		cout<<"-                                                                                                                                                          -"<<endl;//6
		cout<<"-                                                                                                                                                          -"<<endl;//7
		cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;// 
		cout<<"-                                      -                                       *                                     -                                     -"<<endl;//
		cout<<"-                                      -  <��������Ĺ���> ������½��ͼ       *                                      -                                     -"<<endl;//
		cout<<"-                                      -                                    **                                       -                                     -"<<endl;//
		cout<<"-                                      -    ~                          *****                                         -                                     -"<<endl;//
		cout<<"-                                      -        ~             ~   *****                                              -                                     -"<<endl;// 
		cout<<"-                                      -   ~            ~        *     #Godigun       @Phiya                         -                                     -"<<endl;//
		cout<<"-                                      -            ~           *                                                    -                                     -"<<endl;//
		cout<<"-                                      -        *               *                                                    -                                     -"<<endl;//
		cout<<"-                                      -  ~  * *         ~      ********   #Sealidge          / / / / /              -                                     -"<<endl;//
		cout<<"-                                      -      ***      ~        *   ~   *                / / / / / / / /             -                                     -"<<endl;//
		cout<<"-                                      -       * *     ~       * ~    ~  *            / / / / / / / / / /            -                                     -"<<endl;//
		cout<<"-                                      -      *                 ~    ~ ~ *           / / / / / / / / / / /           -                                     -"<<endl;//
		cout<<"-                                      -  ~          ~      ~            *            / / / / / / / / / /            -                                     -"<<endl;//
		cout<<"-                                      -      ~~         ~      *  ~  ~  *             / / / / / / / /               -                                     -"<<endl;//
		cout<<"-                                      -   ~                    ***     *                       / /                  -                                     -"<<endl;//
		cout<<"-                                      -        ~     ~         * ******                         /   #Wild City      -                                     -"<<endl;//
		cout<<"-                                      -                   ~     *     #Me City                                      -                                     -"<<endl;//
		cout<<"-                                      -  @ �׶�       ~          **                                                 -                                     -"<<endl;//
		cout<<"-                                      -  # ����    ~        ~      ******              #Ken City                    -                                     -"<<endl;//
		cout<<"-                                      -  ~ ��           ~      ~         *                                          -                                     -"<<endl;//
		cout<<"-                                      -  / ɳĮ  ~                        *                                         -                                     -"<<endl;//
		cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//0
		cout<<"-                                                                                                                                                          -"<<endl;//1
		cout<<"-                                                                                                                                                          -"<<endl;//2
		cout<<"-                                                                                                                                                          -"<<endl;//3
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//4
		PAUSE;
		}
	}

void Maker_List(){
	//P 
	CLS;
	end(30); 
	cout<<"-                                    ������                                   -"<<endl;Sleep(250);
	cout<<"-                                   MS Studio                                 -"<<endl;Sleep(250);
	end(1);Sleep(250);
	cout<<"-                                  ��ϯ����Ա                                 -"<<endl;Sleep(250);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(250);
	end(1);Sleep(250);
	cout<<"-                                  ��������Ա                                 -"<<endl;Sleep(250);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(250);
	end(1);Sleep(250);
	cout<<"-                                     �ܼ�                                    -"<<endl;Sleep(250);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(250);
	end(1);Sleep(250);
	cout<<"-                                     ��л                                    -"<<endl;Sleep(250);
	cout<<"-                                 MS.DWTornier                                -"<<endl;Sleep(250);
	cout<<"-                                  MS.BlueCat                                 -"<<endl;Sleep(250);
	cout<<"-                                 MS.IceLocke                                 -"<<endl;Sleep(250);
	cout<<"-                                MS.DrivenHank                                -"<<endl;Sleep(250);
	cout<<"-                                      CC                                     -"<<endl;Sleep(250);
	cout<<"-                      (������������˽��QQ:2258488076)                      -"<<endl;Sleep(250);
	for(int i=1;i<=5;i++){
		end(1);
		Sleep(250);
		}
	
	/*
	
	*/
	
	cout<<endl;Sleep(250);
	cout<<"                        ";C_B<<"**************";C_W<<"   ";C_c<<"***************";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"**************";C_W<<"   ";C_c<<"***************";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"                      ";C_c<<"*******";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"                   ";C_c<<"****";C_W<<"   ";C_c<<"***";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"                 ";C_c<<"****";C_W<<"     ";C_c<<"***";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"          ";C_c<<"*******";C_W<<"         ";C_c<<"***";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"        ";C_c<<"***********";C_W<<"       ";C_c<<"***";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"       ";C_c<<"*************";C_W<<"      ";C_c<<"***";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"       ";C_c<<"*************";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"        ";C_c<<"***********";C_W<<"  ";C_r<<"********";C_W<<endl;Sleep(250);
	cout<<"-                       ";C_B<<"***";C_W<<"          ";C_c<<"*******";C_W<<"    ";C_r<<"********";C_W<<endl;Sleep(250);
	for(int i=1;i<=3;i++){
		end(1);
		Sleep(250);
		}
	cout<<"-                      ";C_b<<"**";C_W<<"  ";C_p<<"**";C_W<<"  ";C_y<<"**";C_W<<"  ";C_B<<"**";C_W<<endl;Sleep(250);
	for(int i=1;i<=3;i++){
		end(1);
		Sleep(250);
		}
	Sleep(2500);
	Color_Set(White,Black);
	
	cout<<"��������:�����ڸ������ϼ��������Ӫ��,Ȼ���Ҿ�һ��ʼ����Ϸ,��������w."<<endl;Sleep(250);
	cout<<"         ��ʵ�����Ϸ�ܶ�������û�����갡,ʱ�����ŵ�̫����orz."<<endl;Sleep(250);
	cout<<"         ����Ժ����������Ϸ�Ĺ���,ϣ���ܱ��ֳ���,����һ�����Լ����ֵ���Ϸ."<<endl;Sleep(250);
	cout<<"����ʱ��:2017.8.3-2017.8.14 [AlphaŶ]               by.MS.YXH 2017.8.14.11.20"<<endl;Sleep(250);
	cout<<endl;
	
	PAUSE;
	
	}

void Setting(){
	
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	}

void Fight_ChuShiHua(int kind){
	switch(kind){
		case 1://Isaac
			Hero.Kind=1;
			Hero.ac=50;
			Hero.dmg=70;
			Hero.hp_max=1000;
			Hero.hp=1000;
			Hero.sp_max=1;
			Hero.sp=1;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=1;
			Hero.skill[1]=true;//����ն
			Hero.level=1;
			Hero.exp=0;
			break;
		case 2://Eden
			Hero.Kind=2;
			Hero.ac=1;
			Hero.dmg=5;
			Hero.hp_max=70;
			Hero.hp=70;
			Hero.sp_max=0;
			Hero.sp=0;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=1;
			Hero.skill[1]=true;//����ն 
			Hero.skill[2]=true;//�ķ�ն 
			Hero.level=1;
			Hero.exp=0;
			break; 
		default:
			Hero.ac=1;
			Hero.dmg=3;
			Hero.hp=50;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=0;
			Hero.level=1;
			Hero.exp=0;
			break;
		}
	}

void CG(int n,int a){
	/*
	0.ս��ʤ��! 
	1.����
	2.����ʧ�� 
	3.û�м��� 
	4.4.CG_0_����_��_�ػ� 
	5.CG_0_����_�� 
	6.CG_0����ʧ��
	7.CG_0_�ܵ�����
	8.CG_0_����_��_����
	9.CG_0_�������� 
	10.Game Over 
	11.You Dead 
	12.CG_0_����ն 
	13.CG_1_�Թ�����_go 
	14.CG_1_����û��· 
	15.CG_1_�Թ�����_return 
	16.CG_1_��������_���� 
	17.CG_1_��������_����
	18.CG_1_��������_�ػ�
	19.CG_1_��������_����(�޷�)
	20.CG_1_��������_�ܵ�����
	21.CG_1_��������
	22.CG_1_��������_����ն
	23.CG_1_ʷ��ķ_�ܵ�����
	*/
	if(n==0){//0.ս��ʤ��! 
		CLS;
		if(a==1){
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                  ***                                        -"<<endl;//
		cout<<"-                                 *   *                                       -"<<endl;//
		cout<<"-                               *  ***  *                                     -"<<endl;//
		cout<<"-                                *  *  *                                      -"<<endl;//
		cout<<"-                                 *****                                       -"<<endl;//
		cout<<"-                                   *                                         -"<<endl;//
		cout<<"-                                   *                                         -"<<endl;//
		cout<<"-                                  * *                                        -"<<endl;//
		cout<<"-                                 *   *                                       -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                            ս��ʤ����                               *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		}
		else{
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                 ս��ʤ��������                                                                *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		}
		PAUSE;
		}
	if(n==1){//1.����
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                        +                                                                                                 -"<<endl;//
		cout<<"-                                                                                              +                                                           -"<<endl;//
		cout<<"-                                                                                  +                                                                       -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        *****                                                                             -"<<endl;//
		cout<<"-                                                 +                *    *     *    *                                                                       -"<<endl;//
		cout<<"-                                                                    *   *****   *                                                                         -"<<endl;//
		cout<<"-                                                                      *   *   *                                                                           -"<<endl;//
		cout<<"-                                                                        *****                                                                             -"<<endl;//
		cout<<"-                                                                +         *                                                                               -"<<endl;//
		cout<<"-                                                                          *                                                                               -"<<endl;//
		cout<<"-                                                                          *                  +                                                            -"<<endl;//
		cout<<"-                                                +                         *                                                                               -"<<endl;//
		cout<<"-                                                                         * *                             +                                                -"<<endl;//
		cout<<"-                                                                        *   *                                                                             -"<<endl;//
		cout<<"-                                                                       *     *                                                                            -"<<endl;//
		cout<<"-                                                                      *       *                                                                           -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==2){//2.����ʧ�� 
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       �����˰�Χ�ˣ�����ʧ�ܣ�                      *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==3){//3.�������� 
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                              ��������                               *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==4){//4.CG_0_����_��_�ػ� 
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                           /                     -"<<endl;//
		cout<<"-              *  * *   * *  *                        /                       -"<<endl;//
		cout<<"-              *  ***   ***  *                      /                         -"<<endl;//
		cout<<"-               *           *                     /                           -"<<endl;//
		cout<<"-                ***|||||***                    /                             -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *              |                                  -"<<endl;//
		cout<<"-              *  * *   * *  *             |                                  -"<<endl;//
		cout<<"-              *  ***   ***  *             |                                  -"<<endl;//
		cout<<"-               *           *              |                                  -"<<endl;//
		cout<<"-                ***|||||***               |                                  -"<<endl;//
		cout<<"-                   *****                  |                                  -"<<endl;//
		cout<<"-                                        --+--                                -"<<endl;//
		cout<<"-                                          ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *       \\                                         -"<<endl;//
		cout<<"-              *  * *   * *  *       \\                                        -"<<endl;//
		cout<<"-              *  ***   ***  *        \\                                       -"<<endl;//
		cout<<"-               *           *          \\                                      -"<<endl;//
		cout<<"-                ***|||||***            \\                                     -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *  \\                                              -"<<endl;//
		cout<<"-              *  * *   * *  *   \\                                            -"<<endl;//
		cout<<"-              *  ***   ***  *     \\                                          -"<<endl;//
		cout<<"-               *           *        \\                                        -"<<endl;//
		cout<<"-                ***|||||***           \\                                      -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** ====                                              -"<<endl;//
		cout<<"-              *  * *   * ========                                            -"<<endl;//
		cout<<"-              *  ***   *** ====\\                                             -"<<endl;//
		cout<<"-               *           *      \\                                          -"<<endl;//
		cout<<"-                ***|||||***          \\                                       -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       �ػ�������սʿ������                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                        �ػ�������սʿ������                         *   -"<<endl;//
		cout<<"-   *                             <"<<a<<">\t                              *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==5){//5.CG_0_����_�� 
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **       *                                          -"<<endl;//
		cout<<"-               * ***   *** *     /                                           -"<<endl;//
		cout<<"-              *  * *   * *  *   /                                            -"<<endl;//
		cout<<"-              *  ***   ***  *  /                                             -"<<endl;//
		cout<<"-               *           *  /                                              -"<<endl;//
		cout<<"-                ***|||||***  /                                               -"<<endl;//
		cout<<"-                   *****    /                                                -"<<endl;//
		cout<<"-                           /                                                 -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **           *                                      -"<<endl;//
		cout<<"-               * ***   *** *        /                                        -"<<endl;//
		cout<<"-              *  * *   * *  *     /                                          -"<<endl;//
		cout<<"-              *  ***   ***  *   /                                            -"<<endl;//
		cout<<"-               *           *  /                                              -"<<endl;//
		cout<<"-                ***|||||*** /                                                -"<<endl;//
		cout<<"-                   *****  /                                                  -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                                                 -"<<endl;//
		cout<<"-              *  * *   * *  *                                                -"<<endl;//
		cout<<"-              *  ***   ***  *                                                -"<<endl;//
		cout<<"-               *           *                                                 -"<<endl;//
		cout<<"-                ***|||||***   ----*                                          -"<<endl;//
		cout<<"-                   *****                                                     -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                                                 -"<<endl;//
		cout<<"-              *  * *   * *  *                                                -"<<endl;//
		cout<<"-              *  ***   ***  *                                                -"<<endl;//
		cout<<"-               *           *  |                                              -"<<endl;//
		cout<<"-                ***|||||***    |                                             -"<<endl;//
		cout<<"-                   *****        |                                            -"<<endl;//
		cout<<"-                                 *                                           -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                                                 -"<<endl;//
		cout<<"-              *  * *   * *  *                                                -"<<endl;//
		cout<<"-              *  ***   ***  *                                                -"<<endl;//
		cout<<"-               *           *  |                                              -"<<endl;//
		cout<<"-                ***|||||***   |                                              -"<<endl;//
		cout<<"-                   *****      |                                              -"<<endl;//
		cout<<"-                              |                                              -"<<endl;//
		cout<<"-                            ==|=      |   ***                                -"<<endl;//
		cout<<"-                      -----===|===----+--*   *                               -"<<endl;//
		cout<<"-                            ==*==     |   **  *                              -"<<endl;//
		cout<<"-                              =             *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                             ��������                                *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **       *                                          -"<<endl;//
		cout<<"-               * ***   *** *     /                                           -"<<endl;//
		cout<<"-              *  * *   * *  *   /                                            -"<<endl;//
		cout<<"-              *  ***   ***  *  /                                             -"<<endl;//
		cout<<"-               *           *  /                                              -"<<endl;//
		cout<<"-                ***|||||***  /                                               -"<<endl;//
		cout<<"-                   *****    /                                                -"<<endl;//
		cout<<"-                           /                                                 -"<<endl;//
		cout<<"-                                      |   ***                                -"<<endl;//
		cout<<"-                      ----------------+--*   *                               -"<<endl;//
		cout<<"-                                      |   **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                      ����ס������սʿ�Ĺ�����                       *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==6){//6.CG_0_����ʧ�� 
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  ����:                                                              *   -"<<endl;//
		cout<<"-   *      �����ҵ�һ�������ս������                                     *   -"<<endl;//
		cout<<"-   *          ��ô�������أ�����                                         *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==7){//7.CG_0_�ܵ�����
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                                   * *                   -"<<endl;//
		cout<<"-                **                                     * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                             -                               -"<<endl;//
		cout<<"-                             ***      -                                      -"<<endl;//
		cout<<"-               ***           ***                                             -"<<endl;//
		cout<<"-              *   *  /        *            -                                 -"<<endl;//
		cout<<"-               ***====      *****  __                                        -"<<endl;//
		cout<<"-                ==*--------*- *  *|  |                                       -"<<endl;//
		cout<<"-               **-+==         *   |  |   -                                   -"<<endl;//
		cout<<"-                **           ***   \\/        -                               -"<<endl;//
		cout<<"-                *            * *                                             -"<<endl;//
		cout<<"-               * *           * *                                             -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  ����:                                                              *   -"<<endl;//
		cout<<"-   *      ����             ���ܵ��˹���Ĺ���                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                             -         *** ^                 -"<<endl;//
		cout<<"-                                      -                *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                     -      |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                     -             * *                   -"<<endl;//
		cout<<"-                **                           -         * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  ����:                                                              *   -"<<endl;//
		cout<<"-   *      ����             ���ܵ��˹���Ĺ���                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                                   * *                   -"<<endl;//
		cout<<"-                **                                     * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       ���ܵ��˹���Ĺ���                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==8){//8.CG_0_����_��_���� 
		
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                           /                     -"<<endl;//
		cout<<"-              *  * *   * *  *                        /                       -"<<endl;//
		cout<<"-              *  ***   ***  *                      /                         -"<<endl;//
		cout<<"-               *           *                     /                           -"<<endl;//
		cout<<"-                ***|||||***                    /                             -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *              |                                  -"<<endl;//
		cout<<"-              *  * *   * *  *             |                                  -"<<endl;//
		cout<<"-              *  ***   ***  *             |                                  -"<<endl;//
		cout<<"-               *           *              |                                  -"<<endl;//
		cout<<"-                ***|||||***               |                                  -"<<endl;//
		cout<<"-                   *****                  |                                  -"<<endl;//
		cout<<"-                                        --+--                                -"<<endl;//
		cout<<"-                                          ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *       \\                                         -"<<endl;//
		cout<<"-              *  * *   * *  *       \\                                        -"<<endl;//
		cout<<"-              *  ***   ***  *        \\                                       -"<<endl;//
		cout<<"-               *           *          \\                                      -"<<endl;//
		cout<<"-                ***|||||***            \\                                     -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *  \\                                              -"<<endl;//
		cout<<"-              *  * *   * *  *   \\                                            -"<<endl;//
		cout<<"-              *  ***   ***  *     \\                                          -"<<endl;//
		cout<<"-               *           *        \\                                        -"<<endl;//
		cout<<"-                ***|||||***           \\                                      -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** ====                                              -"<<endl;//
		cout<<"-              *  * *   * ========                                            -"<<endl;//
		cout<<"-              *  ***   *** ====\\                                             -"<<endl;//
		cout<<"-               *           *      \\                                          -"<<endl;//
		cout<<"-                ***|||||***          \\                                       -"<<endl;//
		cout<<"-                   *****                \\  -                                 -"<<endl;//
		cout<<"-                                        -+-                                  -"<<endl;//
		cout<<"-                                       -  ***                                -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       ����������սʿ������                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   *** *                      /                          -"<<endl;//
		cout<<"-              *  * *   * *  *                    /                           -"<<endl;//
		cout<<"-              *  ***   ***  *                   /                            -"<<endl;//
		cout<<"-               *           *                   /                             -"<<endl;//
		cout<<"-                ***|||||***                   /                              -"<<endl;//
		cout<<"-                   *****                  -  /                               -"<<endl;//
		cout<<"-                                           -+-                               -"<<endl;//
		cout<<"-                                          *** -                              -"<<endl;//
		cout<<"-                                         *   *                               -"<<endl;//
		cout<<"-                                          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       ����������սʿ������                          *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==9){//9.CG_0_�������� 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                 ����սʿ.                                                    -"<<endl;//
		cout<<"-                  *******                                                    -"<<endl;//
		cout<<"-                **       **                                                  -"<<endl;//
		cout<<"-               * ***   ***____=_____                                         -"<<endl;//
		cout<<"-              *  * *   * |   ===    |                                        -"<<endl;//
		cout<<"-              *  ***   **|    =\\=   |                                        -"<<endl;//
		cout<<"-               *         |        \\ |                                        -"<<endl;//
		cout<<"-                ***|||||*|          |\\                                       -"<<endl;//
		cout<<"-                   ***** |          |   \\  -                                 -"<<endl;//
		cout<<"-                         |          |   -+-                                  -"<<endl;//
		cout<<"-                          \\        /   -  ***                                -"<<endl;//
		cout<<"-                            \\    /       *   *                               -"<<endl;//
		cout<<"-                              \\/          **  *                              -"<<endl;//
		cout<<"-                                            *  *                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                           ���������ˣ�                            *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==10){//10.Game Over 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                 �㱻ɱ����                                  -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-    GGGGG     A      M M    EEEEE           OOOOO   V   V   EEEEE   RRRR     -"<<endl;//
		cout<<"-    G        A A    M M M   E               O   O   V   V   E       R   R    -"<<endl;//
		cout<<"-    G   G   AAAAA   M M M   EEEEE           O   O   V   V   EEEEE   RRRR     -"<<endl;//
		cout<<"-    G   G   A   A   M M M   E               O   O    V V    E       R  R     -"<<endl;//
		cout<<"-    GGGGG   A   A   M M M   EEEEE           OOOOO     V     EEEEE   R   R    -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                             Thanks For Playing                              -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==11){//11.You Dead 
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-        Y   Y   OOOOO   U   U               DDDD    EEEEE     A     DDDD     -"<<endl;//
		cout<<"-         Y Y    O   O   U   U               D   D   E        A A    D   D    -"<<endl;//
		cout<<"-          Y     O   O   U   U               D   D   EEEEE   AAAAA   D   D    -"<<endl;//
		cout<<"-          Y     O   O   U   U               D   D   E       A   A   D   D    -"<<endl;//
		cout<<"-          Y     OOOOO    UUU                DDDD    EEEEE   A   A   DDDD     -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==12){//12.CG_0_����ն 
		CLS;
		end(1);
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-               ***                                 __   *  |                 -"<<endl;//
		cout<<"-              *   *  /                            |  |*****|                 -"<<endl;//
		cout<<"-               ***  /                             |  |  *  |                 -"<<endl;//
		cout<<"-                *  /                               \\/  ***                   -"<<endl;//
		cout<<"-               **-+-                                   * *                   -"<<endl;//
		cout<<"-                **                                     * *                   -"<<endl;//
		cout<<"-                *                                                            -"<<endl;//
		cout<<"-               * *                                                           -"<<endl;//
		cout<<"-              *  *                                                           -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***            __   *  |                 -"<<endl;//
		cout<<"-             -                     *   *          |  |*****|                 -"<<endl;//
		cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
		cout<<"-         -                           *             \\/  ***                   -"<<endl;//
		cout<<"-                -                 |  **                * *                   -"<<endl;//
		cout<<"-                       -----------+-**                 * *                   -"<<endl;//
		cout<<"-      -                           |  *                                       -"<<endl;//
		cout<<"-              -                     * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***            __   *  |                 -"<<endl;//
		cout<<"-                                   *   *          |  |*****|                 -"<<endl;//
		cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
		cout<<"-                                     *             \\/  ***                   -"<<endl;//
		cout<<"-                                    **                 * *                   -"<<endl;//
		cout<<"-                                     **\\ /             * *                   -"<<endl;//
		cout<<"-                                     *  +                                    -"<<endl;//
		cout<<"-                                    * */ \\                                   -"<<endl;//
		cout<<"-                                   *  *   \\                                  -"<<endl;//
		cout<<"-                                           \\                                 -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***            __   *  |                 -"<<endl;//
		cout<<"-                                   *   *          |  |*****|                 -"<<endl;//
		cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
		cout<<"-                                     *             \\/  ***                   -"<<endl;//
		cout<<"-                                    ** |               * *                   -"<<endl;//
		cout<<"-                                     **+-----------    * *                   -"<<endl;//
		cout<<"-                                     * |                                     -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                       *** ^                 -"<<endl;//
		cout<<"-                                                       *** |                 -"<<endl;//
		cout<<"-                                    ***          ==__   *  |                 -"<<endl;//
		cout<<"-                                   *   *        =/== |*****|                 -"<<endl;//
		cout<<"-                                    ***       /  ==  |  *  |                 -"<<endl;//
		cout<<"-                                     *     /       \\/  ***                   -"<<endl;//
		cout<<"-                                    **| /              * *                   -"<<endl;//
		cout<<"-                                     **+               * *                   -"<<endl;//
		cout<<"-                                     *  |                                    -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		for(int i=1;i<=5;i++){
			CLS;
			end(1); 
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                       *** ^                 -"<<endl;//
			cout<<"-                                                       *** |                 -"<<endl;//
			cout<<"-                                    ***            __   *  |                 -"<<endl;//
			cout<<"-                                   *   *          |  |*****|                 -"<<endl;//
			cout<<"-                                    ***           |  |  *  |                 -"<<endl;//
			cout<<"-                                     *             \\/  ***                   -"<<endl;//
			cout<<"-                                  |  **                * *                   -"<<endl;//
			cout<<"-                       -----------+-**                 * *                   -"<<endl;//
			cout<<"-                                  |  *                                       -"<<endl;//
			cout<<"-                                    * *                                      -"<<endl;//
			cout<<"-                                    *  *                                     -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                                 !                                   *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			Sleep(300);
			CLS;
			end(1); 
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-                                                       *** ^                 -"<<endl;//
			cout<<"-                                                       *** |                 -"<<endl;//
			cout<<"-                                    ***          ==__   *  |                 -"<<endl;//
			cout<<"-                                   *   *        =/== |*****|                 -"<<endl;//
			cout<<"-                                    ***       /  ==  |  *  |                 -"<<endl;//
			cout<<"-                                     *     /       \\/  ***                   -"<<endl;//
			cout<<"-                                    **| /              * *                   -"<<endl;//
			cout<<"-                                     **+               * *                   -"<<endl;//
			cout<<"-                                     *  |                                    -"<<endl;//
			cout<<"-                                    * *                                      -"<<endl;//
			cout<<"-                                   *  *                                      -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                               ! ! !                                 *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			Sleep(300);
			}
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                      \\                                      -"<<endl;//
		cout<<"-                                   -   \\                                     -"<<endl;//
		cout<<"-                               -    -   \\              *** ^                 -"<<endl;//
		cout<<"-                                     -   \\             *** |                 -"<<endl;//
		cout<<"-                                    ***   \\  -     __   *  |                 -"<<endl;//
		cout<<"-                                   *   *  -+-     |  |*****|                 -"<<endl;//
		cout<<"-                                    ***  -*       |  |  *  |                 -"<<endl;//
		cout<<"-                                     *   *         \\/  ***                   -"<<endl;//
		cout<<"-                                    *****              * *                   -"<<endl;//
		cout<<"-                                     *                 * *                   -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                    *  *                                     -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                       -  -  -  -  -  -  -  -                        *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1500);
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                    =  *** ^                 -"<<endl;//
		cout<<"-                                             =         *** |                 -"<<endl;//
		cout<<"-                                    ***         ====_  ==  |                 -"<<endl;//
		cout<<"-                                   *   * =   ====/====*****|                 -"<<endl;//
		cout<<"-                                    ***       / ==== |  *= |                 -"<<endl;//
		cout<<"-                                     *     /   =   \\/  ***                   -"<<endl;//
		cout<<"-                                    **| /          =   * *                   -"<<endl;//
		cout<<"-                                     **+               * *                   -"<<endl;//
		cout<<"-                                     *  |                                    -"<<endl;//
		cout<<"-                                    * *                                      -"<<endl;//
		cout<<"-                                   *  *                                      -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                         ! ! ! ����ն ! ! !                          *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                          *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==13){//13.CG_1_�Թ�����_go 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *          ��         *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==14){//14.CG_1_����û��· 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            ����û��·������orz                                                                *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==15){//15.CG_1_�Թ�����_return 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *          ��         *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==16){//16.CG_1_��������_���� 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
		cout<<"-                                        ********************************           ********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||      ***      |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||      ***      |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||       *       |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||    |\\***      |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*     |*|*        *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *       * |*          *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *         |/* *           *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *             *               *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                    ���ֹ���                                                                   *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(n==17){//17.CG_1_��������_���� 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                             *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                              * ************* *                                                           -"<<endl;//
		cout<<"-                                                                               ***         ***                                                            -"<<endl;//
		cout<<"-                                                                               ***          **                                                            -"<<endl;//
		cout<<"-                                                                               **           **                                                            -"<<endl;//
		cout<<"-                                                                                *           *                                                             -"<<endl;//
		cout<<"-                                                                                 **       **                                                              -"<<endl;//
		cout<<"-                                                                                   *******                                                                -"<<endl;//
		cout<<"-                                                          /\\                                                                                              -"<<endl;//
		cout<<"-                            ******************************||                                                                                              -"<<endl;//
		cout<<"-                          *                               ||  *****                                                                                       -"<<endl;//
		cout<<"-                        *---------------------------------||=*     *=]                                                                                    -"<<endl;//
		cout<<"-                          *                               ||  *   *                                                                                       -"<<endl;//
		cout<<"-                            ******************************||  *   *                                                                                       -"<<endl;//
		cout<<"-                                                          \\/ *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                       \\ \\                   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                      \\ \\  \\                  * ************* *                                                           -"<<endl;//
		cout<<"-                                                      \\  \\  \\                  ***         ***                                                            -"<<endl;//
		cout<<"-                                                       \\  \\  \\                 ***          **                                                            -"<<endl;//
		cout<<"-                                                        \\  \\  \\                **           **                                                            -"<<endl;//
		cout<<"-                                                         \\  \\  \\                *           *                                                             -"<<endl;//
		cout<<"-                                                          \\  \\  \\                **       **                                                              -"<<endl;//
		cout<<"-                                                           \\  \\  \\ *               *******                                                                -"<<endl;//
		cout<<"-                                                            \\  *                                                                                          -"<<endl;//
		cout<<"-                                                           *    \\                                                                                         -"<<endl;//
		cout<<"-                                                              *****                                                                                       -"<<endl;//
		cout<<"-                                                             *     *                                                                                      -"<<endl;//
		cout<<"-                                                              *   *\\                                                                                      -"<<endl;//
		cout<<"-                                                              *   * *                                                                                     -"<<endl;//
		cout<<"-                                                             *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       |||   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                      | | |   * ************* *                                                           -"<<endl;//
		cout<<"-                                                                     |  |  |   ***         ***                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   ***          **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   **           **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |    *           *                                                             -"<<endl;//
		cout<<"-                                                                     |  |  |     **       **                                                              -"<<endl;//
		cout<<"-                                                                     |  |  |       *******                                                                -"<<endl;//
		cout<<"-                                                                     |  |  |                                                                              -"<<endl;//
		cout<<"-                                                                    /-------\\                                                                             -"<<endl;//
		cout<<"-                                                                    \\-------/                                                                             -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   *   |                                                                                 -"<<endl;//
		cout<<"-                                                             *   *      *                                                                                 -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *    *********    *                                                         -"<<endl;//
		cout<<"-                                                                               * */ /********* *                                                          -"<<endl;//
		cout<<"-                                                                              /    / /      ***                                                           -"<<endl;//
		cout<<"-                                                                             /    /          **                                                           -"<<endl;//
		cout<<"-                                                                            /    /    /      **                                                           -"<<endl;//
		cout<<"-                                                                           /    /    /       *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *  =====******    *                                                         -"<<endl;//
		cout<<"-                                                                              ====/ /===****** *                                                          -"<<endl;//
		cout<<"-                                                                            ==/    / /===== ***                                                           -"<<endl;//
		cout<<"-                                                                        =====/    /   =======**                                                           -"<<endl;//
		cout<<"-                                                                         ===/    /    /===   **                                                           -"<<endl;//
		cout<<"-                                                                          =/    /    /==     *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            �����˾������ˣ�����                                                               *     -"<<endl;//
		cout<<"-    *                                                                 <"<<a<<">\t                                                                     *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==18){//18.CG_1_��������_���� 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                             *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                              * ************* *                                                           -"<<endl;//
		cout<<"-                                                                               ***         ***                                                            -"<<endl;//
		cout<<"-                                                                               ***          **                                                            -"<<endl;//
		cout<<"-                                                                               **           **                                                            -"<<endl;//
		cout<<"-                                                                                *           *                                                             -"<<endl;//
		cout<<"-                                                                                 **       **                                                              -"<<endl;//
		cout<<"-                                                                                   *******                                                                -"<<endl;//
		cout<<"-                                                          /\\                                                                                              -"<<endl;//
		cout<<"-                            ******************************||                                                                                              -"<<endl;//
		cout<<"-                          *                               ||  *****                                                                                       -"<<endl;//
		cout<<"-                        *---------------------------------||=*     *=]                                                                                    -"<<endl;//
		cout<<"-                          *                               ||  *   *                                                                                       -"<<endl;//
		cout<<"-                            ******************************||  *   *                                                                                       -"<<endl;//
		cout<<"-                                                          \\/ *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                       \\ \\                   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                      \\ \\  \\                  * ************* *                                                           -"<<endl;//
		cout<<"-                                                      \\  \\  \\                  ***         ***                                                            -"<<endl;//
		cout<<"-                                                       \\  \\  \\                 ***          **                                                            -"<<endl;//
		cout<<"-                                                        \\  \\  \\                **           **                                                            -"<<endl;//
		cout<<"-                                                         \\  \\  \\                *           *                                                             -"<<endl;//
		cout<<"-                                                          \\  \\  \\                **       **                                                              -"<<endl;//
		cout<<"-                                                           \\  \\  \\ *               *******                                                                -"<<endl;//
		cout<<"-                                                            \\  *                                                                                          -"<<endl;//
		cout<<"-                                                           *    \\                                                                                         -"<<endl;//
		cout<<"-                                                              *****                                                                                       -"<<endl;//
		cout<<"-                                                             *     *                                                                                      -"<<endl;//
		cout<<"-                                                              *   *\\                                                                                      -"<<endl;//
		cout<<"-                                                              *   * *                                                                                     -"<<endl;//
		cout<<"-                                                             *   *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                           *   *                                                                                          -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       |||   *    *********    *                                                          -"<<endl;//
		cout<<"-                                                                      | | |   * ************* *                                                           -"<<endl;//
		cout<<"-                                                                     |  |  |   ***         ***                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   ***          **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |   **           **                                                            -"<<endl;//
		cout<<"-                                                                     |  |  |    *           *                                                             -"<<endl;//
		cout<<"-                                                                     |  |  |     **       **                                                              -"<<endl;//
		cout<<"-                                                                     |  |  |       *******                                                                -"<<endl;//
		cout<<"-                                                                     |  |  |                                                                              -"<<endl;//
		cout<<"-                                                                    /-------\\                                                                             -"<<endl;//
		cout<<"-                                                                    \\-------/                                                                             -"<<endl;//
		cout<<"-                                                                        |                                                                                 -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   *   |                                                                                 -"<<endl;//
		cout<<"-                                                             *   *      *                                                                                 -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *    *********    *                                                         -"<<endl;//
		cout<<"-                                                                               * */ /********* *                                                          -"<<endl;//
		cout<<"-                                                                              /    / /      ***                                                           -"<<endl;//
		cout<<"-                                                                             /    /          **                                                           -"<<endl;//
		cout<<"-                                                                            /    /    /      **                                                           -"<<endl;//
		cout<<"-                                                                           /    /    /       *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                              *  =====******    *                                                         -"<<endl;//
		cout<<"-                                                                              ====/ /===****** *                                                          -"<<endl;//
		cout<<"-                                                                            ==/    / /===== ***                                                           -"<<endl;//
		cout<<"-                                                                        =====/    /   =======**                                                           -"<<endl;//
		cout<<"-                                                                         ===/    /    /===   **                                                           -"<<endl;//
		cout<<"-                                                                          =/    /    /==     *                                                            -"<<endl;//
		cout<<"-                                                                          /    /    /      **                                                             -"<<endl;//
		cout<<"-                                                                         /    /    /*******                                                               -"<<endl;//
		cout<<"-                                                                        /    /    /                                                                       -"<<endl;//
		cout<<"-                                                                      *     /    /                                                                        -"<<endl;//
		cout<<"-                                                                           *    /                                                                         -"<<endl;//
		cout<<"-                                                                          /     *                                                                         -"<<endl;//
		cout<<"-                                                                       ***                                                                                -"<<endl;//
		cout<<"-                                                                      *   *                                                                               -"<<endl;//
		cout<<"-                                                                   *   ***                                                                                -"<<endl;//
		cout<<"-                                                                *   * /                                                                                   -"<<endl;//
		cout<<"-                                                             *   *   *                                                                                    -"<<endl;//
		cout<<"-                                                          *   *                                                                                           -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            �ػ��˾������ˣ�����                                                               *    -"<<endl;//
		cout<<"-    *                                                                 <"<<a<<">\t                                                                    *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==19){//CG_1_��������_����(�޷�) 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                 �������ܱ�����                                                                *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==20){//20.CG_1_��������_�ܵ����� 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
		cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
		cout<<"-                             ***    *   /                                                        *----|-*****                                             -"<<endl;//
		cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                                        -   / |  *****                                         -"<<endl;//
		cout<<"-                              * *    /   /                                                            | -| **   *                                         -"<<endl;//
		cout<<"-                             ***    *   /                                                   *-------  | *|  * **                                          -"<<endl;//
		cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                                  -|  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                   -        /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                            -               / |  *****                                         -"<<endl;//
		cout<<"-                              * *    /   /                                     -            -     -   |  | **   *                                         -"<<endl;//
		cout<<"-                             ***    *   /                                    *-------                 | *|  * **                                          -"<<endl;//
		cout<<"-                            ********    *                                                        -    *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                     -             |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                             -       \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                 -                        **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                         -                  /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                        -      -                            / |  *****                                         -"<<endl;//
		cout<<"-                              * *    /   /                     -             -                        |  | **   *                                         -"<<endl;//
		cout<<"-                             ***    *   /                 *-------      - -               -           | *|  * **                                          -"<<endl;//
		cout<<"-                            ********    *                                             -               *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                 -         -                       |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                              -                          \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/  =/   /                                                            / |  *****                                         -"<<endl;//
		cout<<"-                              * *  =========                                                          |  | **   *                                         -"<<endl;//
		cout<<"-                             *** ====*-------                                                         | *|  * **                                          -"<<endl;//
		cout<<"-                            *******=======                                                            *  |  *                                             -"<<endl;//
		cout<<"-                              **  / ==                                                                |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                              �㱻�����籣�ˣ�                                                                 *     -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                     *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		} 
	if(n==21){//��������
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                 ��������                                                                      *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==22){//22.CG_1_��������_����ն 
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                        / / /                                                        * *********** *                                      -"<<endl;//
		cout<<"-                                       /   / /                                                        **         **                                       -"<<endl;//
		cout<<"-                           *******    /   /   /                                                        *         *                                        -"<<endl;//
		cout<<"-                          *********  /   /   /                                                          **     **                                         -"<<endl;//
		cout<<"-                          *       * /   /   /                                                             *****                                           -"<<endl;//
		cout<<"-                          *       */   /   /                                                            /|  *                                             -"<<endl;//
		cout<<"-                           *******/   /   /                                                            / |  ****                                          -"<<endl;//
		cout<<"-                              * *    /   /                                                            |  | ** *                                           -"<<endl;//
		cout<<"-                             ***    *   /                                                             | *****                                             -"<<endl;//
		cout<<"-                            ********    *                                                             *  |  *                                             -"<<endl;//
		cout<<"-                              **  /                                                                   |  |  *                                             -"<<endl;//
		cout<<"-                              *  *                                                                     \\ |  *                                             -"<<endl;//
		cout<<"-                              *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                           *******                                                                     *         *                                        -"<<endl;//
		cout<<"-                          *********                                                                     **     **                                         -"<<endl;//
		cout<<"-                          *       *                                                                       *****                                           -"<<endl;//
		cout<<"-                          *       *                                                                     /|  *                                             -"<<endl;//
		cout<<"-                           *******                                                                     / |  ****                                          -"<<endl;//
		cout<<"-                              *                                                                       |  | ** *                                           -"<<endl;//
		cout<<"-                             ***                                                                      | *****                                             -"<<endl;//
		cout<<"-                            *****                                                                     *  |  *                                             -"<<endl;//
		cout<<"-                              ***\\                                                                    |  |  *                                             -"<<endl;//
		cout<<"-                              *   *                                                                    \\ |  *                                             -"<<endl;//
		cout<<"-                              *    \\   *                                                                \\| * *                                            -"<<endl;//
		cout<<"-                             ***    *  \\                                                                  *   *                                           -"<<endl;//
		cout<<"-                            *   **   \\  \\                                                                 *   *                                           -"<<endl;//
		cout<<"-                           *     * \\  \\  \\                                                                *                                               -"<<endl;//
		cout<<"-                           *      * \\  \\  \\                                                               *                                               -"<<endl;//
		cout<<"-                           *       * \\  \\  \\                                                                                                              -"<<endl;//
		cout<<"-                                      \\  \\  \\                                                                                                             -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                           *******                                                                     *         *                                        -"<<endl;//
		cout<<"-                          *********                                                                     **     **                                         -"<<endl;//
		cout<<"-                          *       *                                                                       *****                                           -"<<endl;//
		cout<<"-                          *       *                                                                     /|  *                                             -"<<endl;//
		cout<<"-                           *******                                                                     / |  ****                                          -"<<endl;//
		cout<<"-                              *                                                                       |  | ** *                                           -"<<endl;//
		cout<<"-     ___________________*    ***                                                                      | *****                                             -"<<endl;//
		cout<<"-    -                       ****                                                                      *  |  *                                             -"<<endl;//
		cout<<"-   ---------------------*--****                                                                       |  |  *                                             -"<<endl;//
		cout<<"-    -___________________      *                                                                        \\ |  *                                             -"<<endl;//
		cout<<"-                        *     *                                                                         \\| * *                                            -"<<endl;//
		cout<<"-                             ***                                                                          *   *                                           -"<<endl;//
		cout<<"-                            *   *                                                                         *   *                                           -"<<endl;//
		cout<<"-                           *     *                                                                        *                                               -"<<endl;//
		cout<<"-                          *      *                                                                        *                                               -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                    *******                                                            *         *                                        -"<<endl;//
		cout<<"-                                   *********                                                            **     **                                         -"<<endl;//
		cout<<"-                                   *       *                                                              *****                                           -"<<endl;//
		cout<<"-                                   *       *                                                            /|  *                                             -"<<endl;//
		cout<<"-                                    *******                                                            / |  ****                                          -"<<endl;//
		cout<<"-                                       *    *___________________                                      |  | ** *                                           -"<<endl;//
		cout<<"-                                      ***                       -                                     | *****                                             -"<<endl;//
		cout<<"-                                      *****-*---------------------                                    *  |  *                                             -"<<endl;//
		cout<<"-                                       *     ___________________-                                     |  |  *                                             -"<<endl;//
		cout<<"-                                       *    *                                                          \\ |  *                                             -"<<endl;//
		cout<<"-                                       *                                                                \\| * *                                            -"<<endl;//
		cout<<"-                                      ***                                                                 *   *                                           -"<<endl;//
		cout<<"-                                     *   *                                                                *   *                                           -"<<endl;//
		cout<<"-                                     *    *                                                               *                                               -"<<endl;//
		cout<<"-                                     *     *                                                              *                                               -"<<endl;//
		cout<<"-                                     *      *                                                                                                             -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(200);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                                      *******                                          *         *                                        -"<<endl;//
		cout<<"-                                                     *********                                          **     **                                         -"<<endl;//
		cout<<"-                                                     *       *                                            *****                                           -"<<endl;//
		cout<<"-                                                     *       *                                          /|  *                                             -"<<endl;//
		cout<<"-                                                      *******                                          / |  ****                                          -"<<endl;//
		cout<<"-                                                         *                                            |  | ** *                                           -"<<endl;//
		cout<<"-                                ___________________*    ***                                           | *****                                             -"<<endl;//
		cout<<"-                               -                       ****                                           *  |  *                                             -"<<endl;//
		cout<<"-                              ---------------------*--****                                            |  |  *                                             -"<<endl;//
		cout<<"-                               -___________________      *                                             \\ |  *                                             -"<<endl;//
		cout<<"-                                                   *     *                                              \\| * *                                            -"<<endl;//
		cout<<"-                                                        ***                                               *   *                                           -"<<endl;//
		cout<<"-                                                       *   *                                              *   *                                           -"<<endl;//
		cout<<"-                                                      *     *                                             *                                               -"<<endl;//
		cout<<"-                                                     *      *                                             *                                               -"<<endl;//
		cout<<"-                                                    *       *                                                                                             -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(200);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                                                        *******                        *         *                                        -"<<endl;//
		cout<<"-                                                                       *********                        **     **                                         -"<<endl;//
		cout<<"-                                                                       *       *                          *****                                           -"<<endl;//
		cout<<"-                                                                       *       *                        /|  *                                             -"<<endl;//
		cout<<"-                                                                        *******                        / |  ****                                          -"<<endl;//
		cout<<"-                                                                           *    *___________________  |  | ** *                                           -"<<endl;//
		cout<<"-                                                                          ***                       - | *****                                             -"<<endl;//
		cout<<"-                                                                          *****-*---------------------*  |  *                                             -"<<endl;//
		cout<<"-                                                                           *     ___________________- |  |  *                                             -"<<endl;//
		cout<<"-                                                                           *    *                      \\ |  *                                             -"<<endl;//
		cout<<"-                                                                           *                            \\| * *                                            -"<<endl;//
		cout<<"-                                                                          ***                             *   *                                           -"<<endl;//
		cout<<"-                                                                         *   *                            *   *                                           -"<<endl;//
		cout<<"-                                                                         *    *                           *                                               -"<<endl;//
		cout<<"-                                                                         *     *                          *                                               -"<<endl;//
		cout<<"-                                                                         *      *                                                                         -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(200);
		for(int i=1;i<=5;i++){
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
			cout<<"-                                                                                                      **         **                                       -"<<endl;//
			cout<<"-                                                                        *******                        *         *                                        -"<<endl;//
			cout<<"-                                                                       *********                        **     **                                         -"<<endl;//
			cout<<"-                                                                       *       *                          *****                                           -"<<endl;//
			cout<<"-                                                                       *       *                        /|  *                                             -"<<endl;//
			cout<<"-                                                                        *******                        / |  ****                                          -"<<endl;//
			cout<<"-                                                                           *                          |  | ** *                                           -"<<endl;//
			cout<<"-                                                  ___________________*    ***                         | *****                                             -"<<endl;//
			cout<<"-                                                 -                       ****                         *  |  *                                             -"<<endl;//
			cout<<"-                                                ---------------------*--****                          |  |  *                                             -"<<endl;//
			cout<<"-                                                 -___________________      *                           \\ |  *                                             -"<<endl;//
			cout<<"-                                                                     *     *                            \\| * *                                            -"<<endl;//
			cout<<"-                                                                          ***                             *   *                                           -"<<endl;//
			cout<<"-                                                                         *   *                            *   *                                           -"<<endl;//
			cout<<"-                                                                        *     *                           *                                               -"<<endl;//
			cout<<"-                                                                       *      *                           *                                               -"<<endl;//
			cout<<"-                                                                      *       *                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                        !                                                                      *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			Sleep(200);
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                        *********                                         -"<<endl;//
			cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
			cout<<"-                                                                                                      **         **                                       -"<<endl;//
			cout<<"-                                                                          *******                      *         *                                        -"<<endl;//
			cout<<"-                                                                         *********                      **     **                                         -"<<endl;//
			cout<<"-                                                                         *       *                        *****                                           -"<<endl;//
			cout<<"-                                                                         *       *                      /|  *                                             -"<<endl;//
			cout<<"-                                                                          *******                      / |  ****                                          -"<<endl;//
			cout<<"-                                                                             *    *_________________=====| ** *                                           -"<<endl;//
			cout<<"-                                                                            ***                       -===***                                             -"<<endl;//
			cout<<"-                                                                            *****-*---------------------====*                                             -"<<endl;//
			cout<<"-                                                                             *     ___________________-===  *                                             -"<<endl;//
			cout<<"-                                                                             *    *                 ==== |  *                                             -"<<endl;//
			cout<<"-                                                                             *                          \\| * *                                            -"<<endl;//
			cout<<"-                                                                            ***                           *   *                                           -"<<endl;//
			cout<<"-                                                                           *   *                          *   *                                           -"<<endl;//
			cout<<"-                                                                          *     *                         *                                               -"<<endl;//
			cout<<"-                                                                          *      *                        *                                               -"<<endl;//
			cout<<"-                                                                          *       *                                                                       -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                     !  !  !                                                                   *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			Sleep(200);
			}
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                 |                                                                        -"<<endl;//
		cout<<"-                                                                              |  |  |                                                                     -"<<endl;//
		cout<<"-                                                                              |  |  |                                                                     -"<<endl;//
		cout<<"-                                                                              |  |  |                                                                     -"<<endl;//
		cout<<"-                                                                              |  |  |                   *********                                         -"<<endl;//
		cout<<"-                                                                        ******|  |  |                * *********** *                                      -"<<endl;//
		cout<<"-                                                                       *******|  |  |                 **         **                                       -"<<endl;//
		cout<<"-                                                                       *     *   *   *                 *         *                                        -"<<endl;//
		cout<<"-                                                                       *       * |                      **     **                                         -"<<endl;//
		cout<<"-                                                                        *******  *                        *****                                           -"<<endl;//
		cout<<"-                                                                           *   * |                      /|  *                                             -"<<endl;//
		cout<<"-                                                                          ****   *                     / |  ****                                          -"<<endl;//
		cout<<"-                                                                           *                          |  | ** *                                           -"<<endl;//
		cout<<"-                                                                           *                          | *****                                             -"<<endl;//
		cout<<"-                                                                           *                          *  |  *                                             -"<<endl;//
		cout<<"-                                                                           *                          |  |  *                                             -"<<endl;//
		cout<<"-                                                                          ***                          \\ |  *                                             -"<<endl;//
		cout<<"-                                                                         *   *                          \\| * *                                            -"<<endl;//
		cout<<"-                                                                          *   *                           *   *                                           -"<<endl;//
		cout<<"-                                                                          *    *                          *   *                                           -"<<endl;//
		cout<<"-                                                                         *    *                           *                                               -"<<endl;//
		cout<<"-                                                                                                          *                                               -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                             -  -  -  -  -  -  -  -                                                            *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                        *********                                         -"<<endl;//
		cout<<"-                                                                                                     * *********** *                                      -"<<endl;//
		cout<<"-                                                                                                      **         **                                       -"<<endl;//
		cout<<"-                                                                        *******                        *         *                                        -"<<endl;//
		cout<<"-                                                                       *********                        **     **                                         -"<<endl;//
		cout<<"-                                                                       *       *                          *****                                           -"<<endl;//
		cout<<"-                                                                       *       *                  =     /|  *                                             -"<<endl;//
		cout<<"-                                                                        *******                        / |  ****                                          -"<<endl;//
		cout<<"-                                                                           **                =    =   |  | ** *                                           -"<<endl;//
		cout<<"-                                                                          ***                         | =****                                             -"<<endl;//
		cout<<"-                                                                          ***    *_____________=___===*  |  *    =                                        -"<<endl;//
		cout<<"-                                                                           * *            =      ======  |  *                                             -"<<endl;//
		cout<<"-                                                                           **-*--*--------------========= |  *       =                                    -"<<endl;//
		cout<<"-                                                                           *      __________=_____======\\| * *                                            -"<<endl;//
		cout<<"-                                                                          ***    *                      = *   *                                           -"<<endl;//
		cout<<"-                                                                         *   *                  =    =  = *   *                                           -"<<endl;//
		cout<<"-                                                                     * * * *                  =           *                                               -"<<endl;//
		cout<<"-                                                                      *   *                               *                                               -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            ����������ն������                                                                 *     -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                     *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		} 
	if(n==23){//Slime
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        ���๾��...             *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//18* 
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                           *******                                                *                                           *                           -"<<endl;//
		cout<<"-                          *********                                              *            ###               ###            *                          -"<<endl;//
		cout<<"-                          *       *                                             *                                               *                         -"<<endl;//
		cout<<"-                          *       *                                            *                                                 *                        -"<<endl;//
		cout<<"-                           *******                                            *                                                   *                       -"<<endl;//
		cout<<"-                              *                                               *                                                   *                       -"<<endl;//
		cout<<"-                             ***                                              *                                                   *                       -"<<endl;//
		cout<<"-                            * * *                                              *                                                 *                        -"<<endl;//
		cout<<"-                           *  *  *                                              *                                               *                         -"<<endl;//
		cout<<"-                              *                                                  *                                             *                          -"<<endl;//
		cout<<"-                              *                                                   **                                         **                           -"<<endl;//
		cout<<"-                             ***                                                    **                                     **                             -"<<endl;//
		cout<<"-                            *   *                                                     *************************************                               -"<<endl;//
		cout<<"-                           *     *                                                                                                                        -"<<endl;//
		cout<<"-                          *      *                                                                                                                        -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        ���๾��...             *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//18* 
		cout<<"-                                     ������                                         *                                       *                             -"<<endl;//
		cout<<"-                           *******                                                *                                           *                           -"<<endl;//
		cout<<"-                          *********                                              *            ###               ###            *                          -"<<endl;//
		cout<<"-                          *       *                                             *                                               *                         -"<<endl;//
		cout<<"-                          *       *                                            *                                                 *                        -"<<endl;//
		cout<<"-                           *******                                            *                                                   *                       -"<<endl;//
		cout<<"-                              *                                               *                                                   *                       -"<<endl;//
		cout<<"-                             ***                                              *                                                   *                       -"<<endl;//
		cout<<"-                            * * *                                              *                                                 *                        -"<<endl;//
		cout<<"-                           *  *  *                                              *                                               *                         -"<<endl;//
		cout<<"-                      *       *                                                  *                                             *                          -"<<endl;//
		cout<<"-                     **       *                                                   **                                         **                           -"<<endl;//
		cout<<"-                    * *      ***                                                    **                                     **                             -"<<endl;//
		cout<<"-                    *  *    *   *                                                     *************************************                               -"<<endl;//
		cout<<"-                    *   *  *     *     *                                                                                                                  -"<<endl;//
		cout<<"-                      *   *      *    * *                                                                                                                 -"<<endl;//
		cout<<"-                     **  *       *   *  *                                                                                                                 -"<<endl;//
		cout<<"-                     * *                                                                                                                                  -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        ���๾��...             *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                     �� ���屻��������                                *                                   *                               -"<<endl;//18* 
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                           *******                                                *                                           *                           -"<<endl;//
		cout<<"-                          *********                                              *            ###               ###            *                          -"<<endl;//
		cout<<"-                          *       *                                             *                                               *                         -"<<endl;//
		cout<<"-                          *       *                                            *                                                 *                        -"<<endl;//
		cout<<"-                           *******                                            *                                                   *                       -"<<endl;//
		cout<<"-                              *                                               *                                                   *                       -"<<endl;//
		cout<<"-                            *****                                             *                                                   *                       -"<<endl;//
		cout<<"-                        *  ******                                              *                                                 *                        -"<<endl;//
		cout<<"-                     *  *    *****                                              *                                               *                         -"<<endl;//
		cout<<"-                   *  *       ***   *                                            *                                             *                          -"<<endl;//
		cout<<"-                  *  *        *   *   *                                           **                                         **                           -"<<endl;//
		cout<<"-                  *   *      ***    *   *                                           **                                     **                             -"<<endl;//
		cout<<"-                  *    *    *   *    *   *                                            *************************************                               -"<<endl;//
		cout<<"-                  *     *****    *    *   *                                                                                                               -"<<endl;//
		cout<<"-                      *  **      *    *    *                                                                                                              -"<<endl;//
		cout<<"-                     *  **       *   *    *                                                                                                               -"<<endl;//
		cout<<"-                     *  *                                                                                                                                 -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        ���๾��...             *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                     ������ô��� ��                                *                                   *                               -"<<endl;//18* 
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                           *******                                                *                                           *                           -"<<endl;//
		cout<<"-                          *********                                              *            ###               ###            *                          -"<<endl;//
		cout<<"-                          *       *                                             *                                               *                         -"<<endl;//
		cout<<"-                          *       *                                            *                                                 *                        -"<<endl;//
		cout<<"-                           *******   *                                        *                                                   *                       -"<<endl;//
		cout<<"-               *              *       **                                      *                                                   *                       -"<<endl;//
		cout<<"-             **             *****      * *                                    *                                                   *                       -"<<endl;//
		cout<<"-            * *         *  ******      *  *                                    *                                                 *                        -"<<endl;//
		cout<<"-           *  *      *  *    *****     *  *                                     *                                               *                         -"<<endl;//
		cout<<"-           *  *    *  *       ***   *                                            *                                             *                          -"<<endl;//
		cout<<"-                  *   *       *   *   *                                           **                                         **                           -"<<endl;//
		cout<<"-                  *   *      ***    *   *                                           **                                     **                             -"<<endl;//
		cout<<"-                  *    *    *   *    *   *                                            *************************************                               -"<<endl;//
		cout<<"-                  *     *****    *    *   *                                                                                                               -"<<endl;//
		cout<<"-                      *  **      *    *    *                                                                                                              -"<<endl;//
		cout<<"-                     *  **       *   *    *                                                                                                               -"<<endl;//
		cout<<"-                     *  *                                                                                                                                 -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                        ���๾��...             *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                     ��                                               *                                   *                               -"<<endl;//18* 
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                           *******                                                *                                           *                           -"<<endl;//
		cout<<"-                          *********                                              *            ###               ###            *                          -"<<endl;//
		cout<<"-                          *       *                                             *                                               *                         -"<<endl;//
		cout<<"-                      *   *       ** *                                         *                                                 *                        -"<<endl;//
		cout<<"-                       *** ******* ** *                                       *                                                   *                       -"<<endl;//
		cout<<"-                   * *  ***   *  *   *   *                                    *                                                   *                       -"<<endl;//
		cout<<"-                 *     *    *****      *   *                                  *                                                   *                       -"<<endl;//
		cout<<"-               *    *   *  ******       *    *                                 *                                                 *                        -"<<endl;//
		cout<<"-            *    *   *  *    ******      *     *                                *                                               *                         -"<<endl;//
		cout<<"-                   *  *       ***   *                                            *                                             *                          -"<<endl;//
		cout<<"-                  *  *        *   *   *                                           **                                         **                           -"<<endl;//
		cout<<"-                  *   *      ***    *   *                                           **                                     **                             -"<<endl;//
		cout<<"-                  *    *    *   *    *   *                                            *************************************                               -"<<endl;//
		cout<<"-                  *     *****    *    *   *                                                                                                               -"<<endl;//
		cout<<"-                      *  **      *    *    *                                                                                                              -"<<endl;//
		cout<<"-                     *  **       *   *    *                                                                                                               -"<<endl;//
		cout<<"-                     *  *                                                                                                                                 -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-              �� �������ѿ���           / / /                                         *                                   *                               -"<<endl;//
		cout<<"-                                       /   / /                                      *                                       *                             -"<<endl;//
		cout<<"-                           *******    /   /   /                                   *                                           *                           -"<<endl;//
		cout<<"-                          *********  /   /   /                                   *          ###                  ###           *                          -"<<endl;//
		cout<<"-                          *       * /   /   /                                   *                                               *                         -"<<endl;//
		cout<<"-                          *       */   /   /                                   *                                                 *                        -"<<endl;//
		cout<<"-                           *******/   /   /                                   *                                                   *                       -"<<endl;//
		cout<<"-                              * *    /   /                                    *                                                   *                       -"<<endl;//
		cout<<"-                             ***    *   /                                     *                                                   *                       -"<<endl;//
		cout<<"-                            ********    *                                      *                                                 *                        -"<<endl;//
		cout<<"-                              **  /                                             *                                               *                         -"<<endl;//
		cout<<"-                              *  *                                               *                                             *                          -"<<endl;//
		cout<<"-                              *                                                   **                                         **                           -"<<endl;//
		cout<<"-                             ***                                                    **                                     **                             -"<<endl;//
		cout<<"-                            *   *                                                     *************************************                               -"<<endl;//
		cout<<"-                           *     *                                                                                                                        -"<<endl;//
		cout<<"-                          *      *                                                                                                                        -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                              �㱻Slime������                                                                  *     -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                     *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==24){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  **************                           **************                                                 -"<<endl;//
		cout<<"-                                                *************        *****************        ************                                                -"<<endl;//
		cout<<"-                                            ***************     *                         *     **************                                            -"<<endl;//
		cout<<"-                                          ***************    *                               *    **************                                          -"<<endl;//
		cout<<"-                                        ****************   *                                   *   ****************                                       -"<<endl;//
		cout<<"-                                        ***************  *                                       *  ***************                                       -"<<endl;//
		cout<<"-                                        **************  *          ###               ###          *  **************                                       -"<<endl;//
		cout<<"-                                        *************  *                                           *  *************                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-                                                     *                                               *                                                    -"<<endl;//
		cout<<"-                                                     *                                               *                                                    -"<<endl;//
		cout<<"-                                                     *                                               *                                                    -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-                                                       *                                           *                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                         **                                     **                                                        -"<<endl;//
		cout<<"-                                                           **                                 **                                                          -"<<endl;//
		cout<<"-                                                          *  *********************************  *                                                         -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                           BOSS <Slime> �����ˣ�����                                                           *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==25){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  **************                           **************                                                 -"<<endl;//
		cout<<"-                                                *************        *****************        ************                                                -"<<endl;//
		cout<<"-                                            ***************     *                         *     **************                                            -"<<endl;//
		cout<<"-                                          ***************    *                               *    **************                                          -"<<endl;//
		cout<<"-                                        ****************   *                                   *   ****************                                       -"<<endl;//
		cout<<"-                                        ***************  *                                       *  ***************                                       -"<<endl;//
		cout<<"-                                        **************  *          ###               ###          *  **************                                       -"<<endl;//
		cout<<"-                                        *************  *                                           *  *************                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-                                                     *                                               *                                                    -"<<endl;//
		cout<<"-                                                     *                                               *                                                    -"<<endl;//
		cout<<"-                                                     *                                               *                                                    -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-                                                       *                                           *                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                         **                                     **                                                        -"<<endl;//
		cout<<"-                                                           **                                 **                                                          -"<<endl;//
		cout<<"-                                                          *  *********************************  *                                                         -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                              �㲻�ֵܵ�Slime�Ĺ���                                                            *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==26){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                        / / /                                         *                                   *                               -"<<endl;//
		cout<<"-                                       /   / /                                      *                                       *                             -"<<endl;//
		cout<<"-                           *******    /   /   /                                   *                                           *                           -"<<endl;//
		cout<<"-                          *********  /   /   /                                   *          ###                  ###           *                          -"<<endl;//
		cout<<"-                          *       * /   /   /                                   *                                               *                         -"<<endl;//
		cout<<"-                          *       */   /   /                                   *                                                 *                        -"<<endl;//
		cout<<"-                           *******/   /   /                                   *                                                   *                       -"<<endl;//
		cout<<"-                              * *    /   /                                    *                                                   *                       -"<<endl;//
		cout<<"-                             ***    *   /                                     *                                                   *                       -"<<endl;//
		cout<<"-                            ********    *                                      *                                                 *                        -"<<endl;//
		cout<<"-                              **  /                                             *                                               *                         -"<<endl;//
		cout<<"-                              *  *                                               *                                             *                          -"<<endl;//
		cout<<"-                              *                                                   **                                         **                           -"<<endl;//
		cout<<"-                             ***                                                    **                                     **                             -"<<endl;//
		cout<<"-                            *   *                                                     *************************************                               -"<<endl;//
		cout<<"-                           *     *                                                                                                                        -"<<endl;//
		cout<<"-                          *      *                                                                                                                        -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                                                                *******           *                                           *                           -"<<endl;//
		cout<<"-                                                               *********         *          ###                  ###           *                          -"<<endl;//
		cout<<"-                                                               *       *        *                                               *                         -"<<endl;//
		cout<<"-                                -                              *       *       *                                                 *                        -"<<endl;//
		cout<<"-                                                                *******       *                                                   *                       -"<<endl;//
		cout<<"-               -                                                   *          *                                                   *                       -"<<endl;//
		cout<<"-                                                                  ***         *                                                   *                       -"<<endl;//
		cout<<"-                     -                  ____________________*    ***           *                                                 *                        -"<<endl;//
		cout<<"-                                       -                        *  *            *                                               *                         -"<<endl;//
		cout<<"-                                      ----------------------*--*-* *             *                                             *                          -"<<endl;//
		cout<<"-             -                         -____________________       *              **                                         **                           -"<<endl;//
		cout<<"-                                                            *     ***               **                                     **                             -"<<endl;//
		cout<<"-                            -                                    *   *                *************************************                               -"<<endl;//
		cout<<"-                                                                *     *                                                                                   -"<<endl;//
		cout<<"-                                                               *      *                                                                                   -"<<endl;//
		cout<<"-                                                              *       *                                                                                   -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                                                              *******             *                                           *                           -"<<endl;//
		cout<<"-                                                             *********           *          ###                  ###           *                          -"<<endl;//
		cout<<"-                                                             *       *          *                                               *                         -"<<endl;//
		cout<<"-                                                             *       *         *      ======                                     *                        -"<<endl;//
		cout<<"-                                                              ******* *____________________===                                    *                       -"<<endl;//
		cout<<"-                                                                 *                         -====                                  *                       -"<<endl;//
		cout<<"-                                                               ******-*----------------------======                               *                       -"<<endl;//
		cout<<"-                                                                ***    ____________________-====                                 *                        -"<<endl;//
		cout<<"-                                                                 *    *         *   =========                                   *                         -"<<endl;//
		cout<<"-                                                                 *               *    ==                                       *                          -"<<endl;//
		cout<<"-                                                                 *                **                                         **                           -"<<endl;//
		cout<<"-                                                                ***                 **                                     **                             -"<<endl;//
		cout<<"-                                                               *   *                  *************************************                               -"<<endl;//
		cout<<"-                                                              *     *                                                                                     -"<<endl;//
		cout<<"-                                                             *      *                                                                                     -"<<endl;//
		cout<<"-                                                            *       *                                                                                     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                ������Slime��                                                                  *     -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                     *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==27){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                        / / /                                         *                                   *                               -"<<endl;//
		cout<<"-                                       /   / /                                      *                                       *                             -"<<endl;//
		cout<<"-                           *******    /   /   /                                   *                                           *                           -"<<endl;//
		cout<<"-                          *********  /   /   /                                   *          ###                  ###           *                          -"<<endl;//
		cout<<"-                          *       * /   /   /                                   *                                               *                         -"<<endl;//
		cout<<"-                          *       */   /   /                                   *                                                 *                        -"<<endl;//
		cout<<"-                           *******/   /   /                                   *                                                   *                       -"<<endl;//
		cout<<"-                              * *    /   /                                    *                                                   *                       -"<<endl;//
		cout<<"-                             ***    *   /                                     *                                                   *                       -"<<endl;//
		cout<<"-                            ********    *                                      *                                                 *                        -"<<endl;//
		cout<<"-                              **  /                                             *                                               *                         -"<<endl;//
		cout<<"-                              *  *                                               *                                             *                          -"<<endl;//
		cout<<"-                              *                                                   **                                         **                           -"<<endl;//
		cout<<"-                             ***                                                    **                                     **                             -"<<endl;//
		cout<<"-                            *   *                                                     *************************************                               -"<<endl;//
		cout<<"-                           *     *                                                                                                                        -"<<endl;//
		cout<<"-                          *      *                                                                                                                        -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                                                                *******           *                                           *                           -"<<endl;//
		cout<<"-                                                               *********         *          ###                  ###           *                          -"<<endl;//
		cout<<"-                                                               *       *        *                                               *                         -"<<endl;//
		cout<<"-                                -                              *       *       *                                                 *                        -"<<endl;//
		cout<<"-                                                                *******       *                                                   *                       -"<<endl;//
		cout<<"-               -                                                   *          *                                                   *                       -"<<endl;//
		cout<<"-                                                                  ***         *                                                   *                       -"<<endl;//
		cout<<"-                     -                  ____________________*    ***           *                                                 *                        -"<<endl;//
		cout<<"-                                       -                        *  *            *                                               *                         -"<<endl;//
		cout<<"-                                      ----------------------*--*-* *             *                                             *                          -"<<endl;//
		cout<<"-             -                         -____________________       *              **                                         **                           -"<<endl;//
		cout<<"-                                                            *     ***               **                                     **                             -"<<endl;//
		cout<<"-                            -                                    *   *                *************************************                               -"<<endl;//
		cout<<"-                                                                *     *                                                                                   -"<<endl;//
		cout<<"-                                                               *      *                                                                                   -"<<endl;//
		cout<<"-                                                              *       *                                                                                   -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                                                              *******             *                                           *                           -"<<endl;//
		cout<<"-                                                             *********           *          ###                  ###           *                          -"<<endl;//
		cout<<"-                                                             *       *          *                                               *                         -"<<endl;//
		cout<<"-                                                             *       *         *      ======                                     *                        -"<<endl;//
		cout<<"-                                                              ******* *____________________===                                    *                       -"<<endl;//
		cout<<"-                                                                 *                         -====                                  *                       -"<<endl;//
		cout<<"-                                                               ******-*----------------------======                               *                       -"<<endl;//
		cout<<"-                                                                ***    ____________________-====                                 *                        -"<<endl;//
		cout<<"-                                                                 *    *         *   =========                                   *                         -"<<endl;//
		cout<<"-                                                                 *               *    ==                                       *                          -"<<endl;//
		cout<<"-                                                                 *                **                                         **                           -"<<endl;//
		cout<<"-                                                                ***                 **                                     **                             -"<<endl;//
		cout<<"-                                                               *   *                  *************************************                               -"<<endl;//
		cout<<"-                                                              *     *                                                                                     -"<<endl;//
		cout<<"-                                                             *      *                                                                                     -"<<endl;//
		cout<<"-                                                            *       *                                                                                     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                �ػ���Slime��                                                                  *     -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                     *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==28){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                        / / /                                         *                                   *                               -"<<endl;//
		cout<<"-                                       /   / /                                      *                                       *                             -"<<endl;//
		cout<<"-                           *******    /   /   /                                   *                                           *                           -"<<endl;//
		cout<<"-                          *********  /   /   /                                   *          ###                  ###           *                          -"<<endl;//
		cout<<"-                          *       * /   /   /                                   *                                               *                         -"<<endl;//
		cout<<"-                          *       */   /   /                                   *                                                 *                        -"<<endl;//
		cout<<"-                           *******/   /   /                                   *                                                   *                       -"<<endl;//
		cout<<"-                              * *    /   /                                    *                                                   *                       -"<<endl;//
		cout<<"-                             ***    *   /                                     *                                                   *                       -"<<endl;//
		cout<<"-                            ********    *                                      *                                                 *                        -"<<endl;//
		cout<<"-                              **  /                                             *                                               *                         -"<<endl;//
		cout<<"-                              *  *                                               *                                             *                          -"<<endl;//
		cout<<"-                              *                                                   **                                         **                           -"<<endl;//
		cout<<"-                             ***                                                    **                                     **                             -"<<endl;//
		cout<<"-                            *   *                                                     *************************************                               -"<<endl;//
		cout<<"-                           *     *                                                                                                                        -"<<endl;//
		cout<<"-                          *      *                                                                                                                        -"<<endl;//
		cout<<"-                         *       *                                                                                                                        -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                                                                *******           *                                           *                           -"<<endl;//
		cout<<"-                                                               *********         *          ###                  ###           *                          -"<<endl;//
		cout<<"-             -                                                 *       *        *                                               *                         -"<<endl;//
		cout<<"-                                -                              *       *       *                                                 *                        -"<<endl;//
		cout<<"-                                                                *******       *                                                   *                       -"<<endl;//
		cout<<"-               -                           -                       *          *                                                   *                       -"<<endl;//
		cout<<"-                                                       -          ***         *                                                   *                       -"<<endl;//
		cout<<"-                     -                  ____________________*    ***           *                                                 *                        -"<<endl;//
		cout<<"-        -                              -                        *  *            *                                               *                         -"<<endl;//
		cout<<"-                                      ----------------------*--*-* *             *                                             *                          -"<<endl;//
		cout<<"-                     -                 -____________________       *              **                                         **                           -"<<endl;//
		cout<<"-                                                            *     ***               **                                     **                             -"<<endl;//
		cout<<"-                            -                                    *   *                *************************************                               -"<<endl;//
		cout<<"-            -                           -                       *     *                                                                                   -"<<endl;//
		cout<<"-                                                               *      *                                                                                   -"<<endl;//
		cout<<"-                                                              *       *                                                                                   -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(500);
		for(int i=1;i<=5;i++){
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                *****************                                         -"<<endl;//
			cout<<"-                                                                                           *                         *                                    -"<<endl;//
			cout<<"-                                                                                        *                               *                                 -"<<endl;//
			cout<<"-                                                                                      *                                   *                               -"<<endl;//
			cout<<"-                                                                                    *                                       *                             -"<<endl;//
			cout<<"-                                                                *******           *                                           *                           -"<<endl;//
			cout<<"-                                                               *********         *          ###                  ###           *                          -"<<endl;//
			cout<<"-                                                               *       *        *                                               *                         -"<<endl;//
			cout<<"-                                -                              *       *       *                                                 *                        -"<<endl;//
			cout<<"-                                                                *******       *                                                   *                       -"<<endl;//
			cout<<"-               -                                                   *          *                                                   *                       -"<<endl;//
			cout<<"-                                                                  ***         *                                                   *                       -"<<endl;//
			cout<<"-                     -                  ____________________*    ***           *                                                 *                        -"<<endl;//
			cout<<"-                                       -                        *  *            *                                               *                         -"<<endl;//
			cout<<"-                                      ----------------------*--*-* *             *                                             *                          -"<<endl;//
			cout<<"-             -                         -____________________       *              **                                         **                           -"<<endl;//
			cout<<"-                                                            *     ***               **                                     **                             -"<<endl;//
			cout<<"-                            -                                    *   *                *************************************                               -"<<endl;//
			cout<<"-                                                                *     *                                                                                   -"<<endl;//
			cout<<"-                                                               *      *                                                                                   -"<<endl;//
			cout<<"-                                                              *       *                                                                                   -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                     ��                                                                        *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			Sleep(200);
			CLS;
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-                                                                                                *****************                                         -"<<endl;//
			cout<<"-                                                                                           *                         *                                    -"<<endl;//
			cout<<"-                                                                                        *                               *                                 -"<<endl;//
			cout<<"-                                                                                      *                                   *                               -"<<endl;//
			cout<<"-                                                                                    *                                       *                             -"<<endl;//
			cout<<"-                                                              *******             *                                           *                           -"<<endl;//
			cout<<"-                                                             *********           *          ###                  ###           *                          -"<<endl;//
			cout<<"-                                                             *       *          *                                               *                         -"<<endl;//
			cout<<"-                                                             *       *         *      ======                                     *                        -"<<endl;//
			cout<<"-                                                              ******* *____________________===                                    *                       -"<<endl;//
			cout<<"-                                                                 *                         -====                                  *                       -"<<endl;//
			cout<<"-                                                               ******-*----------------------======                               *                       -"<<endl;//
			cout<<"-                                                                ***    ____________________-====                                 *                        -"<<endl;//
			cout<<"-                                                                 *    *         *   =========                                   *                         -"<<endl;//
			cout<<"-                                                                 *               *    ==                                       *                          -"<<endl;//
			cout<<"-                                                                 *                **                                         **                           -"<<endl;//
			cout<<"-                                                                ***                 **                                     **                             -"<<endl;//
			cout<<"-                                                               *   *                  *************************************                               -"<<endl;//
			cout<<"-                                                              *     *                                                                                     -"<<endl;//
			cout<<"-                                                             *      *                                                                                     -"<<endl;//
			cout<<"-                                                            *       *                                                                                     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                   ������                                                                      *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *                                                                                                                                               *     -"<<endl;//
			cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
			cout<<"-                                                                                                                                                          -"<<endl;//
			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
			Sleep(200);
			}
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                       |                                                                                  -"<<endl;//
		cout<<"-                                                                    |  |  |                                                                               -"<<endl;//
		cout<<"-                                                                    |  |  |                     *****************                                         -"<<endl;//
		cout<<"-                                                                    |  |  |                *                         *                                    -"<<endl;//
		cout<<"-                                                                    |  |  |             *                               *                                 -"<<endl;//
		cout<<"-                                                              ******|  |  |           *                                   *                               -"<<endl;//
		cout<<"-                                                             *******|  |  |         *                                       *                             -"<<endl;//
		cout<<"-                                                             *     *   *   *      *                                           *                           -"<<endl;//
		cout<<"-                                                             *       * |         *          ###                  ###           *                          -"<<endl;//
		cout<<"-                                                              *******  *        *                                               *                         -"<<endl;//
		cout<<"-                                                                 *   * |       *                                                 *                        -"<<endl;//
		cout<<"-                                                                ****   *      *                                                   *                       -"<<endl;//
		cout<<"-                                                                 *            *                                                   *                       -"<<endl;//
		cout<<"-                                                                 *            *                                                   *                       -"<<endl;//
		cout<<"-                                                                 *             *                                                 *                        -"<<endl;//
		cout<<"-                                                                 *              *                                               *                         -"<<endl;//
		cout<<"-                                                                ***              *                                             *                          -"<<endl;//
		cout<<"-                                                               *   *              **                                         **                           -"<<endl;//
		cout<<"-                                                                *   *               **                                     **                             -"<<endl;//
		cout<<"-                                                               *   *                  *************************************                               -"<<endl;//
		cout<<"-                                                              *   *                                                                                       -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                             -  -  -  -  -  -  -  -                                                            *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                *****************                                         -"<<endl;//
		cout<<"-                                                                                           *                         *                                    -"<<endl;//
		cout<<"-                                                                                        *                               *                                 -"<<endl;//
		cout<<"-                                                                                      *                                   *                               -"<<endl;//
		cout<<"-                                                                                    *                                       *                             -"<<endl;//
		cout<<"-                                                              *******             *                                           *                           -"<<endl;//
		cout<<"-                                                             *********           *          ###                  ###           *                          -"<<endl;//
		cout<<"-                                                             *       *          *                                               *                         -"<<endl;//
		cout<<"-                                                             *       *         *      =                                          *                        -"<<endl;//
		cout<<"-                                                              *******         *               =                                   *                       -"<<endl;//
		cout<<"-                                                                 **           * *         =                                       *                       -"<<endl;//
		cout<<"-                                                                ***           *       =       =   =                               *                       -"<<endl;//
		cout<<"-                                                                ***    *_________*______=_=====     =                            *                        -"<<endl;//
		cout<<"-                                                                 * *                  =      -==                                *                         -"<<endl;//
		cout<<"-                                                                 **-*--*-----------------------===                             *                          -"<<endl;//
		cout<<"-                                                                *       _______________=_____-==   =                         **                           -"<<endl;//
		cout<<"-                                                                ***    *           **   = ==== =                           **                             -"<<endl;//
		cout<<"-                                                               *   *                 **************************************                               -"<<endl;//
		cout<<"-                                                           * * * *                                                                                        -"<<endl;//
		cout<<"-                                                            *   *                                                                                         -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                            ����������ն������                                                                 *     -"<<endl;//
		cout<<"-    *                                                                   <"<<a<<">\t                                                                     *    -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==29){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *        ���ء�       *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                 �ҵ��ˣ����ͣ�                                                                *     -"<<endl;//
		cout<<"-    *                                                                   Ϳ�ڽ���                                                                    *     -"<<endl;//
		cout<<"-    *                                                                  <������+3>                                                                   *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==30){
		CLS;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
		cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
		cout<<"-                                                    ***************************************************                                                   -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                  *******************************************************                                                 -"<<endl;//
		cout<<"-                                                **********************************************************                                                -"<<endl;//
		cout<<"-                                            ******************************************************************                                            -"<<endl;//
		cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
		cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||      *        ���ء�       *      |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
		cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
		cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
		cout<<"-                                                        *                                         *                                                       -"<<endl;//
		cout<<"-                                                      *                                             *                                                     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *                                                                �ҵ��ˣ�ʥ��ˮ��                                                               *     -"<<endl;//
		cout<<"-    *                                                                    ����ȥ                                                                     *     -"<<endl;//
		cout<<"-    *                                                                   <Ѫ��+30>                                                                   *     -"<<endl;//
		cout<<"-    *                                                                                                                                               *     -"<<endl;//
		cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
		cout<<"-                                                                                                                                                          -"<<endl;//
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	
	}

void Demo(){
	//Demo
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-    *****   *   *    *     *   *  *   *  *****       *****  *****  *****     -"<<endl;//
	cout<<"-      *     *   *   * *    **  *  *  *   *           *      *   *  *   *     -"<<endl;//
	cout<<"-      *     *****  *****   * * *  ***    *****       ***    *   *  *****     -"<<endl;//
	cout<<"-      *     *   *  *   *   *  **  *  *       *       *      *   *  *  *      -"<<endl;//
	cout<<"-      *     *   *  *   *   *   *  *   *  *****       *      *****  *   *     -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-              *****  *        *    *   *  *****   *   *  *****               -"<<endl;//
	cout<<"-              *   *  *       * *    * *     *     **  *  *                   -"<<endl;//
	cout<<"-              *****  *      *****    *      *     * * *  *  **               -"<<endl;//
	cout<<"-              *      *      *   *    *      *     *  **  *   *               -"<<endl;//
	cout<<"-              *      *****  *   *    *    *****   *   *  *****               -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                 Demo Over                                   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;	
	} 

void Bought_z(){
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-    *****   *   *    *     *   *  *   *  *****       *****  *****  *****     -"<<endl;//
	cout<<"-      *     *   *   * *    **  *  *  *   *           *      *   *  *   *     -"<<endl;//
	cout<<"-      *     *****  *****   * * *  ***    *****       ***    *   *  *****     -"<<endl;//
	cout<<"-      *     *   *  *   *   *  **  *  *       *       *      *   *  *  *      -"<<endl;//
	cout<<"-      *     *   *  *   *   *   *  *   *  *****       *      *****  *   *     -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-              *****  *        *    *   *  *****   *   *  *****               -"<<endl;//
	cout<<"-              *   *  *       * *    * *     *     **  *  *                   -"<<endl;//
	cout<<"-              *****  *      *****    *      *     * * *  *  **               -"<<endl;//
	cout<<"-              *      *      *   *    *      *     *  **  *   *               -"<<endl;//
	cout<<"-              *      *****  *   *    *    *****   *   *  *****               -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                              �빺��ʣ���½�                                 -"<<endl;//
	cout<<"-                          (��ʵ���һ�ûд��www)                              -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;	
	} 

void Input_Name(){
	//Input_Name
	CLS;
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                                                                               "<<endl;//
	cout<<"                               �������������:                                 "<<endl;//
	cout<<"                               ";//
	cin.getline(Hero.name,16);
	Hero.name_len=strlen(Hero.name);
	}
void Output_Name(){
	if(Hero.name_len<=4)
		cout<<"-    *    "<<Hero.name<<":\t                                                                                                                                     *     -"<<endl;//
	if(Hero.name_len>=5 && Hero.name_len<=11)
		cout<<"-    *    "<<Hero.name<<":\t                                                                                                                             *     -"<<endl;//
	if(Hero.name_len>=12 && Hero.name_len<=15)
		cout<<"-    *    "<<Hero.name<<":\t                                                                                                                     *     -"<<endl;//
	}
void Hide_Cur(){
	CONSOLE_CURSOR_INFO cur=(CONSOLE_CURSOR_INFO){1,0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cur);
	}

void CG_0(){
	//��һ�� 
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                       ����                                                  -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                ���µ����                                   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_1
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-             ******                                                          -"<<endl;//
	cout<<"-         ****      *******                           *****                   -"<<endl;//
	cout<<"-      ***                 *                         *******                  -"<<endl;//
	cout<<"-       *****           ***                          **   **                  -"<<endl;//
	cout<<"-            ***********                      **     *** ***                  -"<<endl;//
	cout<<"-                                            *  *      * *                    -"<<endl;//
	cout<<"-                                             *       ** **                   -"<<endl;//
	cout<<"-                                              *    **     **                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Niya>��֪:                                                        *   -"<<endl;//
	cout<<"-   *        ......                                                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *  <Niya>  :  <���>                                                  *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_2
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-              ******                                                         -"<<endl;//
	cout<<"-          ****      *******                          *****                   -"<<endl;//
	cout<<"-       ***                 *                        *******                  -"<<endl;//
	cout<<"-        *****           ***                         **   **                  -"<<endl;//
	cout<<"-             ***********                     **     *** ***                  -"<<endl;//
	cout<<"-                                            *  *      * *                    -"<<endl;//
	cout<<"-                                             *       ** **                   -"<<endl;//
	cout<<"-                                              *    **     **                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Niya>��֪:                                                        *   -"<<endl;//
	cout<<"-   *        һǧ����...                                                  *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_3
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-               ******                                                        -"<<endl;//
	cout<<"-           ****      *******                         *****                   -"<<endl;//
	cout<<"-        ***                 *                       *******                  -"<<endl;//
	cout<<"-         *****           ***                        **   **                  -"<<endl;//
	cout<<"-              ***********                    **     *** ***                  -"<<endl;//
	cout<<"-                                            *  *      * *                    -"<<endl;//
	cout<<"-                                             *       ** **                   -"<<endl;//
	cout<<"-                                              *    **     **                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              ******       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-                                              *    *       *                 -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Niya>��֪:                                                        *   -"<<endl;//
	cout<<"-   *        ����...������...                                             *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_4
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                 *************************           ���߾�����;���棬      -"<<endl;//
	cout<<"-                   *    DE il Ho  e    *             ���ڵ�����Ken City      -"<<endl;//
	cout<<"-             *********************************       ��Χ�����е�����      -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-           *************************************                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      Ŷ�������ҵ��ˣ�                                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *  <Isaac> : <����>                                                   *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_5
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                 *************************                                   -"<<endl;//
	cout<<"-                   *    DE il Ho  e    *                                     -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-           *************************************                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      ��˵�������Ϲ������ı��أ�                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_6
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                 *************************                                   -"<<endl;//
	cout<<"-                   *    DE il Ho  e    *                                     -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-               *                           *                                 -"<<endl;//
	cout<<"-             *********************************                               -"<<endl;//
	cout<<"-           *************************************                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      �ҵ��Ļ��Ϳ��԰�ѧԺ�����������һ�����Ρ�                     *   -"<<endl;//
	cout<<"-   *      ��Ϊ������½����ѧԺ��                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_7
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      ����������еĺ�һ��...                                        *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	CG_0_Maze();
	
	//Maze_8
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =     =       =                                -"<<endl;//
	cout<<"-                      =       =-----=       =                                -"<<endl;//
	cout<<"-                      =      - - - - -      =                                -"<<endl;//
	cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
	cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
	cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      ǰ����������⡣                                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_9
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =       =  ����� =       =                             -"<<endl;//
	cout<<"-                     =       =  *=+=*  =       =                             -"<<endl;//
	cout<<"-                     =       =  *   *  =       =                             -"<<endl;//
	cout<<"-                     =       =  *****  =       =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      Ŷ������Ǳ��أ�                                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_10
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =   ͻȻ���ϵ�ʬ��վ��������  -"<<endl;//
	cout<<"-                     =               ^         =   ��ԭ���Ǳ���ħͬ���Ĺ���  -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =       __   *  |         =                             -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =                             -"<<endl;//
	cout<<"-                     =      |/\\|  *  |         =                             -"<<endl;//
	cout<<"-                     =       \\/   *            =                             -"<<endl;//
	cout<<"-                     =           ***           =                             -"<<endl;//
	cout<<"-                     =    -      * *      -    =                             -"<<endl;//
	cout<<"-                     =  -    -   * *   -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  ����˻����:                                                        *   -"<<endl;//
	cout<<"-   *          �򰡰���                                                   *   -"<<endl;//
	cout<<"-   *                       <����սʿ>����!                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_11
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =               ^         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =       __   *  |         =                             -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =                             -"<<endl;//
	cout<<"-                     =      |/\\|  *  |         =                             -"<<endl;//
	cout<<"-                     =       \\/   *            =                             -"<<endl;//
	cout<<"-                     =           ***           =                             -"<<endl;//
	cout<<"-                     =    -      * *      -    =                             -"<<endl;//
	cout<<"-                     =  -    -   * *   -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      ������                                                         *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_12
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =               ^         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =       __   *  |         =                             -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =                             -"<<endl;//
	cout<<"-                     =      |/\\|  *  |         =                             -"<<endl;//
	cout<<"-                     =       \\/   *            =                             -"<<endl;//
	cout<<"-                     =           ***           =                             -"<<endl;//
	cout<<"-                     =    -      * *      -    =                             -"<<endl;//
	cout<<"-                     =  -    -   * *   -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>��������:                                                   *   -"<<endl;//
	cout<<"-   *            һֻ����ħ��Ⱦ��ʬ�壿                                   *   -"<<endl;//
	cout<<"-   *            ��ֻ�ð�������ˣ�                                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Maze_13
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =               ^         =                             -"<<endl;//
	cout<<"-                     =           *** |         =                             -"<<endl;//
	cout<<"-                     =           *** |         =       /                     -"<<endl;//
	cout<<"-                     =       __   *  |         =      /                      -"<<endl;//
	cout<<"-                     =      |\\/|*****|         =     /                       -"<<endl;//
	cout<<"-                     =      |/\\|  *  |              /                        -"<<endl;//
	cout<<"-                     =       \\/   *                /                         -"<<endl;//
	cout<<"-                     =           ***           *  /                          -"<<endl;//
	cout<<"-                     =    -      * *            *+*                          -"<<endl;//
	cout<<"-                     =  -    -   * *   -        *  *                         -"<<endl;//
	cout<<"-                     =-     -     -     -      *                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                 ���ó���ѧԺ����ĸ�ħ����                          *   -"<<endl;//
	cout<<"-   *                          <����+30>                                  *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	//Hero.dmg+=30;
	PAUSE;
	
	Fight(1);
	
	if(Hero.hp<=0){
		return;
		}
	
	//CG_0_14
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =       =  ����� =       =                             -"<<endl;//
	cout<<"-                     =       =  *=+=*  =       =                             -"<<endl;//
	cout<<"-                     =       =  *   *  =       =                             -"<<endl;//
	cout<<"-                     =       =  *****  =       =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      �������ա�����ɱ�����ˡ�                                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =       =  ����� =       =                             -"<<endl;//
	cout<<"-                     =       =  *=+=*  =       =                             -"<<endl;//
	cout<<"-                     =       =  *   *  =       =                             -"<<endl;//
	cout<<"-                     =       =  *****  =       =                             -"<<endl;//
	cout<<"-                     =       =- - - - -=       =                             -"<<endl;//
	cout<<"-                     =      -  -  -  -  -      =                             -"<<endl;//
	cout<<"-                     =    -   -   -   -   -    =                             -"<<endl;//
	cout<<"-                     =  -    -    -    -    -  =                             -"<<endl;//
	cout<<"-                     =-     -     -     -     -=                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *      ���ڸÿ�����������ʲô���ɲ�Ҫ����ʧ����                       *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                      * * * * * * * * * * * * * * *                          -"<<endl;//
	cout<<"-                    **************************      *                        -"<<endl;//
	cout<<"-                      *                        *     *                       -"<<endl;//
	cout<<"-                        *                        *   *                       -"<<endl;//
	cout<<"-                         **                       **                         -"<<endl;//
	cout<<"-                         **************************                          -"<<endl;//
	cout<<"-                        *                        **                          -"<<endl;//
	cout<<"-                       *                        * *                          -"<<endl;//
	cout<<"-                      *                        *  *                          -"<<endl;//
	cout<<"-                     **************************   *                          -"<<endl;//
	cout<<"-                     *                        *  *                           -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                              ���ꡣ                                 *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                             **************************                      -"<<endl;//
	cout<<"-                            *                        * *                     -"<<endl;//
	cout<<"-                           *                        *  *                     -"<<endl;//
	cout<<"-                          *                        *  *                      -"<<endl;//
	cout<<"-                         *************************** *                       -"<<endl;//
	cout<<"-                        *                        **                          -"<<endl;//
	cout<<"-                       *                        * *                          -"<<endl;//
	cout<<"-                      *                        *  *                          -"<<endl;//
	cout<<"-                     **************************   *                          -"<<endl;//
	cout<<"-                     *                        *  *                           -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                              ������                                 *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                ___                          -"<<endl;//
	cout<<"-                                               |   |                         -"<<endl;//
	cout<<"-                 ******************************|   |                         -"<<endl;//
	cout<<"-               **                              |\\|/|_*****_#                 -"<<endl;//
	cout<<"-             **--------------------------------|-+- _*   *_##                -"<<endl;// 
	cout<<"-               **                              |/|\\| ***** #                 -"<<endl;//
	cout<<"-                 ******************************|   |  * *                    -"<<endl;//
	cout<<"-                          * *                  |___|  * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                  ��ӱ����￸����һ�ѳ��صĴ�                     *   -"<<endl;//
	cout<<"-   *               �󽣽������Ϸ���Ƕ��һö����ɫ�ı�ʯ                  *   -"<<endl;//
	cout<<"-   *                  ��ʯ�ڻ谵�ķ����з�������Ĺ�â                   *   -"<<endl;//
	cout<<"-   *                          ��ɢ������ĺڰ�                           *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                ___                          -"<<endl;//
	cout<<"-                                               |   |                         -"<<endl;//
	cout<<"-                 ******************************|   |                         -"<<endl;//
	cout<<"-               **  ~       -   ~      -    ~   |   |_*****_#                 -"<<endl;//
	cout<<"-             **--------------------------------|[+] _*   *_##                -"<<endl;// 
	cout<<"-               **     -  ~   -       ~   -   - |   | ***** #                 -"<<endl;//
	cout<<"-                 ******************************|   |  * *                    -"<<endl;//
	cout<<"-                          * *                  |___|  * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                       �����Ͽ���Զ�ŵĻ���                          *   -"<<endl;//
	cout<<"-   *                          ��Ȼ���⼣�߰�                             *   -"<<endl;//
	cout<<"-   *                   ����֪�����ⲻ��һ����ͨ�Ľ�                      *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                ___                          -"<<endl;//
	cout<<"-                                               |   |                         -"<<endl;//
	cout<<"-                 ******************************|   |                         -"<<endl;//
	cout<<"-               **                              |   |_*****_#                 -"<<endl;//
	cout<<"-             **--------------------------------|[+] _*   *_##                -"<<endl;// 
	cout<<"-               **                              |   | ***** #                 -"<<endl;//
	cout<<"-                 ******************************|   |  * *                    -"<<endl;//
	cout<<"-                          * *                  |___|  * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-                          * *                         * *                    -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
	cout<<"-   *         ���ѵ��ǣ�����                                              *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                   ***                                       -"<<endl;//
	cout<<"-                                  *   *  =                                   -"<<endl;//
	cout<<"-                                   **====                                    -"<<endl;//
	cout<<"-                                    */ ====                                  -"<<endl;//
	cout<<"-                                  **/   /                                    -"<<endl;// 
	cout<<"-                                 * /   /                                     -"<<endl;//
	cout<<"-                                * /   /                                      -"<<endl;//
	cout<<"-                                  |__/                                       -"<<endl;//
	cout<<"-                                  *  *                                       -"<<endl;//
	cout<<"-                                 *    *                                      -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                          ��Ѹ�ٽ����պ�                             *   -"<<endl;//
	cout<<"-   *                            �̶��ڱ���                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                  =                          =               -"<<endl;//
	cout<<"-      =                  =            =               =                      -"<<endl;//
	cout<<"-                                                                     =       -"<<endl;//
	cout<<"-           =         =                      =                    =           -"<<endl;//
	cout<<"-                                 =                                 =         -"<<endl;//
	cout<<"-               =                                 ==                          -"<<endl;//
	cout<<"-         =       =                                       =                   -"<<endl;//
	cout<<"-                         =         =      =                                  -"<<endl;//
	cout<<"-           =                                 =             =         =       -"<<endl;//
	cout<<"-                  =          ==                                              -"<<endl;//
	cout<<"-            =                     =                   = =                    -"<<endl;//
	cout<<"-                 =          =               =        =           =           -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *            \"���˹���..\"ͻȻ���Ϸ�����ʯ���˲��������               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-   ====================                             ================         -"<<endl;//
	cout<<"-    =========     =======   ==================        =      =               -"<<endl;//
	cout<<"-      =                  =            = ===============     ==               -"<<endl;//
	cout<<"-            =============         =====                              =       -"<<endl;//
	cout<<"-           =         =                      ===========          =           -"<<endl;//
	cout<<"-                                 =======                           =         -"<<endl;//
	cout<<"-  =====       =========     ===                  ==      =========           -"<<endl;//
	cout<<"-         =       =           ===                   ==========                -"<<endl;//
	cout<<"-            ===========  =         =============                             -"<<endl;//
	cout<<"-           =       ===    ======             =  ========   =         =       -"<<endl;//
	cout<<"-        ===========          ==                                              -"<<endl;//
	cout<<"-      ==    =           ===========          ========== =                    -"<<endl;//
	cout<<"-  =           =  =          =               =        =============           -"<<endl;//
	cout<<"-          ===                        ==========          =============       -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                   \"���������ˣ�\"��ʯ��������                        *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-   ====================                             ================         -"<<endl;//
	cout<<"-    =========     =======   ==================        =      =               -"<<endl;//
	cout<<"-      =         =======================================     ==========       -"<<endl;//
	cout<<"-            ====================================          ============       -"<<endl;//
	cout<<"-      ==========================            ===========     =============    -"<<endl;//
	cout<<"-                         ===============              ===============        -"<<endl;//
	cout<<"-  =============================        ================  =========           -"<<endl;//
	cout<<"-         ===============     ====================================            -"<<endl;//
	cout<<"-            ===========  =======================                             -"<<endl;//
	cout<<"-       ===============================       =  ========   ============      -"<<endl;//
	cout<<"-    ===============       =====    =================================         -"<<endl;//
	cout<<"-      =======       ===============   ================= =                    -"<<endl;//
	cout<<"-  ===========================================        =============           -"<<endl;//
	cout<<"-          ===        =============  ==========          =============        -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *            ��Ȼ���Ѿ��е�������������ˣ�����˹�ȥ��             *   -"<<endl;//
	cout<<"-   *                �ε�֮ǰ ���þ��������������˱���                  *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-  =========================================================================  -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                             ��������                                *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *  (�������)                                                         *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	}

void CG_0_Maze(){
	
	char ch;
	while(ch!='1' && ch!='2' && ch!='l' && ch!='r'){
		Maze_1_goto:
		//Maze-Start-1
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           ===================                               -"<<endl;//
		cout<<"-                           =                 =                               -"<<endl;//
		cout<<"-                           =-----------------=                               -"<<endl;//
		cout<<"-                           =                 =                               -"<<endl;//
		cout<<"-                           = <--         --> =                               -"<<endl;//
		cout<<"-                           = left      right =                               -"<<endl;//
		cout<<"-                           =                 =                               -"<<endl;//
		cout<<"-                           =-----------------=                               -"<<endl;//
		cout<<"-                           =- - - - - - - - -=                               -"<<endl;//
		cout<<"-                           =  -  -  -  -  -  =                               -"<<endl;//
		cout<<"-                           =-   -   -   -   -=                               -"<<endl;//
		cout<<"-                         =-    -    -    -    -=                             -"<<endl;//
		cout<<"-                       =-     -     -     -     -=                           -"<<endl;//
		cout<<"-                     =-      -      -      -      -=                         -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *  <Isaac>����:                                                       *   -"<<endl;//
		cout<<"-   *      ��߷ֳ�2��·�ˣ����Ҹ��������߰���                            *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *  1.left    2.right     ������1��2                                   *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		ch=_getch();
		}
	//Maze-Start-2
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                           ===================                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =-----------------=                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =                 =                               -"<<endl;//
	cout<<"-                           =-----------------=                               -"<<endl;//
	cout<<"-                           =- - - - - - - - -=                               -"<<endl;//
	cout<<"-                           =  -  -  -  -  -  =                               -"<<endl;//
	cout<<"-                           =-   -   -   -   -=                               -"<<endl;//
	cout<<"-                         =-    -    -    -    -=                             -"<<endl;//
	cout<<"-                       =-     -     -     -     -=                           -"<<endl;//
	cout<<"-                     =-      -      -      -      -=                         -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	Sleep(1000);
	if(ch=='1' || ch=='l'){
		//Maze-Left-1
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           =====                                             -"<<endl;//
		cout<<"-                           =    ====                                         -"<<endl;//
		cout<<"-                           =      = ====                                     -"<<endl;//
		cout<<"-                           =      =     =====                                -"<<endl;//
		cout<<"-                           =      =         =                                -"<<endl;//
		cout<<"-                           =     -          =                                -"<<endl;//
		cout<<"-                           =    -     -     =                                -"<<endl;//
		cout<<"-                           =   -     -     -=                                -"<<endl;//
		cout<<"-                           =  -     -     - =                                -"<<endl;//
		cout<<"-                           = -     -     -  =                                -"<<endl;//
		cout<<"-                           =-     -     -   =                                -"<<endl;//
		cout<<"-                          =-     -     -    =                                -"<<endl;//
		cout<<"-                         =-     -     -     =                                -"<<endl;//
		cout<<"-                        =-     -     -     -=                                -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		//Maze-Left-2
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           ==================                                -"<<endl;//
		cout<<"-                         = =                =                                -"<<endl;//
		cout<<"-                       =   =                =                                -"<<endl;//
		cout<<"-                     =     =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =                =                                -"<<endl;//
		cout<<"-                   =       =-    -    -    -=                                -"<<endl;//
		cout<<"-                   =     = -    -     -    -                                 -"<<endl;//
		cout<<"-                   =   =  -    -      -    -                                 -"<<endl;//
		cout<<"-                   = =   -    -       -    -                                 -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		//Maze-Left-3
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
		cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
		cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
		cout<<"-                      =      - - - - -      =                                -"<<endl;//
		cout<<"-                      =       =-----=       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =     =       =                                -"<<endl;//
		cout<<"-                      =       =-----=       =                                -"<<endl;//
		cout<<"-                      =      - - - - -      =                                -"<<endl;//
		cout<<"-                      =    -  -  -  -  -    =                                -"<<endl;//
		cout<<"-                      =  -   -   -   -   -  =                                -"<<endl;//
		cout<<"-                      =-    -    -    -    -=                                -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		}
	if(ch=='2' || ch=='r'){
		//Maze-Right-1
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                       ======                                -"<<endl;//
		cout<<"-                                    ====    =                                -"<<endl;//
		cout<<"-                                ==== =      =                                -"<<endl;//
		cout<<"-                           =====     =      =                                -"<<endl;//
		cout<<"-                           =         =      =                                -"<<endl;//
		cout<<"-                           =          -     =                                -"<<endl;//
		cout<<"-                           =     -     -    =                                -"<<endl;//
		cout<<"-                           =-     -     -   =                                -"<<endl;//
		cout<<"-                           = -     -     -  =                                -"<<endl;//
		cout<<"-                           =  -     -     - =                                -"<<endl;//
		cout<<"-                           =   -     -     -=                                -"<<endl;//
		cout<<"-                           =    -     -     -=                               -"<<endl;//
		cout<<"-                           =     -     -     -=                              -"<<endl;//
		cout<<"-                           =-     -     -     -=                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		//Maze-Right-2
		CLS;
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                           ==================                                -"<<endl;//
		cout<<"-                           =                = =                              -"<<endl;//
		cout<<"-                           =                =   =                            -"<<endl;//
		cout<<"-                           =                =     =                          -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =                =       =                        -"<<endl;//
		cout<<"-                           =-    -    -    -=       =                        -"<<endl;//
		cout<<"-                            -    -     -    - =     =                        -"<<endl;//
		cout<<"-                            -    -      -    -  =   =                        -"<<endl;//
		cout<<"-                            -    -       -    -   = =                        -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		Sleep(1000);
		
		goto Maze_1_goto;
		
		}
	
	}

void CG_1(){
	//��һ�� 
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              -                                                            -                                              -"<<endl;//
	cout<<"-                                                                                                                                           -              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                      ��һ��                                                            *********                                                         -"<<endl;//
	cout<<"-                                         -                    **          ****        *************                                                       -"<<endl;//
	cout<<"-                                                                     ****      **    ***************                                                      -"<<endl;//
	cout<<"-                                   ����                *                   **    *********     *****                         -                            -"<<endl;//
	cout<<"-                                                                    ** *     ***********          **                                                      -"<<endl;//
	cout<<"-                                                                          *************            *                                        *******       -"<<endl;//
	cout<<"-                   -       --      -   *      **                ***    ** ***************        **                                        *       *      -"<<endl;//
	cout<<"-            -      -                                               ***    ***********    ********                                          *       *      -"<<endl;//
	cout<<"-              -                                         **            ***     ****         *  *                                            *       *      -"<<endl;//
	cout<<"-                                                                   ***                    ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        *  *     *                                         *       *      -"<<endl;//
	cout<<"-                                                                                       *  **    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                      *  * *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  *__   *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        * |  |  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *|__|  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                   * *    *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                                   * * *   *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                          * *        *     *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                         * * *       *********************-"<<endl;//
	cout<<"-                                                                                          *    *                           *    *****                     -"<<endl;//
	cout<<"-                                                                                          *    *                           *****                          -"<<endl;//
	cout<<"-                                                                                          *    *                      *****                               -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_1
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        ��ͻȻ��ɳ���Ͼ����𣬴�ڵĴ�����������          -"<<endl;//5,117 
	cout<<"-                                                                                                        ���ħ�������ֿ�����½���Ѿ�������ȥ��3�ꡣ       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ����                                                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *    <Alice> : <����˿>                                                                                                                         *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_2
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        3��ǰ�Ľ��죬Ҳ��ج�ο�ʼ�ĵط���                 -"<<endl;//
	cout<<"-                                                                                                        ������̽��ʱ����Ѩ����������������                -"<<endl;//
	cout<<"-                                                                                                        Ȼ���ħ�ͷ��������֡���                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ������                                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_3
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        Ȼ��ĸ��Ϊ�˱������׵��ң�Ҳ����ħ˺����2�롣     -"<<endl;//
	cout<<"-                                                                                                        �Ǹ������������б�������ʣ�                      -"<<endl;//
	cout<<"-                                                                                                        ÿ������˯ʱ�����ͻ�����ҡ�                      -"<<endl;//
	cout<<"-                                                                                                        �ҷ���һ��Ҫɱ���ħ��Ϊĸ�ױ���                -"<<endl;//
	cout<<"-                                                                                                        �������Σ���֪���롣����                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        (��)                                                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_4
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                        ��ߵߵߵ��ͻȻ�����⴫������������                -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ��                                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_5
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ������վ����С�ܵ�ȥ���š�                       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        �������ˡ�                                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_6
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ����վ��һ��΢Ц�Ĵ󺺣�����һ���޴�İ�����       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                          *   *   *                                                                       -"<<endl;//
	cout<<"-                                                                         *    *       *                                                                   -"<<endl;//
	cout<<"-                                                                        *         *       *                                                               -"<<endl;//
	cout<<"-                                                                       *              *   *   *                                                           -"<<endl;//
	cout<<"-                                                                      *              *       *                                                            -"<<endl;//
	cout<<"-                                                                     *              *       *                                                             -"<<endl;//
	cout<<"-                                                                    *    =         *       *                                                              -"<<endl;//
	cout<<"-                                                                   *         =    *       *                                                               -"<<endl;//
	cout<<"-                                                                  *              *   =   *                                                                -"<<endl;//
	cout<<"-                                                                 *              *       *                                                                 -"<<endl;//
	cout<<"-                                                                *    =         *       *                                                                  -"<<endl;//
	cout<<"-                                                               *         =    *       *                                                                   -"<<endl;//
	cout<<"-                                                              *              *   =   *                                                                    -"<<endl;//
	cout<<"-                                                             *              *       *                                                                     -"<<endl;//
	cout<<"-                                                            *    =         *       *                                                                      -"<<endl;//
	cout<<"-                                                           *          =   *       *                                                                       -"<<endl;//
	cout<<"-                                                          *              *   =   *                                                                        -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Reno:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        �ˣ��þò���������ѧԺ�ĸ���İ�����                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *    <Reno> : <��ŵ>                                                                                                                            *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_7
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ���ǵ۹��ʼ�ѧԺ�Ľ�����                           -"<<endl;//
	cout<<"-                                                                                                       Сʱ�����͸���һ���������                         -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                          *   *   *                                                                       -"<<endl;//
	cout<<"-                                                                         *    *       *                                                                   -"<<endl;//
	cout<<"-                                                                        *         *       *                                                               -"<<endl;//
	cout<<"-                                                                       *              *   *   *                                                           -"<<endl;//
	cout<<"-                                                                      *              *       *                                                            -"<<endl;//
	cout<<"-                                                                     *              *       *                                                             -"<<endl;//
	cout<<"-                                                                    *    =         *       *                                                              -"<<endl;//
	cout<<"-                                                                   *         =    *       *                                                               -"<<endl;//
	cout<<"-                                                                  *              *   =   *                                                                -"<<endl;//
	cout<<"-                                                                 *              *       *                                                                 -"<<endl;//
	cout<<"-                                                                *    =         *       *                                                                  -"<<endl;//
	cout<<"-                                                               *         =    *       *                                                                   -"<<endl;//
	cout<<"-                                                              *              *   =   *                                                                    -"<<endl;//
	cout<<"-                                                             *              *       *                                                                     -"<<endl;//
	cout<<"-                                                            *    =         *       *                                                                      -"<<endl;//
	cout<<"-                                                           *          =   *       *                                                                       -"<<endl;//
	cout<<"-                                                          *              *   =   *                                                                        -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        Ŷ��лл��                                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_8
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ��Ϊ��ǰ���׺��������ڼҺȾƣ�                     -"<<endl;//
	cout<<"-                                                                                                       ������Ҳ�������졣                                 -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                          *   *   *                                                                       -"<<endl;//
	cout<<"-                                                                         *    *       *                                                                   -"<<endl;//
	cout<<"-                                                                        *         *       *                                                               -"<<endl;//
	cout<<"-                                                                       *              *   *   *                                                           -"<<endl;//
	cout<<"-                                                                      *              *       *                                                            -"<<endl;//
	cout<<"-                                                                     *              *       *                                                             -"<<endl;//
	cout<<"-                                                                    *    =         *       *                                                              -"<<endl;//
	cout<<"-                                                                   *         =    *       *                                                               -"<<endl;//
	cout<<"-                                                                  *              *   =   *                                                                -"<<endl;//
	cout<<"-                                                                 *              *       *                                                                 -"<<endl;//
	cout<<"-                                                                *    =         *       *                                                                  -"<<endl;//
	cout<<"-                                                               *         =    *       *                                                                   -"<<endl;//
	cout<<"-                                                              *              *   =   *                                                                    -"<<endl;//
	cout<<"-                                                             *              *       *                                                                     -"<<endl;//
	cout<<"-                                                            *    =         *       *                                                                      -"<<endl;//
	cout<<"-                                                           *          =   *       *                                                                       -"<<endl;//
	cout<<"-                                                          *              *   =   *                                                                        -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Reno����:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        ���ε��ˣ�����ô��ɥ������������Ҫ�Ķ�����                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_9
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ��һֱ�����۹��ʼ�ѧԺ����ѧϰ��                 -"<<endl;//
	cout<<"-                                                                                                       ��Ҳ֪�����ѵ���Ū�������ˣ�                       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                          *   *   *                                                                       -"<<endl;//
	cout<<"-                                                                         *    *       *                                                                   -"<<endl;//
	cout<<"-                                                                        *         *       *                                                               -"<<endl;//
	cout<<"-                                                                       *              *   *   *                                                           -"<<endl;//
	cout<<"-                                                                      *              *       *                                                            -"<<endl;//
	cout<<"-                                                                     *              *       *                                                             -"<<endl;//
	cout<<"-                                                                    *    =         *       *                                                              -"<<endl;//
	cout<<"-                                                                   *         =    *       *                                                               -"<<endl;//
	cout<<"-                                                                  *              *   =   *                                                                -"<<endl;//
	cout<<"-                                                                 *              *       *                                                                 -"<<endl;//
	cout<<"-                                                                *    =         *       *                                                                  -"<<endl;//
	cout<<"-                                                               *         =    *       *                                                                   -"<<endl;//
	cout<<"-                                                              *              *   =   *                                                                    -"<<endl;//
	cout<<"-                                                             *              *       *                                                                     -"<<endl;//
	cout<<"-                                                            *    =         *       *                                                                      -"<<endl;//
	cout<<"-                                                           *          =   *       *                                                                       -"<<endl;//
	cout<<"-                                                          *              *   =   *                                                                        -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ʲô����                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_10
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       Reno����µ����ҵķ�Ӧ��Ц��һ�¡�                 -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                          *   *   *                                                                       -"<<endl;//
	cout<<"-                                                                         *    *       *                                                                   -"<<endl;//
	cout<<"-                                                                        *         *       *                                                               -"<<endl;//
	cout<<"-                                                                       *              *   *   *                                                           -"<<endl;//
	cout<<"-                                                                      *              *       *                                                            -"<<endl;//
	cout<<"-                                                                     *              *       *                                                             -"<<endl;//
	cout<<"-                                                                    *    =         *       *                                                              -"<<endl;//
	cout<<"-                                                                   *         =    *       *                                                               -"<<endl;//
	cout<<"-                                                                  *              *   =   *                                                                -"<<endl;//
	cout<<"-                                                                 *              *       *                                                                 -"<<endl;//
	cout<<"-                                                                *    =         *       *                                                                  -"<<endl;//
	cout<<"-                                                               *         =    *       *                                                                   -"<<endl;//
	cout<<"-                                                              *              *   =   *                                                                    -"<<endl;//
	cout<<"-                                                             *              *       *                                                                     -"<<endl;//
	cout<<"-                                                            *    =         *       *                                                                      -"<<endl;//
	cout<<"-                                                           *          =   *       *                                                                       -"<<endl;//
	cout<<"-                                                          *              *   =   *                                                                        -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Reno����:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        ����ɣ��Լ��ú����á�                                                                                                                 *     -"<<endl;//
	cout<<"-    *        ��ʱ�����Ҫ�Լ���Ken City��Phiya��                                                                                                    *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_10
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ���Ȳ������ؽӹ��˰���������ķŵ�ɳ���ϡ�         -"<<endl;//
	cout<<"-                                                                                                       �ó����������˰�����                             -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        �ţ�ллReno���塣                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_11
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                        /\\                                                                                -"<<endl;//
	cout<<"-                                                         ***************||                                                                                -"<<endl;//
	cout<<"-                                                       *----------------||===]    ____                                                                    -"<<endl;//
	cout<<"-                                                         ***************||       |�۹�|                                                                   -"<<endl;//
	cout<<"-                                                                        \\/       |____|                                                                   -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                          ����װ��һ������                                                                     *     -"<<endl;//
	cout<<"-    *                                                     ��һ��۹��ʼ�ѧԺ��������                                                                *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Big_Map//CG_1_12
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//1
	cout<<"-                                                                                                                                                          -"<<endl;//2
	cout<<"-                                                                                                                                                          -"<<endl;//3
	cout<<"-                                                                                                                                                          -"<<endl;//5
	cout<<"-                                                          ���ǣ��ұ�̤����ǰ��[Phiya]���ó̡�                                                             -"<<endl;//4
	cout<<"-                                                             �����ó���ͼ����·�߹滮�á�                                                                 -"<<endl;//6
	cout<<"-                                                                                                                                                          -"<<endl;//7
	cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;// 
	cout<<"-                                      -                                       *                                     -                                     -"<<endl;//
	cout<<"-                                      -  ������½��ͼ                        *                                      -                                     -"<<endl;//
	cout<<"-                                      -                                    **                                       -                                     -"<<endl;//
	cout<<"-                                      -    ~                          *****                                         -                                     -"<<endl;//
	cout<<"-                                      -        ~             ~   *****                                              -                                     -"<<endl;// 
	cout<<"-                                      -   ~            ~        *     #Godigun       @Phiya                         -                                     -"<<endl;//
	cout<<"-                                      -            ~           *                     ..                             -                                     -"<<endl;//
	cout<<"-                                      -        *               *                     .                              -                                     -"<<endl;//
	cout<<"-                                      -  ~  * *         ~      ********   #Sealidge...       / / / / /              -                                     -"<<endl;//
	cout<<"-                                      -      ***      ~        *   ~   *   .            / / / / / / / /             -                                     -"<<endl;//
	cout<<"-                                      -       * *     ~       * ~    ~  *  .         / / / / / / / / / /            -                                     -"<<endl;//
	cout<<"-                                      -      *                 ~    ~ ~ *  .        / / / / / / / / / / /           -                                     -"<<endl;//
	cout<<"-                                      -  ~          ~      ~            *  .         / / / / / / / / / /            -                                     -"<<endl;//
	cout<<"-                                      -      ~~         ~      *  ~  ~  *  .          / / / / / / / /               -                                     -"<<endl;//
	cout<<"-                                      -   ~                    ***     *   .                   / /                  -                                     -"<<endl;//
	cout<<"-                                      -        ~     ~         * ******    .                    /   #Wild City      -                                     -"<<endl;//
	cout<<"-                                      -                   ~     *     #Me City                                      -                                     -"<<endl;//
	cout<<"-                                      -  @ �׶�       ~          **        .                                        -                                     -"<<endl;//
	cout<<"-                                      -  # ����    ~        ~      ******  ............#Ken City                    -                                     -"<<endl;//
	cout<<"-                                      -  ~ ��           ~      ~         *                                          -                                     -"<<endl;//
	cout<<"-                                      -  / ɳĮ  ~                        *                                         -                                     -"<<endl;//
	cout<<"-                                      -------------------------------------------------------------------------------                                     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//0
	cout<<"-                                                                                                                                                          -"<<endl;//1
	cout<<"-                                                                                                                                                          -"<<endl;//2
	cout<<"-                                                                                                                                                          -"<<endl;//3
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//4
	PAUSE;
	//CG_1_13
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                      ����.                                                                                               -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                    *********                                                                                             -"<<endl;//
	cout<<"-                                                   *=       =*                                                                                            -"<<endl;//
	cout<<"-                                             ***** *  *****  * *********************************                                                          -"<<endl;//
	cout<<"-                                             *     * *_____* *                                **                                                          -"<<endl;//
	cout<<"-                                             **    * *_____* *                         ذ��  * *                                                          -"<<endl;//
	cout<<"-                                             **    * *_____* *   ��(�����н���) /\\      /\\   * *                                                          -"<<endl;//
	cout<<"-                                             * *   * *_____* *   ***************||      ||  *  *                                                          -"<<endl;//
	cout<<"-                                             * *   *=       =*  *               ||===]  ==  *  *                                                          -"<<endl;//
	cout<<"-                                             *  *   *********    ***************||      =  *   *                                                          -"<<endl;//
	cout<<"-                                             *  *                               \\/    O=   *   *                                                          -"<<endl;//
	cout<<"-                                             *  ********************************************   *                                                          -"<<endl;//
	cout<<"-                                             *   ******************************************    *                                                          -"<<endl;//
	cout<<"-                                             *   *                                        *    *                                                          -"<<endl;//
	cout<<"-                                             *   *                                        *    *                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                     �����һ�������׼���ҵ�װ����                                                              *     -"<<endl;//
	cout<<"-    *                                                          �����˷ܵ�˯���š�                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_14
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                      -  -  -                                                                             -"<<endl;//
	cout<<"-                                                                    -         -                                                                           -"<<endl;//
	cout<<"-                                                                   -           -                                                                          -"<<endl;//
	cout<<"-                                                                  -             -                                                                         -"<<endl;//
	cout<<"-                                                                  -             -                                                                         -"<<endl;//
	cout<<"-                                                                   -           -                                                                          -"<<endl;//
	cout<<"-                                                                    -         -                                                                           -"<<endl;//
	cout<<"-                                                                     -       -                                                                            -"<<endl;//
	cout<<"-                                                                      -     -                                                                             -"<<endl;//
	cout<<"-                                                                       - | -                                                                              -"<<endl;//
	cout<<"-                                                                        -+-                                                                               -"<<endl;//
	cout<<"-                                                                         |                                                                                -"<<endl;//
	cout<<"-                                                                         |                                                                                -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        Ŷ�����ˡ��һ�Ҫ����ĸ�����µ���������˵�����Կ���Σ�ա�                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *    <���Բ鿴����״̬>                                                                                                                         *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_15
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       �ڶ������ϣ����ߵ���Ժ��������ĸ�׵�Ĺ��           -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ������                                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_16
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              -                                                            -                                              -"<<endl;//
	cout<<"-                                                                                                                                           -              -"<<endl;//
	cout<<"-                                                                                                          ��Ϊ����Ů��������Сʱ���ײ�û�н���ս����    -"<<endl;//
	cout<<"-                                                                                                          ��ĸ�׸���˵�˺ܶ༼�ɣ�                        -"<<endl;//
	cout<<"-                                                                                        *********         �������Ҹ��׵��洫��������ն��                  -"<<endl;//
	cout<<"-                                         -                    **          ****        *************       ��һ����Ϊ�����ļ��ܣ�                          -"<<endl;//
	cout<<"-                                                                     ****      **    ***************      ��������������                                  -"<<endl;//
	cout<<"-                                                       *                   **    *********     *****                         -                            -"<<endl;//
	cout<<"-                                                                    ** *     ***********          **                                                      -"<<endl;//
	cout<<"-                                                                          *************            *                                        *******       -"<<endl;//
	cout<<"-                   -       --      -   *      **                ***    ** ***************        **                                        *       *      -"<<endl;//
	cout<<"-            -      -                                               ***    ***********    ********                                          *       *      -"<<endl;//
	cout<<"-              -                                         **            ***     ****         *  *                                            *       *      -"<<endl;//
	cout<<"-                                                                   ***                    ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        *  *     *                                         *       *      -"<<endl;//
	cout<<"-                                                                                       *  **    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                      *  * *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  *__   *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        * |  |  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *|__|  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                          ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-    ******************************************************************                   *      *                                          *       *      -"<<endl;//
	cout<<"-    *    Alice:                                                      *                    ******                                    * *    *       *      -"<<endl;//
	cout<<"-    *        ĸ�ס�                                                  *                     *  *                                    * * *   *       *      -"<<endl;//
	cout<<"-    *        ��Ҫ�뿪�����ˣ�ϣ���������ҲҪ���ÿ��ġ�              *                     *  *                           * *        *     *       *      -"<<endl;//
	cout<<"-    *        �����Ұɣ�                                              *                     *  *                          * * *       *********************-"<<endl;//
	cout<<"-    *                                                                *                     *  *                            *    *****                     -"<<endl;//
	cout<<"-    ******************************************************************                     *  *                            *****                          -"<<endl;//
	cout<<"-                                                                                           *  *                       *****                               -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_17
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ����һ�����죬�ҹ������ţ�                         -"<<endl;//
	cout<<"-                                                                                                       �뿪�����ȥԶ�ڱ�����ѧԺ��                     -"<<endl;//
	cout<<"-                                                                                                       Ϊ�ҵ�Ŀ����ܶ���                                 -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_18 
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       �Ͼ��ǵ�һ���뿪[Ken City]��                       -"<<endl;//
	cout<<"-                                                                                                       �ҵ����黹��ʮ�����ġ�                           -"<<endl;//
	cout<<"-                                                                                                       ���ǣ����������ĽŲ���                           -"<<endl;//
	cout<<"-                                                                                                       �߽���[Ken City]���ߵ�[Fog Forest]��               -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                       ***       ***                                                                      -"<<endl;//
	cout<<"-                                                                     *******   *******                                                                    -"<<endl;//
	cout<<"-                                                                    ********* *********                                                                   -"<<endl;//
	cout<<"-                                                                    ********* *********                                                                   -"<<endl;//
	cout<<"-                                       ***         ***         ***      |         |      ***         ***         ***                                      -"<<endl;//
	cout<<"-                                     *******     *******     *******    |         |    *******     *******     *******                                    -"<<endl;//
	cout<<"-                                    *********   *********   *********   |         |   *********   *********   *********                                   -"<<endl;//
	cout<<"-                                    *********   *********   *********   |   * *   |   *********   *********   *********                                   -"<<endl;//
	cout<<"-                                        |           |           |       | *     * |       |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           |       *         *       |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           |     *             *     |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           |   *                 *   |           |           |                                       -"<<endl;//
	cout<<"-                                        |           |           | *                     * |           |           |                                       -"<<endl;//
	cout<<"-                                                                *                         *                                                               -"<<endl;//
	cout<<"-                                                              *                             *                                                             -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_1_19
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       �����ҵ����룬ɭ��Խ��Խ�ܼ���                     -"<<endl;//
	cout<<"-                                                                                                       ɭ��Խ��Խ�ܼ���                                   -"<<endl;//
	cout<<"-                   ***         ***         ***         ***         ***               ***         ***   ����Խ��Խϡ�衣  ***         ***                  -"<<endl;//
	cout<<"-                 *******     *******     *******     *******     *******           *******     *******     *******     *******     *******                -"<<endl;//
	cout<<"-                *********   *********   *********   *********   *********         *********   *********   *********   *********   *********               -"<<endl;//
	cout<<"-                *********   *********   *********   *********   *********         *********   *********   *********   *********   *********               -"<<endl;//
	cout<<"-           ***      |  ***      |  ***      |  ***      |  ***      |  ***       ***  |      ***  |      ***  |      ***  |      ***  |      ***          -"<<endl;//
	cout<<"-         *******    |*******    |*******    |*******    |*******    |*******   *******|    *******|    *******|    *******|    *******|    *******        -"<<endl;//
	cout<<"-        *********   *********   *********   *********   *********   ********* *********   *********   *********   *********   *********   *********       -"<<endl;//
	cout<<"-        *********   *********   *********   *********   *********   ********* *********   *********   *********   *********   *********   *********       -"<<endl;//
	cout<<"-            |  ***  |   |  ***  |   |  ***  |   |  ***  |   |  ***  |   |         |   |  ***  |   |  ***  |   |  ***  |   |  ***  |      ***  |           -"<<endl;//
	cout<<"-            |*******    |*******    |*******    |*******    |*******    |         |    *******|    *******|    *******|    *******|    *******|           -"<<endl;//
	cout<<"-            *********   *********   *********   *********   *********   |         |   *********   *********   *********   *********   *********           -"<<endl;//
	cout<<"-            *********   *********   *********   *********   *********   |   * *   |   *********   *********   *********   *********   *********           -"<<endl;//
	cout<<"-            |   |       |   |       |   |       |   |       |   |       | *     * |       |   |       |   |       |   |       |   |       |   |           -"<<endl;//
	cout<<"-                |           |           |           |           |       *         *       |           |           |           |           |               -"<<endl;//
	cout<<"-                |           |           |           |           |     *             *     |           |           |           |           |               -"<<endl;//
	cout<<"-                |           |           |           |           |   *                 *   |           |           |           |           |               -"<<endl;//
	cout<<"-                |           |           |           |           | *                     * |           |           |           |           |               -"<<endl;//
	cout<<"-                                                                *                         *                                                               -"<<endl;//
	cout<<"-                                                              *                             *                                                             -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
	cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
	cout<<"-                                                    ***************************************************                                                   -"<<endl;//
	cout<<"-                                                  *******************************************************                                                 -"<<endl;//
	cout<<"-                                                  *******************************************************                                                 -"<<endl;//
	cout<<"-                                                **********************************************************                                                -"<<endl;//
	cout<<"-                                            ******************************************************************                                            -"<<endl;//
	cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
	cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     |||||***************|||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     ||||| <-         -> |||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
	cout<<"-                                                        *                                         *                                                       -"<<endl;//
	cout<<"-                                                      *                                             *                                                     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ������ô�в�·��                                                                                                                       *     -"<<endl;//
	cout<<"-    *        ����Ҫ�������߰���                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	CG_1_Maze();
	
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                *****************                       ******************                                                -"<<endl;//
	cout<<"-                                            *************************               **************************                                            -"<<endl;//
	cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||            *         *            |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||          *             *          |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||        *                 *        |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
	cout<<"-                                                        *                                         *                                                       -"<<endl;//
	cout<<"-                                                      *                                             *                                                     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        �۰��������߳����ˣ��춼���ˣ���Me City����Զ��                                                                                        *     -"<<endl;//
	cout<<"-    *        �������ᵽ[����ɽ��]��                                                                                                                 *     -"<<endl;// 
	cout<<"-    *        ����������ʥսʱ�������ٻ������������Կ���ħ�ĵط�......                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                *****************                       ******************                                                -"<<endl;//
	cout<<"-                                            *************************               **************************                                            -"<<endl;//
	cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||            *         *            |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||          *             *          |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||        *                 *        |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
	cout<<"-                                                        *                                         *                                                       -"<<endl;//
	cout<<"-                                                      *                                             *                                                     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        �ǻ��ǿ���·��......                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;// 
	cout<<"-    *        (��һ�����)                                                                                                                           *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	PAUSE;
	}

void CG_1_Maze(){
	char in;
	
	int x=3,                       // 1 -> �ֲ�( 2 ) -> x-1
		y=3;                       // 2 -> ����( 3 )
	
	int Maze_Map[12][12]={    // 3 -> ��· 
		0, 0,0,0,0,0, 0,0,0,0,0, 0,// 4 -> ��ʾ 1 ��· 
		                           // 5 -> ��ʾ 2 ���� 
		0, 0,0,0,0,0, 0,3,0,0,0, 0,// 6 -> ���� 1  
		0, 0,0,0,0,0, 0,0,0,0,0, 0,// 7 -> ���� 2 
		0, 0,0,1,0,3, 0,0,0,0,0, 0,// * -> monster 
		0, 0,1,0,1,0, 6,0,0,0,0, 0,// * -> Boss
		0, 3,0,3,0,2, 1,1,3,0,0, 0,// 9 -> �յ� 
		
		0, 0,0,0,3,1, 2,3,0,0,0, 0,
		0, 0,0,0,0,4, 5,3,0,0,3, 0,
		0, 0,0,0,7,1, 0,0,0,9,2, 0,
		0, 0,0,0,0,3, 0,0,0,0,3, 0,
		0, 0,0,0,0,0, 3,0,1,3,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x1_to[12][12]={//�ֲ� or ���� ��· x
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,//1
		0, 0,0,0,0,0, 0,0,0,0,0, 0,//2
		0, 0,0,4,0,0, 0,0,0,0,0, 0,//3
		0, 0,5,0,3,0, 0,0,0,0,0, 0,//4
		0, 0,0,0,0,5, 4,1,0,0,0, 0,//5
		
		0, 0,0,0,0,7, 6,0,0,0,0, 0,//6
		0, 0,0,0,0,8, 10,0,0,0,0, 0,//7
		0, 0,0,0,0,9, 0,0,0,0,9, 0,//8
		0, 0,0,0,0,0, 0,0,0,0,0, 0,//9
		0, 0,0,0,0,0, 0,0,8,0,0, 0,//10
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y1_to[12][12]={//�ֲ� or ���� ��· y
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,4,0,0, 0,0,0,0,0, 0,
		0, 0,3,0,5,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 6,7,0,0,0, 0,
		
		0, 0,0,0,0,5, 7,0,0,0,0, 0,
		0, 0,0,0,0,5, 8,0,0,0,0, 0,
		0, 0,0,0,0,5, 0,0,0,0,10, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,10,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x2_to[12][12]={//�ֲ� or ���� ��· x
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,4,0,0, 0,0,0,0,0, 0,
		0, 0,5,0,5,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 5,5,0,0,0, 0,
		
		0, 0,0,0,0,6, 7,0,0,0,0, 0,
		0, 0,0,0,0,0, 10,0,0,0,0, 0,
		0, 0,0,0,0,8, 0,0,0,0,7, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,10,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y2_to[12][12]={//�ֲ� or ���� ��· y
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,2,0,0, 0,0,0,0,10, 0,
		0, 0,1,0,5,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,5, 7,8,0,0,0, 0,
		
		0, 0,0,0,0,4, 6,0,0,0,0, 0,
		0, 0,0,0,0,0, 6,0,0,0,0, 0,
		0, 0,0,0,0,4, 0,0,0,0,10, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,9,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x3_to[12][12]={//���� ��· x
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 7,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,8, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y3_to[12][12]={//���� ��· y 
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,6, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 7,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,9, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_x_return[12][12]={//���� 
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,5,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,4, 0,0,0,0,0, 0,
		0, 0,3,0,3,0, 5,0,0,0,0, 0,
		0, 4,0,4,0,4, 5,5,5,0,0, 0,
		
		0, 0,0,0,6,5, 5,6,0,0,0, 0,
		0, 0,0,0,0,6, 6,6,0,0,8, 0,
		0, 0,0,0,8,7, 0,0,0,8,10, 0,
		0, 0,0,0,0,8, 0,0,0,0,8, 0,
		0, 0,0,0,0,0, 7,0,10,10,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		},
		Maze_y_return[12][12]={//����
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		
		0, 0,0,0,0,0, 0,7,0,0,0, 0,
		0, 0,0,0,0,0, 0,0,0,0,0, 0,
		0, 0,0,0,0,4, 0,0,0,0,0, 0,
		0, 0,3,0,3,0, 6,0,0,0,0, 0,
		0, 2,0,2,0,4, 5,6,7,0,0, 0,
		
		0, 0,0,0,5,5, 5,6,0,0,0, 0,
		0, 0,0,0,0,5, 6,6,0,0,10, 0,
		0, 0,0,0,5,5, 0,0,0,10,8, 0,
		0, 0,0,0,0,5, 0,0,0,0,10, 0,
		0, 0,0,0,0,0, 6,0,6,8,0, 0,
		
		0, 0,0,0,0,0, 0,0,0,0,0, 0 
		};
	bool wolf1=1,wolf2=1,wolf3=1,wolf4,wolfking=1,chest1=1,chest2=1;//chest1 dmg+3   chest2 hp+30
	/*
	wolf1 -> x=3 y=5
	wolf2 -> x=8 y=4
	wolf3 -> x=7 y=10
	wolf4 -> x=9 y=10
	slime -> x=8 y=9
	*/
	
	while(1){
		in='0';	
		if( (x==3 && y==5 && wolf1)||(x==8 && y==4 && wolf2)||(x==7 && y==10 &&wolf3)||(x==9 && y==10 && wolf4) ){//Elf Hunter
			CG(16,0);
			Fight(2);
			if(Hero.hp<=0)
				return;
			if(x==3)
				wolf1=0;
			if(x==8)
				wolf2=0;
			if(x==7)
				wolf3=0;
			if(x==9)
				wolf4=0;
			} 
		if( x==8 && y==9 && wolfking ){//Slime
			CG(24,0);
			Fight(3);
			if(Hero.hp<=0)
				return;
			wolfking=0;
			}
		if( x==4 && y==6 && chest1 ){
			CG(29,0);
			Hero.dmg+=3;
			chest1=0;
			}
		if( x==8 && y==4 && chest2 ){
			CG(30,0);
			Hero.hp+=30;
			Hero.hp_max+=30;
			chest2=0;
			}
		switch(Maze_Map[x][y]){
			case 1 :{//�ֲ�( 2 ) -> x-1
				while(in!=LEFT && in!=RIGHT && in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||***************|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     ||||| <-         -> |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                        A ������[Left]                                     D ������[Right]                                     *     -"<<endl;//
				cout<<"-    *                                                              S ������һ��[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case (LEFT):{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case RIGHT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x2_to[x][y];
						t2=Maze_y2_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						if(x==3 && y==3){
							CG(14,0);
							break;
							}
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0001");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						cout<<"Maze_x1_to[x][y]:"<<Maze_x1_to[x][y]<<endl<<"Maze_y1_to[x][y]:"<<Maze_y1_to[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 2 :{//����( 3 )
				while(in!=UP && in!=DOWN && in!=LEFT && in!=RIGHT){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||       ^       |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*****  |  *****|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     ||||| <-         -> |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                        A ������[Left]          W ��ǰ��[Forward]          D ������[Right]                                     *     -"<<endl;//
				cout<<"-    *                                                              S ������һ��[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case LEFT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case RIGHT:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x2_to[x][y];
						t2=Maze_y2_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case UP:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x3_to[x][y];
						t2=Maze_y3_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0002");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 3 :{//��·( 0 )
				while(in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *         *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*             *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*                 *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                              S ������һ��[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0003");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 4 :{//��ʾ 1 ��· 
				while(in!=UP && in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*        ^        *|||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *          |          *  |   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *|   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
			 	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
			 	cout<<"-                                                        *                                         *                                                       -"<<endl;//
			 	cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                    W ��ǰ��[Forward]     �����и���ʾ�ƣ�д��:                                                *     -"<<endl;//
				cout<<"-    *                                                   S ������һ��[Return]        ǰ������·                                                      *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case UP:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0004");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 5 :{//��ʾ 2 ����
				while(in!=UP && in!=DOWN){
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          ******************   ******************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||               |||||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*        ^        *|||===  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *          |          *  |   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *|   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
			 	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
			 	cout<<"-                                                        *                                         *                                                       -"<<endl;//
			 	cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                               W ��ǰ��[Forward]               �����и���ʾ�ƣ�д��:                                           *     -"<<endl;//
				cout<<"-    *                                              S ������һ��[Return]                  ǰ��������                                                 *     -"<<endl;//
				cout<<"-    *                                                                           ����׼�����㹻ʵ�� ��ҪóȻ�ж�                                     *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case UP:{
						CG(13,0);
						int t1,t2;
						t1=Maze_x1_to[x][y];
						t2=Maze_y1_to[x][y];
						x=t1;
						y=t2;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0005");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 6 :{//����
				while(in!=DOWN){
				//.........
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *        ���ӡ�       *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                              S ������һ��[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0006");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 7 :{//����2
				while(in!=DOWN){
				//.........
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                          *****************     *****************                                                         -"<<endl;//
				cout<<"-                                                      *********************** ***********************                                                     -"<<endl;//
				cout<<"-                                                    ***************************************************                                                   -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                  *******************************************************                                                 -"<<endl;//
				cout<<"-                                                **********************************************************                                                -"<<endl;//
				cout<<"-                                            ******************************************************************                                            -"<<endl;//
				cout<<"-                                          *******************************  |||||  ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************|||||***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||     |||||     |||||     |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||    *******    |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||  *  *=+=*  *  |||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||||*    *   *    *|||||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||     |||*      *****      *|||     |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *        ���ӡ�       *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                              S ������һ��[Return]                                                             *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0007");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				break;
				}
			case 9 :{//�յ� 
				while(in!=UP && in!=DOWN){
				//CG_1_Boss();
				CLS;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
				cout<<"-                                                *****************                       ******************                                                -"<<endl;//
				cout<<"-                                            *************************               **************************                                            -"<<endl;//
				cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
				cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||              *     *              |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||            *         *            |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||          *             *          |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||        *                 *        |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
				cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
				cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
				cout<<"-                                                        *                                         *                                                       -"<<endl;//
				cout<<"-                                                      *                                             *                                                     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                W ͨ�أ�[Yeah!]                                                                *     -"<<endl;//
				cout<<"-    *                                                   S �����һ�����̽��һ�ᡣ[ɭ���������ر��ء�]                                                *     -"<<endl;// 
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *                                                                                                                                               *     -"<<endl;//
				cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
				cout<<"-                                                                                                                                                          -"<<endl;//
	 			cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
				in=_getch();
				switch(in){
					case UP:{
						CG(13,0);
						return;
						break;
						}
					case DOWN:{
						CG(15,0);
						int t1,t2;
						t1=Maze_x_return[x][y];
						t2=Maze_y_return[x][y];
						x=t1;
						y=t2;
						break;
						}
					case 'c':{
						check("0002","0009");
						cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
						PAUSE;
						break;
						}
					}
				}
				
				break;
				}
			default:{
				check("0001","0002");
				cout<<"x:"<<x<<endl<<"y:"<<y<<endl<<"Maze_Map[x][y]:"<<Maze_Map[x][y]<<endl;
				PAUSE;
				break;
				}
			}
		//...
		}
	}

void CG_2(){
	//�ڶ��� 
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              -                                                            -                                              -"<<endl;//
	cout<<"-                                                                                                                                           -              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                      �ڶ���                                                            *********                                                         -"<<endl;//
	cout<<"-                                         -                    **          ****        *************                                                       -"<<endl;//
	cout<<"-                                                                     ****      **    ***************                                                      -"<<endl;//
	cout<<"-                                   ����                *                   **    *********     *****                         -                            -"<<endl;//
	cout<<"-                                                                    ** *     ***********          **                                                      -"<<endl;//
	cout<<"-                                                                          *************            *                                        *******       -"<<endl;//
	cout<<"-                   -       --      -   *      **                ***    ** ***************        **                                        *       *      -"<<endl;//
	cout<<"-            -      -                                               ***    ***********    ********                                          *       *      -"<<endl;//
	cout<<"-              -                                         **            ***     ****         *  *                                            *       *      -"<<endl;//
	cout<<"-                                                                   ***                    ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        *  *     *                                         *       *      -"<<endl;//
	cout<<"-                                                                                       *  **    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                      *  * *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  *__   *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        * |  |  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *|__|  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                   * *    *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                                   * * *   *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                          * *        *     *       *      -"<<endl;//
	cout<<"-                                                                                          *    *                         * * *       *********************-"<<endl;//
	cout<<"-                                                                                          *    *                           *    *****                     -"<<endl;//
	cout<<"-                                                                                          *    *                           *****                          -"<<endl;//
	cout<<"-                                                                                          *    *                      *****                               -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                *****************                       ******************                                                -"<<endl;//
	cout<<"-                                            *************************               **************************                                            -"<<endl;//
	cout<<"-                                          *******************************         ******************************                                          -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                        ***********************************     ***********************************                                       -"<<endl;//
	cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||                                   |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||            *         *            |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||          *             *          |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||        *                 *        |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||      *                     *      |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||    *                         *    |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||  *                             *  |||||                                                      -"<<endl;//
	cout<<"-                                                       |||||*                                 *|||||                                                      -"<<endl;//
	cout<<"-                                                       |||*                                     *|||                                                      -"<<endl;//
	cout<<"-                                                        *                                         *                                                       -"<<endl;//
	cout<<"-                                                      *                                             *                                                     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ���Ҹ��ط�����Ӫ�ذɡ�                                                                                                                 *     -"<<endl;// 
	cout<<"-    *        (�ոյ�Slime�ö��ģ����϶���ģ��Ͽ��Ҹ��ط�ϴ��)                                                                                    *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                      ����һ�ᣬ���ҵ���һЩ�ʺ���Ӫ�ĵط�.               -"<<endl;//
	cout<<"-                                                                                               *                                    *                     -"<<endl;//
	cout<<"-                                                                                              ***  *              *                ***      *             -"<<endl;//
	cout<<"-                                                                                   *      *  ********      *     ***      *       *****    ***            -"<<endl;//
	cout<<"-                                                                                  ***    ***   | *****    ***   *****    ***        |     *****           -"<<endl;//
	cout<<"-                                                                                 *****  *****  |   |     *****    |     *****       |       |             -"<<endl;//
	cout<<"-                                                                                   |      |    |   |       |      |       |         |       |             -"<<endl;//
	cout<<"-                                                             Ȫˮ��                |      |    |   |       |      |       |     *                *        -"<<endl;//
	cout<<"-                                                                                 *   *    |    |   |       |      |  *                                   *-"<<endl;//
	cout<<"-                                                        *  ~     ~   ~    ~  **            *     *           *                                            -"<<endl;//
	cout<<"-                                                           *   ~    ~   ~ *                                                                               -"<<endl;//
	cout<<"-                                                    *           *    *                                                                                    -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              *                                                                                                           -"<<endl;//
	cout<<"-                                           *                                                                                                              -"<<endl;//
	cout<<"-                                      *                                                                                                                   -"<<endl;//
	cout<<"-                                  *                                                                                                                       -"<<endl;//
	cout<<"-                              *                                                                                                                           -"<<endl;//
	cout<<"-                          *                                                                                                                               -"<<endl;//
	cout<<"-                       *                                                                                                                                  -"<<endl;//
	cout<<"-                     *                                                                                                                                    -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        1.������ɽ���Ե�һ��Ȫˮ�����������֡�                                                                                                 *     -"<<endl;//
	cout<<"-    *          �������������ʺ���Ӫ����ɭ������ܻ���Ұ�޳�û��                                                                                     *     -"<<endl;// 
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                      ����һ�ᣬ���ҵ���һЩ�ʺ���Ӫ�ĵط�.               -"<<endl;//
	cout<<"-                                                                                               *                                    *                     -"<<endl;//
	cout<<"-                                                                                              ***  *              *                ***      *             -"<<endl;//
	cout<<"-                                                                                   *      *  ********      *     ***      *       *****    ***            -"<<endl;//
	cout<<"-                                                                                  ***    ***   | *****    ***   *****    ***        |     *****           -"<<endl;//
	cout<<"-                                                                                 *****  *****  |   |     *****    |     *****       |       |             -"<<endl;//
	cout<<"-                                                                                   |      |    |   |       |      |       |         |       |             -"<<endl;//
	cout<<"-                                                                                   |      |    |   |       |      |       |     *                *        -"<<endl;//
	cout<<"-                                                                                 *   *    |    |   |       |      |  *                                   *-"<<endl;//
	cout<<"-                                                        *  ~     ~   ~    ~  **            *     *           *                                            -"<<endl;//
	cout<<"-                                                           *   ~    ~   ~ *                                                                               -"<<endl;//
	cout<<"-                                                    *           *    *                                                                                    -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              *                                                                                                           -"<<endl;//
	cout<<"-                                           * * *  * *                                                                                                     -"<<endl;//
	cout<<"-                                    ��Ѩ�� /  /  /  / *                                                                                                   -"<<endl;//
	cout<<"-                                  * *                 *                                                                                                   -"<<endl;//
	cout<<"-                              *        *   *  *    *                                                                                                      -"<<endl;//
	cout<<"-                          *                                                                                                                               -"<<endl;//
	cout<<"-                       *                                                                                                                                  -"<<endl;//
	cout<<"-                     *                                                                                                                                    -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        2.����һ����Ѩ,���������ɾ��ģ����Ե���Ӫ�ء�                                                                                          *     -"<<endl;//
	cout<<"-    *          ��ˮ�Ƚ�Զ��ϴ���Ƚ��鷳����ʮ�ְ�ȫ�����õ��ı���Χ����                                                                         *     -"<<endl;// 
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                             _                                                                                            -"<<endl;//
	cout<<"-                                                          |\\/ \\/|                                                                                         -"<<endl;//
	cout<<"-                                                          |+ + +|                                     ����һ�ᣬ���ҵ���һЩ�ʺ���Ӫ�ĵط�.               -"<<endl;//
	cout<<"-                                                          |_____|                                                                                         -"<<endl;//
	cout<<"-                                                          *     *                                                                                         -"<<endl;//
	cout<<"-                                                      *           *                                                                                       -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                   *                *                                                                                  *  -"<<endl;//
	cout<<"-                                                                                                                                           *  *   *       -"<<endl;//
	cout<<"-      *                                          *                    *             * *                             *      *            *                 -"<<endl;//
	cout<<"-   *     *                                    *   *                              *       *                   *                        *                   -"<<endl;//
	cout<<"- *                                 *   *  *                             *     *                        *                       *    *                     -"<<endl;//
	cout<<"-*          *                     *              *                         * *                *                                    *                       -"<<endl;//
	cout<<"-                    * *         *             *                             *                     *                              *                        -"<<endl;//
	cout<<"-             *    *            *                                                               *             * *                                          -"<<endl;//
	cout<<"-               *          *    *            *                                  *               *         *        *                                       -"<<endl;//
	cout<<"-                              *                                                                       *                           *                       -"<<endl;//
	cout<<"-                *            *            *                                      *                *                  *                                    -"<<endl;//
	cout<<"-                           *                                                                       *                                                      -"<<endl;//
	cout<<"-                        *               *                                          *               *                   *           *                      -"<<endl;//
	cout<<"-                  *  *                                                                                                                                    -"<<endl;//
	cout<<"-                                                                                     *                *                                                   -"<<endl;//
	cout<<"-                    *                 *                                                 *               *               *           *                     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        3.������ɽ���ϵ�����������Ұ�����������п��Ծ�ס�ķ��䣬�޴����Ȫ���豸��ȫ��                                                     *     -"<<endl;//
	cout<<"-    *          �������Χ���Ǳ���ʥ�������������Ķ�ħ�е������Ǳ�����������ȴ���ҽ�����                                                         *     -"<<endl;// 
	cout<<"-    *          ֻҪ�ܽ������Ͳ��õ���Σ�յ����⡣                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                               *                                    *                     -"<<endl;//
	cout<<"-                                                                                              ***  *              *                ***      *             -"<<endl;//
	cout<<"-                                                                                   *      *  ********      *     ***      *       *****    ***            -"<<endl;//
	cout<<"-                                                                                  ***    ***   | *****    ***   *****    ***        |     *****           -"<<endl;//
	cout<<"-                                                                                 *****  *****  |   |     *****    |     *****       |       |             -"<<endl;//
	cout<<"-                                                                                   |      |    |   |       |      |       |         |       |             -"<<endl;//
	cout<<"-                                                                                   |      |    |   |       |      |       |     *                *        -"<<endl;//
	cout<<"-                                                                                 *   *    |    |   |       |      |  *                                   *-"<<endl;//
	cout<<"-                                                        *  ~     ~   ~    ~  **            *     *           *                                            -"<<endl;//
	cout<<"-                                                           *   ~    ~   ~ *                                                                               -"<<endl;//
	cout<<"-                                                    *           *    *                                                                                    -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              *                                                                                                           -"<<endl;//
	cout<<"-                                           * * *  * *                                                                                                     -"<<endl;//
	cout<<"-                                                      *                                                                                                   -"<<endl;//
	cout<<"-                                  * *                 *                                                                                                   -"<<endl;//
	cout<<"-                              *        *   *  *    *                                                                                                      -"<<endl;//
	cout<<"-                          *                                                                                                                               -"<<endl;//
	cout<<"-                       *                                                                                                                                  -"<<endl;//
	cout<<"-                     *                                                                                                                                    -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ��ô����Ҫȥ����ȹ�ҹ���أ�  [1.Ȫˮ]  [2.��Ѩ]  [3.���]                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;// 
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	while(1){
		bool t=0;
		switch(_getch()){
			case '1':
				CG_2_1();
				t=1;
				break;
			case '2':
				CG_2_2();
				t=1;
				break;
			case '3':
				CG_2_3();
				t=1;
				break;
			}
		if(t)
			break;
		}
	
	
	}
void CG_2_1(){
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                      ����Ȫˮ��װ�������ª��С����                    -"<<endl;//
	cout<<"-                                                                                                      Ȼ��ȥϴ�˸��裬Ȼ���û��hahaha                    -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;// 
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	} 
void CG_2_2(){
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-         ������ּ���Щľͷ���˻�                                                                                                                       -"<<endl;//
	cout<<"-         ���˵�Ȫˮ���˵㿪ˮ��                                                                                                                           -"<<endl;//
	cout<<"-         ��ɫ�����䰵...                                                                                                                                  -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *    Alice:                                                                                                                                     *     -"<<endl;//
	cout<<"-    *        ��������ˣ���ô����                                                                                                                 *     -"<<endl;//
	cout<<"-    *        �����ˣ����첻ϴ���ˣ�����һ�°ɡ�                                                                                                     *     -"<<endl;// 
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-         ���̺ô���                                                                                                                                       -"<<endl;//
	cout<<"-         ���ڴ��ϻ���˯ȥ...                                                                                                                              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;// 
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	
	
	PAUSE;
	}
void CG_2_3(){
	
	}



/*
taskkill /f /im StudentMain.exe
	//CG_1_6
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//P
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                              -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
		//P
		CLS;
		end(1); 
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
*/
