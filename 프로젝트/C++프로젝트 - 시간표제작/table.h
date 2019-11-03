#include<iostream>
#include<stdio.h>
#include "subject.h"
#include<windows.h>
#include<fstream>

using namespace std;

HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);

string day_[] = {
	"월",
	"화",
	"수",
	"목",
	"금"
};

int color[] = {
	2,
	3,
	4,
	5,
	6,
	8,
	9,
	10,
	11,
	12,
	13,
	13,
	13,
	13,
	13
};

void erase(int times){
	for(int i=0; i<times; i++)
		cout<<"                                                                                "<<endl;
	
}

void gotoxy2(int x, int y){
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
}

int wherex(){
   if (consoleHandler == INVALID_HANDLE_VALUE)
      return 0;
   CONSOLE_SCREEN_BUFFER_INFO screenInfo;
   GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);
   return screenInfo.dwCursorPosition.X + 1;
}

int wherey(){
   if (consoleHandler == INVALID_HANDLE_VALUE)
      return 0;
 CONSOLE_SCREEN_BUFFER_INFO screenInfo;
 GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);
   return screenInfo.dwCursorPosition.Y + 1;
}

class Table{
private:
	string table_name;
	Subject sub_list[21];
	int number_of_subject;
	int time_table[5][60];
	int grade;
public:	
	Table()
	:number_of_subject(0), grade(0){
		for(int i=0; i<5; i++){
			for(int j=0; j<60; j++){
				time_table[i][j] = 0;
			}
		}
	}
	bool check_time(Subject subject){
		
		for(int i=1; i<=number_of_subject; i++){
			for(int j=0; j<sub_list[i].get_n(); j++){
				Time a = sub_list[i].get_time(j);
				for(int k=0; k<subject.get_n(); k++){
					Time b = subject.get_time(k);
					if(a.day.compare(b.day) != 0){
						break;
					}
					int mas = a.hour[0]*60+a.hour[1];
					int maf = a.hour[2]*60+a.hour[3];
					int mbs = b.hour[0]*60+b.hour[1];
					int mbf = b.hour[2]*60+b.hour[3];
					if((mas<=mbs&&mbs<=maf)||(mas<=mbf&&mbf<=maf)||(mbs<=mas&&mas<=mbf)||(mbs<=maf&&maf<=mbf)){
						return false;
					}
				}
			
			}
		}
		
		return true;
	} 
	bool insert_subject(Subject subject){
		if(check_time(subject)){
			//cout<<"insert"<<endl;
			grade += subject.get_unit();
			number_of_subject++;
			sub_list[number_of_subject] = subject;
			for(int i=0; i<subject.get_n(); i++){
				Time a = subject.get_time(i);
				int imas = (a.hour[0]*60+a.hour[1])/15-36;
				int imaf = (a.hour[2]*60+a.hour[3])/15-36;
				int iday; 
				string day = a.day;
				if(day.compare("월")==0){
					iday = 0;	
				}else if(day.compare("화")==0){
					iday = 1;	
				}else if(day.compare("수")==0){
					iday = 2;	
				}else if(day.compare("목")==0){
					iday = 3;	
				}else if(day.compare("금")==0){
					iday = 4;	
				}else {
					
				}
				for(int j=imas; j<=imaf; j++){
					time_table[iday][j] = number_of_subject;
				}
			}
		}else{
			//cout<<"insert fail!"<<endl;
		}
	}
	bool insert_subject_force(Subject subject){
		
		grade += subject.get_unit();
		number_of_subject++;
		sub_list[number_of_subject] = subject;
		for(int i=0; i<subject.get_n(); i++){
			Time a = subject.get_time(i);
			int imas = (a.hour[0]*60+a.hour[1])/15-36;
			int imaf = (a.hour[2]*60+a.hour[3])/15-36;
			int iday; 
			string day = a.day;
			if(day.compare("월")==0){
				iday = 0;	
			}else if(day.compare("화")==0){
				iday = 1;	
			}else if(day.compare("수")==0){
				iday = 2;	
			}else if(day.compare("목")==0){
				iday = 3;	
			}else if(day.compare("금")==0){
				iday = 4;	
			}else {
				
			}
			for(int j=imas; j<=imaf; j++){
				time_table[iday][j] = -1;
			}
		}
	}
	void get_sub(){
		sub_list[number_of_subject].show_subject(); 
	}
	bool delete_subject(Subject subject){
		Subject delete_sub;
		int isfind = 0;
		if(number_of_subject==0){
			cout<<"더 이상 지울 수 없습니다."<<endl;
			return false;
		}
		//cout<<"delete"<<endl;
		for(int j=1; j<=number_of_subject; j++){
			delete_sub = sub_list[j];
			if(delete_sub.get_course_number().compare(subject.get_course_number()) == 0 ){
				grade -= subject.get_unit();
				isfind = j;
				for(int i=0; i<delete_sub.get_n(); i++){
					Time a = delete_sub.get_time(i);
					int imas = (a.hour[0]*60+a.hour[1])/15-36;
					int imaf = (a.hour[2]*60+a.hour[3])/15-36;
					int iday; 
					string day = a.day;
					if(day.compare("월")==0){
						iday = 0;	
					}else if(day.compare("화")==0){
						iday = 1;	
					}else if(day.compare("수")==0){
						iday = 2;	
					}else if(day.compare("목")==0){
						iday = 3;	
					}else if(day.compare("금")==0){
						iday = 4;	
					}else {
						
					}
					for(int j=imas; j<=imaf; j++){
						time_table[iday][j] = 0;
					}
				}
				for(int i=j+1; i<=number_of_subject; i++){
					sub_list[i-1] = sub_list[i];
				}
				number_of_subject--;
				re_initial();
				
				return true;
			}
		}

		return false;
	}
	
