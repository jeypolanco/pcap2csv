read_pcap: read_pcap.o eth2.o ip.o
	gcc -Wall -g -o bread_pcap read_pcap.o eth2.o ip.o -l pcap

read_pcap.o: read_pcap.c eth2.h ip.h
	gcc -Wall -g -c read_pcap.c

ip.o: ip.c
	gcc -Wall -g -c ip.c

eth2.o: eth2.c
	gcc -Wall -g -c eth2.c

pcap2csv: pcap2csv.c
	gcc -Wall -g -o bpcap2csv pcap2csv.c -l bsd

bitmask: bitmask.c
	gcc -Wall -g -o bitmask bitmask.c

.PHONY: clean
clean:
	find . -maxdepth 1 -type f -perm 775 -delete
	find . -maxdepth 1 -type f -iname '*.o' -delete
