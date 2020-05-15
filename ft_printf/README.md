# ft_printf

The project of Moana and Wendell's codam's printf function rewrite.

## General Intructions

Your function must be called ft_printf.
- Your project must be written in accordance with the Norm.
- You have to handle errors carefully. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
- Your must submit a Makefile which will compile a libftprintf.a. This lib will be linked to our testing main to give you your results.
- (DONE) You’ll have to submit a file called author containing your username followed by a ’\n’ at the root of your repository.

``` (bash)
$>cat -e author
xlogin$
```

- You are allowed to use the following functions:
	- write
	- malloc
	- free
	- exit
	- The functions of man 3 stdarg
- You can ask your questions on the forum.

## Mandatory part
- You have to recode the libc’s printf function.
- Your function will be called ft_printf and will be prototyped similarly to printf.
- You won’t do the buffer management in the printf function.
- You have to manage the following conversions: *csp* `%c`, `%s`, `%p`
- You have to manage the following conversions: *d i o u x X* 
- With the following modifiers: *hh*, *h*, *l* and *ll*.
	- diouxX  The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o),unsigned decimal (u), or unsigned hexadecimal (x and X) notation. The letters *abcdef* are used for x conversions; the letters *ABCDEF* are used for conversions.
- You have to manage the following conversion: *f* with the following modifiers: *l* and *L*.
- You must manage %%
- You must manage the flags #0-+ and space
- You must manage the minimum field-width
- You must manage the precision
	- The precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.

## Modifiers Specifiers
| Modifier/Flags | notes | `d`				| `i`				| `o`						| `u`						| `x`						| `X`						| `n` (optional)	| `c` 		| `s`			| `f` |
| ---: | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |  --- |
| `hh`			|	| signed char	| same as `d` | unsigned char			| same as `o`			| same as `o`			| same as `o`			| 				| 			| 			| |
| `h` 			|	| short			| same as `d`			| unsigned short		| same as `o`		| same as `o`		| same as `o`		|  				|  			|  			| |
| `l`			|	| long			| same as `d`			| unsigned long			| same as `o`			| same as `o`			| same as `o`		|  				| wint_t	| wchar_t * |	|
| `ll` 			|	| long long 	| same as `d` 	| unsigned long long	| same as `o`	| same as `o`	| same as `o`	|  				|			| 			| 
| `L`           |   |	|	|	|	|	|	|	|	|	| long double |
| `#`			| converted to an 'alternate form' | no effect	| no effect	| precision of the number is increased to force the first character of the output string to a zero | no effect	|non-zero result has the string '0x' prepended to it| non-zero result has the string '0X' prepended to it| no effect	| no effect	| no effect	| no effect	|
| `0`			| Zero padding | the converted value is padded on the left with zeros rather than blanks. If a precision is given the 0 flag is ignored | same as `d` | same as `d` | same as `d` | same as `d` | same as `d` | no effect	| the converted value is padded on the left with zeros rather than blanks | same as `c` | same as `d` |
| `-` | negative field width flag, `-` overrides a `0` if both are given |	|	|	|	|	|	|	|	|	|   |
| `+`		| sign must always be placed before a number produced by a signed conversion, `+` overrides a `space` if both are used |	|	|	|	|	|	|	|	|	|   |
| `space`	| blank should be left before a positive number produced by a signed conversion |	|	|	|	|	|	|	| undefined behavior | undefined behavior |  |


## Conversions

- `%c`	Character
  - The int argument is converted to an unsigned char, and the resulting character is written.
- `%s`	String
  - Support for precision
  - If a precision is given, no null character need be present; if the precision is not specified, or is greater than the size of the array, the array must contain a terminating NULL character.
  - With the L flag, we need to support wide characters* and precision refers to bytes printed.
- `%p`	Pointer
  - Printed in hexadecimal (as if by '%#x' or '%#lx').
- `%d`	Integer (base 10)
- `%i`	Integer (base 10)
- `%o`	Integer in unsigned octal (base 8)
- `%u`	Unsigned decimal (integer) number
- `%x`	Integer in hexadecimal (base 16)
  - The letters ''abcdef'' are used.
- `%X`	Integer in hexadecimal (base 16)
  - The letters ''ABCDEF'' are used.
- for diouxX conversions the precision, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros.
- `%b`  binary
- `%*any other char*` - Just print the char, with the flags applied (precision, spacing)
- `%n` - The number of characters written so far is stored into the integer indicated by the int* (or variant) pointer argument. No argument is converted.

## Return
This function returns the number of characters printed (not including the trailing `\0' used to end output to strings).

## Bonus part
Below are a few interesting ideas of bonuses for you to either create or use. You can of
course add your own bonuses, which will then be evaluated directly by your correctors.
- More detailed conversions management: e and g. Be careful, your L flag must works with both of them to validate this bonus.
- More detailed flags management: * (DO: %*.*d, -7 2 11,235 = %-7.2d, 11,235 -> "11,23  ") , $ (MAYBE) and ’ (?).
- buffer management
- printf printing in fd
- printf return into string
- Non-existing flags management: %b to print in binary, %r to print a string of non printable characters, %k to print a date in any ordinary ISO format etc.
- Management of alter tools for colors, fd or other fun stuff like that :)

## Hints

`man 3 printf / man 3 stdarg`

ORDER:
 - % (initializer)
 - Width, Precision
 - Flags
 - Datatype / Conversion

## Terminology
 - Conversion: A definition of a type to print out from an argument.
 - Modifiers: Modifiers are flags that change the behavior of a printed conversion type.

## Bonuses
- buffer management
- supports unicode
- implemented dprintf for printing into given file descriptor
- implemented wildcards
- supports color coding
- supports binary with %b

## PRINTF VERSIONS

* STDOUT (printf)
* File Descriptor (dprintf)
* Char Buffer (sprintf)