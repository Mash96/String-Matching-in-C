#include<stdio.h>
#include<string.h>

void SpecialSearch(char *,char *,char *);
void main(){
	char *pattern1 = "matching";
	char *pattern2 = "function";
	char *text = "gtmatchingwefunction";
	SpecialSearch(pattern1,pattern2,text);
}

void SpecialSearch(char *p1,char *p2,char *T)  //checking two patterns inside the text
{
	int m1 = strlen(p1);
	int m2 = strlen(p2);
	int n = strlen(T);

	int lps[m1]; //length of p1
	int lp[m2]; //length of p2

	int len = 0;
	lps[0] = 0;  //prefix array of pattern1
	lp[0] = 0;   //prefix array of pattern2

	

	for(int q = 1; q < m1; q++){		//create  a prefix table for the pattern1
		while(len > 0 && p1[len] != p1[q]){  
			len = lps[len];
		}
		if(p1[len] == p1[q]){
			len++; 		
		}
		lps[q] = len;
	}
	
	

	for(int q = 1; q < m2; q++){		//create  a prefix table for the pattern2
		while(len > 0 && p2[len] != p2[q]){  
			len = lp[len];
		}
		if(p2[len] == p2[q]){
			len++; 		
		}
		lp[q] = len;
	}
	
	


	int j ;
	int k = 0;

	for(j=0;j<n;j++){			//checking pattern1 in text
		while(k>0 && p1[k] != T[j]){
			k = lps[k];
		}
		if(p1[k]==T[j]){
			k++;
		}
		if(k==m1){
			printf("%s Found at index %d\n",p1,j-m1+1);
			k = lps[k];
		}
	}

	for(j=0;j<n;j++){			//checking pattern2 in text
		while(k>0 && p2[k] != T[j]){
			k = lp[k];
		}
		if(p2[k]==T[j]){
			k++;
		}
		if(k==m2){
			printf("%s Found at index %d\n",p2,j-m2+1);
			k = lp[k];
		}
	}
}
	
	
	
	
