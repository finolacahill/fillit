# **Fillit**
_________________________________

Final grade 100/100
### The Challenge 
Fillit is a project that allowed me to familiarize myself with a recurring
problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. I had to find a way to
assemble a given Tetriminos set altogether in the smallest possible square. A Tetriminos is a 4-blocks such as seen in Tetris
###Learning objectives 
This project was the first program, as opposed to function, demanded of us at school. It was a group project, completed in pairs. It was a first step into parsing and error management. We had to ensure each tetris piece was valid to a particular set of rules. In terms of algorithm design, it allowed us to discover how to make use of backtracking and rescursion. 
### Usage
If you enter into the sources directory and use the command "make", this will create a fillit executible. 
Fillit will take a file with tetrimonis as an executible. The input must follow strict guides. Each line must contain 4 chars followed by a \n, there may only be four lines per piece, and there may only be 4 hash signs, the rest of the chars being dots. Any deviance from this and the program will return an error. 
Otherwise, Fillit will take the pieces and print on the stdout the smallest possible competed square map. The first tetris piece will be represented by A, the next by B etc. 
i.e.

##..
#...
#...
....

...#
...#
..##
....

becomes

AAB
A.B
ABB

Please see [this PDF](https://github.com/finolacahill/fillit/blob/master/fillit.en.pdf) for further details. 
