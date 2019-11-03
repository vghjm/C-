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
	int hour[4];//0-���� ��, 1-���� ��, 2-���� �� , 3-���� �� 
};

class Subject{
public:
	string course_number;	
	string name;
	string professor;
	int unit;//����
	string campus;
	string etc; //��Ÿ����... ���� �̻�� 
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
	void show_subject(){// 1�ٷ� ��� 
		cout<<course_number<<' '<<name<<' '<<professor;
		cout<<' '<<time[0].day<<' '<<time[0].full_time<<' '<<time[0].classroom;
		cout<<' '<<time[1].day<<' '<<time[1].full_time<<' '<<time[1].classroom;
		cout<<' '<<unit<<' '<<campus<<endl;
	};
	void show_subject(int form){// 1�ٷ� ��� , ������ 
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
		cout<<"�����: "<<name<<endl; 
		cout<<"������: "<<professor<<endl;
		cout<<"�м���ȣ : "<<course_number<<endl;
		cout<<"����: "<<endl;
		for(int i=0; i<n; i++){
			cout<<time[i].day<<"���� "<<time[i].hour[0]<<"�ð�"<<time[i].hour[1]<<"�� - "<<time[i].hour[2]<<"�ð�"<<time[i].hour[3]<<"��"<<endl; 
		} 
		cout<<"����: "<<unit<<endl;
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








