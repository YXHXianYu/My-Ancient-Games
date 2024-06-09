#include<algorithm>
#include<windows.h>
#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
#define PAUSE system("pause")                         //��ͣ 
#define CLS system("cls")                             //���� 
#define COLOR_Basic system("color f5")                //��ʼ����ɫ
#define TITLE_Basic system("title ������˵                                                                                  by.YXH����") 
#define MODE_Basic system("mode con cols=80 lines=25")//��ʼ������ 1��80���ַ� 1��25���ַ� 
#define MODE_Up system("mode con cols=157 lines=36"); //��ʼ������ 1��80���ַ� 1��36���ַ� 
#define FIGHT_Basic Fight_ChuShiHua(1)                //��ʼ��ս��ϵͳ
#define D20 Random(1,20)

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
}Hero;

struct monster{
	int money,
		hp,
		ac,
		dmg,
		speed;
	char name[100];
};

bool have_demo=0;//


void end(int n);                //���� 
void space(int n);              //�ո�
void check();                   //��麯��
void Loading();                 //���ؽ��� 
int Random(int low,int high);   //�������
int Change_a_little(int n);     //���Ե���ֵ[3r] 
void Skill();
void Fight(int kind);           //Fight

void Fight_ChuShiHua(int kind); //ս����ʼ�� 
void Fight_CG(int n,int a);
void Demo();
void Input_Name();
void Output_Name();
void Hide_Cur();

void Menu();                    //�˵�
void Play();                    //��ʼ��Ϸ 
void Map();                     //�鿴��ͼ 
void Maker_List();              //���������� 

void CG_1();                    //��һ��CG 
void CG_1_Maze();                  //��һ��Maze
void CG_2();                    //�ڶ���CG 

int main(){
	
	COLOR_Basic;
	TITLE_Basic;
	MODE_Basic;
	Hide_Cur();
	//have_demo=1;
	Menu();
	PAUSE;
	
	return 0;
	}


void end(int n){
	for(int i=1;i<=n;i++)
		cout<<endl;
	}

void space(int n){
	for(int i=1;i<=n;i++)
		cout<<" ";
	}

void check(){
	CLS;
	cout<<"�������bug!!!\n(���ƺ����������ߵİ���)\n";
	cout<<"�����������߻㱨\n";
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
	int temp=rand()%high+low;
	if(temp>high)
		temp=temp-high+low;
	return temp;
	}

int Change_a_little(int n){
	return n/2-5;
	}

void Skill(monster * m,bool * if_out){
	char in;
	while(in != '1'){
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
					cout<<"2.�ķ�ն";
					space(7);
					break;
					}
				case 3:{
					cout<<Hero.skill_sum<<".ȡ��";
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
						Fight_CG(3,0);
						break;
						}
					Hero.sp--;
					int hurts=Hero.dmg*5+Random(10,20);
					Fight_CG(12,hurts);
					m -> hp -= hurts;
					break;
					}
				case '2':{
					if(Hero.sp<=2){
						Fight_CG(3,0);
						break;
						}
					Hero.sp-=3;
					int hurts=Hero.dmg*5+Random(10,20);
					Fight_CG(12,hurts);
					m -> hp -= hurts;
					break;
					break;
					}
				case '3':{
					*if_out=true;
					return;
					}
				}
		}
	}

