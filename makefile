pcap2csv: pcap2csv.o eth2.o ip.o tcp.o
	gcc -Wall -g -o pcap2csv pcap2csv.o eth2.o ip.o tcp.o -l pcap

pcap2csv.o: pcap2csv.c eth2.h ip.h tcp.h
	gcc -Wall -g -c pcap2csv.c

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
