#include"pattern_parser.h"
#include<string.h>

int pattern_length(const char* pattern, int* length){
	*length = strlen(pattern);
	return 0;
}

int pattern_parse(const char* pattern, struct pattern_result* pattern_result, const int* pattern_result_length){
	for(int i =0; i < *pattern_result_length; i++){
		if(pattern[i] >= UPPERCASE_MIN && pattern[i] <= UPPERCASE_MAX){
			pattern_result[i].type = TYPE_UPPERCASE;
			pattern_result[i].i = UPPERCASE_MIN;
		}
		else if(pattern[i] >= LOWERCASE_MIN && pattern[i] <= LOWERCASE_MAX){
			pattern_result[i].type = TYPE_LOWERCASE;
			pattern_result[i].i = LOWERCASE_MIN;
		}
		else if(pattern[i] >= NUMERIC_MIN && pattern[i] <= NUMERIC_MAX){
			pattern_result[i].type = TYPE_NUMERIC;
			pattern_result[i].i = NUMERIC_MIN;
		}
		else{
			return ERROR_PATTERN_NOT_IMPLEMENTED;
		}
		
	}
	return 0;
}
int pattern_get_lower_bound(const int type, int* bound){
	switch(type){
		case(TYPE_UPPERCASE):
			*bound = UPPERCASE_MIN;
			break;
		case(TYPE_LOWERCASE):
			*bound = LOWERCASE_MIN;
			break;
		case(TYPE_NUMERIC):
			*bound = NUMERIC_MIN;
			break;
		default: 
			return ERROR_PATTERN_NOT_IMPLEMENTED;
	}
	return 0;
}
int pattern_get_upper_bound(const int type, int* bound){
	switch(type){
		case(TYPE_UPPERCASE):
			*bound = UPPERCASE_MAX;
			break;
		case(TYPE_LOWERCASE):
			*bound = LOWERCASE_MAX;
			break;
		case(TYPE_NUMERIC):
			*bound = NUMERIC_MAX;
			break;
		default: 
			return ERROR_PATTERN_NOT_IMPLEMENTED;
	}
	return 0;
}
