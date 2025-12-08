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

void GameBoard::editBoard(const int tile, const char symbol)
{
  const int row = (tile - 1) / 3;
  const int column = (tile - 1) % 3;

  gameBoard[row][column] = symbol;
}

bool GameBoard::hasPlayerWon(const char symbol) const
{

  // Check the vertical win-conditions
  for (int row = 0; row <= 2; row++)
  {
    if (gameBoard[row][0] == symbol && gameBoard[row][1] == symbol && gameBoard[row][2] == symbol)
    { return true; }
  }

  // check the horizontal win-conditions
  for (int column = 0; column <= 2; column++)
  {
    if (gameBoard[0][column] == symbol && gameBoard[1][column] == symbol && gameBoard[2][column] == symbol)
    { return true; }
  }

  // If none of the other are true, return the diagonal win-condition
  return gameBoard[0][0] == gameBoard[1][1] == gameBoard[2][2] == symbol ||
         gameBoard[0][2] == gameBoard[1][1] == gameBoard[2][0] == symbol;
}

bool GameBoard::isBoardFull() const
{
  for (int row = 0; row <= 2; row++)
  {
    for (int column = 0; column <= 2; column++)
    {
      if (gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
      { return false; } // If the tile is not X or O, it's not yet occupied
    }
  }
  // If the entire board consists of X of O, there a no playable spaces left.
  return true;
}


