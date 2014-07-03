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
  int val = ((data[offset+4] << 24 ) 
	     +( data[offset+5] << 16 )
	     +( data[offset+6] << 8 )
	     +( data[offset+7] ));

  printf("\"seq_num, %u\",", val);
}
void print_ack_num(const u_char * data, int offset)
{
  int val = ((data[offset+8] << 24 ) 
	     +( data[offset+9] << 16 )
	     +( data[offset+10] << 8 )
	     +( data[offset+11] ));

  printf("\"ack_num, %u\",", val);

}
void print_data_off(const u_char * data, int offset)
{
  printf("\"tcp_head_len, %d\"", (data[offset+12] >> 4) * 4);
}
void print_cntrl_bits(const u_char * data, int offset)
{
  printf("\"tcp_head_len, 0x%x\"", data[offset+13]);
}
void print_window(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset+14] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+15]);
  int val = x | y;
  printf("\"window, %d\",", val);
  
}
void print_chksum_tcp(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset+16] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+17]);
  int val = x | y;
  printf("\"chksum, 0x%x\",", val);
  
}
void print_urg_ptr(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset+18] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+19]);
  int val = x | y;
  printf("\"urg_ptr, 0x%x\",", val);

}
void print_tcp_fields(const u_char * data, int offset)
{
  print_src_port(data, offset);
  print_dst_port(data, offset);
  print_seq_num(data, offset);
  print_ack_num(data, offset);
  print_data_off(data, offset);
  print_cntrl_bits(data, offset);
  print_window(data, offset);
  print_chksum_tcp(data, offset);
  print_urg_ptr(data, offset);
}

