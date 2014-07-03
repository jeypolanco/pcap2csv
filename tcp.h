#ifndef TCP_H
#define TCP_H

void print_src_port(const u_char * data, int offset);
void print_dst_port(const u_char * data, int offset);
void print_seq_num(const u_char * data, int offset);
void print_ack_num(const u_char * data, int offset);
void print_data_off(const u_char * data, int offset);
void print_reserved(const u_char * data, int offset);
void print_window(const u_char * data, int offset);
void print_chksum_tcp(const u_char * data, int offset);
void print_urg_ptr(const u_char * data, int offset);
void print_tcp_fields(const u_char * data, int offset);

#endif
