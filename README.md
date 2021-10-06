# ECEN_749
# Question 3
This the repository for HW and LAB for TAMU ECEN-749 Microprocessor System Design
Write a C program to create the class roster for ECEN449. Create a menu-
driven program. The menu should have 3 options: Add, Remove and
Create Roster.
(a)
‘Add’ prompts the user to provide the name, section number and UIN of
the student. The user can choose from three sections (501, 502 and 503).
There can be a maximum of 3 students in each section. If a user tries to
‘Add’ to a section that is already full, print out a message stating that the
section chosen is full and also mention which sections have a seat
available.
(b)
‘Remove’ should prompt the user to provide the name and section of the
student to be removed from the class list.
(c)
‘Create Roster’ should print out the total number of seats, the number of
seats occupied and the number remaining. This information should be
printed out for each of the sections. Also, ‘Create Roster’ should create
files 501.txt, 502.txt and 503.txt which consist of the student names in each
of the sections in alphabetic order, followed by their UIN.
Use the following sequence of steps to test your code:
Add to Section 501: Derrick Perry (129402130), Vernon Myers
(129008860), Terrell Adams (129471152), Amy Wood (129442100). The
program should complain about you adding Amy to Section 501. So add
her to Section 502. Now add to Section 502: Kerry Ryan (1294718850),
Rebecca Martinez (129010060). Then remove Rebecca from section 502.
Finally add to Section 503: Patrick Ward (129114810), Joseph Peterson
(129772800). Finally, run “Create Roster”. Your submission should contain
all the messages that your program prints out when you run the above
sequence of steps including 501.txt, 502.txt, and 503.txt

# Question 4
You have to write C-code in this question. Firstly, generate ’N’ floating
point random numbers between 0 and 4095, where ’N’ is 20, and store
them in a file named q4input.txt. The first line of this file should contain the
number N and subsequent lines should contain one random number each.
Then, using the q4input.txt file as input, read N as well as the random
numbers from the input file, and sort the numbers in ascending order.
Store these sorted numbers in the file named q4output.txt. Follow the
same formatting for the output file as for the input file i.e. the first line of the
output file should contain N and subsequent lines should contain one
random number each. In addition to printing your C-code, provide a
printout of the input and output files as well.
Note: Use of library function to generate random numbers is permitted.
Use of library functions for sorting is NOT permitted

