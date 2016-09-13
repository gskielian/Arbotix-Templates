#include <stdio.h>
#include <unistd.h>

int main(void)
{
  FILE *file;
  file = fopen("/dev/ttyUSB0","w");

  printf("waiting for servo to boot\n");
  //waitfor it to boot
  sleep(4);
  printf("waited 4 seconds\n");
  printf("starting servo code\n");

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
