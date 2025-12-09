//
// Created by sebastian on 12/9/25.
//

#pragma once
#include "GameBoard.h"

class GameAI
{
  public:
    GameAI(GameBoard& gameBoard, char symbol);
    ~GameAI() = default;

  void makeMove();

private:
  GameBoard& m_gameBoard;
  const char m_symbol;

  // Returns 0 if there are no winning moves
  int canWin();
  int playerCanWin();

  // Returns a random valid move.
  int pickRandomMove();
};
