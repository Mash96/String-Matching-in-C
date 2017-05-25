#include <stdio.h>
#include <string.h>

void main(){

	//take two strings
	char S1[10]={"Vishwa"};
	char S2[10]={"Vishwa"};
	int i;
	char *isEqual="True"; //assign isequal to true

	//slide through the longest length string
	for(i=0;i<10;i++){

		//check whether each letter is mathching in both strings
		if(S1[i]!=S2[i]){ 
			//if not assign isequl to false
			isEqual="False";
			break;
		}
	}
	if(isEqual=="True"){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}
			
	
