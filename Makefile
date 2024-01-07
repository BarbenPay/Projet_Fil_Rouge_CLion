main.out: main.o Regroupement.o fichier_Log.o Decoupage.o
	gcc -o main.out Regroupement.o fichier_Log.o Decoupage.o

main.o: main.c Regroupement/Regroupement.h Log/fichier_Log.h Découpage/Decoupage.h
	gcc -c main.c -o main.o

Regroupement.o: Regroupement/Regroupement.c Regroupement/Regroupement.h Log/fichier_Log.h
	gcc -c Regroupement/Regroupement.c -o Regroupement.o

fichier_Log.o: Log/fichier_Log.c Log/fichier_Log.h
	gcc -c Log/fichier_Log.c -o fichier_Log.o

Decoupage.o: Découpage/Decoupage.c Découpage/Decoupage.h Log/fichier_Log.h
	gcc -c Découpage/Decoupage.c -o Decoupage.o

clean:
	rm -rf *.o
