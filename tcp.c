#include <stdio.h>
#include <sys/types.h>

void print_src_port(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+1]);
  int val = x | y;
  printf("\"src_port, %d\",", val);
}
void print_dst_port(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset+2] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+3]);
  int val = x | y;
  printf("\"dst_port, %d\",", val);
}
void print_seq_num(const u_char * data, int offset)
{
}
void print_ack_num(const u_char * data, int offset)
{
}
void print_data_off(const u_char * data, int offset)
{
}
void print_reserved(const u_char * data, int offset)
{
}
void print_window(const u_char * data, int offset)
{
}
void print_chksum_tcp(const u_char * data, int offset)
{
}
void print_urg_ptr(const u_char * data, int offset)
{
}
void print_tcp_fields(const u_char * data, int offset)
{
  print_src_port(data, offset);
  print_dst_port(data, offset);  
}
