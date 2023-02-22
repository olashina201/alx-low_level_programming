#include "main.h"

/**
 * main - entry point
 *
 * return 0
 */
int main(void)
{
  char sh = "putchar";

  while (sh)
  {
      _putchar(sh);
      sh++;
  }

  _putchar("\n");

  return (0);

}
