#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
//#include "subject.h"
#include "menu.h"
#include "table.h"

using namespace std;

typedef struct list_node *list_ptr;
typedef struct list_node{
	Subject data;
	list_ptr llink;
	list_ptr rlink;
};

string text[] = {
	" ",
	"시간표1.txt",
	"시간표2.txt",
	"시간표3.txt"
};

// 전역변수 
bool my_info = false;
list_ptr list_subject_ptr = NULL;
Subject *subject;
ifstream fp;
string message;
Table table[4];
int table_info = 0;
bool message_flag = false; 
int *vt;

int find_end(list_ptr ptr){
	list_ptr temp = ptr;
	int length = 0;
	
	if(temp==NULL){
		return length;
		
	}else{
		do{
			length++;
			temp = temp->rlink;
		}while(temp!=(ptr));
	}
	
	return length;
}

int count_node(int size){
	 list_ptr temp;
	 int count = 0;
	
	 temp = list_subject_ptr;
	 if (temp == NULL){
	  return size;
	
	 }
	 else{
	  do{
	   size++;
	   temp = temp->rlink;
	  } while (temp != (list_subject_ptr));
	 }
	 return size;
}
  
void make_node(list_ptr *ptr, Subject subject){
	list_ptr newnode;
	list_ptr prenode;
	newnode = new list_node;
	newnode->data = subject;
	
	if(*ptr==NULL){
		*ptr = newnode;
		newnode->llink = newnode;
		newnode->rlink = newnode;
	}else{
		prenode = (*ptr)->llink;
		prenode->rlink = newnode;
		newnode->llink = prenode;
		(*ptr)->llink = newnode;
		newnode->rlink = *ptr;
		
	}
}

Subject delete_node(list_ptr *ptr, list_ptr del){
	/*
		ptr is the pointer of head of list
		del is the position of removal node
	*/
	Subject data;
	list_ptr pre = del->llink;				//previous node of del node
	list_ptr next = del->rlink;				//next node of del node
	
	data = del->data;						//del node's data
	if(*ptr!=del){
		//In case, the delete node is not the first node
		next->llink = pre;					//next node's left position is previous node
		pre->rlink = next;					//previous node's right position is next node
	}else{
		//In case, the delete node is the first case
		*ptr = next;
		next->llink = pre;					//next node's left position is previous node
		pre->rlink = next;					//previous node's right position is next node
	}
	delete del;
	
	return data;
}

bool check_subject(Subject subject){
	list_ptr temp;
	string number;
	string test = subject.get_course_number();
	
	temp = list_subject_ptr; 
	if(temp==NULL){
		return false;
		
	}else{
		do{
			number = temp->data.get_course_number();
			//gotoxy(2,36);
			//cout<<"비교결과 : "<<number<<" "<<test<<" "<<number.compare(test)<<endl;
			if(number.compare(test)==0){
				return true;
			}
			temp=temp->rlink;
		}while(temp!=(list_subject_ptr));
	}
	
	return false;
}

void round_node(){
	list_ptr temp;
	
	
	temp = list_subject_ptr; 
	if(temp==NULL){
		return ;
		
	}else{
		do{
			temp->data.show_subject();
			temp=temp->rlink;
		}while(temp!=(list_subject_ptr));
	}
} 



int read_subjects(int mode){
	int size;
	
	fp>>size;
	//delete[] subject;
	subject = new Subject[size];
	for(int i=0; i<size; i++){
		subject[i].insert_subject(fp, mode);
	}
	
	return size;
}

void input_info(Subject *subject, int size, int line, int index){
	gotoxy(1, line+2);
	subject[index].show_subject(0);
	gotoxy(10, line+2);
	if(subject[index].get_prefer_grade()>main_info.year){
		cout<<"X";
	}else{
		cout<<"O";
	}
}

void input_info_2(Subject *subject, int size, int line, int index){
	gotoxy(0, line);
	subject[index].show_subject();
	gotoxy(10, line);
	if (subject[index].get_prefer_grade()>main_info.year){
		cout << "X";
	}
	else{
		cout << "O";
	}

}

