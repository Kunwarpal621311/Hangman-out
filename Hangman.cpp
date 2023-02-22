// ==============================================================
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<vector> 
// ===============================================================
using namespace std;
// class for stroing Qusestion
class Question{
    public:
    string Que;
    string ans;
};
// =================================================================

//  function =======================================================
void start( int Question_index);
void body(string pre,char* world,int life,int len);
bool check( string pre_define,char user_option,char* &arr);
bool win(char* world,string pre_define);
void restart(int Qusetion_index);
void about();
// ================================================================



// main function
// ==============================================================
int main(){
    system("CLS");
cout<<"=========================================================================="<<endl;
cout<<"\t\t\t MAIN MENU"<<endl;
cout<<"=========================================================================="<<endl;
cout<<"1) start  "<<endl;
cout<<"2) about "<<endl;
cout<<"3) Exit   "<<endl;
fflush(stdin);
int  op;
cin>>op;
if(op==1){
    start(0);
   
}
else if(op==2){
     about();
}
else if(op==3){
    exit;
}
else{
    cout<<"WRONG INPUT "<<endl;
    main();
}

return 0;
}
// ==============================================================

// ==============================================================
void start(int Qusetion_index){
 system("CLS");
int life=0;
cout<<"======================================================================================================"<<endl;
cout<<"\t\t\t\t\t HANGMAN  GAME "<<endl;
cout<<"======================================================================================================"<<endl;
ifstream fin("database.txt");
vector<Question> Questions;

if(!fin){
     cout<<"File is not present"<<endl;
}
else{
    string line;
    while(getline(fin,line)){

        if(line.substr(0,8)=="Question"){
            Question  obj;
            getline(fin,line);
            obj.Que=line;
            getline(fin,line);
            obj.ans=line;
            Questions.push_back(obj);
        }
    }
}
int len =Questions[Qusetion_index].ans.length();
char *world=new char[len];
for(int i=0;i<len;i++){
    world[i]='_';
}
while(life!=7){
    body(Questions[Qusetion_index].Que,world,life,len);
    char user_input;
    cout<<"\n Enter :";
    cin>>user_input;
    if(check(Questions[Qusetion_index].ans,user_input,world));
    else{
    life++;
    }
        if(win(world,Questions[Qusetion_index].ans)){
            life=7;
             body(Questions[Qusetion_index].Que,world,life,len);
             restart(Qusetion_index);
        }

}
}
// =====================================================================

// =====================================================================
bool check( string pre_define,char user_option,char* &arr){
    int c=0;
for(int i=0;i<pre_define.length();i++){
    if(user_option==pre_define[i]){
            c=1;
            if(arr[i]!=user_option){
                arr[i]=user_option;
            }
            else{
                c=0;
                cout<<"retry"<<endl;
                break;
            }
            
    }  
    
 }
 if(c==0){
    return false;
 }
 return true;

}
// =====================================================================

// =====================================================================
bool win(char* world,string pre_define){
    int temp=0;
    int len=pre_define.length();
    for(int i=0;i<len;i++){
        if(world[i]!=pre_define[i]){
            temp=1;
        }
    }
    if(temp==0){
        return true;
    }
    return false;
}
// =====================================================================

// =====================================================================
void restart(int Qusetion_index){
char op;
cout<<"\t\t\t\t\tDo YOU WANT PLAY AGAIN y/n  : ";
cin>>op;
if(op=='y' || op=='Y'){
    system("CLS");
    start(Qusetion_index+1);
}
else if(op=='n'||op=='N'){
    system("CLS");
    main();
}
else{
    restart(Qusetion_index);
}
}
// =====================================================================

