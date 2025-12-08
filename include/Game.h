//
// Created by sebastian on 12/8/25.
//

#pragma once
#include "GameBoard.h"

class Game
{
public:
  Game();
  ~Game() = default;
  void playGame();

private:
  GameBoard m_gameBoard;

  bool m_isGameOver {true};
  char m_currentPlayer {'X'};

  // Helper Functions
  void printStatus() const;
  [[nodiscard]] int getMove() const;
  void SwitchPlayer();
  bool CheckGameStatus();
  void clearConsole();
};