void draw_page(Subject *subject, int size, int page){
	system("cls");
	system("mode con:cols=200 lines=50");
	cout<<"┌─────────────────────────────────────────────────────────────────────────────────┐"<<endl;
	cout<<"│학점│권장│ 학수번호 │             과목명            │       교수명      │                             수업시간과 강의실                           │  캠퍼스 │"<<endl;
	for(int i=0; i<N_LIMIT; i++){
		cout<<endl;
	}
	cout<<"└──────────────────────────────────────────────────────────────────────────────────┘"<<endl;
	for(int i=page*N_LIMIT; i<(page+1)*N_LIMIT&&i<size; i++){
		input_info(subject, size, i%N_LIMIT, i);
	}
}

/*
int edit_time(){
	system("cls");
	system("mode con:cols=150 lines=70");
	fstream fs;
	int ch;
	int instruction = 0;
	int limit = N_LIMIT;
	int k = 0;
	int size = count_node(k);	
	int number_menu = size;
	int pre_inst;
	round_node();
	list_ptr tptr = list_subject_ptr;
	subject = new Subject[size];
	for (int i = 0; i<size; i++){
		subject[i] = tptr->data;
		tptr = tptr->rlink;
		}
	do{
		ch = _getch();
		if (ch == 0xE0 || ch == 0){//입력받은 값이 확장키 이면
			ch = _getch();  //한번더 입력을 받는다.
			pre_inst = instruction;
			switch (ch){
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
			if (instruction<0){
				instruction = 0;
			}			
			else if (instruction>=number_menu){
				instruction = number_menu-1;
			}
			else{
				gotoxy(0, pre_inst-1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				input_info_2(subject, size, pre_inst, pre_inst);
				gotoxy(0, instruction-1);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				input_info_2(subject, size, instruction, instruction);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}


		}
		else if (ch == ESC){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}
		else if (ch == ENTER){
			gotoxy(0, size+1);
			erase(10);
			gotoxy(0, size +1);
			Subject temp = subject[instruction];
			int c;
			cout << "어떤 시간표에 넣으시겠습니까?(1~3)" << endl;
			cin >> c;
			switch (c){
			case 1:	
				cout << subject[instruction].get_course_number() << " - ";
				cout << subject[instruction].get_name() << " (";
				cout << subject[instruction].get_professor() << ") " << " 이(가) 시간표" << c << "에 추가되었습니다." << endl;
				fs.open("시간표1.txt",ios_base::app);				
				fs << temp.course_number << ' ' << temp.name << ' ' << temp.professor;
				fs << ' ' << temp.time[0].day << ' ' << temp.time[0].full_time << ' ' << temp.time[0].classroom;
				fs << ' ' << temp.time[1].day << ' ' << temp.time[1].full_time << ' ' << temp.time[1].classroom;
				fs << ' ' << temp.unit << ' ' << temp.campus << endl;				
				fs.close();
				break;
			case 2:				
				cout << subject[instruction].get_course_number() << " - ";
				cout << subject[instruction].get_name() << " (";
				cout << subject[instruction].get_professor() << ") " << " 이(가) 시간표" << c << "에 추가되었습니다." << endl;
				fs.open("시간표2.txt", ios_base::app);
				fs << temp.course_number << ' ' << temp.name << ' ' << temp.professor;
				fs << ' ' << temp.time[0].day << ' ' << temp.time[0].full_time << ' ' << temp.time[0].classroom;
				fs << ' ' << temp.time[1].day << ' ' << temp.time[1].full_time << ' ' << temp.time[1].classroom;
				fs << ' ' << temp.unit << ' ' << temp.campus << endl;
				fs.close();
				break;
			case 3:				
				cout << subject[instruction].get_course_number() << " - ";
				cout << subject[instruction].get_name() << " (";
				cout << subject[instruction].get_professor() << ") " << " 이(가) 시간표" << c << "에 추가되었습니다." << endl;
				fs.open("시간표3.txt", ios_base::app);
				fs << temp.course_number << ' ' << temp.name << ' ' << temp.professor;
				fs << ' ' << temp.time[0].day << ' ' << temp.time[0].full_time << ' ' << temp.time[0].classroom;
				fs << ' ' << temp.time[1].day << ' ' << temp.time[1].full_time << ' ' << temp.time[1].classroom;
				fs << ' ' << temp.unit << ' ' << temp.campus << endl;
				fs.close();
				break;
			default:
				break;
			}		
	
		}
	} while (1);
	return instruction;
}
*/

