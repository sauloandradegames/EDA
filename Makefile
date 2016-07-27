OBJS = Node.o Dnode.o Tnode.o List.o Dlist.o CircularList.o Stack.o Queue.o BinTree.o Heap.o Main.o
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
	
Tnode : Tnode.h Tnode.cpp
	$(CC) $(CFLAGS) Tnode.cpp
	
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
	
Heap : Heap.h Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp
	
clean:
	\rm *.o
