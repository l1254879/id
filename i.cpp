#include<iostream>
#include<fstream.h>
#include<string.h>
#include<sys/time.h>
#include<cstdlib>
using namespace std;

void open_file();
int sumofAllPlaces(const string &IDNumber);
bool isvalid(const string &IDNumber);
int returnSubstr(const string &IDNumber);
void allinone(const string &IDNumber,bool type);
void generate(char*);
int main(){
  struct timeval tv;
  struct timeval tz;
  gettimeofday(&tv,NULL);
  open_file();
  gettimeofday(&tz,NULL);
  long spentus=(tz.tv_sec*1000000+tz.tv_usec)-(tv.tv_sec*1000000+tv.tv_usec);
  int us=spentus%1000000;
  cout<<us<<" microseconds"<<endl;
  return 0;
}
void open_file(){
  FILE*tmp;
  char id[11]={0};//since fgets read \0
	bool type;
  fstream file;
  tmp=fopen("id_out.txt","r");
  if(!tmp){ //if faile to open file
    cout<<"Fail to open file"<<endl;
  }
  else{
    fgets(id,11,tmp);//get the a line string
  }
 type=sumofAllPlaces(id);
	allinone(id,type);


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
	char Id[10]={0};
	if(type)
		cout<<IDNumber<<": an invalid ID #"<<endl;
	else
		cout<<IDNumber<<": an invalid ID #"<<endl;
	generate(Id);


}
void generate(char *IDNumber){
	char ran;
	int i;
	char english;
	int check;
	srand(time(NULL));
	english=rand()%26+65;
	IDNumber[0]=english;
	for(i=2;i<9;i++){
		ran=rand()%10+48;
		IDNumber[i]=ran;
	}
	check=sumofAllPlaces(IDNumber);
	IDNumber[9]=check+48;
	cout<<IDNumber<<endl;

}
