/**
 * 2个问题
 * 一个是如何翻转数组
 * 一个是如何找到最大的数
 * 这2个都是在数组的一个区间内进行的
 * 如何设计更优雅的函数参数呢
 */
#include <stdio.h>

int main()
{
  int bytes_read;
  int nbytes = 100;
  char *my_string;

  puts ("Please enter a line of text.");

  /* These 2 lines are the heart of the program. */
  my_string = (char *) malloc (nbytes + 1);
  bytes_read = getline (&my_string, &nbytes, stdin);

  if (bytes_read == -1)
    {
      puts ("ERROR!");
    }
  else
    {
      puts ("You typed:");
      puts (my_string);
    }

  return 0;
}

