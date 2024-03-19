#include <stdio.h>

int main(void) {
  char s[] = "Oi!";
  printf("%s\n", s);
  printf("%c %c %c %c\n", s[0], s[1], s[2], s[3]);
  printf("%d %d %d %d\n", s[0], s[1], s[2], s[3]);
  return 1;
}