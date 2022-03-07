# -*- MakeFile -*-

bin: process.c
	gcc $< -o $@

run:
	./bin

clean:
	rm bin
