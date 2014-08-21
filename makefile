read_pcap: read_pcap.o eth2.o ip.o tcp.o
	gcc -Wall -g -o bread_pcap read_pcap.o eth2.o ip.o tcp.o -l pcap

read_pcap.o: read_pcap.c eth2.h ip.h tcp.h
	gcc -Wall -g -c read_pcap.c

ip.o: ip.c
	gcc -Wall -g -c ip.c

eth2.o: eth2.c
	gcc -Wall -g -c eth2.c

tcp.o: tcp.c
	gcc -Wall -g -c tcp.c

.PHONY: clean
clean:
	find . -maxdepth 1 -type f -perm 775 -delete
	find . -maxdepth 1 -type f -iname '*.o' -delete

test: test.py csv2sql.py
	python -m unittest test
