#!bash

myfile=`ls -t1 *.cc | head -n 1`
echo $myfile
g++ $myfile -g -Og -std=c++17 -Wall -Wextra -Wconversion -Wshadow -o sol || exit

