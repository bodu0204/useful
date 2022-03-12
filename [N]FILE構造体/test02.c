#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
void showbit (void *vp, size_t size);
void showfile(FILE	*f);
void wstr(char *s);
void showint(int	i);
void showad(void *p);
void showll(long long	i);



int main (void)
{
	fflush(stdout);
	stdout->_bf._base = malloc(4096);
	stdout->_bf._size = 4096;
	stdout->_p = stdout->_bf._base;
	stdout->_flags = 2185;
	stdout->_lbfsize = -4096;
	stdout->_blksize = 4096;
	stdout->_p[0] = 'a';
	stdout->_p++;
	stdout->_w--;
	while (1)
	{
		/* code */
	}

	return (0);
}

void showfile(FILE	*f)
{
	wstr("FILE *f  (self)                            ");	showad(f);																						wstr("\n");
	wstr("unsigned char *_p;                         ");	showad(f->_p);	wstr(" ");	showbit(f->_p, 16);													wstr("\n");
	wstr("int _r;                                    ");	showint(f->_r);																					wstr("\n");
	wstr("int _w;                                    ");	showint(f->_w);																					wstr("\n");
	wstr("short _flags;                              ");	showint(f->_flags);																				wstr("\n");
	wstr("short _file;                               ");	showint(f->_file);																				wstr("\n");
	wstr("struct __sbuf _bf;                         ");	wstr("unsigned char *_base; ");	showad(f->_bf._base);	wstr(" ");	showbit(f->_bf._base, 16);	wstr("\n");
	wstr("                                           ");	wstr("int _size;            ");	showint(f->_bf._size);											wstr("\n");
	wstr("int _lbfsize;                              ");	showint(f->_lbfsize);																			wstr("\n");
	//wstr("\n/* operations */");																																wstr("\n");
	wstr("void *_cookie;                             ");	showad(f->_cookie);	wstr(" ");	showbit(f->_cookie, 16);										wstr("\n");
	wstr("int (*_close)(void *);                     ");	showad(f->_close);																				wstr("\n");
	wstr("int (*_read) (void *, char *, int);        ");	showad(f->_read);																				wstr("\n");
	wstr("fpos_t (* _seek) (void *, fpos_t, int);    ");	showad(f->_seek);																				wstr("\n");
	wstr("int (* _write)(void *, const char *, int); ");	showad(f->_write);																				wstr("\n");
	//wstr("\n/* separate buffer for long sequences of ungetc() */");																							wstr("\n");
	wstr("struct __sbuf _ub;                         ");	wstr("unsigned char *_base; ");	showad(f->_ub._base);	wstr(" ");	showbit(f->_ub._base, 16);	wstr("\n");
	wstr("                                           ");	wstr("int _size;            ");	showint(f->_ub._size);											wstr("\n");
	wstr("struct __sFILEX *_extra;                   ");	showad(f->_extra);																				wstr("\n");
	wstr("int _ur;                                   ");	showint(f->_ur);																				wstr("\n");
	//wstr("\n/* tricks to meet minimum requirements even when malloc() fails */");																			wstr("\n");
	wstr("unsigned char _ubuf[3];                    ");	showad(f->_ubuf);	wstr(" ");	showbit(f->_ubuf, 3);											wstr("\n");
	wstr("unsigned char _nbuf[1];                    ");	showad(f->_nbuf);	wstr(" ");	showbit(f->_nbuf, 1);											wstr("\n");
	//wstr("\n/* separate buffer for fgetln() when line crosses buffer boundary */");																			wstr("\n");
	wstr("struct __sbuf _lb;                         ");	wstr("unsigned char *_base; ");	showad(f->_lb._base);	wstr(" ");	showbit(f->_lb._base, 16);	wstr("\n");
	wstr("                                           ");	wstr("int _size;            ");	showint(f->_lb._size);											wstr("\n");
	//wstr("\n/* Unix stdio files get aligned to block boundaries on fseek() */");																			wstr("\n");
	wstr("int _blksize;                              ");	showint(f->_blksize);																			wstr("\n");
	wstr("fpos_t _offset;    (== long long)          ");	showll((long long)f->_offset);																	wstr("\n");
	return ;
}

void showint(int	i)
{
	long	l;
	long	x;
	int		s;
	char	*num = "0123456789";

	if (i == 0)
	{
		write(1, "0", 1);
		return ;
	}
	s = 1;
	if (i < 0)
	{
		s = -1;
		write(1, "-", 1);
	}
	l = i * s;
	x = 1;
	while (l > 10)
	{
		x *= 10;
		l /= 10;
	}
	l = i * s;
	while (x > 0)
	{
		i = l / x;
		write(1, num + i, 1);
		l -= i * x;
		x /= 10;
	}
	return ;
}

void showll(long long	i)
{
	long long	l;
	long long	x;
	int			s;
	char		*num = "0123456789";

	if (i == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (i < 0)
		write(1, "-", 1);
	else
		i *= -1;
	l = i;
	x = -1;
	while (i < -10)
	{
		x *= 10;
		i /= 10;
	}
	while (x < 0)
	{
		s = l / x;
		write(1, num + s, 1);
		l -= s * x;
		x /= 10;
	}
	return ;
}

void wstr(char *s)
{
	write (1, s, strlen(s));
	return ;
}

void showbit (void *vp, size_t size)
{
	unsigned char	*p;
	char	*num = "0123456789ABCDEF";

	if (!vp)
		return ;
	p = vp;
	while (size > 0)
	{
		write(1, num + (*p / 16), 1);
		write(1, num + (*p % 16), 1);
		if (isprint(*p))
		{
			write(1, "(", 1);
			write(1, p, 1);
			write(1, ")", 1);
		}
		else
			write(1, "   ", 3);
		write(1, " ", 1);
		p++;
		size--;
	}
	return ;
}

void showad(void *p)
{
	unsigned long	l;
	unsigned long	x;
	int		s;
	char	*num = "0123456789ABCDEF";

	write(1, "0x", 2);
	l = (unsigned long)p;
	x = 1;
	while (l > 16)
	{
		x *= 16;
		l /= 16;
	}
	l = (unsigned long)p;
	while (x > 0)
	{
		s = l / x;
		write(1, num + s, 1);
		l -= s * x;
		x /= 16;
	}
	return ;
}
