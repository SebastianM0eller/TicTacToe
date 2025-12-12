//
// Created by sebastian on 12/8/25.
//

#include "GameBoard.h"
#include <iostream>
#include <algorithm>

GameBoard::GameBoard() : m_gameBoard()
{
  char tileChar {'1'};
  int tileNumber {1};

  for (int row = 0; row <= 2; row++)
  {
    for (int column = 0; column <= 2; column++)
    {
      m_gameBoard[row][column] = tileChar++;
      m_validMoves.push_back(tileNumber++);
    }
  }
}

void GameBoard::PrintBoard() const
{
  std::cout << m_gameBoard[0][0] << " | " << m_gameBoard[0][1] << " | " << m_gameBoard[0][2] << "\n";
  std::cout << "--+---+--\n";
  std::cout << m_gameBoard[1][0] << " | " << m_gameBoard[1][1] << " | " << m_gameBoard[1][2] << "\n";
  std::cout << "--+---+--\n";
  std::cout << m_gameBoard[2][0] << " | " << m_gameBoard[2][1] << " | " << m_gameBoard[2][2] << "\n";
}

void GameBoard::EditBoard(const int tile, const char symbol)
{
  const int row = (tile - 1) / 3;
  const int column = (tile - 1) % 3;

  m_gameBoard[row][column] = symbol;
  std::erase(m_validMoves, tile);
}

bool GameBoard::hasPlayerWon(const char symbol) const
{

  // Check the vertical win-conditions
  for (int row = 0; row <= 2; row++)
  {
    if (m_gameBoard[row][0] == symbol && m_gameBoard[row][1] == symbol && m_gameBoard[row][2] == symbol)
    { return true; }
  }

  // check the horizontal win-conditions
  for (int column = 0; column <= 2; column++)
  {
    if (m_gameBoard[0][column] == symbol && m_gameBoard[1][column] == symbol && m_gameBoard[2][column] == symbol)
    { return true; }
  }

  // If none of the other are true, return the diagonal win-condition
  return (m_gameBoard[0][0] == symbol && m_gameBoard[1][1] == symbol && m_gameBoard[2][2] == symbol) ||
         (m_gameBoard[0][2] == symbol && m_gameBoard[1][1] == symbol && m_gameBoard[2][0] == symbol);
}

bool GameBoard::isBoardFull() const
{
  for (int row = 0; row <= 2; row++)
  {
    for (int column = 0; column <= 2; column++)
    {
      if (m_gameBoard[row][column] != 'X' && m_gameBoard[row][column] != 'O')
      { return false; } // If the tile is not X or O, it's not yet occupied
    }
  }
  // If the entire board consists of X of O, there a no playable spaces left.
  return true;
}

bool GameBoard::isMoveValid(const int tile) const
{
  return std::ranges::find(m_validMoves, tile) != m_validMoves.end();
}


