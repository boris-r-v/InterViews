all: search.c reuseAPI.c
	gcc search.c -o search
	gcc reuseAPI.c -o reuseAPI


list: list_node.c list_element.c list_main.c
	gcc -c list_node.c list_element.c list_main.c
	gcc list_node.o list_element.o list_main.o -o list_main

cpp: 1.cpp 2.cpp
	g++ 1.cpp 2.cpp -o link

sum:
	gcc -c sum_as_template.c all_possible_sums.c main.c
	gcc sum_as_template.o all_possible_sums.o main.o -o sum

