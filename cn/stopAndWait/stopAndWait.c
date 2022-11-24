#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<unistd.h>

int main() {
  int i, j, packet[30];
  int fsize = (rand() % 16) + 1;
  printf("\n\t Frame Size : %d \n", fsize);
  printf("\n\t -------Data Log ------- \n");
  printf("\n FRAME\t \tDATA\t WAITING\t \tACKNOW\t \tRESEND\t");
  for (i = 0; i < fsize; i++) {
    packet[i] = rand() % 1000;
    printf("\n %d \t\t %d", i + 1, packet[i]);
    while (j = 0 || rand() % 2 == 0) {
      sleep(1);
      printf("\t1 ");
      sleep(1);
      for (j = 2; rand() % 2 == 0 && j < 4; j++) {
        printf("%d ", j);
        sleep(1);
      }
      if (j == 4)
        printf("\t\t\t NO \tRESENDING...\n %d \t %d", i + 1, packet[i]);
      else
        break;
    }
    if (j == 0) {
      sleep(1);
      printf("\t0 ");
    }
    printf("\t\t\t YES \t\t NO");
  }
  printf("\n\n----------ALL DATA PACKETS SEND ----------\n");
  return 0;
}