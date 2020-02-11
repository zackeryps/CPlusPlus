
mylibrary: mycpplibrary.o library.o item.o book.o movie.o musicalbum.o
	g++ -o mylibrary mycpplibrary.o library.o item.o book.o movie.o musicalbum.o

libraryTester: libraryTest.o library.o item.o book.o movie.o musicalbum.o
	g++ -o libraryTester libraryTest.o library.o item.o book.o movie.o musicalbum.o

itemTester: itemTest.o item.o book.o movie.o musicalbum.o
	g++ -o itemTester itemTest.o item.o book.o movie.o musicalbum.o

mycpplibrary.o: mycpplibrary.cpp library.h
	g++ -c -g mycpplibrary.cpp

libraryTest.o: libraryTest.cpp library.h
	g++ -c -g libraryTest.cpp

itemTest.o: itemTest.cpp item.h
	g++ -c -g itemTest.cpp

library.o: library.cpp library.h
	g++ -c -g library.cpp

item.o: item.cpp item.h
	g++ -c -g item.cpp

book.o: book.cpp book.h item.h
	g++ -c -g book.cpp

movie.o: movie.cpp movie.h item.h
	g++ -c -g movie.cpp

musicalbum.o: musicalbum.cpp musicalbum.h item.h
	g++ -c -g musicalbum.cpp

clean:
	clear
	rm *.o itemTester libraryTester mylibrary
