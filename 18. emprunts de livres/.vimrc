let b:CompileCommand="gcc -w -g -fsanitize=address main.c -o main"
let b:RunCommand="./main < input.txt"
