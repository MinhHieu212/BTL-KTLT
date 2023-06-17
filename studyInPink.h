/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void Rounding_EXP(int& EXP ){
	if (EXP > 900) EXP = 900;
	else if (EXP <0) EXP = 0;    	
}
void Rounding_HP(int& HP ){
	if (HP > 999) HP = 999;
	else if (HP < 0) HP = 0;    	
}
void Rounding_M(int& M ){
	if (M > 2000) M = 2000;
	else if (M < 0) M = 0 ;    	
}

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    if( E1 < 0 || E1 > 999 ) return -999;
    else {
    Rounding_EXP(EXP1); 
    Rounding_EXP(EXP2);                                            
    if(E1 < 400){
                    	// EXP2 of Watson
    	if(E1 < 50)	        EXP2 += 25;
		else if (E1 < 100)	EXP2 += 50;
		else if (E1 < 150)  EXP2 += 85;
		else if (E1 < 200)	EXP2 += 75;
		else if (E1 < 250)	EXP2 += 110;
		else if (E1 < 300)	EXP2 += 135;
		else	            EXP2 += 160;
		
		                // EXP1 of Cherlock 
    	if(E1 % 2 == 0) EXP1 = ceil(EXP1 - E1/5.0) ;
    	else EXP1 = ceil(EXP1 + E1/10.0) ;
    	
	}else{
			            // EXP2 of Watson
		if (E1 < 500)	    EXP2 = ceil(EXP2 + E1/7.0 + 9); 
		else if (E1 < 600)  EXP2 = ceil(EXP2 + E1/9.0 + 11); 
		else if (E1 < 700)	EXP2 = ceil(EXP2 + E1/5.0 + 6); 
		else if (E1 < 800)
	        { 	
			EXP2 = ceil(EXP2 + E1/7.0 + 9); 
		    if(EXP2 > 200) EXP2 = ceil(EXP2 + E1/9.0 + 11);
			}
		else
		    {  
			EXP2 = ceil(EXP2 + E1/9.0 + E1/7.0 + 20); 
		   	if(EXP2 > 600) EXP2 = ceil(EXP2 + E1/5.0 + 6);
		   	EXP2 = ceil(EXP2*1.15);
			}
		    	    	
		             	// EXP1 of Cherlock 
		EXP1 = ceil(EXP1 - E1*0.1); 	
	}
	Rounding_EXP(EXP1); 
    Rounding_EXP(EXP2);
    return EXP1 + EXP2;
    }
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    if(E2 < 0 || E2 > 999) return -999;
    else {
    Rounding_EXP(EXP1); 
    Rounding_EXP(EXP2);
    Rounding_HP(HP2);
    Rounding_M(M2);
    
    if (E2 < 300){
    	float d = E2/9.0 + 10 ;
		EXP2 += ceil(d);
		EXP1 += ceil(d/3.0);  
	}
	else if (E2 < 500){
		float d = E2/9.0 + 10 ;
		EXP2 += ceil(d);
		EXP1 += ceil(d/3.0); 
		float d2 = 0.35*E2;
		EXP2 += ceil(d2);
		EXP1 += ceil(d2/3.0);
	}else{
		int temp = EXP2 ;
        float d = E2/9.0 + 10 ;
		EXP2 += ceil(d);
		EXP1 += ceil(d/3.0); 
		float d2 = 0.35*E2;
		EXP2 += ceil(d2);
		EXP1 += ceil(d2/3.0);
		float d3 = (EXP2-temp)*0.17;
		EXP2 += ceil(d3);
		EXP1 += ceil(d3/3.0);		
	}
	
	HP2 = ceil(HP2 - pow(E2,3)/pow(2,23));
	if (E2 % 2 == 0) M2 += ceil(pow(E2,2)/50);
	
    Rounding_EXP(EXP1); 
    Rounding_EXP(EXP2);
    Rounding_HP(HP2);
    Rounding_M(M2);
    return EXP2 + HP2 + M2 + EXP1 ;
    }
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    if(E3 < 0 || E3 > 999) return -999;
    else {
     Rounding_EXP(EXP1);
	 Rounding_HP(HP1); 
	 Rounding_M(M1);
	 
    // RACE 1
	int P[20] = {1 ,3 ,5 ,7 ,9 ,11 ,13 ,15 ,17};
	int P1[20]; 
	int k = 0;
	int kt = 0; 
    for (int i = 1 ; i < 10 ; i++)
    	P1[i] = (P[i-1]+E3)%26 + 65; 
    	
	for (int i = 1 ; i < 10 ; i++){
		if (P1[i]==80){
		    k = i;  kt = i;
			HP1 -= 80*2*k;
			EXP1 += (1000-80*k)%101; 
			M1 = ceil(M1-(k*E3)/9.0); 
		}
	}	 
	if(k==0) M1 -= E3*9;
	
	// RACE 2 
	int N[10] = {2, 3, 5, 7, 11, 13, 17};
	int N1[10] , N2[10] , s = 0  , m = 0;
	k = 0;
	for (int i = 1 ; i < 8 ; i++){
    	N1[i] = (N[i-1]+E3)%26; 
    	s += N1[i]; 
    }
    m = ceil(s/7.0);
    
    for (int i = 1 ; i < 8 ; i++)
    	N2[i] = (N1[i]+m+s)%26 + 65; 
		  
	for (int i = 1 ; i < 8 ; i++){
		if (N2[i]==80){
			k = i;  kt = i;
			HP1 -= 80*2*k;
			EXP1 += (1000-80*k)%101;  
			M1 = ceil(M1-(k*E3)/9.0);
		}
	}	 
    if(k==0) M1 = ceil(M1 - 7*7*E3/9.0);
	
	// RACE 3   
	int  A[30]={4, 16, 36, 64, 100, 144, 196, 256, 324, 400, 484, 576, 676, 784, 900, 1024, 1156, 1296, 1444, 1600};
	int A1[30] , A2[30]; 
	k = 0;	
	for(int i = 1 ; i < 21 ; i++)
		A1[i] = (A[i-1]+E3*E3)%113;
	
	int max = A1[1];
	for(int i = 1 ; i < 21 ; i++)
		if(max < A1[i]) max = A1[i];	
		 
	for(int i = 1 ; i < 21 ; i++)
	 	A2[i] = ((int)ceil((A1[i]+E3)/max))%26 + 65;
	for(int i = 20 ; i > 0 ; i--){
		if(A2[i]==80){
			k = 21 - i;  kt = i;
			HP1 -= 80*3*k;
			EXP1 += (3500-80*k)%300;
			M1 = ceil(M1-(k*E3)/9.0);
		}
	}	
	if(k==0) M1 = ceil(M1 - 20*20*E3/9.0);
	
	// RACE 4
	int D[20]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int D1[20] , D2[20];
	k = 0;   
	for(int i = 1 ; i < 13 ; i++) 
	    D1[i] = (D[i-1] + (int)pow(ceil(E3/29.0),3))%9;
	    
	int minn = D1[1] , minn_idx ;
	for(int i = 1 ; i < 13 ; i++){
	  	if(minn > D1[i]){
		 minn = D1[i];
		 minn_idx = i;	
		}  	
    }
    
	for(int i = 1 ; i < 21 ; i++) 
        D2[i] = ((int)((D1[i]+E3)*ceil(minn*1.0/minn_idx)))%26 + 65;
	for(int i = 12 ; i > 0 ; i--){
		if (D2[i] == 80){
			k = 13 - i;  kt = i;
			HP1 -= 80*k*4;
			EXP1 += ((4500-80*k)%400);
 	        M1 = ceil(M1-(k*E3)/9.0);
		}
	}	
	if(k==0)  M1 = ceil(M1 - 12*12*E3/9.0);	
	
	if(kt==0){
	HP1 -= ((59*E3)%900); 
	EXP1 -= ((79*E3)%300);
    }
	
	Rounding_EXP(EXP1);
    Rounding_HP(HP1); 
	Rounding_M(M1);
	
	if(kt==0)return -1;
	else return EXP1 + HP1 + M1 ;	
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
