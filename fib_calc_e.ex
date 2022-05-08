###########################################################################
#                                                                         #
# "fib_calc_e.ex"                                                         #
#                                                                         #
# Author: Jarod Graygo                                                    #
#                                                                         #
# Gets the nth fibonacci number using the Elixir programming language     #
#                                                                         #
# The program can be run with the command "elixir fib_calc_e.ex"          #
#                                                                         #
# Elixir is a purely functional programming language where all objects    #
# are immutable, but can be copied to create new/different objects        #
# based on the input object. In a functional programming language         #
# computation is treated more as mathematical functions and state         #
# changes, as well as mutable data, are avoided                           #
#                                                                         #
###########################################################################

# Elixir utilizes eager evaluation for evaluating arguments, meaning the arguments are evaluated BEFORE the function
# is applied

fib_num = IO.gets("Which number in the fibonacci sequence would you like the value of? ") # Get user input
          |> Integer.parse                        # Pipe user input into Integer.parse function to extract an integer
          |> elem(0)                              # Pipe result of Integer.parse into elem function to extract the parsed integer

# Arguments are passed either by-value or by-reference to each function. The method chosen does not make a difference to
# the programmer due to the fact that all objects in Elixir are immutable so the method used is picked by the compiler
# on a per-object basis (ex. Maps are passed by-reference)

Stream.unfold({1,1}, fn {a,b} -> {a,{b,a+b}} end) # Unfolds into an array of the fibonacci sequence beginning with 1, 1
          |> Enum.take(fib_num)                   # Pipe the function into Enum.take which gets the first "fib_num" numbers of the fibonacci sequence
          |> Enum.take(-1)                        # Pipe the result into Enum.take to extract the last element in the array (the number the user wants)
          |> IO.inspect(charlists: :as_lists)     # Pipe the final result into IO.inspect which prints the result to the console

# Elixir uses a tracing garbage collector which works by testing for reachability of objects from certain root objects,
# if the object is unreachable from a root object it is considered garbage and collected as such
