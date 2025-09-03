Push_Swap (Radix Sort Version)

Push_swap is a C program designed to sort a stack of integers using a limited set of operations. The goal is to sort efficiently with the least number of moves, following the rules of the 42 School project.

This implementation uses the Radix Sort algorithm to handle larger stacks efficiently.

🔹 Project Overview

The program sorts a stack of integers using two stacks (A and B) and a limited set of operations:

sa, sb, ss → swap the top two elements

pa, pb → push from one stack to the other

ra, rb, rr → rotate stack

rra, rrb, rrr → reverse rotate stack

This radix sort version converts integers into binary representation and sorts by bit positions, which allows sorting large numbers efficiently.

Features

Efficiently sorts large stacks with minimal operations

Works with any set of unique integers