void Fight(int kind){
	monster m;
	if(kind==1){//Skeleton
		m.ac=0;
		m.dmg=1;
		m.speed=1;
		m.hp=50;
		}
	if(kind==2){//
		
		}
	char in;
	do{
		//Fight_1
		if(kind==1){//CG_1
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
			cout<<"-   *    1.����    2.����    HP:"<<Hero.hp<<"\t\t                          *   -"<<endl;//
			cout<<"-   *    3.����    4.����    SP:"<<Hero.sp<<"\t\t                          *   -"<<endl;// 
			cout<<"-   *                                                                     *   -"<<endl;//
			cout<<"-   ***********************************************************************   -"<<endl;//
			cout<<"-                                                                             -"<<endl;//
			cout<<"-------------------------------------------------------------------------------"<<endl;//
			}
		in=_getch();
		int luck=D20;
		int hurts;
		switch(in){
			case '1':{
				if(luck>18 && luck<=20){
					hurts=Change_a_little(Random(9,14))+Hero.dmg;
					if(hurts<0) hurts=0;
					Fight_CG(4,hurts*2);
					m.hp-=hurts*2;
					}
				if(luck>10 && luck<=18){
					hurts=Change_a_little(Random(9,14))+Hero.dmg;
					if(hurts<0) hurts=0;
					Fight_CG(8,hurts);
					m.hp-=hurts;
					}
				if(luck<=10 && luck>=0){
					hurts=Change_a_little(Random(9,14))+Hero.dmg-m.ac;
					if(hurts<0) hurts=0;
					Fight_CG(9,hurts);
					m.hp-=hurts;
					}
				if(luck>20 || luck<0){
					check();
					cout<<luck<<endl;
					PAUSE;
					}
				if(m.hp<=0)
					break;
				hurts=Change_a_little(Random(9,14))+Hero.dmg-m.ac;
				if(hurts<0) hurts=0;
				Fight_CG(7,hurts);
				Hero.hp-=hurts;
				break;
				}
			case '2':{
				int hurts=Change_a_little(Random(9,14))-Hero.ac+m.dmg;
				if(hurts<0) hurts=0;
				Fight_CG(5,hurts);
				Hero.hp-=hurts;
				Hero.sp++;
				break;
				}
			case '3':{
				bool if_out=0;
				if(Hero.skill_sum==0)
					Fight_CG(3,0);
				else
					Skill(&m,&if_out);
				if(m.hp<=0)
					break;
				if(if_out)
					break;
				hurts=Change_a_little(Random(9,14))+Hero.dmg-m.ac;
				if(hurts<0) hurts=0;
				Fight_CG(7,hurts);
				Hero.hp-=hurts;
				break;
				}
			case '4':{
				Fight_CG(6,0);
				break;
				}
			}
		if(m.hp<=0){
			Fight_CG(0,0);
			Hero.exp++;
			Hero.hp=Hero.hp_max;
			Hero.sp=Hero.sp_max;
			return;
			}
		if(Hero.hp<=0){
			return;
			}
	}while(1);
	
	}

inline void Menu(){
	int p=1,max_p=4;
	char ch=0;
	while(1){
		CLS;
		end(1);
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
			if(p==i)
				cout<<"->   ";
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
				case 3:
					cout<<" �˳���Ϸ";
					space(7);
					break;
				case 4:
					cout<<" ����������";
					space(5);
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
		cout<<"-  W S ����Enter ���вٿ�                              ������:MS Game Studio  -"<<endl;//
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
				case 3:
					exit(0); 
					break;
				case 4:
					CLS;
					Maker_List();
					break;
				default:
					break;
				}
			}
		}
	
	PAUSE;
	}

void Play(){
	
	FIGHT_Basic;
	//CG_1();
	if(have_demo){
		Demo();
		return;
		}
	MODE_Up;
	CG_2();
	MODE_Basic;
	
	}

