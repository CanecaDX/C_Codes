index:
	gcc -c mainTree.c
	gcc -c tree.c
	gcc mainTree.c tree.c -o exec -Wall -Wextra -g

run: index
	./exec

clear:
	#limpando arquivo
	rm mainTree.o
	rm tree.o
	rm exec
