#include <iostream>
#include <vector> 
#include <cstdlib>
#include <ctime>



int main()
{



    std::cout << " ******** Welcome to Tic Tac Toe! ******** " << std::endl;
beginning:
    int position;
    int playercounter = 0;
    int playernumber;
    bool AI = false;
    int ai = '0';
    AI:
    std::cout << "Type 0 if you want to play against a human player or 1 if you want to play against AI\n";
    std::cin >> ai;

    // Check that ai is a number: 
    if (std::cin.fail()) { 
        std::cout << "\nInvalid imput\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto AI;
    }
    if (ai == 0 || ai == 1) {
        AI = ai;
    }
    else {
        std::cout << "Invalid imput\n";
        goto AI;
    }

    // First case: the playes plays against a human player.
    if (AI == false) {

        std::vector <char> table = { '1','2','3','4','5','6','7','8','9' };
    table:
        for (int i = 0; i < table.size(); i++) {
            if (i % 3 == 0) {
                std::cout << "\n | ";

            }
            std::cout << table[i] << " | ";
        }


        for (int i = 0; i < table.size(); i++) {

            // Check for horizontal winning conditions
            if (i % 3 == 0) {
                if (table.at(i) == table.at(i + 1) && table.at(i) == table.at(i + 2)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }
                    goto end;
                }


            }

            // Check for vertical winning conditions
            if (i < 3) {
                if (table.at(i) == table.at(i + 3) && table.at(i) == table.at(i + 6)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }
                    goto end;
                }

            }

            // Check for diagonal winning condition 1
            if (i == 0) {
                if (table.at(i) == table.at(4) && table.at(i) == table.at(8)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }

                    goto end;
                }

            }

            // Check for diagonanal winning condition 2
            if (i == 2) {
                if (table.at(i) == table.at(4) && table.at(i) == table.at(6)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }

                    goto end;
                }
            }

            // If all position are taken and nobody won, it's a tie.
            if (playercounter == 9) {
                std::cout << "\nIt's a tie!\n";
                goto end;
            }

        }


        // Determine player's number        
        if (playercounter % 2 == 0) {
            playernumber = 1;
        }

        else {
            playernumber = 2;
        }
    imput:
        std::cout << "\n\nPlayer " << playernumber << " - Write a number from 1 to 9: ";
        std::cin >> position;

        // Reject invalid imputs
        if (std::cin.fail()) {
            std::cout << "\nInvalid imput";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto imput;
        }
        else if (position <= 9 && position > 0) { // These are the only valid imput positions for the table
            if (table.at(position - 1) != 'X' && table.at(position - 1) != 'O') { // Reject the imput if the position is already taken

                // Differentiate the symbols for player 1 and player 2
                if (playernumber == 1) {
                    table.at(position - 1) = 'X';

                }
                else {
                    table.at(position - 1) = 'O';

                }
                playercounter++;
                goto table;
            }

            else {
                std::cout << "The position you have chosen is already taken!";
                goto imput;
            }
        }

        else {
            std::cout << "\nInvalid imput";
            goto imput;
        }
    }


    // Second case: the player plays agains AI.
    if (AI == true) {

        std::vector <char> table = { '1','2','3','4','5','6','7','8','9' };
    table2:
        for (int i = 0; i < table.size(); i++) {
            if (i % 3 == 0) {
                std::cout << "\n | ";

            }
            std::cout << table[i] << " | ";
        }


        for (int i = 0; i < table.size(); i++) {

            // Check for horizontal winning conditions
            if (i % 3 == 0) {
                if (table.at(i) == table.at(i + 1) && table.at(i) == table.at(i + 2)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }
                    goto end;
                }


            }

            // Check for vertical winning conditions
            if (i < 3) {
                if (table.at(i) == table.at(i + 3) && table.at(i) == table.at(i + 6)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }
                    goto end;
                }

            }

            // Check for diagonal winning condition 1
            if (i == 0) {
                if (table.at(i) == table.at(4) && table.at(i) == table.at(8)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }

                    goto end;
                }

            }

            // Check for diagonanal winning condition 2
            if (i == 2) {
                if (table.at(i) == table.at(4) && table.at(i) == table.at(6)) {
                    if (table.at(i) == 'X') {
                        std::cout << "\n\nPlayer 1 won!!!!\n";
                    }
                    else {
                        std::cout << "\n\nPlayer 2 won!!!!\n";
                    }

                    goto end;
                }
            }

            // If all position are taken and nobody won, it's a tie.
            if (playercounter == 9) {
                std::cout << "\nIt's a tie!\n";
                goto end;
            }

        }


        // Determine player's number        
        if (playercounter % 2 == 0) {
            playernumber = 1;
        }

        else {
            playernumber = 2;
        }

        // Create a random variable to select a position in the table.
        srand(std::time(0));
        imput3:
        if (playernumber == 2) {
            position = (1 + rand() % 9);
            // Reject invalid imputs
            if (std::cin.fail()) {
                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                goto imput2;
            }
            else if (position <= 9 && position > 0) { // These are the only valid imput positions for the table
                if (table.at(position - 1) != 'X' && table.at(position - 1) != 'O') { // Reject the imput if the position is already taken

                    
                    std::cout << "\n\nComputer's turn:" << std::endl;
                    table.at(position - 1) = 'O';
                    playercounter++;
                    goto table2;
                }

                else {
                    
                    goto imput3;
                }
            }

            else {
                
                goto imput3;
            }
        }

        else {

        imput2:
            std::cout << "\n\nPlayer " << playernumber << " - Write a number from 1 to 9: ";
            std::cin >> position;

            // Reject invalid imputs
            if (std::cin.fail()) {
                std::cout << "\nInvalid imput";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                goto imput2;
            }
            else if (position <= 9 && position > 0) { // These are the only valid imput positions for the table
                if (table.at(position - 1) != 'X' && table.at(position - 1) != 'O') { // Reject the imput if the position is already taken
                    table.at(position - 1) = 'X';
                    playercounter++;
                    goto table2;
                }

                else {
                    std::cout << "The position you have chosen is already taken!";
                    goto imput2;
                }
            }

            else {
                std::cout << "\nInvalid imput";
                goto imput2;
            }
        }
    }

end:
    char yn;
    std::cout << "Do you want to play again (Y/N) ? \n";
    std::cin >> yn;
    yn = toupper(yn); // Makes yn case insensitive.
    if (yn == 'Y') {
        goto beginning;
    }



    return 0;

}

