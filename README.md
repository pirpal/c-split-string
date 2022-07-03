C Split String
------------------


Some C functions to split a string according to a given separator.

	
### Why?

Because I don't like to use functions like `strtok` or `strsep`.

### Compile and run example `main.c`



```sh
$ mkdir bin obj tests/bin
$ make && ./bin/SPLIT_STRING
```


### Usage

Put files `split_string.c` and `split_string.h` in your source files. Include
it with:

```c
#include "split_string.h"
```

- `new_split`:  returns an array of strings made of string's tokens.

- `free_split`:  must be called for each split created with `new_split`

- `log_split`:  print to stdout (or a log file) your brand new split


> the number of tokens in a string is always: nb of separators + 1


```c
// Include header file:
#include "split_string.h"

#define HOBBITS "bilbo;frodo;sam;merry;pippin"
#define SEP ';'

int main (void)
{
	// Get tokens as array of strings:
	char **split = new_split(HOBBITS, SEP);
	
	// Print tokens:
	log_split(stdout, split);
	
	// Free memory allocated by new_split:
	free_split(split);
	
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

### Empty fields

Empty fields are returned as empty strings `""`:

```c
const char *CSV_LINE = ";a;csv;line;;with;empty;fields;;"

char **split = new_split(CSV_LINE, ';');
log_split(stdout);
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
	
	
### If no separator is found

The program won't exit on error, but the split will be an array with
an empty string as its unique element:
                                                                    
```c
const char *str = "a,comma,separated,line";
                                                                    
// passing a wrong separator:
char **split = new_split(str, ':');
                                                                    
// split => [""]
```

