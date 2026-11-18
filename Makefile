all:
	gcc main.c -o saat -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm -f saat
