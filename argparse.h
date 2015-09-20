#ifndef ARGPARSE_H
#define ARGPARSE_H

#include<argp.h>
#include"string.h"

const char *argp_program_version = "1.0.0";
const char *argp_program_bug_address = "the github page (https://github.com/nvanheuverzwijn/unique-offset-string)";
static char doc[] = "Generates a unique offset string.";
static char args_doc[] = "LENGTH";
static struct argp_option options[] = {
  {"pattern",  'p', "PATTERN", 0,  "Specify a pattern for the output like 'A0aA' Default value is 'A0aA'" },
  { 0 }
};
struct arguments
{
  int length;
  char* pattern;
};

static error_t parse_opt (int key, char *arg, struct argp_state *state){
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;

  switch (key)
    {
    case 'p':
     arguments->pattern = arg;
     break;
    case ARGP_KEY_ARG:
      if (state->arg_num >= 1){
        argp_usage (state);
      }
      arguments->length = atoi(arg);
      break;
    case ARGP_KEY_END:
      if (state->arg_num < 1){
        argp_usage (state);
      }
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}
static struct argp argp = { options, parse_opt, args_doc, doc };


struct arguments parse_argument(int argc, char *argv[]){
	struct arguments a;
	a.pattern = "A0aA";
	argp_parse(&argp, argc, argv, 0, 0, &a);
	return a;
}

#endif /*ARGPARSE_H*/
