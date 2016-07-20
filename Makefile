OBJS = Node.o Dnode.o List.o Dlist.o CircularList.o Stack.o Queue.o BinTree.o Main.o
CC = g++
DEBUG = -g -ggdb
CFLAGS = $(DEBUG) -Wall -c
LFLAGS = $(DEBUG) -Wall

Main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Main

Node : Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp
	
Dnode : Dnode.h Dnode.cpp
	$(CC) $(CFLAGS) Dnode.cpp
	
List : List.h List.cpp
	$(CC) $(CFLAGS) List.cpp
	
Dlist : Dlist.h Dlist.cpp
	$(CC) $(CFLAGS) Dlist.cpp
	
CircularList : CircularList.h CircularList.cpp
	&(CC) $(CFLAGS) CircularList.cpp
	
Stack : Stack.h Stack.cpp
	$(CC) $(CFLAGS) Stack.cpp

Queue : Queue.h Queue.cpp
	$(CC) $(CFLAGS) Queue.cpp
	
BinTree : BinTree.h BinTree.cpp
	$(CC) $(CFLAGS) BinTree.cpp
	
clean:
	\rm *.o
