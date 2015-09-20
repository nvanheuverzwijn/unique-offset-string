# unique-offset-string
Create a unique offset string used for overflow.

# Installation

Simply call `make`.
```
$ cd ~/unique-offset-string
$ make
$ ./unique-offset-string --usage
Usage: unique-offset-string [-?V] [-p PATTERN] [--pattern=PATTERN] [--help]
            [--usage] [--version] LENGTH
```
You can then move the executable in `/usr/bin/` if you want.

# Usage

The help section.
```
Usage: unique-offset-string [OPTION...] LENGTH
Generates a unique offset string.

  -p, --pattern=PATTERN      Specify a pattern for the output like 'A0aA'
                             Default value is 'A0aA'
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

Report bugs to the github page
(https://github.com/nvanheuverzwijn/unique-offset-string).
```

The default pattern is `A0aA`.
```
$ ./unique-offset-string 8
A0aAA0aB
```

You can specify a pattern using the `-p` option. Only the uppercase(A), lowercase(a) and numeric(0) ASCII value are supported for the pattern option.
```
$ ./unique-offset-string -p A0a 10
A0aA0bA0cA
```
