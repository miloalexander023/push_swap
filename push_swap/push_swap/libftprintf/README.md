This project has been created as part
of the 42 curriculum by <miloalex>

the point of this project is to write a library that contains ft_printf().
ft_printf() is a function that will mimic the original printf() function from libc.



Here are the requirements:

• Do not implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
• Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.
• Your header file must be named ft_printf.h and must contain the prototype of
  your ft_printf() function.




You have to implement the following conversions:

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.



Resources:

i was pretty familiar for this project so i only used AI once to explain me why an "unsinged long" is behaving differently then an "unsinged int", cause it was giving me problems with converting the numbers with my to_hex() in my put_ptr() function.

i had enough room for more functions.
so instead of trying to change my to_hex() function (to make it work for both),
i decided to copy it and adapted it to work for "unsinged long" 

from:
int	to_hex(char *decimal, unsigned int num, int width)

to
int	to_hex_ptr(char *decimal, unsigned long num, int width)



data structure explanation:

i used ft_printf() to read trough the given string
and used applysign() whenever it encountered a '%'

in my applysign it looks for the given sign after '%', such as:
• cspdiuxX%
corresponding to those signs it would send the next argument (using va_arg()) to the designated function where it will print the argument using write()

after writing al characters it wil return the lengt of the total string