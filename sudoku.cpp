//let's create a sudoku solver
//we will use a 9x9 grid for that we will create a Board struct with array of arrays

//we will also need a function to print the board

//we will also need a function to check if a number is valid in a given position

//we will also need a function to check if the board is solved

//we will also need a function to solve the board - we will use backtracking for that

//we also want to keep track of our moves so we can undo them if needed
//so Moves struct also would be helpful

//we will also need a function to print the moves

//we will also need a function to undo the last move

//we will also need a function to make a move

#include <iostream>
//need file operations
#include <fstream>

using namespace std;

//let's start with the Board struct
struct Board {
    int grid[9][9]; //9x9 grid
    //we could add moves here but we will keep them separate for now
};

// //let's create a Moves struct
// struct Moves {
//     int row;
//     int col;
//     int num;
// };


//let's create a function that prints a Board
void print_board(Board b) {
    for (int i = 0; i < 9; i++) {
        //print horizontal line
        if (i % 3 == 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            //print vertical line
            if (j % 3 == 0) {
                cout << "|";
            }
            cout << b.grid[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "---------------------" << endl;
}

//let's create a function that checks if a number is valid in a given position
bool is_valid(Board b, int row, int col, int num) {
    //check if the number is in the row
    for (int i = 0; i < 9; i++) {
        if (b.grid[row][i] == num) {
            return false;
        }
    }
    //check if the number is in the column
    for (int i = 0; i < 9; i++) {
        if (b.grid[i][col] == num) {
            return false;
        }
    }
    //check if the number is in the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (b.grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

//let's create a function that checks if the board is solved
bool is_solved(Board b) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (b.grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

//let's create a function that solves the board
bool solve_board(Board &b) {
    int row, col;
    //if the board is solved return true
    if (is_solved(b)) {
        return true;
    }
    //find an empty position
    //note we are using row and col outside the loop - to keep them IN SCOPE
    bool found = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (b.grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    //try to fill the empty position
    for (int num = 1; num <= 9; num++) {
        if (is_valid(b, row, col, num)) {
            b.grid[row][col] = num;
            if (solve_board(b)) {
                return true;
            }
            b.grid[row][col] = 0;
        }
    }
    return false;
}
//TODO create solver that is NOT recursive - we would simply keep a stack of moves and try to solve the board
//then backtrack if needed

//lets make a function to read puzzle from text file in 9x9 format
//we will use 0 for empty cells and 1 to 9 for filled cells
//we will use newline to separate rows
//columns will be next to each other

//we will also need a function to write the board to a text file

//now let's make a read function
bool read_board(Board &b, string filename) {
    ifstream file(filename);
    //we will use char to store digits
    char digit;
    if (!file.is_open()) {
        cout << "Could not open file " << filename << endl;
        return false;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // file >> b.grid[i][j];
            file >> digit; //here we parse each char that is not newline
            //we could check if digit is between 0 and 9 - but later
            //we will convert char to int
            b.grid[i][j] = digit - '0'; //very popular approach to convert char to int
        }
    }
    file.close();
    //no error checking here for now
    return true;
}

//now our main will read and print the board

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide a filename with sudoku puzzle!" << endl;
        return 1;
    }
    Board b;
    if (!read_board(b, argv[1])) {
        cout << "Could not read the board!" << endl;
        return EXIT_FAILURE;
    }
    cout << "Initial board:" << endl;
    print_board(b);
    if (solve_board(b)) {
        cout << "Solved board:" << endl;
        print_board(b);
    } else {
        cout << "Could not solve the board!" << endl;
    }
    return EXIT_SUCCESS;
}

