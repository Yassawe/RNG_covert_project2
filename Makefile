make:
	make sender receiver

sender: sender.c 
	gcc -Wall -O -mrdseed sender.c -o sender
receiver: receiver.c
	gcc -Wall -O -mrdseed receiver.c -o receiver

timing:
	gcc -Wall -O timing.c -lrt -mrdseed -o timing

clean:
	$(RM) sender receiver timing