void list_info(list_ptr ptr, int x, int i){
	Subject st = ptr->data;
	int n = st.get_n();
	
	gotoxy(x, i+8);
	cout<<setw(32)<<st.get_name()<<"-";
	cout<<setw(14)<<st.get_professor();
	if(n==2){
		Time a = st.get_time(0);
		Time b = st.get_time(1);
		cout<<setw(6)<<a.day<<a.full_time;
		cout<<setw(6)<<b.day<<b.full_time;
	}else if(n==4){
		Time a = st.get_time(0);
		Time b = st.get_time(3);
		cout<<setw(6)<<a.day<<a.full_time;
		cout<<setw(6)<<b.day<<b.full_time;
	}
	for(int i=0; i<st.get_n(); i++){
		Time a = st.get_time(i);
		
	}
	//cout<<endl;
	
}

void color_change(int index){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index);
}

void show_subject_info(int index, int mode){
	Subject temp_subject = subject[index];
	int limit = N_LIMIT;
	
	if(mode == 1){
		if(index%limit==0){
			cout<<limit<<". ";
		}else{
			cout<<index%limit<<". ";	
		}
		cout<<setw(30)<<temp_subject.get_name();
		cout<<setw(30)<<temp_subject.get_professor();
		if(index%limit == 1){
			color_change(7);
		}
		if(vt[index]!=0){
			color_change(2);
			cout<<setw(7)<<"Inserted"<<endl;
			color_change(7);
		}else{
			cout<<"            "<<endl;
		}
	}
	
	color_change(7);
}



