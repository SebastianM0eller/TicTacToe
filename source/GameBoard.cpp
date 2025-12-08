//
// Created by sebastian on 12/8/25.
//

#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard() : gameBoard()
{
    char tileNumber {'1'};

    for (int row = 0; row <= 2; row++)
    {
        for (int column = 0; column <= 2; column++)
        {
            gameBoard[row][column] = tileNumber++;
        }
    }
}

void GameBoard::printBoard() const
{
    std::cout << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << "\n";
    std::cout << "--+---+--\n";
    std::cout << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << "\n";
    std::cout << "--+---+--\n";
    std::cout << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << "\n";
}

void GameBoard::editBoard(const int tileNumber, const char playerSymbol)
{
    const int row = (tileNumber - 1) / 3;
    const int column = (tileNumber - 1) % 3;

    gameBoard[row][column] = playerSymbol;
}

