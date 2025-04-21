# Simple File Parser in C

This project provides a basic implementation of a file parser written in C. It reads a text file line by line, tokenizes each line by whitespace, and stores the tokens in a 3D array of characters.

## 📄 Features

- Parses up to 64 lines (can be changed)
- Each line supports up to 16 tokens (can be changed)
- Each token supports up to 16 characters (can be changed)
- Returns a 3D array: `file[line][token]`

## 🛠️ Compilation

To compile the program, run:

```bash
gcc Parser.c -o Parser

```
This project can also be used as a module simply by importing the *Parser.c* and *Parser.h* files into your project directory, including the header file and compiling with the *Parser.c* file.

```bash
gcc {your_main_file.c} Parser.c -o {your_output_file_name}
```
