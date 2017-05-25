#include <stdio.h>
#include <string.h>
char *NaiveStringMatch(char *,char*);
void main(void){
	char *pattern="caab";
	char *text="abddcaab";
	
	NaiveStringMatch(pattern,text);
	
}
char *NaiveStringMatch(char *P, char *T)
{
	int m = strlen(P);
	int n = strlen(T);
	// S equals number of shifts
	// number of shifts should be less than (text_length - patter_length)
	for(int S=1;S<(n-m+1);S++){
		char *isEqual="True";
		//slide through the pattern
		for(int i=0;i<m;i++){  
			//after a shift the text index numbering start from 
			//[number of shift made + i]
			if(P[i]!=T[S+i]){
				isEqual="False";
			}
		}
		if(isEqual=="True"){
				
			printf("%d\n",S);
		}
		
	}
	
	
	
}
