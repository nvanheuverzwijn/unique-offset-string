#include<stdio.h>
#include<stdlib.h>
#include"argparse.h"
#include"pattern_parser.h"

int main(int argc, char* argv[])
{
	int errno;
	struct arguments args = parse_argument(argc, argv);
	int size;
	if(errno = pattern_length(args.pattern, &size)){
		exit(errno);
	}

	struct pattern_result presult[size];
	if(errno = pattern_parse(args.pattern, presult, &size)){
		exit(errno);
	}

	int length = args.length;
	char str[length];
	int bound;
	for(int i = 0; i < length; i++){
		for(int j = size - 1; j > 0; j--){
			if(errno = pattern_get_upper_bound(presult[j].type, &bound)){
				exit(errno);
			}	
			if(presult[j].i > bound){
				if(errno = pattern_get_lower_bound(presult[j].type, &bound)){
					exit(errno);
				}
				presult[j].i = bound;
				presult[j-1].i++;
			}
		}
		if(errno = pattern_get_upper_bound(presult[0].type, &bound)){
			exit(errno);
		}
		if(presult[0].i > bound){
			break;
		}
		str[i] = (char)presult[i%size].i;
		if(i%size == size - 1){
			presult[size - 1].i++;
		}
	}
	str[length] = '\0';
	printf("%s\n", str);
	return 0;
}