Table select_subject_menu(){
	list_ptr tptr = list_subject_ptr;
	int size = find_end(tptr);
	subject = new Subject[size+1];
	Table main_table;
	Table sub_table;
	Subject temp_subject;
	int ch;
	vt = new int[size+1];
	int limit = N_LIMIT;
	int page = size/(limit+1) + 1;
	int now_page = 1;
	int pre_page;
	int now_ins = 1;
	int pre_ins;
	bool is_page_changed = true;
	bool is_table_changed[2] = {true, true};
	bool is_moved = true;
	int base_y[4] = {1, 1, 12, 24};
	int color = 10;
	int line = 1;
	bool check;
	
	
	//initial
	system("mode con lines=180 cols=220");
	for (int i = 1; i<=size; i++){
			//list_info(tptr, 0, i);
			subject[i] = tptr->data;
			tptr = tptr->rlink;
			vt[i] = 0;
			//gotoxy(40, pre_inst+10);
	}
	
	
	do{
		
		if(is_page_changed){
			gotoxy(0, base_y[3]);
			pre_ins = now_ins;
			pre_page = now_page;
			for(; now_ins<pre_ins + limit&&now_ins<=size; now_ins++){
				show_subject_info(now_ins, 1);
			}
			now_ins = pre_ins;
			line = 1;
			is_page_changed = false;
		}
		
		if(is_table_changed[0]){
			sub_table = main_table;
			gotoxy(0, base_y[1]);
			cout<<"시간표 		";
			main_table.show_table(1);
			is_table_changed[0] = false;
			is_table_changed[1] = true;
		}
		
		if(is_moved){
			is_table_changed[1] = true;
			sub_table = main_table;
			
			if(vt[now_ins]==0){
				//no select 
				sub_table.insert_subject_force(subject[now_ins]);
			}else {
				color_change(vt[now_ins]);
				gotoxy(0, base_y[3] + line - 1);
				show_subject_info(now_ins, 1);
				color_change(7);
				//selecting
			}
			
			is_moved = false;
		}
		
		if(is_table_changed[1]){
				
			gotoxy(0, base_y[2]);	
			cout<<"변경된 시간표 		";
			sub_table.show_table(0);
			is_table_changed[1] = false;
		}
		
		gotoxy(0, 40);
		check = main_table.check_time(subject[now_ins]);
		cout<<"page :"<<now_page<<"/"<<page<<endl; 
		if(check){
			color_change(3);
			cout<<"과목 등록가능, enter = 등록          "<<endl;
			color_change(7);
		}else{
			color_change(3);
			cout<<"과목이 이미 등록되었거나, 시간이 겹침"<<endl;
			color_change(7);
		}
		cout<<"size: "<<size<<"  "<<"page: "<<page<<endl; 
		cout<<"now_page: "<<now_page<<"   "<<"now_ins: "<<now_ins<<endl;
		cout<<"line: "<<line<<"    "<<"color: "<<color<<endl;
		cout<<"condition : "<<check;
		
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
			pre_ins = now_ins;
			pre_page = now_page;
			switch(ch){
				case LEFT:
					now_page--;
					if(now_page<1){
						now_page = pre_page;
						is_moved = false;
					}else{
						now_ins = (now_page-1)*limit + 1;
						line = 1;
						is_page_changed = true;
						is_moved = true;
					}
					break;
				case RIGHT:
					now_page++;
					if(now_page>page){
						now_page = pre_page;
						is_moved = false;
					}else{
						now_ins = (now_page-1)*limit + 1;
						line = 1;
						is_page_changed = true;
						is_moved = true;
					}
					break;
				case UP:
					line--;
					if(line<1){
						line++;
						is_moved = false;
					}else{
						now_ins--;
						gotoxy(0, base_y[3] + line);
						color_change(7);
						show_subject_info(pre_ins, 1);
						gotoxy(0, base_y[3] + line - 1);
						color_change(9);
						show_subject_info(now_ins, 1);
						
						
						is_moved = true;
					}
					break;
				case DOWN:
					line++;
					if((line>limit)||(now_ins+1>size)){
						line--;
						is_moved = false;
					}else{
						now_ins++;
						gotoxy(0, base_y[3] + line - 2);
						color_change(7);
						show_subject_info(pre_ins, 1);
						gotoxy(0, base_y[3] + line - 1);
						color_change(9);
						show_subject_info(now_ins, 1);
						
						
						is_moved = true;
					}
					break;
			}
		}else if(ch==ENTER){
			if(vt[now_ins]==0){
				check = main_table.check_time(subject[now_ins]);
				if(check){
					vt[now_ins] = color;
					main_table.insert_subject(subject[now_ins]);
					is_moved = true;
					is_table_changed[0] = true;
				}else{
					
				}
			} else {
				main_table.delete_subject(subject[now_ins]);
				vt[now_ins] = 0;
				is_table_changed[0] = true;
				is_moved = true;
			}
			
		}else if(ch==ESC){
			int inst;
			
			inst = table_menu();
			switch(inst){
				case 1:
				case 2:
				case 3:
					table_info = inst;
					return main_table;
				case 4:
					table_info = 0;
					return main_table;
				case 5:
					break; 
			} 
			
		}
		gotoxy(0, 40);
		cout<<"page :"<<now_page<<"/"<<page<<endl; 
		if(check){
			color_change(3);
			cout<<"과목 등록가능, enter = 등록          "<<endl;
			color_change(7);
		}else{
			color_change(3);
			cout<<"과목이 이미 등록되었거나, 시간이 겹침"<<endl;
			color_change(7);
		}
	//	cout<<"size: "<<size<<"  "<<"page: "<<page<<endl; 
	//	cout<<"now_page: "<<now_page<<"   "<<"now_ins: "<<now_ins<<endl;
	//	cout<<"line: "<<line<<"    "<<"color: "<<color<<endl;
	//	cout<<"condition : "<<check;
		
	}while(1);
	
	return main_table;
}




