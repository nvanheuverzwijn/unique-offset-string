all: unique_offset_string

unique_offset_string: unique_offset_string.c argparse.h pattern_parser.c
	gcc unique_offset_string.c pattern_parser.c -o unique_offset_string
