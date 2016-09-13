#include <stdio.h>
#include <unistd.h>

int main(void)
{
  FILE *file;
  file = fopen("/dev/ttyUSB0","w");

  //waitfor it to boot
  sleep(7);
  printf("waited 7 seconds");

  //send position data
  while(1) {
    fprintf(file,"0800\n");
    sleep(1);
    fprintf(file,"3000\n");
    sleep(1);
  }

  fclose(file);

  return 0;
}
