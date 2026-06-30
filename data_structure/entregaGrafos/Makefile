index:
	gcc -c grafosMain.c
	gcc -c grafos.c
	gcc grafosMain.c grafos.c -o exec -Wall -Wextra -g

run: index
	./exec

clear:
	#limpando arquivo
	rm grafosMain.o
	rm grafos.o
	rm exec
