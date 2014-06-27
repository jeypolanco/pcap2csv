/*
 * Use pcap_open_offline() to open a savefile, containing packet capture data,
 * and use the print_addrs() routine to print the source and destination IP
 * addresses from the packet capture data to stdout.
 */

#include <stdio.h>
#include <pcap.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "eth2.h"

#define IFSZ 16
#define FLTRSZ 120
#define MAXHOSTSZ 256
#define PCAP_SAVEFILE "./pcap_savefile"

int packets = 0;   /* running count of packets read in */

int usage(char *progname);
void print_pkt_fields(u_char *user, const struct pcap_pkthdr *hdr, const u_char *data);

int
main(int argc, char **argv)
{
  pcap_t *p;               /* packet capture descriptor */
  char ifname[IFSZ];       /* interface name (such as "en0") */
  char filename[80];       /* name of savefile to read packet data from */
  char errbuf[PCAP_ERRBUF_SIZE];  /* buffer to hold error text */
  char prestr[80];         /* prefix string for errors from pcap_perror */
  int majver = 0, minver = 0;  /* major and minor numbers for the */
  /* current Pcap library version */

  /*
   * For this program, the interface name must be passed to it on the command
   * line. The savefile name may optionally be passed in as well. If no:
   * savefile name is passed in, "./pcap_savefile" is assumed. If there are
   * arguments, program has been invoked incorrectly.
   */
  if (argc < 2)
    usage(argv[0]);

  if (strlen(argv[1]) > IFSZ) {
    fprintf(stderr, "Invalid interface name.\n");
    exit(1);
  }
  strcpy(ifname, argv[1]);

  /*
   * If there is a second argument (the name of the savefile), save it in
   * filename. Otherwise, use the default name.
   */
  if (argc >= 3)
    strcpy(filename,argv[2]);
  else
    strcpy(filename, PCAP_SAVEFILE);

  /*
   * Open a file containing packet capture data. This must be called
   * before processing any of the packet capture data. The file
   * containing pcaket capture data should have been generated by a
   * previous call to pcap_open_live().
   */
  if (!(p = pcap_open_offline(filename, errbuf))) {
    fprintf(stderr,
	    "Error in opening savefile, %s, for reading: %s\n",
	    filename, errbuf);
    exit(2);
  }

  /*
   * Call pcap_dispatch() with a count of 0 which will cause
   * pcap_dispatch() to read and process packets until an error or EOF
   * occurs. For each packet read from the savefile, the output routine,
   * print_pkt_fields(), will be called to print the source and destinations
   * addresses from the IP header in the packet capture data.
   * Note that packet in this case may not be a complete packet. The
   * amount of data captured per packet is determined by the snaplen
   * variable which was passed into pcap_open_live() when the savefile
   * was created.
   */
  if (pcap_dispatch(p, 0, &print_pkt_fields, (u_char *)0) < 0) {
    /*
     * Print out appropriate text, followed by the error message
     * generated by the packet capture library.
     */
    sprintf(prestr,"Error reading packets from interface %s",
	    ifname);
    pcap_perror(p,prestr);
    exit(4);
  }

  printf("\nPackets read in: %d\n", packets);

  /*
   * Print out the major and minor version numbers. These are the version
   * numbers associated with this revision of the packet capture library.
   * The major and minor version numbers can be used to help determine
   * what revision of libpcap created the savefile, and, therefore, what
   * format was used when it was written.
   */

  if (!(majver = pcap_major_version(p))) {
    fprintf(stderr,
	    "Error getting major version number from interface %s",
	    ifname);
    exit(5);
  }
  printf("The major version number used to create the savefile was: %d.\n", majver);

  if (!(minver = pcap_minor_version(p))) {
    fprintf(stderr,
	    "Error getting minor version number from interface %s",
	    ifname);
    exit(6);
  }
  printf("The minor version number used to create the savefile was: %d.\n", minver);

  /*
   * Close the packet capture device and free the memory used by the
   * packet capture descriptor.
   */

  pcap_close(p);
  return 0;
}


int
usage(char *progname)
{
  printf("Usage: %s <interface> [<savefile name>]\n", basename(progname));
  exit(7);
}


/*
 * Function:    print_addrs()
 *
 * Description: Write source and destination IP addresses from packet data
 *              out to stdout.
 *              For simplification, in this sample, assume the
 *              following about the captured packet data:
 *                      - the addresses are IPv4 addresses
 *                      - the data link type is ethernet
 *                      - ethernet encapsulation, according to RFC 894, is used.
 *
 * Return:      0 upon success
 *              -1 on failure (if packet data was cut off before IP addresses).
 */
void
print_pkt_fields(u_char *user, const struct pcap_pkthdr *hdr, const u_char *data)
{
  int offset = 0;

  if (hdr->caplen < 0) {
    /* captured data is not long enough to extract mac address */
    fprintf(stderr,
	    "Error: not enough captured packet data present to extract MAC addresses.\n");
    return;
  }

  if (hdr->caplen >= 14) {
    print_ether_fields(data, offset);
  }
  printf("\n");
  packets++; /* keep a running total of number of packets read in */
}
