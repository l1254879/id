#include<iostream>
#include<fstream.h>
#include<string.h>
#include<sys/time.h>
#include<cstdlib>
using namespace std;

void open_file(int,char**);
int sumofAllPlaces(const string &IDNumber);
bool isvalid(const string &IDNumber);
int returnSubstr(const string &IDNumber);
void allinone(const string &IDNumber,bool type);
void generate(int);

int main(int argc,char*argv[]){
  open_file(argc,argv);
  return 0;
}
void open_file(int argc,char *argv[]){
  FILE*tmp;
  char id[10]={0};//since fgets read \0
	bool type;
	int i;
  fstream file;
  if(argc==1){ //if faile to open file
    cout<<"Fail to open file"<<endl;
  }
 else if(argc==2){
  	file.open(argv[1],ios::in);
  	do{//get a line string
  		file.getline(id,sizeof(id));
		type=isvalid(id);
			if(type== true)
 				allinone(id,type);
			else
 				allinone(id,type);

	}while(!file.eof());
	file.close();
  }
  else{
  	cout<<"Too much argument"<<endl;
  }
  
 
}
bool isvalid(const string &IDNumber){
	int check;//get the check code
	int a;
	a=IDNumber[9];
	check=sumofAllPlaces(IDNumber);
	if(check==a-48)
		return true;
	else
		return false;
}

int sumofAllPlaces(const string &IDNumber){
		int lo_num;//get the local stat change code
		int rest;//aim of lo_num
		int divide;//aim of lo_num
		int check;
		int tmp,tmp1=0;
		int i,j=8;
		lo_num=returnSubstr(IDNumber);
		rest=lo_num%10;
		divide=lo_num/10;
		tmp=rest*9+divide;//deal with lo_num
		for(i=1;i<9;i++){
			tmp1=(IDNumber[i]-48)*j+tmp1;
			j--;
		}
		tmp=tmp+tmp1;//get the all of the sum
		check=10-(tmp%10);//check code arithmetic
			return check;
}

bool startsWith(const string &IDNumber,const string &substr){
	//if(substr)

}
string& fakeOne(const string &gender){

}
int returnSubstr(const string &IDNumber){
	int change[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	int get_ascii=0;
	get_ascii=IDNumber[0];
	get_ascii=get_ascii-65;
	return change[get_ascii];
}
void allinone(const string &IDNumber,bool type){
	char gender;
  struct timeval tv;
  struct timeval tz;
	if(sizeof(IDNumber)>1){
	
		if(type)
			cout<<IDNumber<<": an valid ID #";
		else
			cout<<IDNumber<<": an invalid ID #";
	}
	else{
			if(IDNumber[0]=='M')
				gender='M';
			else if(IDNumber[0]=='F')
				gender='F';
			cout<<"This is gender"<<gender<<endl;
			//generate(gender);
		}
  		/*gettimeofday(&tv,NULL);
		generate(gender);
  		gettimeofday(&tz,NULL);
 		 long spentus=(tz.tv_sec*1000000+tz.tv_usec)-(tv.tv_sec*1000000+tv.tv_usec);
  		int us=spentus%1000000;
		cout<<"Timing:"<<us<<" microseconds"<<endl;*/

}
void generate(char gender){
	char ran;
	char Id[11]={NULL};
	char english;
	int check,i;
	srand(time(NULL));
	english=rand()%26+65;
	Id[0]=english;
	Id[1]=gender;
	for(i=2;i<9;i++){
		ran=rand()%10+48;
		Id[i]=ran;
	}
	check=sumofAllPlaces(Id);
	Id[9]=check+47;
	cout<<"Generated a valid ID #:"<<Id<<endl;

}
