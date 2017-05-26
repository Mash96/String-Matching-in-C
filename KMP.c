#include <stdio.h>
#include <string.h>
#include <math.h>

int prefixFn(char *);
int kmpMatch(char *,char *);

void main(){
	char *pattern = "abacab";
	char *text = "dcdabacab";
	
	prefixFn(pattern);
	kmpMatch(text,pattern);
}

int prefixFn(char *P)
{
	int m = strlen(P);
	int pi[m] ; //prefix table
	int k =0;  //length of the longest prefix that has been found in the pattern
		   //pointer to the end of the matching prefix
	pi[0] = k; //initializing the integer array
	
	for(int q = 1; q < m; q++){ //pointer to the point for which we are calculating the pi value
		while(k > 0 && P[k] != P[q]){  //checking for equalities inside the prefix
			k = pi[k];
		}
		if(P[k] == P[q]){
			k++; 		//creating the prefix array
		}
		pi[q] = k;
	}
	
	for(int j=0;j<m;j++){
		return pi[j];
	}
}

int kmpMatch(char *T,char *P)
{
	int n = strlen(T);
	int m = strlen(P);
	int q = 0;  	//no. of chars matched
	int pi[m];
	for(int j =0;j<m;j++){ 
		pi[j] = prefixFn(P);    //precompute pi
	}
	
	for(int i=0; i<n;i++){   //pointer of text
		while(q<0 && P[q] != T[i]){ //check from left to right
			q = pi[q];	    //check from the pi array    
		}
		if(P[q] == T[i]){  //if a match then itterate q by 1
			q++;
		}
		if(q==m){
			printf("%d\n", i-m+1); //valid shifts
			q = pi[q];             //goto next match
		}
	}
}
	
			
		
	
