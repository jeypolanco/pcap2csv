#include <stdio.h>
#include <sys/types.h>

void print_version_ip(const u_char * data, int offset)
{
  int mask = 0b00001111;
  int value = data[offset] >> 4;
  printf("\"version, 0x%01x\",", (mask & value));
}

void print_ihl(const u_char * data, int offset)
{
  int mask = 0b00001111;
  printf("\"ihl, %d\",", (mask & data[offset]) * 4);
}

int get_ihl(const u_char * data, int offset)
{
  int mask = 0xf;
  return (mask & data[offset]) * 4;
}

void print_tos_ip(const u_char * data, int offset)
{
  printf("\"tos, 0x%02x\",", data[offset+1]);
}

void print_tot_len(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset+2] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+3]);
  int val = x | y;
  printf("\"datagram_len, %d\",", val);
}

int get_tot_len(const u_char * data, int offset)
{
  int x_mask = 0x0000ff00;
  int x = (x_mask & data[offset+2] << 8);
  int y_mask = 0x000000ff;
  int y = (y_mask & data[offset+3]);
  int val = x | y;
  return val;
}

void print_id_ip(const u_char * data, int offset)
{
  printf("\"id, 0x%02x%02x\",", data[offset+4], data[offset+5]);
}

void print_flags_ip(const u_char * data, int offset)
{
  int mask = 0b00000111;
  int value = data[offset+6] >> 5;
  printf("\"flags, 0x%01x\",", (mask & value));
}

void print_frag_off(const u_char * data, int offset)
{
  int mask = 0x1F;
  printf("\"frag_off, 0x%02x%02x\",", (mask & data[offset+6]), data[offset+7]);
}

void print_ttl_ip(const u_char * data, int offset)
{
  printf("\"ttl, 0x%02x\",", data[offset+8]);
}

void print_protocol(const u_char * data, int offset)
{
  printf("\"protocol, 0x%02x\",", data[offset+9]);
}

void print_chksum(const u_char * data, int offset)
{
  printf("\"header checksum, 0x%02x%02x\",", data[offset+10], data[offset+11]);
}

void print_src_ip_addr(const u_char * data, int offset)
{
  printf("\"src_ip, %d.%d.%d.%d\",",
	 data[offset+12], data[offset+13],
	 data[offset+14], data[offset+15]);
}

void print_dst_ip_addr(const u_char * data, int offset)
{
  printf("\"dst_ip, %d.%d.%d.%d\",",
	 data[offset+16], data[offset+17],
	 data[offset+18], data[offset+19]);
}

void print_ip_fields(const u_char * data, int offset)
{
  print_version_ip(data, offset);
  print_ihl(data, offset);
  print_tos_ip(data, offset);
  print_tot_len(data, offset);
  print_id_ip(data, offset);
  print_flags_ip(data, offset);
  print_frag_off(data, offset);
  print_ttl_ip(data, offset);
  print_protocol(data, offset);
  print_chksum(data, offset);
  print_src_ip_addr(data, offset);
  print_dst_ip_addr(data, offset);
  
}
