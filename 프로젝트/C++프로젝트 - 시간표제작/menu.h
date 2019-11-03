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
	string subject_of_study; // 학과 
};
 
Info main_info;	//전역변수로 개인정보저장 

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
		"학년 및 학과입력",
		"전공 목록",
		"교양 목록",
		"시간표 담기",
		"텍스트 출력",
		"프로그램종료"
	};
	
	cout<<"2015학년도 2학기 시간표 제작 프로그램"<<endl;
	cout<<"┌────────────────────────────┐"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"│ "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" │"<<endl;
		}
	cout<<"└────────────────────────────┘"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
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
		"추천수강목록",
		"전공목록",
		"뒤로가기",
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"전공과목  메뉴창"<<endl;
	cout<<"┌────────────────────────────┐"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"│ "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" │"<<endl;
		}
	cout<<"└────────────────────────────┘"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
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
		"인문사회교양",
		"과학기술교양",
		"사회역사교양",
		"BSM교양 과목",
		"뒤로가기"
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"교양과목 메뉴창"<<endl; 
	cout<<"┌────────────────────────────┐"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"│ "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" │"<<endl;
		}
	cout<<"└────────────────────────────┘"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
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
		"시간표1에 저장",
		"시간표2에 저장",
		"시간표3에 저장",
		"저장하지 않음",
		"뒤로가기"
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"시간표 설정창"<<endl;
	cout<<"┌────────────────────────────┐"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"│ "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" │"<<endl;
		}
	cout<<"└────────────────────────────┘"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
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
		"시간표 1",
		"시간표 2",
		"시간표 3",
		"시간표 4"
	};
	
	system("cls");
	system("mode con lines=20 cols=80");
	cout<<"┌────────────────────────────┐"<<endl;
		for(int i=1; i<=number_menu; i++){
			cout<<"│ "<<i<<". ";
			if(i==1){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			}
			cout<<menu[i];
			for(int j=0; j<51-menu[i].size(); j++){
				cout<<" ";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout<<" │"<<endl;
		}
	cout<<"└────────────────────────────┘"<<endl;
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
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


