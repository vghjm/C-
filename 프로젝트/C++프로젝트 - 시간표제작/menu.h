#include<iostream>
#include<windows.h>
#include<conio.h>



#define N_MAIN_MENU 6
#define N_TABLE_MENU 4
#define N_MAJOR_MENU 3
#define N_CULTURE_MENU 5
#define N_LIMIT 13
#define N_TABLE 5
#define LEFT   75
#define RIGHT  77
#define UP       72
#define DOWN  80
#define ESC     27
#define SPACE 32
#define FUN1    59
#define FUN2    60
#define ENTER 13

using namespace std;

bool is_end = false;

typedef struct Info{
	int year;
	string subject_of_study; // �а� 
};
 
Info main_info;	//���������� ������������ 

void gotoxy(int x, int y){
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
}



int main_menu(void){
	int ch;
	int instruction = 1;
	int number_menu = N_MAIN_MENU;
	int pre_inst;
	string menu[] = {
		" ",
		"�г� �� �а��Է�",
		"���� ���",
		"���� ���",
		"�ð�ǥ ���",
		"�ؽ�Ʈ ���",
		"���α׷�����"
	};
	
	cout<<"2015�г⵵ 2�б� �ð�ǥ ���� ���α׷�"<<endl;
	cout<<"������������������������������������������������������������"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"�� "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" ��"<<endl;
		}
	cout<<"������������������������������������������������������������"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//�Է¹��� ���� Ȯ��Ű �̸�
			ch = getch();  //�ѹ��� �Է��� �޴´�.
			pre_inst = instruction;
			switch(ch){
				case LEFT:
					instruction--;
					break;
				case RIGHT:
					instruction++;
					break;
				case UP:
					instruction--;
					break;
				case DOWN:
					instruction++;
					break;
			}
			if(instruction<1){
				instruction	= 1;
			}else if(instruction>number_menu){
				instruction = number_menu;
			}
			gotoxy(6, pre_inst+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << menu[pre_inst];
			gotoxy(6, instruction+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << menu[instruction];
			
			
		}else if(ch==ENTER){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}
	}while(1);
	
	return instruction;
}

int major_menu(void){
	int ch;
	int instruction = 1;
	int number_menu = N_MAJOR_MENU;
	int pre_inst;
	string menu[] = {
		" ",
		"��õ�������",
		"�������",
		"�ڷΰ���",
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"��������  �޴�â"<<endl;
	cout<<"������������������������������������������������������������"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"�� "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" ��"<<endl;
		}
	cout<<"������������������������������������������������������������"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//�Է¹��� ���� Ȯ��Ű �̸�
			ch = getch();  //�ѹ��� �Է��� �޴´�.
			pre_inst = instruction;
			switch(ch){
				case LEFT:
					instruction--;
					break;
				case RIGHT:
					instruction++;
					break;
				case UP:
					instruction--;
					break;
				case DOWN:
					instruction++;
					break;
			}
			if(instruction<1){
				instruction	= 1;
			}else if(instruction>number_menu){
				instruction = number_menu;
			}
			gotoxy(6, pre_inst+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << menu[pre_inst];
			gotoxy(6, instruction+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << menu[instruction];
			
			
		}else if(ch==ENTER){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}
	}while(1);
	
	return instruction;
}

int culture_menu(void){
	int ch;
	int instruction = 1;
	int number_menu = N_CULTURE_MENU;
	int pre_inst;
	string menu[] = {
		" ",
		"�ι���ȸ����",
		"���б������",
		"��ȸ���米��",
		"BSM���� ����",
		"�ڷΰ���"
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"������� �޴�â"<<endl; 
	cout<<"������������������������������������������������������������"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"�� "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" ��"<<endl;
		}
	cout<<"������������������������������������������������������������"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//�Է¹��� ���� Ȯ��Ű �̸�
			ch = getch();  //�ѹ��� �Է��� �޴´�.
			pre_inst = instruction;
			switch(ch){
				case LEFT:
					instruction--;
					break;
				case RIGHT:
					instruction++;
					break;
				case UP:
					instruction--;
					break;
				case DOWN:
					instruction++;
					break;
			}
			if(instruction<1){
				instruction	= 1;
			}else if(instruction>number_menu){
				instruction = number_menu;
			}
			gotoxy(6, pre_inst+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << menu[pre_inst];
			gotoxy(6, instruction+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << menu[instruction];

			
		}else if(ch==ENTER){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}
	}while(1);
	
	return instruction;
}

int table_menu(void){
	int ch;
	int instruction = 1;
	int number_menu = N_TABLE_MENU;
	int pre_inst;
	string menu[] = {
		" ",
		"�ð�ǥ1�� ����",
		"�ð�ǥ2�� ����",
		"�ð�ǥ3�� ����",
		"�������� ����",
		"�ڷΰ���"
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"�ð�ǥ ����â"<<endl;
	cout<<"������������������������������������������������������������"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"�� "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" ��"<<endl;
		}
	cout<<"������������������������������������������������������������"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//�Է¹��� ���� Ȯ��Ű �̸�
			ch = getch();  //�ѹ��� �Է��� �޴´�.
			pre_inst = instruction;
			switch(ch){
				case LEFT:
					instruction--;
					break;
				case RIGHT:
					instruction++;
					break;
				case UP:
					instruction--;
					break;
				case DOWN:
					instruction++;
					break;
			}
			if(instruction<1){
				instruction	= 1;
			}else if(instruction>number_menu){
				instruction = number_menu;
			}
			gotoxy(6, pre_inst+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << menu[pre_inst];
			gotoxy(6, instruction+1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << menu[instruction];
			
			
		}else if(ch==ENTER){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}
	}while(1);
	
	return instruction;
}


int select_table(void){
	int ch;
	int instruction = 1;
	int number_menu = N_TABLE;
	int pre_inst;
	string menu[] = {
		" ",
		"�ð�ǥ 1",
		"�ð�ǥ 2",
		"�ð�ǥ 3",
		"�ð�ǥ 4"
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"������������������������������������������������������������"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"�� "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" ��"<<endl;
		}
	cout<<"������������������������������������������������������������"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//�Է¹��� ���� Ȯ��Ű �̸�
			ch = getch();  //�ѹ��� �Է��� �޴´�.
			pre_inst = instruction;
			switch(ch){
				case LEFT:
					instruction--;
					break;
				case RIGHT:
					instruction++;
					break;
				case UP:
					instruction--;
					break;
				case DOWN:
					instruction++;
					break;
			}
			if(instruction<1){
				instruction	= 1;
			}else if(instruction>number_menu){
				instruction = number_menu;
			}
			gotoxy(6, pre_inst);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << menu[pre_inst];
			gotoxy(6, instruction);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << menu[instruction];
			
			
		}else if(ch==ENTER){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}
	}while(1);
	
	return instruction;
}