void Map(){
	//Map
	CLS;
	end(1);
	cout<<"-------------------------------------------------------------------------------"<<endl;// 
	cout<<"-                                       *                                     -"<<endl;//[phiya]��[�����۹�]���׶������������ҵĺ��ġ�
	cout<<"-  <��������Ĺ���> ������½��ͼ       *                                      -"<<endl;//
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
	cout<<"-  # ����    ~        ~      ******              #Ken City                    -"<<endl;//
	cout<<"-  ~ ��           ~      ~         *                                          -"<<endl;//
	cout<<"-  / ɳĮ   ~                        *                                         -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//Map
	CLS;
	end(1);
	cout<<"-------------------------------------------------------------------------------"<<endl;// 
	cout<<"-                                       *                                     -"<<endl;//
	cout<<"-  <��������Ĺ���> ������½��ͼ       *          [phiya]��[�����۹�]���׶��� -"<<endl;//
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
	cout<<"-                                    ������                                   -"<<endl;Sleep(500);
	cout<<"-                                MS Game Studio                               -"<<endl;Sleep(500);
	end(1);Sleep(500);
	cout<<"-                                  ����������                                 -"<<endl;Sleep(500);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(500);
	end(1);Sleep(500);
	cout<<"-                                  ����������                                 -"<<endl;Sleep(500);
	cout<<"-                                 MS.YXH_XianYu                               -"<<endl;Sleep(500);
	end(1);Sleep(500);
	cout<<"-                            ������������Ϸ�й�����                           -"<<endl;Sleep(500);
	cout<<"-                                 MS.DWTornier                                -"<<endl;Sleep(500);
	cout<<"-                                MS.HYH_BlueCat                               -"<<endl;Sleep(500);
	cout<<"-                                 MS.IceLocke                                 -"<<endl;Sleep(500);
	cout<<"-                                      CC                                     -"<<endl;Sleep(500);
	cout<<"-                      (������������˽��QQ:2258488076)                      -"<<endl;Sleep(500);
	for(int i=1;i<=6;i++){
		end(1);
		Sleep(500);
		} 
	Sleep(2500);
	PAUSE;
	
	}

