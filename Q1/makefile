default:
	gcc q1.c -o q1
	./q1
step1:
	gcc -E q1.c > q1.i
step2:
	gcc -S q1.c
step3:
	gcc -c q1.c
step4:
	gcc q1.o -o q1
clear:
	rm ./q1 q1.i q1.s q1.o