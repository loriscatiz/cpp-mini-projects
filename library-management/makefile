library.app: main.o Book.o Member.o Library.o
	g++ -o app main.o Book.o Member.o Library.o

main.o: main.cpp Book.hpp Member.hpp Library.hpp
	g++ -c main.cpp

Library.o: Library.cpp Library.hpp Book.hpp
	g++ -c Library.cpp

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

Member.o: Member.cpp Member.hpp
	g++ -c Member.cpp


clean:
	rm -f *.o app