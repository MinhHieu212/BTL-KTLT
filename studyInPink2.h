/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream file;
    file.open(ntb1);
		string firstline, line2th; 
		getline(file,firstline);
		getline(file,line2th);
	file.close();	
	string tmp;
	tmp = firstline.substr(11,3);
	for(int i=0 ; i<3 ; i++){
		if(tmp[i]<'0'||tmp[i]>'9'){
			return "00000000000";
		}
	}
    stringstream sti(tmp);
    int n = 0;
    sti >> n;
    if(n > 999 || n < 1) return "00000000000";
    long long num = 0; int num0 = 0;
    string number = "0123456789";
    for(int i = 0 ; i < 10 ; i++){
    	int cnt = 0;
    	for(int j = 0 ; j < 2*n-1 ; j++){
    		if(number[i] == line2th[j]) cnt++;
		}
		num = num*10 + cnt%10;
		if(num == 0) num0++;
	}
	string result;          
    ostringstream convert;   
    convert << num;      
    result = convert.str(); 
    string str0 = "00000000000";
    string Result = str0.substr(0,num0);
    return Result+result;
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream file;
	file.open(ntb2);
	    int lines = 0;
	    file >> lines;
	    file.ignore();
	    if(lines < 5 || lines > 100) 
		   return  "1111111111";
	    string line[100];
	    for(int i = 0 ; i < lines ; i++)
	    	getline(file,line[i]);
    file.close(); 
    long long cntP = 0;
    for(int i = 0 ; i < lines ; i++){
    	int len = line[i].length();
		for(int j = 0 ; j < len-3 ; j++){
			if((line[i][j] == 'P'||line[i][j] == 'p')&&line[i][j+1] == 'i'&&line[i][j+2] == 'n'&&line[i][j+3] == 'k')
			cntP++;
		}
	}
    if(cntP < 10000) cntP *= cntP;  
    string result;          
    ostringstream convert;   
    convert << cntP;      
    result = convert.str(); 
    string Result = "9";
    int n = result.length();
    for( int i = 0 ; i < 10-n ; i++){
        result += Result;	
	}
	return result;
}

bool isPrime(int n){
     if(n<2)
     return false;
     for(int i = 2; i <= (int)sqrt(n); i++){
     if(n%i==0)
     return false;
	 }
     return true;
}
 
int roundSnt(int n){
	int i = 0;
	int up , down ;
	while(1){
		up = n + i;
		down = n - i;
		if(isPrime(up) || isPrime(down)) break;
		i++;
	}
	if(isPrime(up)) return up;
	else return down;
}

int fb(int n){
if(n==1||n==0||n==2||n==3) return n;  
   return fb(n-2)+fb(n-1);
} 

bool checkFibo(int n){ 
     int d = 0;
     for( int i = 0 ; i <= n ; i++){
	 if(n == fb(i)) d++;
	 }
	 if(d==1) return true;
	 else return false;
}

int roundFibo(int n){
	int i = 0;
	int up , down ;
	while(1){
		up = n + i;
		down = n - i;
		if(checkFibo(up) || checkFibo(down)) break;
		i++;
	}
	if(checkFibo(up)) return up;
	else return down;
}

string notebook3(string ntb3){
    // Complete this function to gain point
    long long arr[10][10];
    ifstream file;
	file.open(ntb3);
		for(int i = 0 ; i < 10 ; i++){
			for(int j = 0 ; j < 10 ; j++){
				int tmp ;
				file >> tmp;
				arr[i][j] = abs(tmp);
				file.ignore();
			}
		}	
	 file.close();
	 // Buoc 1
	 for(int i = 0 ; i < 9 ; i++){
	 	 for(int j = i+1 ; j < 10 ; j++)
		    arr[i][j] = roundSnt(arr[i][j]);
	 }
	 // Buoc 2
	for(int i = 1 ; i < 10 ; i++){
    	for(int j = i-1 ; j >= 0 ; j-- )
		    arr[i][j] = roundFibo(arr[i][j]);
	 }
	 // Buoc 3
	for(int i = 0 ; i < 10 ; i++)
		for(int j = 7 ; j < 9 ; j++)
			for(int k = j+1 ; k < 10 ; k++)
				if(arr[i][j] > arr[i][k]) 
				
				{
					int tmp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = tmp;
				}
			
	long long num = 0; int num0 = 0;
    for(int i = 0 ; i < 10 ; i++){
    	int max = arr[i][0]; int index = 0;
    	for(int j = 0 ; j < 10 ; j++){
    		if(arr[i][j] >= max){
    			max = arr[i][j];
    			index = j;
			}
		}  num = num*10 + index;
		   if(num == 0) num0++;
    }
    
	string result;          
    ostringstream convert;   
    convert << num;      
    result = convert.str(); 
    string str0 = "00000000000";
    string Result = str0.substr(0,num0);
    return Result+result;	 
}

