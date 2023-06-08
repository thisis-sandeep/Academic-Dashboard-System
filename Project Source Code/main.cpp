#include <iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

class Assessment{
    int studentId,tId;
    char sname[20],tname[20];
    char scourse[20],tcourse[20];
    char course[20];
public:
    int cId;
    void getDetail(void);
    void putDetail(void);

    void getTDetail(void);
    void putTDetail(void);

    void getCDetail(void);
    void putCDetail(void);

    int get_cId(void)
    {
        return cId;
    }
};

Assessment a;
fstream f1;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

void Assessment :: getDetail(void){
   cout<<"\n Enter student's id =";
   cin>>studentId;
   cout<<"\n Enter student's name =";
   fflush(stdin);
   cin>>sname;
   cout<<"\n Enter student's course =";
   fflush(stdin);
   cin>>scourse;
}

void Assessment :: putDetail (void){
    cout<<setw(6)<<studentId
        <<setw(15)<<sname
        <<setw(15)<<scourse<<endl;
}

void Assessment :: getTDetail(void){
   cout<<"\n Enter teacher's id =";
   cin>>tId;
   cout<<"\n Enter teacher's name =";
   fflush(stdin);
   cin>>tname;
   cout<<"\n Enter teacher's course =";
   fflush(stdin);
   cin>>tcourse;
}

void Assessment :: putTDetail(void){
    cout<<setw(6)<<tId
        <<setw(15)<<tname
        <<setw(15)<<tcourse<<endl;
}

void Assessment :: getCDetail(void){
    cout<<"\n Enter course's id =";
    cin>>cId;
    cout<<"\n Enter course =";
    fflush(stdin);
    cin>>course;
}
void Assessment :: putCDetail(void){
    cout<<setw(6)<<cId
        <<setw(15)<<course<<endl;
}

void addStudent(){
    char ch='y';
    f1.open("stud.dat",ios::app | ios::binary);
    while(ch=='y' || ch=='Y'){
        a.getDetail();
        f1.write((char*)&a,sizeof(a));
        cout<<"Add more records....(y/n)";
        cin>>ch;
    }
    f1.close();
}
void addTeacher(){
    char ch='y';
    f1.open("teacher.dat",ios::app | ios::binary);
    while(ch=='y' || ch=='Y'){
        a.getTDetail();
        f1.write((char*)&a,sizeof(a));
        cout<<"Add more records....(y/n)";
        cin>>ch;
    }
    f1.close();
}

void addCourse(){
    char ch='y';
    f1.open("course2.dat",ios::app | ios::binary);
    while(ch=='y' || ch=='Y'){
        a.getCDetail();
        f1.write((char*)&a,sizeof(a));
        cout<<"Add more records....(y/n)";
        cin>>ch;
    }
    f1.close();
}

void showALlStudent(void){
    f1.open("stud.dat",ios::in | ios::binary);
    if(!f1){
        cout<<"\n File not found";
        exit(0);
    }
    else{
        f1.read((char*)&a,sizeof(a));
        while(!f1.eof()){
            a.putDetail();
            f1.read((char*)&a,sizeof(a));
        }
    }
    f1.close();
}

void showALlTeacher(void){
    f1.open("teacher.dat",ios::in | ios::binary);
    if(!f1){
        cout<<"\n File not found";
        exit(0);
    }
    else{
        f1.read((char*)&a,sizeof(a));
        while(!f1.eof()){
            a.putTDetail();
            f1.read((char*)&a,sizeof(a));
        }
    }
    f1.close();
}

void showALlCou(void){
    f1.open("course2.dat",ios::in | ios::binary);
    if(!f1){
        cout<<"\n File not found";
        exit(0);
    }
    else{
        f1.read((char*)&a,sizeof(a));
        while(!f1.eof()){
            a.putCDetail();
            f1.read((char*)&a,sizeof(a));
        }
    }
    f1.close();
}

void deleteRecord(){
    int f=0;
    int id;
    FILE *fp1,*fp2;
    fp1=fopen("course2.dat","rb");
    fp2=fopen("new.dat","wb");
    cout<<"\n Enter course id =";
    cin>>id;
    while(fread(&a,sizeof(a),1,fp1)){
        if(a.cId==id)
            f=1;
        else
            fwrite(&a,sizeof(a),1,fp2);
    }
    if(f==0)
        cout<<"\n Account not found.";
    else{
        fclose(fp1);
        fclose(fp2);
        remove("course2.dat");
        rename("new.dat","course2.dat");
    }
}
void syllabus_read(){
    ifstream obj;
    obj.open("syllabus.txt");
    for(string line;getline(obj,line);){
        cout<<line<<endl;
    }
}

void syllabus_update(){
    ofstream obj;
    obj.open("syllabus.txt",ios::app);
    string s1,s2,s3;
    cout<<"enter unit name"<<endl;
    fflush(stdin);
    getline(cin,s1);
    cout<<"enter page number like 1..10"<<endl;
    getline(cin,s2);
    cout<<"enter content"<<endl;
    getline(cin,s3);
    obj<<s1;
    obj.close();
    obj.open("syllabus.txt",ios::app);
    obj<<s2;
    obj.close();
    obj.open("syllabus.txt",ios::app);
    obj<<s3;
    obj.close();
    obj.open("syllabus.txt",ios::app);
    obj.close();
}

