/*
 * Author: Hiroyuki Chishiro
 * License: 2-Clause BSD
 */
#include <stdio.h>

int myvlaadd(int num, ...);

int main(void)
{
  printf("1 + 2 + 3 = %d\n", myvlaadd(3, 1, 2, 3));
  printf("1 + 2 + 3 + 4 = %d\n", myvlaadd(4, 1, 2, 3, 4));
  printf("1 + 2 + 3 + 4 + 5 = %d\n", myvlaadd(5, 1, 2, 3, 4, 5));
  printf("1 + 2 + 3 + 4 + 5 + 6 = %d\n", myvlaadd(6, 1, 2, 3, 4, 5, 6));
  printf("1 + 2 + 3 + 4 + 5 + 6 + 7 = %d\n", myvlaadd(7, 1, 2, 3, 4, 5, 6, 7));

  return 0;
}

int myvlaadd(int num, ...)
{
  int i, sum;
  int tmp;

  for (i = sum = 0; i < num; i++) {
    switch (i) {
    case 0:
      asm volatile("mov -0xa8(%%rbp), %0" : "=r"(tmp));
      break;

    case 1:
      asm volatile("mov -0xa0(%%rbp), %0" : "=r"(tmp));
      break;

    case 2:
      asm volatile("mov -0x98(%%rbp), %0" : "=r"(tmp));
      break;

    case 3:
      asm volatile("mov -0x90(%%rbp), %0" : "=r"(tmp));
      break;

    case 4:
      asm volatile("mov -0x88(%%rbp), %0" : "=r"(tmp));
      break;

    case 5:
      asm volatile("mov 0x10(%%rbp), %0" : "=r"(tmp));
      break;

    case 6:
      asm volatile("mov 0x18(%%rbp), %0" : "=r"(tmp));
      break;

    default:
      fprintf(stderr, "Error: number of arguments is too many.\n");
      break;
    }

    sum += tmp;
  }


  return sum;
}
