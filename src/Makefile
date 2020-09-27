target: simpleUI.o tokenizer.o history.o
	cc -o target simpleUI.o tokenizer.o history.o

clean:
	rm -f *.o target

simpleUI.o: simpleUI.c tokenizer.h history.h

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c
