#ifndef PATTERN_PARSER_H
#define PATTERN_PARSER_H

#define ERROR_PATTERN_NOT_IMPLEMENTED 100

#define TYPE_UPPERCASE 0
#define TYPE_LOWERCASE 1
#define TYPE_NUMERIC 2

#define UPPERCASE_MIN 65
#define UPPERCASE_MAX 90
#define LOWERCASE_MIN 97
#define LOWERCASE_MAX 122
#define NUMERIC_MIN 48
#define NUMERIC_MAX 57

struct pattern_result{
	int type; // What kind of value this is
	int i; // The current position of the value
};

int pattern_length(const char* pattern, int* length);
int pattern_parse(const char* pattern, struct pattern_result* pattern_result, const int* pattern_result_length);
int pattern_get_lower_bound(const int type, int* bound);
int pattern_get_upper_bound(const int type, int* bound);

#endif /*PATTERN_PARSER_H*/
