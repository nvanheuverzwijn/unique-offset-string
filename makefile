all: unique_offset_string

unique_offset_string: unique_offset_string.c
	gcc unique_offset_string.c -o unique_offset_string
