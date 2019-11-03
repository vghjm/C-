#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>


using namespace std;

typedef struct Time{
	string full_time;
	string day;
	string classroom;
	int hour[4];//0-시작 시, 1-시작 분, 2-종료 시 , 3-종료 분 
};

class Subject{
public:
	string course_number;	
	string name;
	string professor;
	int unit;//학점
	string campus;
	string etc; //기타정보... 현재 미사용 
	Time time[4];
	int n;
	int prefer_grade; 

//public:
	void insert_subject(ifstream &fp, int mode){
		fp>>course_number>>name>>professor>>n;
		for(int i=0; i<n; i++){
			fp>>time[i].day>>time[i].full_time>>time[i].classroom;
			int temp = 0;
			for(int j=0; j<time[i].full_time.size(); j++){
				char a = time[i].full_time.at(j);
				if(a!=':'&&a!='-'){
					time[i].hour[temp] *= 10;
					time[i].hour[temp] += a-'0';
				}else{
					temp++;
				}
			}
		}
		fp>>unit>>campus;
		if(mode == 1){
			fp>>prefer_grade;
		}else{
			prefer_grade = 0;
		}
		
	};
	void show_subject(){// 1줄로 출력 
		cout<<course_number<<' '<<name<<' '<<professor;
		cout<<' '<<time[0].day<<' '<<time[0].full_time<<' '<<time[0].classroom;
		cout<<' '<<time[1].day<<' '<<time[1].full_time<<' '<<time[1].classroom;
		cout<<' '<<unit<<' '<<campus<<endl;
	};
	void show_subject(int form){// 1줄로 출력 , 수정판 
		cout<<setw(form+4)<<unit;
		cout<<setw(form+4)<<"         ";
		cout<<setw(form+9)<<course_number;
		cout<<setw(form+32)<<name;
		cout<<setw(form+23)<<professor;
		if(n==2){
			cout<<setw(form+8)<<time[0].day;
			cout<<setw(form+15)<<time[0].full_time;
			cout<<setw(form+7)<<time[0].classroom;
			cout<<"         ";
			cout<<setw(form+8)<<time[1].day;
			cout<<setw(form+15)<<time[1].full_time;
			cout<<setw(form+7)<<time[1].classroom;
		}else if(n==4){
			cout<<setw(form+8)<<time[0].day;
			cout<<setw(form+15)<<time[0].full_time;
			cout<<setw(form+7)<<time[0].classroom;
			cout<<"        ~";
			cout<<setw(form+8)<<time[3].day;
			cout<<setw(form+15)<<time[3].full_time;
			cout<<setw(form+7)<<time[3].classroom;
		}
		cout<<setw(form+16)<<campus;
	};
	void show_subject_info(){
		cout<<"과목명: "<<name<<endl; 
		cout<<"교수명: "<<professor<<endl;
		cout<<"학수번호 : "<<course_number<<endl;
		cout<<"요일: "<<endl;
		for(int i=0; i<n; i++){
			cout<<time[i].day<<"요일 "<<time[i].hour[0]<<"시간"<<time[i].hour[1]<<"분 - "<<time[i].hour[2]<<"시간"<<time[i].hour[3]<<"분"<<endl; 
		} 
		cout<<"학점: "<<unit<<endl;
		cout<<campus<<endl;
	}
	string get_course_number(){
		return course_number;
	}
	string get_name(){
		return name;
	} 
	string get_professor(){
		return professor;
	}
	int get_unit(){
		return unit;
	}
	string get_campus(){
		return campus;
	}
	int get_prefer_grade(){
		return prefer_grade;
	}
	int get_n(){
		return n;
	}
	Time get_time(int num){
		return time[num];
	}
	
};








