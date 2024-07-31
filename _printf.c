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
va_list args;
va_start(args, format);
char ch;
char *str;
int c = 0;
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
ch = va_arg(args, int);
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
