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

  [[nodiscard]] bool hasPlayerWon(char symbol) const;
  [[nodiscard]] bool isBoardFull() const; // Is it a draw?
  [[nodiscard]] bool isMoveValid(int tile) const;

private:
  char m_gameBoard[3][3];
};