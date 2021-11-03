#include "shell.h"

/**
 * funper - print whit a format in format[i]
 * @format: format to print
 * @i: integer
 * @toPrint: list to print.
 * @pun: pointer to len in _printf;
 * Return: inreger 1 or 2 or 0.
 */
int funper(const char *format, int i, va_list toPrint, int *pun)
{
	int c = 0;

	tpPer relFormatFun[] = {
		{'c', printChar		},
		{'s', printString	},
		{'i', printInt		},
		{'d', printDec		}
	};

	if (format[i + 1] == '\0')
		return (-1);
	if (format[i + 1] == 'K' || format[i + 1] == '!')
	{
		_putchar(format[i], pun);
		return (1);
	}
	if (format[i + 1] == '%')
	{
		_putchar('%', pun);
		return (2);
	}
	while (c < 4)
	{
		if (relFormatFun[c].t == format[i + 1])
		{
			relFormatFun[c].f(toPrint, pun);
			return (2);
		}
		c++;
	}
	if (format[i + 1] == ' ')
		return (1 + funper(format, i + 1, toPrint, pun));
	else if (format[i + 1] != '\0')
	{
		_putchar(format[i + 1], pun);
		return (2);
	}
	else
		return (0);
}