void uploadAssignment(){
    char ch[100];
    cout<<"\n If you want to open the file than write 'open file' and than enter\n";
    gets(ch);

    if(strcmp(ch,"open file")==0){
        ShellExecute(NULL,"open","E:\\MCA\\OOPs using c++\\CAP444Lecture0.pdf",NULL,NULL,SW_NORMAL);
    }
}

int main()
{
    int c,k;
    do{
        system("CLS");
        SetConsoleTextAttribute(h,9);
        cout<<"\n\n************************************************************************************************************************\n\n\n";
        cout<<"\n\t\t\tREGULAR ASSESSMENT OF THE LEARNING PERFORMANCE RELATED TO A COURSE MODULE\n";
        cout<<"\n\n************************************************************************************************************************\n\n\n";
        SetConsoleTextAttribute(h,13);
        cout<<"====================================================\n\n";
        cout<<"\n\t\t Main Menu\n\n";
        cout<<"====================================================\n\n";
        cout<<"\n\t1. Teacher login";
        cout<<"\n\t2. Student login";
        cout<<"\n\t3. Exit";
        cout<<"\n\n\tEnter your choice =";
        cin>>c;
        switch(c){
        case 1:
            int choice1,k1;
            do{
                system("CLS");
                SetConsoleTextAttribute(h,9);
                cout<<"\n\n************************************************************************************************************************\n\n\n";
                cout<<"\n\t\t\tREGULAR ASSESSMENT OF THE LEARNING PERFORMANCE RELATED TO A COURSE MODULE\n";
                cout<<"\n\n************************************************************************************************************************\n\n\n";
                SetConsoleTextAttribute(h,10);
                cout<<"====================================================\n\n";
                cout<<"\n\t\t Main Menu\n\n";
                cout<<"====================================================\n\n";
                cout<<"\n\t1. Open/Create teacher account";
                cout<<"\n\t2. Display all teacher";
                cout<<"\n\t3. Add Course";
                cout<<"\n\t4. Delete Course";
                cout<<"\n\t5. Display course";
                cout<<"\n\t6. Syllabus";
                cout<<"\n\t7. Upload assignment";
                cout<<"\n\t8. Exit";
                cout<<"\n\n\tEnter your choice =";
                cin>>choice1;
                switch(choice1){
                case 1:
                    addTeacher();
                    break;
                case 2:{
                    cout<<".........................................................\n";
                    cout<<setw(6)<<"tId"<<setw(15)<<"tname"<<setw(15)<<"tcourse"<<endl;
                    cout<<".........................................................\n";
                    showALlTeacher();
                    cout<<".........................................................\n";
                    break;
                }
                case 3:
                    addCourse();
                    break;
                case 4:
                    deleteRecord();
                    break;
                case 5:{
                    cout<<".........................\n";
                    cout<<setw(6)<<"cId"<<setw(15)<<"course"<<endl;
                    cout<<".........................\n";
                    showALlCou();
                    cout<<".........................\n";
                    break;
                    }
                case 6:{
                    syllabus_update();
                    syllabus_read();
                    break;
                }
                case 7:
                    uploadAssignment();
                    break;
                case 8:
                    exit(0);
                    break;
                default:
                    cout<<"\n Wrong choice";
                }
                cout<<"\n Do you want to continue, or go to the login page press 1.";
                cin>>k1;
            }while(k1!=1);

            break;
        case 2:
            int choice2,k2;
            do{
                system("CLS");
                SetConsoleTextAttribute(h,9);
                cout<<"\n\n************************************************************************************************************************\n\n\n";
                cout<<"\n\t\t\tREGULAR ASSESSMENT OF THE LEARNING PERFORMANCE RELATED TO A COURSE MODULE\n";
                cout<<"\n\n************************************************************************************************************************\n\n\n";
                SetConsoleTextAttribute(h,12);
                cout<<"====================================================\n\n";
                cout<<"\n\t\t Main Menu\n\n";
                cout<<"====================================================\n\n";
                cout<<"\n\t1. Open/Create student account";
                cout<<"\n\t2. Display all students";
                cout<<"\n\t3. Upload assignment";
                cout<<"\n\t4. Exit";
                cout<<"\n\n\tEnter your choice =";
                cin>>choice2;
                switch(choice2){
                case 1:
                    {
                        addStudent();
                        break;
                    }
                case 2:{
                    cout<<".........................................................\n";
                    cout<<setw(6)<<"studentId"<<setw(15)<<"sname"<<setw(15)<<"scourse"<<endl;
                    cout<<".........................................................\n";
                    showALlStudent();
                    cout<<".........................................................\n";
                    break;
                }
                case 3:
                    uploadAssignment();
                    break;
                case 4:
                    exit(0);
                    break;
                default:
                    cout<<"\n Wrong choice";
                }
                cout<<"\n Do you want to continue, or go to the login page press 1.";
                cin>>k2;
            }while(k2!=1);
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"\n Wrong choice";
        }
        cout<<"\n Do you want to cont... otherwise press 1 for exit...";
        cin>>k;
    }while(k!=1);

    return 0;
}