	void re_initial(){
		Subject sub;
		
		for(int i=0; i<5; i++){
			for(int j=0; j<60; j++){
				time_table[i][j] = 0;
			}
		}
		grade = 0;
		for(int i=1; i<=number_of_subject; i++){
			grade += sub_list[i].get_unit();
		}
		for(int i=1; i<=number_of_subject; i++){
			sub = sub_list[i];
			for(int j=0; j<sub.get_n(); j++){
				Time a = sub.get_time(j);
				int imas = (a.hour[0]*60+a.hour[1])/15-36;
				int imaf = (a.hour[2]*60+a.hour[3])/15-36;
				int iday; 
				string day = a.day;
				if(day.compare("월")==0){
					iday = 0;	
				}else if(day.compare("화")==0){
					iday = 1;	
				}else if(day.compare("수")==0){
					iday = 2;	
				}else if(day.compare("목")==0){
					iday = 3;	
				}else if(day.compare("금")==0){
					iday = 4;	
				}else {
					
				}
				for(int k=imas; k<=imaf; k++){
					time_table[iday][k] = i;
				}
			}
		}
	}
	
	void show_table(int mode){
		int t;
		int x, y;
		
		cout<<" 채워진 학점: "<<setw(3)<<grade<<endl; 
		cout<<"○09───10───11───12───13───14───15───16───17───18───19───20───21───22───23───24"<<endl;
		for(int i=0; i<5; i++){
			cout<<day_[i];
			for(int j=0; j<60; j++){
				t = time_table[i][j];
				if(j%4==0){
					if(t==0){
						cout<<"│";
					}else if(t==-1){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout<<"○";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}else{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[t]);
						cout<<"│";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}else if(t==0){
					cout<<setw(2)<<t;
				}else if(t==-1){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout<<setw(2)<<"○";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}else{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[t]);
					cout<<setw(2)<<t;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				
			}
			cout<<"│"<<endl;
		}
		cout<<"○09───10───11───12───13───14───15───16───17───18───19───20───21───22───23───24";
		if(mode == 1){
			x = wherex();
			y = wherey();
			y -= 6;
			x += 3;
			
			for(int i=1; i<=15; i++){
				gotoxy2(x, y+i-1);
				erase(1);
			}
				
			for(int i=1; i<=number_of_subject&&i<=15; i++){
				gotoxy2(x, y+i-1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[i]);
				cout<<setw(30)<<sub_list[i].get_name();
				cout<<setw(20)<<sub_list[i].get_professor();
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		
		
	}
	void get_file(ofstream *fout){
		for(int i=1; i<=number_of_subject; i++){
			
			(*fout)<<"학수번호: "<<sub_list[i].get_course_number()<<endl; 
			(*fout)<<"과목명: "<<sub_list[i].get_name()<<endl;
			(*fout)<<"교수명: "<<sub_list[i].get_professor()<<endl;
			(*fout)<<"요일: "<<endl;
			
			for(int j=0; j<sub_list[i].get_n(); j++){
				Time pp = sub_list[i].get_time(j);
				
				(*fout)<<pp.day<<"요일 "<<pp.full_time<<endl;
				//(*fout)<<a.day<<"요일 "<<a.hour[0]<<"시간"<<a.hour[1]<<"분 - "<<a.hour[2]<<"시간"<<a.hour[3]<<"분"<<endl; 
			} 
			(*fout)<<"학점: "<<sub_list[i].get_unit()<<endl;
			(*fout)<<sub_list[i].get_campus()<<endl; 
			(*fout)<<endl;
		}
		
	}
};

