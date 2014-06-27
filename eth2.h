#ifndef ETH2_H
#define ETH2_H

void print_dst_mac(const u_char * data, int offset);
void print_src_mac(const u_char * data, int offset);
void print_ether_type(const u_char * data, int offset);
void print_ether_fields(const u_char * data, int offset);

#endif