/*
void manage_table(){
	int pre_inst;
	list_ptr pre_ptr;
	int limit = N_LIMIT;
	int page;
	int prepage;
	int nowpage = 0;
	int ch;
	int instruction = 1;
	int size = find_end(list_subject_ptr);
	int *vt = new int[size+1];
	int count = 1;
	
	page = ceil(size/limit);
	if(size%limit == 0){
		page--;
	}
	system("cls");
	system("mode con lines=120 cols=180");
	table[table_info].show_table();
	list_ptr tptr = list_subject_ptr;
	subject = new Subject[size+1];
	for (int i = 1; i<=size; i++){
			vt[i] = 0;
			list_info(tptr, 0, i);
			subject[i] = tptr->data;
			tptr = tptr->rlink;
			//gotoxy(40, pre_inst+10);
	}
	tptr = list_subject_ptr;

	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
			pre_ptr = tptr;
			pre_inst = instruction;
			switch(ch){
				case LEFT:
					nowpage--;
					break;
				case RIGHT:
					nowpage++;
					break;
				case UP:
					instruction--;
					tptr = tptr->llink;
					break;
				case DOWN:
					instruction++;
					tptr = tptr->rlink;
					break;
			}
			if(instruction<1){
				instruction	= 1;
				tptr = tptr->rlink;
			}else if(instruction>size){
				instruction = size;
				tptr = tptr->llink;
			}
			
			if(nowpage<0){
				nowpage = 0;
			}else if(nowpage>page){
				nowpage = prepage;
			}
			if(instruction<0){
				instruction	= 0;
			}else if(instruction>limit-1||instruction+nowpage*N_LIMIT>=number_menu){
				instruction = pre_inst;
			}
			
			gotoxy(1, 10+size);
			cout<<"ins :"<<instruction<<" page: "<<page;
			if(vt[pre_inst]==1){
				
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				list_info(pre_ptr, 0, pre_inst);
			}
			
			if(vt[instruction]==1){
				
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				list_info(tptr, 0, instruction);
			}
			
			
			
			
		}else if(ch==ENTER){
			if(vt[instruction] == 1){
					
			}else{
				
				if(table[table_info].insert_subject(tptr->data)){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), count);
					count++;
					list_info(tptr, 1, instruction);
					vt[instruction] = 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					gotoxy(0,0);
					table[table_info].show_table();
				}
			}
			
		}else if(ch==ESC){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return ;
		}
	}while(1);
	
	
}
*/

