# C - Pointer Arithmetic

Pointers variables are also known as address data types because they are used to store the address of another variable.

The address is the memory location that is assigned to the variable. It doesn’t store any value. Hence, there are only a few operations that are allowed to perform on Pointers in C language. The operations are slightly different from the ones that we generally use for mathematical calculations. The operations are:
* Increment/Decrement of a Pointer
* Addition of integer to a pointer
* Subtraction of integer to a pointer
* Subtracting two pointers of the same type

## Practical Example

A fishing port wants to keep a record of the fishing vessels, their owners, and the crew of each vessel. For the above, it is desired to store each person's name, surname, age, and role played within the crew (harpooner, cook, lookout, captain, etc.). Of the boats it is required to know the name, length, beam, maximum number of crew members and their crew (crew information).

The C implementation allows:

* Incorporate ships to the port (As many as required at any time).
*Incorporate crew members and associate them with existing boats (as long as there are places available). Each crew member can be from a single ship.
* Know which crew members are assigned to a specific vessel and the role of each one of them. You must also be able to meet the owner of the boat (note that this is not a crew member).
* Show the registry of all boats (with their crew and the number of places available).

## Installation

Use the terminal to compile the program.

```bash
gcc main.c -o main 
```
