#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  char buf[64];
  int nums[4];
  int count = 0;
  int i = 0;

  printf("Enter four integers separated by spaces: ");
  gets(buf, sizeof(buf));

  while (buf[i] == ' ' || buf[i] == '\t')
    i++;

  while (buf[i] != '\0' && buf[i] != '\n' && count < 4) {
    int sign = 1;
    int value = 0;

    if (buf[i] == '-') {
      sign = -1;
      i++;
    }

    if (buf[i] < '0' || buf[i] > '9') {
      printf("Invalid input.\n");
      exit(1);
    }

    while (buf[i] >= '0' && buf[i] <= '9') {
      value = value * 10 + (buf[i] - '0');
      i++;
    }

    nums[count++] = sign * value;

    while (buf[i] == ' ' || buf[i] == '\t')
      i++;
  }

  if (count != 4 || (buf[i] != '\0' && buf[i] != '\n')) {
    printf("Please enter exactly four integers separated by spaces.\n");
    exit(1);
  }

  int result = hello(nums[0], nums[1], nums[2], nums[3]);
  printf("Returned sum = %d\n", result);
  exit(0);
}
