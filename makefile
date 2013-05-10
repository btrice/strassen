strassen: strassen.o strassen_impl.o
		gcc   -o strassen strassen.o strassen_impl.o -Wall -lm
strassen.o: strassen.c
		gcc -o strassen.o -c strassen.c -Wall  --pedantic
strassen_impl.o: strassen_impl.c strassen_impl.h
		gcc -o strassen_impl.o -c strassen_impl.c -Wall  --pedantic
#nettoyage
clean :
	rm -rf *.o
