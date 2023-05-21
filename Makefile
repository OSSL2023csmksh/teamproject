stat : mainstat.c stat.o
	gcc -o stat mainstat.c stat.o
stat.o : stat.c stat.h
	gcc -c stat.c -o stat.o
clean :
	rm *.o stat
