#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	if(argc != 2){
		printf("USAGE: %s LENGTH\n", argv[0]);
		printf("EXEMPLE: %s 200\n", argv[0]);
		return 0;
	}
	int cpt_uppercase = 65;
	int cpt_lowercase = 97;
	int cpt_numeric = 48;
	int length = atoi(argv[1]);
	char str[length];
	for(int i = 0; i < length; i++){
		// If not at the end of possibilities, reset numeric or lowercase.
		if(cpt_numeric > 57){
			cpt_numeric = 48;
			cpt_lowercase++;
		}
		if(cpt_lowercase > 122){
			cpt_lowercase = 97;
			cpt_uppercase++;
		}
		// maximum limit
		if(cpt_uppercase > 90 ){
			break;
		}

		// Append the char to the string
		if((i)%3 == 0){
			str[i] = (char)cpt_uppercase;
		}
		else if((i)%3 == 1){
			str[i] = (char)cpt_lowercase;
		}
		else if((i)%3 == 2){
			str[i] = (char)cpt_numeric;
			cpt_numeric++;
		}
	}
	str[length] = '\0';
	printf("%s\n", str);
	return 0;
}

