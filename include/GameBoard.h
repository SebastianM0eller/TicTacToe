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
  void editBoard(int tile, char symbol);

  bool hasPlayerWon(char symbol) const;
  bool isBoardFull() const; // Is it a draw?

private:
  char gameBoard[3][3];
};