#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>

using namespace std;

char un[20];

class Admin{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15],mail[50],fname[20];
    char passwd[20],rpasswd[20];
    public:
    char rollno[15];
    //funciton to get student data entry from admin portal all record entries are made by this method
    void getsdata(){
        cout<<"\nEnter Student Name:";
        gets(name);
        cout<<"\nEnter student ID/Roll no:";
        cin>>rollno;
        cout<<"\nEEnter students Father's name:";
        gets(fname);
        cout<<"\nEnter mobile number:";
        gets(mobile);
        cout<<"\nEnter email id:";
        gets(mail);
        cout<<"\nEnter total subjects:";
        cin>>totsub;
        for(int i=0;i<totsub;i++){
            cout<<"\nEnter the subject "<<i+1<<" name:";
            cin>>subject[i];
        }
        cout<<"\nCreate your login password:";
        cin>>passwd;
        cout<<"\nEnter unique keyword to recover password:";
        cin>>rpasswd;
        cout<<"\nPlease note that your username is your ID/Roll no.\n";
    }
    //function to authenticate login of both students and faculties with reference to their unique ID/Password login is provided
    int login(){
        if((strcmp(::un,rollno))==0){
            cout<<"\nEnter login password:";
            int len=0;
            len=strlen(passwd);
            char inputpasswd[20];
            int i;
            for(i=0;i<len;i++){
                inputpasswd[i]=getch();
                cout<<"#";
            }
            inputpasswd[i]=NULL;
            if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
                return 1;
            else 
                return 0;
        }else{
            return 0;
        }
    }
    //function to help both students and faculties to recover the password with the help of unique keyword provided by the admin
    int recover(){
        char key[20];
        if(strcmp(::un,rollno)==0){
            cout<<"\nEnter unique keyword(Provided by admin):";
            cin>>key;
            if((strcmp(key,rpasswd)==0)){
                cout<<"\nYou are a valid user.";
                cout<<"\nYour password is:"<<passwd;
                cout<<"\nPlease exit to login again";
                return 1;
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }
    //function to display the faculty profile to the faculty at their respective portals
    int faprofile(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nFaculty Name         :"<<name;
            cout<<"\nFaculty Father's name:"<<fname;
            cout<<"\nFaculty Mobile No.   :"<<mobile;
            cout<<"\nFaculty E-Mail ID    :"<<mail;
            return 1;
        }else{
            return 0;
        }
    }
    //function to display diffrent subjects of faculty at their respective portals
    int knowfasub(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nFaculty total subjects:"<<totsub;
            for(int i=0;i<totsub;i++){
                cout<<"\n\tSubject "<<i+1<<":"<<subject[i];
            }
            return 1;
        }else{
            return 0;
        }
    }
    //function to help faculty to add subject in their module
    void addfasub(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nEnter new subject:";
            cin>>subject[totsub];
            totsub++;
            cout<<"\nNew subject added successfully...";
        }
    }
    //function to help faculty to delete subject from their module
    void delfasub(){
        knowfasub();
        int de=0;
        if((strcmp(::un,rollno)==0)){
            if(totsub==0||totsub<0){
                totsub=0;
                cout<<"\nNone subjects exisst...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the subject no.to be deleted:";
            cin>>de;
            if(de==totsub){
                totsub--;
                strcpy(subject[totsub]," ");
            }else if(totsub==1){
                totsub=0;
                strcpy(subject[totsub]," ");
            }else{
                de--;
                strcpy(subject[totsub]," ");
                for(int p=de;p<totsub;p++){
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
            cout<<"\nRecords updated successfully...";
        }
    }
    //function to help faculty to modify his personal profile
    void modfaprofile(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nThe profile Details are: ";
            cout<<"\n 1. Faculty E-Mail : "<<mail;
            cout<<"\n 2. Faculty Mobile : "<<mobile;
            int g=-1;
            cout<<"\nEnter detail number to be modified:";
            cin>>g;
            if(g==1){
                char nmail[50];
                cout<<"\nEnter new mail address:";
                strcpy(mail,nmail);
                cout<<"\nRecords updated successfuly!";
            }else if(g==2){
                char nmobile[15];
                cout<<"\nEnter new mobile number:";
                gets(nmobile);
                strcpy(mobile,nmobile);
                cout<<"\nRecords updated successfuly!";
            }
            else{
                cout<<"\nInvalid input provided...";
            }
        }
    }
    //function to display student profile at student portal
    int stprofile(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nStudent Name          :"<<name;
            cout<<"\nStudent Father's Name :"<<fname;
            cout<<"\nStudent Mobile No.    :"<<mobile;
            cout<<"\nStudent E-Mail ID     :"<<mail;
            return 1;
        }else{
            return 0;
        }
    }
    int knowstsub(){
         if((strcmp(::un,rollno)==0)){
            cout<<"\nStudent total subjects:"<<totsub;
            for(int i=0;i<totsub;i++){
                cout<<"\n\tSubject "<<i+1<<":"<<subject[i];
            }
            return 1;
        }else{
            return 0;
        }
    }
    void addstsub(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nEnter new subject:";
            cin>>subject[totsub];
            totsub++;
            cout<<"\nNew subject added successfully...";
        }
    }
    void delstsub(){
        knowstsub();
        int de=0;
        if((strcmp(::un,rollno)==0)){
            if(totsub==0||totsub<0){
                totsub=0;
                cout<<"\nNone subjects exisst...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the subject no.to be deleted:";
            cin>>de;
            if(de==totsub){
                totsub--;
                strcpy(subject[totsub]," ");
            }else if(totsub==1){
                totsub=0;
                strcpy(subject[totsub]," ");
            }else{
                de--;
                strcpy(subject[totsub]," ");
                for(int p=de;p<totsub;p++){
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
            cout<<"\nRecords updated successfully...";
        }
    }
     void modstprofile(){
        if((strcmp(::un,rollno)==0)){
            cout<<"\nThe profile Details are: ";
            cout<<"\n 1. Student E-Mail : "<<mail;
            cout<<"\n 2. Student Mobile : "<<mobile;
            int g=-1;
            cout<<"\nEnter detail number to be modified:";
            cin>>g;
            if(g==1){
                char nmail[50];
                cout<<"\nEnter new mail address:";
                strcpy(mail,nmail);
                cout<<"\nRecords updated successfuly!";
            }else if(g==2){
                char nmobile[15];
                cout<<"\nEnter new mobile number:";
                gets(nmobile);
                strcpy(mobile,nmobile);
                cout<<"\nRecords updated successfuly!";
            }
            else{
                cout<<"\nInvalid input provided...";
            }
        }
    }
    void getfadata(){
        cout<<"\nEnter the Faculty Name:";
        gets(name);
        cout<<"\nEnter Faculty ID/Roll no:";
        cin>>rollno;
        cout<<"\nEEnter Faculty Father's name:";
        gets(fname);
        cout<<"\nEnter mobile number:";
        gets(mobile);
        cout<<"\nEnter email id:";
        gets(mail);
        cout<<"\nEnter total subjects:";
        cin>>totsub;
        for(int i=0;i<totsub;i++){
            cout<<"\nEnter the subject "<<i+1<<" name:";
            cin>>subject[i];
        }
        cout<<"\nCreate your login password:";
        cin>>passwd;
        cout<<"\nEnter unique keyword to recover password:";
        cin>>rpasswd;
        cout<<"\nPlease note that your username is your ID/Roll no.\n";
    }
    void stdisplay(){
        cout<<"\nStudent Name         :"<<name;
        cout<<"\nStudent ID/Roll no   :"<<rollno;
        cout<<"\nStudent Father's Name:"<<fname;
        cout<<"\nStudent Mobile No.   :"<<mobile;
        cout<<"\nStudent E-Mail ID    :"<<mail;
        cout<<"\nStudent subjcts      :"<<totsub;
        for(int i=0;i<totsub;i++){
            cout<<"\n   Subject "<<i+1<<" :"<<subject[i];
        }
        if(totsub==0){
            cout<<" None Subjects specified...";
        }
    }
    void fadisplay(){
        cout<<"\nFacullty Name         :"<<name;
        cout<<"\nFacullty ID/Roll no   :"<<rollno;
        cout<<"\nFacullty Father's Name:"<<fname;
        cout<<"\nFacullty Mobile No.   :"<<mobile;
        cout<<"\nFacullty E-Mail ID    :"<<mail;
        cout<<"\nFacullty subjcts      :"<<totsub;
        for(int i=0;i<totsub;i++){
            cout<<"\n   Subject "<<i+1<<" :"<<subject[i];
        }
        if(totsub==0){
            cout<<" None Subjects specified...";
        }
    }
}a;
Admin f;
//a & f are the objects of class Admin
void main(){
    int ch;
    cout<<"\n\n\n\t\t\tWelcome to RKGIT Database Portal ";
    cout<<"\n\n\n\t\t\tEnter to continue ";
    getch();
    cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
    cout<<"\n\n\n\t\t\tPress 2 for Faculty Portal";
    cout<<"\n\n\n\t\t\tPress 1 for Student Portal";
    cin>>ch;
    if(ch==1){
        char adminuser[20],adminpass[20];
        cout<<"\n\t\tWelcome to Admin Login Portal ";
        cout<<"\nEnter the username:";
        cin>>adminuser;
        cout<<"\nEnter the Password:";
        int k;
        for(k=0;k<8;k++){
            adminpass[k]=getch();
            cout<<"*";
        }
        getch();
        adminpass[k]=NULL;
        if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0)){
            //clear screen

        }
        else{
            cout<<"\n\n\t\t\t Invalid Access to Portal ";
            cout<<"\n\n\t\t\tThank You !!!";
            getch();
            exit(0);
        }
        char opera='y';
        do{
            int tmp;
            cout<<"\n\t\t\t\tWelcome to Admin Panel";
            cout<<"\n\nPress 1 to Add a Faculty Record";
            cout<<"\n\nPress 2 to Add Multiple Records of Faculty";
            cout<<"\n\nPress 3 to view all records of Faculty";
            cout<<"\n\nPress 4 to Delete a Faculty Record";
            cout<<"\n\nPress 5 to Add a student Record";
            cout<<"\n\nPress 6 to Add multiple records of students";
            cout<<"\n\nPress 7 to view all records of students";
            cout<<"\n\nPress 8 to Delete a student Record";
            cout<<"\nPress 9 to Exit.";
            cout<<"\n\n\\tEnter your Choice:";
            cin>>tmp;
            //clrscr();
            if(tmp==1){
                cout<<"\nEnter the details:-";
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                a.getfadata();
                fs.write((char *)&a,sizeof(Admin));
                fs.close();
                cout<<"\nRecord entered successfuly...";
            }
            if(tmp==2){
                int m=0;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                do{
                    cout<<"\nEnter the details:-";
                    a.getfadata();
                    fs.write((char *)&a,sizeof(Admin));
                    cout<<"\nPress 0 if you want to enter more records:";
                    cin>>m;
                }while(m==0);
                fs.close();
                cout<<"\nRecord entered successfuly...";
            }
            if(tmp==3){
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                while(!fs.eof()){
                    fs.read((char *)&a,sizeof(Admin));
                    a.fadisplay();
                }
                fs.close();
            }
            if(tmp==4){
                char tmpfaid[15];
                int de=0,result=-1;
                cout<<"\nEnter Faculty ID/Roll no:-";
                cin>>tmpfaid;
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt",ios::out|ios::ate);
                while(!fs.eof()){
                    fs.read((char *)&a,sizeof(Admin));
                    result=strcmp(tmpfaid,a.rollno);
                    if(result==0){
                        de=1;
                    }else{
                        fs1.write((char*)&a,sizeof(Admin));
                    }
                }

                    if(de==1){
                        cout<<"\nRecord Deleted Successfully...";
                    }else{
                        cout<<"\nRecord not found....";
                    }
                    fs.close();
                    fs1.close();
                    remove("fainfo.txt");
                    rename("fanewinfo.txt","fainfo.txt");
                
            }
            if(tmp==5){
                cout<<"\nEnter the Details:-";
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                a.getsdata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"\nRecord entered successfully...";
            }
            if(tmp==6){
                int m=0;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                do{
                    cout<<"\nEnter the details:-";
                    a.getsdata();
                    fs.write((char *)&a,sizeof(Admin));
                    cout<<"\nPress 0 if you want to enter more records:";
                    cin>>m;
                }while(m==0);
                fs.close();
                cout<<"\nRecord entered successfuly...";
            }
            if(tmp==7){
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                while(!fs.eof()){
                    fs.read((char *)&a,sizeof(Admin));
                    a.stdisplay();
                }
                fs.close();
            }
            if(tmp==8){
                char tmpstid[15];
                int de=0,result=-1;
                cout<<"\nEnter Faculty ID/Roll no:-";
                cin>>tmpstid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt",ios::out|ios::ate);
                while(!fs.eof()){
                    fs.read((char *)&a,sizeof(Admin));
                    result=strcmp(tmpstid,a.rollno);
                    if(result==0){
                        de=1;
                    }else{
                        fs1.write((char*)&a,sizeof(Admin));
                    }
                }

                    if(de==1){
                        cout<<"\nRecord Deleted Successfully...";
                    }else{
                        cout<<"\nRecord not found....";
                    }
                    fs.close();
                    fs1.close();
                    remove("stinfo.txt");
                    rename("stnewinfo.txt","stinfo.txt");
            }
            if(tmp==9){
                cout<<"\n\n\n\n\t\t\tThank You!!!";
                getch();
                exit(0);
            }
            if(tmp<1||tmp>9){
                //clrscr();
                cout<<"\n\n\n\n\t\t\t\tInvalid Input......";
            }
           getch();
           cout<<"\nPress y for more operations otherwise n:";
           cin>>opera;
           if(opera!='y'){
            getch();
            //clrscr();
             cout<<"\n\n\n\n\t\t\tThank You!!!";
                getch();
           }
        }while(opera=='Y'||opera=='y');
    }//closing of admin login

}