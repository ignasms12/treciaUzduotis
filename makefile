all:
	make deque list vector
deque:
	g++ -std=c++17 -o main_deque_a 'a strategija/deque/main.cpp' 'a strategija/deque/funcs.cpp'
	g++ -std=c++17 -o main_deque_b 'b strategija/deque/main.cpp' 'b strategija/deque/funcs.cpp'
list:
	g++ -std=c++17 -o main_list_a 'a strategija/lists/main.cpp' 'a strategija/lists/funcs.cpp'
	g++ -std=c++17 -o main_list_b 'b strategija/lists/main.cpp' 'b strategija/lists/funcs.cpp'
vector:
	g++ -std=c++17 -o main_vector_a 'a strategija/vectors/main.cpp' 'a strategija/vectors/funcs.cpp'
	g++ -std=c++17 -o main_vector_b 'b strategija/vectors/main.cpp' 'b strategija/vectors/funcs.cpp'
run_deque_a:
	./main_deque_a
run_deque_b:
	./main_deque_b
run_list_a:
	./main_list_a
run_list_b:
	./main_list_b
run_vector_a:
	./main_vector_a
run_vector_b:
	./main_vector_b
clear:
	rm *.txt main_deque_a main_deque_b main_list_a main_list_b main_vector_a main_vector_b
