target:
        gcc main.c -o main
        taskset 0x1 ./main