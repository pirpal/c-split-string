C Split String
------------------


Some C functions to split a string according to a given separator.

	
# Why?

Because I don't like to use functions like `strtok` or `strsep`.

# Compile and run example `main.c`


See `Makefile`. C11 standard used.

To compile and run `main.c` example:


```sh
$ make && ./SPLIT_STRING
```


# Usage

Put files `split_string.c` and `split_string.h` in your source files. Include
it with:

```c
#include "split_string.h"
```

- `tokens_nb`:  gives you the number of tokens in a string

- `new_split`:  returns an array of strings made of string's tokens.

- `free_split`:  must be called for each split created with `new_split`

- `log_split`:  print to stdout (or a log file) your brand new split


The number of tokens is required by  `free_split` and `log_split`


```c
uint16_t tok_nb = tokens_nb(str, sep);
```

If you work on a CSV file, this number should be the same for all lines, so you
have to call the function only once, for example on the first line of the file.
But `tokens_nb` can also be used in a function where you verify that your CSV
file is well written before you use it ; it should have consistent lines with
the same amount of tokens/separators. It's probably worth checking that before
looping through the file's lines.

> the number of tokens in a string is always (nb of separators + 1)


```c
// Include header file:
#include "split_string.h"

#define HOBBITS "bilbo;frodo;sam;merry;pippin"
#define SEP ';'

int main (void)
{
	// Get numbers of tokens in the string:
	int tok_nb = tokens_nb(HOBBITS, SEP);
	
	// Get tokens as array of strings:
	char **split = new_split(HOBBITS, SEP);
	
	// Print tokens:
	log_split(stdout, split, tok_nb);
	
	// Free memory allocated by new_split:
	free_split(split, tok_nb);
	
	return EXIT_SUCCESS;
}
```

Output:

```txt
[0] 'bilbo'
[1] 'frodo'
[2] 'sam'
[3] 'merry'
[4] 'pippin'
```

# Empty fields

Empty fields are returned as empty strings `""`:

```c
const char *CSV_LINE = ";a;csv;line;;with;empty;fields;;"

int tok_nb = tokens_nb(CSV_LINE, ';');

char **split = new_split(CSV_LINE, ';');
log_split(stdout, tok_nb);
```

Output:

```txt
[0] ''
[1] 'a'
[2] 'csv'
[3] 'line'
[4] ''
[5] 'with'
[6] 'empty'
[7] 'fields'
[8] ''
[9] ''
```
	
	
# If no separator is found

The program won't exit on error, but the split will be an array with
an empty string as its unique element:
                                                                    
```c
const char *str = "a,comma,separated,line";
                                                                    
// passing a wrong separator:
char **split = new_split(str, ':');
                                                                    
// split => [""]
```
                                                                    
So it's better to check tokens number before calling `new_split`:

```c
if (tokens_nb(str, sep) == 0) {
	// do something else...
}
```