string g(string p1 , string p2){
	int a , b , c = 0 , sum , d;
	long long num = 0; 
	int num0 = 0;
	for(int i = 0 ; i < 10 ; i++){
		a = p1[i] - 48; 
		b = p2[i] - 48;
		sum = a + b + c; 
		if(sum > 9) {
		    d = sum%10; c = sum/10;
		}else{
			d = sum; c = 0;
		}
		num = num*10 + d;
		if(num == 0) num0++;	
	}	
	string result;          
    ostringstream convert;   
    convert << num;      
    result = convert.str(); 
    string str0 = "00000000000";
    string Result = str0.substr(0,num0);
    return Result+result;  
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string PASS;
    PASS = pwd1 +";"+ pwd2 +";"+ pwd3 +";"+ g(pwd1,pwd2) +";"+ g(pwd1,pwd3) +";"+ g(pwd2,pwd3)
    +";"+ g(g(pwd1,pwd2),pwd3) +";"+ g(g(pwd2,pwd3),pwd1) +";"+ g(g(pwd1,pwd2),g(pwd3,pwd1));
    return PASS;
}

bool check(int m ){
	if(m > 100 || m < 0 ) return false;
	return true;
}

string Xoa(string str){
	int len = str.length();
	for(int i = 0 ; i < len ; i++){
		if(str[i] > '9' || str[i] < '0') str[i] = ' ';
	}
	return str;
}
 
bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {

    // Complete this function to gain point
    outCatchUps = "";
    outTimes = "";
    for(int i = 0 ; i < 100 ; i++){
    	for(int j = 0 ; j < 100 ; j++){
    		arr[i][j] = -9;
		}
	}
	int arr2[100][100];
	for(int i = 0 ; i < 100 ; i++){
    	for(int j = 0 ; j < 100 ; j++){
    		arr2[i][j] = 0;
		}
	}

	int n=0 , m=0 , time = 0;
	arr[0][0] = 0;
	for(int i = 0 ; i < moves.length() ; i++){  
		if(moves[i] == 'R'){
		    if(check(n+1)){
		    n++ ; time++;
			arr[m][n] = 9*time;	
		    }
		    else continue;    
		}
		else if(moves[i] == 'L'){
		    if(check(n-1)){
		    n-- ; time++;
			arr[m][n] = 9*time;	
		    }
		    else continue;
		}
		else if(moves[i] == 'U'){
			if(check(m-1)){
		    m-- ; time++;
			arr[m][n] = 9*time;	
		    }
		    else continue;
		}
		else{
			if(check(m+1)){
		    m++ ; time++;
			arr[m][n] = 9*time;	
		    }
		    else continue;
	    }
	}
 
    int k=2;
    points  = Xoa(points);
    int id[200] ; id[0] = 0; id[1] = 0; 
    stringstream ss(points);
	while(ss >> id[k]) k++;
	for(int i = 2 ; i < k ; i = i+2){
    arr2[id[i]][id[i+1]] = (abs(id[i]-id[i-2]) + abs(id[i+1]-id[i-1]))*14 + arr2[id[i-2]][id[i-1]]; 
    }
	int check = 0;
	for(int i = 2 ; i < k ; i = i+2){
		if(check!=0){
			outCatchUps += "-;";
			outTimes += "-;";
	     	continue;
		} 
		
	    if(arr2[id[i]][id[i+1]] > arr[id[i]][id[i+1]]){
	     	  outCatchUps += "N;";
	     	  outTimes += (to_string(arr2[id[i]][id[i+1]]) + ";");
		}else{
		 	  outCatchUps += "Y;";
		 	  outTimes += (to_string(arr2[id[i]][id[i+1]]) + ";");
			  check++;
		}
    } 
    int lenout = outCatchUps.length();
    outCatchUps = outCatchUps.substr(0,lenout-1);
    lenout = outTimes.length();
    outTimes = outTimes.substr(0,lenout-1);
	
	
	
		if(check!=0)
		return true;
        return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream file;
    file.open(tag);
    string Email , Address ;
    getline(file,Email);
    getline(file,Address);
    file.close();
    int len = Email.length();
    Email = Email.substr(7,len);
    int len2 = Address.length();
	if(len2 == 21) Address = Address.substr(9,1);
	else Address = Address.substr(9,2); 
    stringstream ss(Address);
    int n ; ss >> n;
    string Name = message;
    for(int i = 0 ; i < n-1 ; i++){
    	message += Name;
	}
	return Email + ";" + message;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
