#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format.
 * @format: the fixed argument to be printed
 *
 * Return: number of characters printed as int 
 */
int _printf(const char *format, ...)
{
char ch;
char *str;
int c = 0; 
va_list args;
va_start(args, format); 
if (!format) 
{
return -1;
}
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
ch = (char)va_arg(args, int);
write(1, &ch, 1);
c++;
break;
}
case 's':
{
str = va_arg(args, char *);
while (*str)
{
write(1, str, 1);
str++;
c++;
}
break;
}
case '%':
{
write(1, "%", 1);
c++;
break;
}
default:
{
write(1, "%", 1);
write(1, format, 1);
c += 2;
break;
}
}
}
else
{
write(1, format, 1);
c++;
}
format++;
}
va_end(args);
return c;
}
