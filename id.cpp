#include<iostream>
#include<fstream>
#include<string.h>
#include<sys/time.h>
#include<cstdlib>
#include<sstream>
using namespace std;
void openfile_and_merge(int,char**);
string& fakeOne(const string &gender);
int sumofAllPlaces(const string &IDNumber);
int returnSubstr(const string &IDNumber);
bool isvalid(const string &IDNumber);
bool startsWith (const string&,const string&);
int initrand();

int main(int argc,char*argv[]){  /* It is main function*/
  openfile_and_merge(argc,argv);    //use argv to open file
  return 0;
}
void openfile_and_merge(int argc,char *argv[]){
  char id[11]={0};//since getline read \0
  bool type_for_str_compare,type_for_id_valid;//str_compare is to use on returnSubstr,id_valid use on isvalid function
  int substr; //returnSubstr return int
  string call_startwith;//deal with string int transform
  string gender;//get M or F
  string Id;//get the finish generate ID
  struct timeval start,end;
  double time;
  ifstream file;//open file 
  stringstream ss;//let string to int int to string

  if(argc==1){    //if there is only a.out
    cout<<"No file"<<endl;
  }
 else if(argc==2){//if ./a.out inputfile
    file.open(argv[1],ios::in); //open file
    if(!file){ //if cannot find the file
      cout<<"Failed to open file"<<endl;
     }
     else{	//else can find the file
     		    while(file.getline(id,11)&&!file.eof()){//get a line string                             
     				if(id[1]=='\0'){                                                  /*     Generate  ID if read one char     */
     					     gender=id[0];      
     					     gettimeofday(&start,NULL);//starta
     					     Id=fakeOne(gender);
     					     gettimeofday(&end,NULL);//enda
     					     time=(double)((end.tv_usec)-(start.tv_usec));
     					    if(gender[0]=='M')
     						        cout<<"Generate a valid Male ID #: "<<Id<<"; Timing: "<<time<<" microseconds"<<endl;
                          	 else if(gender[0]=='F')
   						        	cout<<"Generate a valid Female ID #: "<<Id<<"; Timing: "<<time<<" microseconds"<<endl;
                   }
            		else{
              				 substr=returnSubstr(id);         /*   Deal with  judge id */
              				 ss.clear();
              				 ss<<substr;
              				 ss>>call_startwith;
             				 type_for_str_compare=startsWith(id,call_startwith);
             				 call_startwith.clear();
              				 if(type_for_str_compare){
                    			 type_for_id_valid=isvalid(id);
            					 if(type_for_id_valid)
                     					 cout<<id<<": a valid ID #"<<endl;
             					 else
                     					cout<<id<<" an invalid ID #"<<endl;
			  				}
			  				else
			  					cout<<"Tranform failure"<<endl;
           		 }
       		}
          file.close(); //close the file
        }
      }
      else{
         file.close();
      }
    }
string& fakeOne(const string &gender){
    	char ran; //set the random char
    	static string id_is_generating;//use to generate id
    	string tmp;//used to get the char and added to id_is_generating
    	char english;//random to generate a local number
    	int check_code;//get the return check_code
    	int i; //i for loop
    	char solve_check_to_char;//help to int to char
    	stringstream ss;//ss file stringstream function
		static int nouse=initrand();


    	/*         declar over           */
    	english = rand()% 26 + 65; //the ascii A-Z is btw 65-90
    	tmp = english;
    	id_is_generating.clear();
    	id_is_generating=id_is_generating + tmp;

    	/*        generate  the first local number over            */

      	if(gender[0]=='M'){
        	  tmp='1';  //ascii number 49 is number 1
     	}
      	else if(gender[0]=='F'){
        	  tmp='2'; //ascii number 50 is number 2
      	}
    	else{
    		cout<<"Wrong number must be M & F"<<endl;
    	}
    	id_is_generating = id_is_generating + tmp;
    	for(i=2;i<9;i++){ // want to generate other Id number and leave the last space to check
    		ran = rand() % 10 + 48; //ascii number 48-58
    		tmp = ran;
    		id_is_generating = id_is_generating + tmp;
    	}
    	check_code = sumofAllPlaces(id_is_generating.c_str());
    	ss << check_code;
    	ss >> solve_check_to_char;
    	tmp = solve_check_to_char;
    	id_is_generating = id_is_generating+tmp;
    	return id_is_generating;
}
int sumofAllPlaces(const string &IDNumber){
    	int lo_num;//get the local stat change code
    	int rest;//aim of lo_num
    	int divide;//aim of lo_num
    	int check_code;
    	int tmp_for_count_localnum = 0 , tmp_for_count_restnum = 0;
    	int sum_of_tmp;
    	int i,j=8;
    	static char ID[11];
    	/*          declar is over           */
    	strcpy(ID,IDNumber.c_str());
    	lo_num=returnSubstr(ID);
    	rest=lo_num % 10;
    	divide = lo_num / 10;
    	tmp_for_count_localnum = rest *9 + divide;//deal with lo_num
    	for(i=1;i<9;i++){
    		tmp_for_count_restnum = ( ID[i] - 48 )*j + tmp_for_count_restnum ;
    		j--;
    	}
    	sum_of_tmp = tmp_for_count_localnum + tmp_for_count_restnum ;//get the all of the sum
    	check_code = 10 - (sum_of_tmp % 10);//check code arithmetic
    	if(check_code==10)
    			 check_code=0;
    	     return check_code;
}
int returnSubstr(const string &IDNumber){
    	int change_local_char_to_Int[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33}; //local mapping
    	int get_ascii=0;//get the A-Z ascii
    	get_ascii=IDNumber[0];//get the first place ------local char
    	get_ascii=get_ascii-65;
    	return change_local_char_to_Int[get_ascii];
}
bool isvalid(const string &IDNumber){
	int return_check_code;//declar the check code
	char Id_check_code;
	char tmp_check;
	Id_check_code=IDNumber[9];//the last ID num that is check code
	return_check_code=sumofAllPlaces(IDNumber);//get int check code
	tmp_check=return_check_code+48;
	if(tmp_check==Id_check_code)
		return true;
	else
		return false;
}
bool startsWith (const string& IDNumber,const string& substr){

  int get_local_num;//get the first IDNumber
  string cpy_substr;
  string trans_substr_to_char;
  stringstream ss;

  trans_substr_to_char.clear();
  cpy_substr=substr;
  get_local_num = returnSubstr(IDNumber);
  ss.clear();
  ss<<get_local_num;
  ss>>trans_substr_to_char;
  if(cpy_substr.compare(trans_substr_to_char)==0){//str compare
    return true;
   }
  else
    return false;
}
int initrand(){
	srand(time(0)); //metarandom
	return 0;
}
