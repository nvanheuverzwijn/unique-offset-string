all: unique-offset-string

unique-offset-string: unique_offset_string.c argparse.h pattern_parser.c
	gcc unique_offset_string.c pattern_parser.c -o unique-offset-string
