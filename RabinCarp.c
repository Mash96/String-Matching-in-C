#include <stdio.h>
#include<string.h>
#include<math.h>

char *RabinCarp(char *, char *, int,int);
void main(void){

	char *Pattern = "abcabdabc";
	char *Text = "adabcabdabcabdabdabc";
	int d = 100;
	int q = 13;

	RabinCarp(Text,Pattern,d,q);
	
	
}

char *RabinCarp(char *T, char *P, int d,int q) //d is usually consider as the size of the alphabet
						//choose a "q" such that "dq" fix a word in your 							//system, usually take a prime number
{
	int m = strlen(P);
	int n = strlen(T);
	int i,j;
	int p = 0;  //hash value of Pattern
	int t = 0;  //hash value of Text
	int h = 1;  //pow(d,m-1)%q

	
	//calculating pow(d,m-1)%q
	for(i=0;i < m-1;i++){

		h = (h*d)%q;
	}
	// Calculate the hash value of pattern and first window of text
	for (i=0; i < m; i++){
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}
	  // Slide the pattern over text one by one
	for (i = 0; i <= n-m;i++){

	    // Check the hash values of current window of text and pattern. 
	    // If the hash values match then only
            // check for characters on by one
		if(p==t){

			//check the characters one by one
			for(j=0; j<m;j++){
				if(T[i+j] != P[j]){
					break;
				}	
			}

			 // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			//print the number of shifts has done
			printf("Pattern occurse with shift : %d\n",i);

			
		}
		// Calculate hash value for next window of text: Remove
           	 // leading digit, add trailing digit
		if(i<n-m){
			t = (d*(t-T[i]*h) + T[i+m])%q;

			// We might get negative value of t, converting it
                        // to positive
			if(t<0){
				t = (t+q);
			}
		}
	}

	
	
	
}
				

	
