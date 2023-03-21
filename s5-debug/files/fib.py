#!/usr/bin/python3
import sys

# import the external fib function
import fibonacci       # reads the file fibonacci.py

argc = len(sys.argv)

if (argc != 2) :
  print("Us:", sys.argv[0], "<number>", file=sys.stderr)
  print(
   "   where <number> is the number from which to compute fibonacci(number).",
   file=sys.stderr)
#  quit(1)
else :
  num = int(sys.argv[1])
  result = fibonacci.fibonacci(num)     # call function fibonacci in fibonacci.py
  print("fibonacci(", num, ") =", result)
#  input('Press Return to finish')