void Fight_ChuShiHua(int kind){
	switch(kind){
		case 1://Isaac
			Hero.ac=2;
			Hero.dmg=3;
			Hero.hp_max=50;
			Hero.sp_max=0;
			Hero.money=0;
			Hero.speed=1;
			Hero.skill_sum=1;
			Hero.skill[1]=true;//����ն
			Hero.level=1;
			Hero.exp=0;
			break;
		case 2://Eden
			Hero.ac=1;
			Hero.dmg=3;
			Hero.hp=30;
			Hero.hp_max=50;
			Hero.sp=0;
			Hero.sp_max=0;
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

void Fight_CG(int n,int a){
	/*
	0.ս��ʤ��! 
	1.���ܳɹ� 
	2.����ʧ�� 
	3.û�м��� 
	4.CG_1���� 
	5.CG_1���� 
	6.CG_1����ʧ�� 
	*/
	if(n==0){//0.ս��ʤ��! 
		CLS;
		end(1); 
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
		PAUSE;
		}
	if(n==1){
		;
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
	if(n==4){//4.CG_1_����_��_�ػ� 
		
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
		cout<<"-   *                       �ػ�������սʿ������                          *   -"<<endl;//
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==5){//5.CG_1_����_�� 
		
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
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==6){//6.CG_1_����ʧ�� 
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
	if(n==7){//7.CG_1_�ܵ�����
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
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
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
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
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
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==8){//8.CG_1_����_��_���� 
		
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
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
		PAUSE;
		}
	if(n==9){//9.CG_1_�������� 
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
	if(n==12){//12.CG_1_����ն 
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
		cout<<"-   *                               <"<<a<<">\t                                  *   -"<<endl;//
		cout<<"-   *                                                                     *   -"<<endl;//
		cout<<"-   ***********************************************************************   -"<<endl;//
		cout<<"-                                                                             -"<<endl;//
		cout<<"-------------------------------------------------------------------------------"<<endl;//
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

void CG_1(){
	//��һ�� 
	CLS;
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-                      ��һ��                                                 -"<<endl;//
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
	cout<<"-   *  <Niya>:<���>                                                      *   -"<<endl;//
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
	cout<<"-   *      ���������ҵ��ˣ�                                               *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
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
	cout<<"-   *      ��˵������Ken.Caesar���µı��أ�                               *   -"<<endl;//
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
	cout<<"-   *      �ҵ��Ļ��ͷ�������                                             *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
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
	cout<<"-   *      �úڰ������ֲ���ĸо�...                                      *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	
	CG_1_Maze();
	
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
	cout<<"-   *      Ŷ���ҵ��ˣ�                                                   *   -"<<endl;//
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
	cout<<"-   *      ���ڣ��ҵĵ�һ��ս����Ҫ��ʼ����������Ȳ��������أ�         *   -"<<endl;//
	cout<<"-   *      �ڵ۹��ʼ�ѧԺ��ѧ�Ľ���������ڿ��������ó��ˣ�             *   -"<<endl;//
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
	cout<<"-   *                    ���ó��˸��������ľ��                           *   -"<<endl;//
	cout<<"-   *                          <����+1>                                   *   -"<<endl;//
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	Hero.dmg++;
	PAUSE;
	
	Fight(1);
	
	if(Hero.hp<=0){
		Fight_CG(11,0);
		Fight_CG(10,0);
		return;
		}
	
	//CG_1_14
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
	cout<<"-   *                            �㽫���պ�                               *   -"<<endl;//
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
	cout<<"-   *                                                                     *   -"<<endl;//
	cout<<"-   ***********************************************************************   -"<<endl;//
	cout<<"-                                                                             -"<<endl;//
	cout<<"-------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	}

void CG_1_Maze(){
	
	char ch;
	while(ch!='1' && ch!='2' && ch!='l' && ch!='r'){
		Maze_1_goto:
		//Maze-Start-1
		CLS;
		end(1);
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
	end(1);
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
		end(1);
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
		end(1);
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
		end(1);
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
		end(1);
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
		end(1);
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
	cout<<"-                                                                                        *  *    *                                          *       *      -"<<endl;//
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
	//CG_2_1
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        ����                                                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_2
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        ������                                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_3
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        (��)                                                                                                                                   *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_4
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        ��                                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_5
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        �������ˡ�                                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_6
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ����վ��һ��΢Ц�Ĵ󺺣�����һ���޴�İ�����       -"<<endl;//
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
	cout<<"-    *    Reno����:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        ��������ѧԺ�ĸ���İ�����                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_7
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ���ǵ۹��ʼ�ѧԺ�Ľ�����                           -"<<endl;//
	cout<<"-                                                                                                       Сʱ�����͸���һ���������                         -"<<endl;//
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        Ŷ��лл��                                                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_8
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ��Ϊ��ǰ���׺��������ڼҺȾƣ�                     -"<<endl;//
	cout<<"-                                                                                                       ������Ҳ�������졣                                 -"<<endl;//
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
	cout<<"-    *    Reno����:                                                                                                                                  *     -"<<endl;//
	cout<<"-    *        ���ε��ˣ�����ô��ɥ������������Ҫ�Ķ�����                                                                                             *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_9
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       ��һֱ�����۹��ʼ�ѧԺ����ѧϰ��                 -"<<endl;//
	cout<<"-                                                                                                       ��Ҳ֪�����ѵ���Ū�������ˣ�                       -"<<endl;//
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        ʲô����                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_10
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
	//CG_2_10
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        �ţ�ллReno���塣                                                                                                                     *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_11
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
	//Big_Map//CG_2_12
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
	cout<<"-                                      -  <��������Ĺ���> ������½��ͼ       *                                      -                                     -"<<endl;//
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
	//CG_2_13
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
	//CG_2_14
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        Ŷ�����ˡ��һ�Ҫ����ĸ�����µ�������ϣ�����ܸ��Һ��ˡ�                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_15
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
	cout<<"-    *    Eden:                                                                                                                                      *     -"<<endl;//
	cout<<"-    *        ������                                                                                                                                 *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *                                                                                                                                               *     -"<<endl;//
	cout<<"-    *************************************************************************************************************************************************     -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_16
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                              -                                                            -                                              -"<<endl;//
	cout<<"-                                                                                                                                           -              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                        *********                                                         -"<<endl;//
	cout<<"-                                         -                    **          ****        *************                                                       -"<<endl;//
	cout<<"-                                                                     ****      **    ***************                                                      -"<<endl;//
	cout<<"-                                                       *                   **    *********     *****                         -                            -"<<endl;//
	cout<<"-                                                                    ** *     ***********          **                                                      -"<<endl;//
	cout<<"-                                                                          *************            *                                        *******       -"<<endl;//
	cout<<"-                   -       --      -   *      **                ***    ** ***************        **                                        *       *      -"<<endl;//
	cout<<"-            -      -                                               ***    ***********    ********                                          *       *      -"<<endl;//
	cout<<"-              -                                         **            ***     ****         *  *                                            *       *      -"<<endl;//
	cout<<"-                                                                   ***                    ******                                           *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        *  *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  **    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                      *  * *    *                                          *       *      -"<<endl;//
	cout<<"-                                                                                       *  *__   *                                          *       *      -"<<endl;//
	cout<<"-                                                                                        * |  |  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *|__|  *                                          *       *      -"<<endl;//
	cout<<"-                                                                                         ********                                          *       *      -"<<endl;//
	cout<<"-                                                                                         *      *                                          *       *      -"<<endl;//
	cout<<"-    ******************************************************************                   *      *                                          *       *      -"<<endl;//
	cout<<"-    *    Eden:                                                       *                   ********                                   * *    *       *      -"<<endl;//
	cout<<"-    *        ĸ�ס�                                                  *                    *    *                                   * * *   *       *      -"<<endl;//
	cout<<"-    *        ��Ҫ�뿪�����ˣ�ϣ���������ҲҪ���ÿ��ġ�              *                    *    *                          * *        *     *       *      -"<<endl;//
	cout<<"-    *        �����Ұɣ�                                              *                    *    *                         * * *       *********************-"<<endl;//
	cout<<"-    *                                                                *                    *    *                           *    *****                     -"<<endl;//
	cout<<"-    ******************************************************************                    *    *                           *****                          -"<<endl;//
	cout<<"-                                                                                          *    *                      *****                               -"<<endl;//
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	PAUSE;
	//CG_2_17
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
	//CG_2_18 
	CLS;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                       �Ͼ��ǵ�һ���뿪[Ken City]��                       -"<<endl;//
	cout<<"-                                                                                                       �ҵ����黹��ʮ�����ġ�                           -"<<endl;//
	cout<<"-                                                                                                       ���ǣ����������ĽŲ���                           -"<<endl;//
	cout<<"-                                                                                                       �߽���[Ken City]���ߵ�[Iron Forest]��              -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                                                                                                          -"<<endl;//
	cout<<"-                                                                       ***       ***                                                                      -"<<endl;//
	cout<<"-                                                                     *******   *******                                                                    -"<<endl;//
	cout<<"-                                                                    ********* *********                                                                   -"<<endl;//
	cout<<"-                                                                    ********* *********                                                                   -"<<endl;//
	cout<<"-                                                               ***      |         |      ***                                                              -"<<endl;//
	cout<<"-                                                             *******    |         |    *******                                                            -"<<endl;//
	cout<<"-                                                            *********   |         |   *********                                                           -"<<endl;//
	cout<<"-                                                            *********   |   * *   |   *********                                                           -"<<endl;//
	cout<<"-                                                                |       | *     * |       |                                                               -"<<endl;//
	cout<<"-                                                                |       *         *       |                                                               -"<<endl;//
	cout<<"-                                                                |     *             *     |                                                               -"<<endl;//
	cout<<"-                                                                |   *                 *   |                                                               -"<<endl;//
	cout<<"-                                                                | *                     * |                                                               -"<<endl;//
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
	}
 
/*
	//CG_2_6
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