// =====================================================================
void body(string pre,char*  world,int life,int len){
    system("CLS");    
cout<<"======================================================================================================"<<endl;
cout<<"\t\t\t\t\t HANGMAN  GAME "<<endl;
cout<<"======================================================================================================"<<endl;

if(life==0){
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\tLIFES : 6 "<<endl;
cout<<"||   /          "<<endl;
cout<<"||  /           "<<endl;
cout<<"|| /            "<< endl;
cout<<"||              "<<"\t\t "<<pre<<endl;
cout<<"||              "<<endl;
cout<<"||              "<<endl;
cout<<"||              "<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||       "<<endl;
cout<<"||       "<<endl;;
cout<<"||        "<<endl;
cout<<"||       "<<endl;
cout<<"||       "<<endl;
cout<<"||       "<<endl;
cout<<"||      "<<endl;
cout<<"====================="<<endl;

    }
   else if(life==1){
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\t\t\t\tLIFES : 5 "<<endl;
cout<<"||   /      ||  "<<endl;
cout<<"||  /       ||  "<<endl;
cout<<"|| /            "<< endl;
cout<<"||              "<<"\t\t"<<pre<<endl;
cout<<"||              "<<endl;
cout<<"||              "<<endl;
cout<<"||              "<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"====================="<<endl;

    }
   else if(life==2){
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\t\t\t\tLIFES :4"<<endl;
cout<<"||   /      ||"<<endl;
cout<<"||  /       ||"<<endl;
cout<<"|| /      (0  0)"<< endl;
cout<<"||        ------"<<"\t\t "<<pre<<endl;
cout<<"||              "<<endl;
cout<<"||              "<<endl;
cout<<"||              "<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"||"<<endl;
cout<<"====================="<<endl;
}

else if(life==3){
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\t\t\t\tLIFES : 3 "<<endl;
cout<<"||   /      ||"<<endl;
cout<<"||  /       ||"<<endl;
cout<<"|| /      (0  0)"<< endl;
cout<<"||        ------"<<"\t\t "<<pre;
cout<<endl;
cout<<"||          ||  "<<endl;
cout<<"||          ||  "<<endl;
cout<<"||          ||   "<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||          ||   "<<endl;
cout<<"||          ||   "<<endl;
cout<<"||          ||   "<<endl;
cout<<"||               "<<endl;
cout<<"||               "<<endl;
cout<<"||               "<<endl;
cout<<"||               "<<endl;
cout<<"====================="<<endl;
}

else  if(life==4){
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\t\t\t\tLIFES : 2 "<<endl;
cout<<"||   /      ||"<<endl;
cout<<"||  /       ||"<<endl;
cout<<"|| /      (0  0)"<< endl;
cout<<"||        ------"<<"\t\t "<<pre;
cout<<endl;
cout<<"||         _||_ "<<endl;
cout<<"||        []||[]"<<endl;
cout<<"||       [] || []"<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||       [] || []"<<endl;
cout<<"||       '' || ''"<<endl;
cout<<"||          ||    "<<endl;
cout<<"||              "<<endl;
cout<<"||               "<<endl;
cout<<"||               "<<endl;
cout<<"||               "<<endl;
cout<<"====================="<<endl;
}
    
else if(life==5){   
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\t\t\t\tLIFES : 1 "<<endl;
cout<<"||   /      ||"<<endl;
cout<<"||  /       ||"<<endl;
cout<<"|| /      (0  0)"<<"----->(OH NO I AM HANG PLSS SAVE ME )"<< endl;
cout<<"||        ------"<<"\t\t "<<pre;
cout<<endl;
cout<<"||         _||_ "<<endl;
cout<<"||        []||[]"<<endl;
cout<<"||       [] || []"<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||       [] || []"<<endl;
cout<<"||       '' || ''"<<endl;
cout<<"||        __||__ "<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       '''  '''"<<endl;
cout<<"====================="<<endl;
 }

else if(life==6){   
cout<<"______________________"<<endl;
cout<<"||===================="<<"\t\t\t\t\t\t\t\t\t\tLIFES : 0 "<<endl;
cout<<"||   /      ||"<<endl;
cout<<"||  /       ||"<<endl;
cout<<"|| /      (0  0)"<<"----->(......DEAD )"<< endl;
cout<<"||        ------"<<"\t\t "<<pre;
cout<<endl;
cout<<"||         _||_ "<<endl;
cout<<"||        []||[]"<<endl;
cout<<"||       [] || []"<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||       [] || []"<<endl;
cout<<"||       '' || ''"<<endl;
cout<<"||        __||__ "<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       '''  '''"<<endl;
cout<<"====================="<<endl;
 }

 else if(life==7){
cout<<"______________________"<<endl;
cout<<"||===================="<<endl;
cout<<"||   /          "<<endl;
cout<<"||  /           "<<endl;
cout<<"|| /      (0  0)"<<"---->(thank you for save me  )"<< endl;
cout<<"||        ------"<<"\t\t "<<pre;
cout<<endl;
cout<<"||         _||_ "<<endl;
cout<<"||        []||[]"<<endl;
cout<<"||       [] || []"<<"\t\t\t";
 for(int i=0;i<len;i++){
        cout<<world[i]<<" ";
        }
cout<<endl;
cout<<"||       [] || []"<<endl;
cout<<"||       '' || ''"<<endl;
cout<<"||        __||__ "<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"||       | |  | |"<<endl;
cout<<"====================="<<endl;
 }

}
// =====================================================================


// =====================================================================
void about(){
    system("CLS");
cout<<"=========================================================================="<<endl;
cout<<"\t\t\t ABOUT"<<endl;
cout<<"=========================================================================="<<endl;
cout<<"1) LINKDIN"<<endl;
cout<<"2) INSTGARM"<<endl;
cout<<"3) GITHUG"<<endl;
cout<<"4) MAIN MENU"<<endl;
char option;
cout<<"Enter your option : ";
cin>>option;
if(option=='1'){
     system("start chrome https://www.linkedin.com/in/kunwarpal/");
}
else if(option=='2'){
    system(" start chrome https://www.instagram.com/");
}
else if(option=='3'){
    system(" start chrome https://github.com/Kunwarpal621311");
}
else if(option=='4'){
    main();
}
else{
    system("ClS");
    cout<<"Enter a valid number"<<endl;
    abort();
}

}
// =====================================================================