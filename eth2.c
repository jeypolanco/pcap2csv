#include <stdio.h>
#include <sys/types.h>

void print_dst_mac(const u_char * data, int offset)
{
  printf("\"dest_mac, %02x:%02x:%02x:%02x:%02x:%02x\",",
	 data[offset], data[offset+1], data[offset+2],
	 data[offset+3], data[offset+4], data[offset+5]);
}
void print_src_mac(const u_char * data, int offset)
{
  printf("\"src_mac, %02x:%02x:%02x:%02x:%02x:%02x\",",
	 data[offset+6], data[offset+7], data[offset+8],
	 data[offset+9], data[offset+10], data[offset+11]);
}

void print_ether_type(const u_char * data, int offset)
{
  printf("\"ether_type, 0x%02x%02x\",", data[offset+12], data[offset+13]);
}

void print_ether_fields(const u_char * data, int offset)
{
  print_dst_mac(data, offset);
  print_src_mac(data, offset);
  print_ether_type(data, offset);
}
