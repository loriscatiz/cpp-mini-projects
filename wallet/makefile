app: main.o wallet.o transaction.o
	g++ -o app main.o wallet.o transaction.o

main.o: main.cpp wallet.hpp
	g++ -c main.cpp

wallet.o: wallet.cpp transaction.hpp
	g++ -c wallet.cpp

transaction.o: transaction.cpp
	g++ -c transaction.cpp

clean:
	rm -f *.o app