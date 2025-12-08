//
// Created by sebastian on 12/8/25.
//

#pragma once

class GameBoard
{
public:
  GameBoard();
  ~GameBoard() = default;

  void printBoard() const;
  void editBoard(int tileNumber, char playerSymbol);

private:
  char gameBoard[3][3];
};