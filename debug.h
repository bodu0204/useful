#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#define TEST printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TEST_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TESTn(i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, #i, (long)(i)); fflush(stdin);
#define TESTu(i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define TESTx(i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define TESTd(i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, #i, (double)(i)); fflush(stdin);
#define TESTp(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (void *)(i)); fflush(stdin);
#define TESTs(i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stdin);
#define TESTc(i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stdin);
#define T TEST
#define T_ TEST_
#define Tn(i) TESTn(i)
#define Tu(i) TESTu(i)
#define Tx(i) TESTx(i)
#define Td(i) TESTd(i)
#define Tp(i) TESTp(i)
#define Ts(i) TESTs(i)
#define Tc(i) TESTc(i)
#define FORn(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (long)(i[test_arg])); fflush(stdin);}}
#define FORu(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (unsigned long)(i[test_arg])); fflush(stdin);}}
#define FORx(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (unsigned long)(i[test_arg])); fflush(stdin);}}
#define FORd(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (double)(i[test_arg])); fflush(stdin);}}
#define FORp(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (void *)(i[test_arg])); fflush(stdin);}}
#define FORs(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (char *)(i[test_arg])); fflush(stdin);}}
#define FORc(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (char)(i[test_arg])); fflush(stdin);}}
#define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#endif



/*ショートカット


#include "debug.h"

#ifndef _H 
#include ""
#endif





 */

/* 一定回数でプログラムを強制終了 */

//* test */static	size_t stc = 0;
//* test */const int stc_max = 10000;
//* test */const int onoff = 1;
//* test */stc++;
//* test */if (stc > stc_max && onoff)
//* test */{
//* test */	printf("the number is too big"); TEST
//* test */	exit(0);
//* test */}

/* 時間を計測 */
//* test */	double	time_diff(void)
//* test */	{
//* test */		static struct timespec	p = {0};
//* test */		struct timespec			n;
//* test */		unsigned int			sec;
//* test */		int						nsec;
//* test */
//* test */		if (!p.tv_sec)
//* test */		{
//* test */			clock_gettime(CLOCK_REALTIME, &p);
//* test */			return (0);
//* test */		}
//* test */		clock_gettime(CLOCK_REALTIME, &n);
//* test */		sec = n.tv_sec - p.tv_sec;
//* test */		nsec = n.tv_nsec - p.tv_nsec;
//* test */		p = n;
//* test */		return ((double)sec + (double)nsec / (1000 * 1000 * 1000));
//* test */	}
