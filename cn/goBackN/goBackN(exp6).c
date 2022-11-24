#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<unistd.h>

int n, r;
struct frame {
  char ack;
  int data;
}
frm[10];
int sender(void);
void recvack(void);
void resend_gb(void);
int main() {
  int c;
  sender();
  recvack();
  resend_gb();
  printf("\n All Frames sent successfully\n");
}
int sender() {
  int i;
  printf("\n Enter no.of Frames to be sent: ");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    printf("\n Enter data for Frames[%d]", i);
    scanf("%d", & frm[i].data);
    frm[i].ack = 'y';
  }
  return 0;
}
void recvack() {
  int i;
  rand();
  r = rand() % n;
  frm[r].ack = 'n';
  for (i = 1; i <= n; i++) {
    if (frm[i].ack == 'n')
      printf("\n The Frame Number %d is not received", r);
  }
}
void resend_gb() {
  int i;
  printf("\nResending Frame %d", r);
  for (i = r; i <= n; i++) {
    sleep(2);
    frm[i].ack = 'y';
    printf("\n The Received Frame is %d", frm[i].data);
  }
}