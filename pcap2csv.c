#include<stdio.h>
#include <bsd/string.h>
#define BUFSIZE 36

int main(){
  char src_mac[BUFSIZE];
  char dst_mac[BUFSIZE];  
  snprintf(src_mac, BUFSIZE, "\"src_mac, %x:%x:%x:%x:%x:%x\"",
    0xe0, 0xb9, 0xa5, 0x34, 0x74, 0x2d);
  snprintf(dst_mac, BUFSIZE, "\"dst_mac, %x:%x:%x:%x:%x:%x\"",
    0xe0, 0xb9, 0xa5, 0x34, 0x74, 0x2d);
  printf("%s, ", src_mac);
  printf("%s", dst_mac);

  return 0;
}
