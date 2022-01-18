#define END   0    /* これで不定引数は終り */
#define CHAR  1
#define SHORT 2
#define INT   3
#define LONG  4
#define FLOAT 5
#define DOUBLE 6
#define STRING 7  /* char * も出来る */
#define LONGLONG 8 /* gcc 専用の 64bit int */

#include <stdarg.h>
#include <math.h>

void main( )
{
     va_out( "", LONGLONG, 4294967296LL, DOUBLE, 4.3, STRING, "test",
             INT, 69, DOUBLE, M_PI, CHAR, 'a', END );
}

void va_out( char *dummy, ... )
{
     va_list argp;
     int kind;

     va_start( argp, dummy );  /* 最初の不定引数を取得 */
     while( 1 ) {
          kind = *(int *)argp; /* 現実には va_list は void * である */
          va_arg( argp, int ); /* int 型スタックをスキップして飛ばす */

          switch( kind ) {
          case END:
               va_end( argp );
               return;
               break;
          case CHAR:
               printf( "char %c\n", *(char *)argp );
               va_arg( argp, char );
               break;
          case SHORT:
               printf( "short %d\n", *(short *)argp );
               va_arg( argp, short );
               break;
          case INT:
               printf( "int %d\n", *(int *)argp );
               va_arg( argp, int );
               break;
          case LONG:
               printf( "long %ld\n", *(long *)argp );
               va_arg( argp, long );
               break;
          case FLOAT:
               printf( "float %g\n", *(float *)argp );
               va_arg( argp, float );
               break;
          case DOUBLE:
               printf( "double %g\n", *(double *)argp );
               va_arg( argp, double );
               break;
          case STRING:  /* 文字列はダブルポインタ */
               printf( "string %s\n", *(char **)argp );
               va_arg( argp, char * );
               break;
          case LONGLONG: /* long long だって問題ない */
               printf( "long long %Ld\n", *(long long *)argp );
               va_arg( argp, long long );
               break;
          }
     }
}
