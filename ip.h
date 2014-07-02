#ifndef IP_H
#define IP_H

void print_version_ip(const u_char * data, int offset);
void print_ihl(const u_char * data, int offset);
void print_tos_ip(const u_char * data, int offset);
void print_tot_len(const u_char * data, int offset);
void print_id_ip(const u_char * data, int offset);
void print_flags_ip(const u_char * data, int offset);
void print_frag_off(const u_char * data, int offset);
void print_ttl_ip(const u_char * data, int offset);
void print_protocol(const u_char * data, int offset);
void print_chksum(const u_char * data, int offset);
void print_src_ip_addr(const u_char * data, int offset);
void print_dst_ip_addr(const u_char * data, int offset);
void print_ip_fields(const u_char * data, int offset);

#endif
