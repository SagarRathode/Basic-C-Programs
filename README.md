# Basic-C-Programs
Basic c Program for practice


implementation of vfork() system call
create child process using parent block (child and parent run in same memory)
but fork() system call 
The child process and the parent process run in separate memory

Dynamic memory allocation for 4Dimenssional and 3Dimenssional array


📝 This is Sample Project

MyPatternProject.c

📘 Pattern Menu Program (C)

📌 Overview

This project provides a menu-driven C program that lets the user choose from different pattern programs (pattern17_1.c, pattern17_2.c, etc.).

The program compiles the selected pattern file.

Then it runs the compiled program.

After execution, control returns to the menu so the user can select again.

User can exit anytime by choosing the Exit option.

🛠️ Features
Menu-driven interface using switch and do-while loop.

Each pattern program is compiled dynamically when selected.

Runs the chosen pattern program without terminating the main menu.

Simple to extend: just add new pattern cases in the menu.

📂 File Structure
project/

│── menu.c             # Main menu program (this file)

│── pattern17_1.c      # Example pattern program

│── pattern17_2.c

│── pattern17_3.c

│── pattern17_4.c

│── README.md          # Documentation


▶️ How to Compile & Run

Compile the main menu program:

gcc MyPatternProject.c -o MyPatternProject

Run it:

./MyPatternProject

Choose from the menu:
Welcome To Pattern
1. pattern17_1    2. pattern17_2
3. pattern17_3    4. pattern17_4
5. Exit
Enter Your Choice for pattern =>

📜 How It Works

The program displays a menu in a loop.

User enters a choice (1–4).

The program calls makeExe("pattern17_X"):

Uses system("gcc -Wall -g pattern17_X.c -o pattern17_X") to compile.

If successful, runs it with system("./pattern17_X").

Once the pattern finishes running, control returns to the menu.

If user enters 5, the program exits.

🧩 Adding New Patterns
Create a new file, e.g., pattern17_5.c.
Add a new case in menu.c:
case 6:
    makeExe("pattern17_5");
    break;
Recompile the menu:

gcc MyPatternProject.c -o MyPatternProject

🚀 Example Session

Welcome To Pattern
1. pattern17_1    2. pattern17_2
3. pattern17_3    4. pattern17_4
5. Exit
Enter Your Choice for pattern => 1

Compiling pattern17_1...
Compiled successfully, Exe is pattern17_1
[output of pattern17_1.c here]

Welcome To Pattern
1. pattern17_1    2. pattern17_2
3. pattern17_3    4. pattern17_4
5. Exit
Enter Your Choice for pattern =>

