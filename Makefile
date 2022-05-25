make:
	make sender receiver

sender: sender.c 
	gcc -Wall -O3 -mrdseed sender.c -o sender
receiver: receiver.c
	gcc -Wall -O3 -mrdseed receiver.c -o receiver

clean:
	$(RM) sender receiver