int list_menu(Subject *subject, int size){
	int ch;
	int instruction = 0;
	int limit = N_LIMIT; 
	int page;
	int prepage;
	int nowpage = 0;
	int number_menu = size;
	int pre_inst;

	
	page = ceil(size/limit);
	if(size%limit == 0){
		page--;
	}
	draw_page(subject, size, 0);
	do{	
		ch = getch();
		if(ch == 0xE0 || ch ==0){//입력받은 값이 확장키 이면
			ch = getch();  //한번더 입력을 받는다.
			pre_inst = instruction;
			prepage = nowpage;
			switch(ch){
				case LEFT:
					nowpage--;
					break;
				case RIGHT:
					nowpage++;
					break;
				case UP:
					instruction--;
					break;
				case DOWN:
					instruction++;
					break;
			}
			if(nowpage<0){
				nowpage = 0;
			}else if(nowpage>page){
				nowpage = prepage;
			}
			if(instruction<0){
				instruction	= 0;
			}else if(instruction>limit-1||instruction+nowpage*N_LIMIT>=number_menu){
				instruction = pre_inst;
			}
			
			if(prepage!=nowpage){
				draw_page(subject, size, nowpage);
				pre_inst = instruction = 0;
			}else{
				gotoxy(6, pre_inst+2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				input_info(subject, size, pre_inst, pre_inst+nowpage*N_LIMIT);
				gotoxy(6, instruction+2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				input_info(subject, size, instruction, instruction+nowpage*N_LIMIT);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			
			
		}else if(ch==ESC){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			return instruction;
		}else if(ch == ENTER){
			gotoxy(2,16);
			erase(10);
			gotoxy(2,16);
			if(check_subject(subject[instruction+nowpage*N_LIMIT])){ 
				cout<<"이미 선택한 과목입니다.";
			}else{
				cout<<subject[instruction+nowpage*N_LIMIT].get_course_number()<<" - ";
				cout<<subject[instruction+nowpage*N_LIMIT].get_name()<<" (";
				cout<<subject[instruction+nowpage*N_LIMIT].get_professor()<<") "<<" 이(가) 추가되었습니다."<<endl;
				Subject temp = subject[instruction+nowpage*N_LIMIT];
				temp.show_subject_info();
				make_node(&list_subject_ptr, temp);	
			}		
		}
		gotoxy(0, 34);
		cout<<"page: "<<nowpage<<"/"<<page;
	}while(1);
	
	return instruction;
}

void file_out(Table t){
	ofstream fout;
	
	if(table_info==0){
		message = "시간표가 만들어지지 않았습니다.";
		message_flag = true; 
		return ;
	}else if(table_info==1){
		fout.open("시간표1.txt");
	}else if(table_info==2){
		fout.open("시간표2.txt");
	}else if(table_info==3){
		fout.open("시간표3.txt",  ios::trunc);
	}
	
	table[table_info].get_file(&fout);
	system("cls");
	system("mode con lines=120 cols=220");
	table[table_info].show_table(1);
	gotoxy(0, 10);
	color_change(4);
	cout<<text[table_info]<<"에 저장되었습니다."<<endl;
	cout<<endl;
	cout<<endl;
	color_change(8);
	cout<<"press any key..."<<endl;
	getch();
	
}

void sub_menu(int option){
	int temp;
	char c;
	
	system("cls");
	//delete[] subject;
	if(option==1){	//	학년 및 학과입력
		cout<<"학년: ";
		cin>>main_info.year;
		cout<<"학과: ";
		cin>>main_info.subject_of_study;
		my_info = true;
		message = "학년정보가 등록되었습니다.";
		message_flag = true; 
	}else if(option==2){	//	전공 목록 출력
		if(main_info.subject_of_study.empty()){
			system("cls");
			message = "학과정보를 입력하여주세요.";
			message_flag = true; 
			return ; 
		}else if(!main_info.subject_of_study.compare("컴퓨터공학과\n")){
			system("cls");
			message = "컴퓨터공학과가 아닙니다.";
			message_flag = true; 
			return ; 
		} 
		switch(major_menu()){
			case 1:
				fp.open("recommand.txt");
				break;
			case 2:
				fp.open("major.txt");
				break;
			case 3:
				return ;
		}
		temp = read_subjects(1);
		fp.close(); 
		list_menu(subject, temp);
	}else if(option==3){	//	교양 목록 출력
		switch(culture_menu()){
			case 1:
				fp.open("humanity.txt");
				break;
			case 2:
				fp.open("science_tecnology.txt");
				break;
			case 3:
				fp.open("social_history.txt");
				break;
			case 4:
				fp.open("bsm.txt");
				break;
			case 5:
				return ; 
		} 
		temp = read_subjects(0);
		fp.close();
		list_menu(subject, temp);
	}else if(option==4){	//	시간표 담기
		if(find_end(list_subject_ptr) == 0 ){
			message = "시간표에 담을 과목이 없습니다.";
			message_flag = true;
			return ;
		}
		table[table_info] = select_subject_menu();
		
		/*
		switch(table_menu()){
			case 1:	//시간표 선택 
				int num;
				cout << "어떤 시간표에 넣으시겠습니까?(1~3)" << endl;
				table_info = select_table();
				message = "시간표가 등록되었습니다."; 
				message_flag = true;
				break;
			case 2:	//시간표제작
			 	if(table_info==-1){
			 		table_info = -1;
				 }
				table[table_info] = select_subject_menu();
				//edit_time();
				//manage_table();
				break;
			case 3:	//시간표 출력 
				break;
			case 4:	//뒤로가기 
				return ;
		}
		*/
		
	}
	/*
	else if(option==5){	//	시간표 수정 
		
	}else if(option==6){	//	시간표 콘솔 출력
		
	}
	*/
	else if(option==5){	//	텍스트 출력
		if(table_info == 0){
			message = "시간표가 만들어 지지 않았습니다.";
			message_flag = true;
			return ; 
		}
		file_out(table[table_info]);
	}else if(option==6){	//	프로그램종료
		is_end = true;
		cout<<"프로그램 종료"<<endl;
		return ;
	}else{
		
	}
	
}

void message_trigger(){
	if(message_flag){
		system("cls");
		cout<<message<<endl;
		Sleep(1500);
		message_flag = false;
	}else{
		return ;
	}
	
	return;
}

void info(int mode){
	
	
	gotoxy(0, 10);
	cout<<"알림: "<<endl;
	if(my_info){
		cout<<"학년 : "<<main_info.year <<"  전공 : "<<main_info.subject_of_study<<endl;
	}else {
		cout<<"학년, 학과 정보가 입력되지 않았습니다."<<endl; 
	}
	if(table_info == 0){
		cout<<"시간표가 생성되지 않았습니다."<<endl;
	}else {
		cout<<"시간표"<<table_info<<" 에 저장되었습니다."<<endl;
	}
	if(message_flag){
		color_change(3);
		cout<<message<<endl;
		message_flag = false;
		color_change(7);
	}
	gotoxy(0, 0); 
}

int main(void){
	
	while(!is_end){
		system("cls");
		system("mode con lines=20 cols=80");
		info(1);
		sub_menu(main_menu());
		//	message_trigger();
	}
	getch();
	//round_node();
	
	return 0;
}
