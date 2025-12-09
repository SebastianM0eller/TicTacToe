//
// Created by sebastian on 12/9/25.
//

#include "GameAI.h"
#include "Random.h"

GameAI::GameAI(GameBoard& gameBoard, const char symbol)
  : m_gameBoard(gameBoard), m_symbol(symbol) {}

void GameAI::makeMove()
{
  if (canWin() != 0)
    { m_gameBoard.EditBoard(canWin(), m_symbol); }
  else if (playerCanWin() != 0)
   { m_gameBoard.EditBoard(playerCanWin(), m_symbol); }
  else { m_gameBoard.EditBoard(pickRandomMove(), m_symbol); }
}

int GameAI::canWin()
{
  for (int tile = 1; tile <= 9; tile++)
  {
    GameBoard copy = m_gameBoard;
    if (copy.isMoveValid(tile))
    {
      copy.EditBoard(tile, m_symbol);
      if (copy.hasPlayerWon(m_symbol)) { return tile; }
    }
  }
  return 0;
}

int GameAI::playerCanWin()
{
  char playerSymbol = (m_symbol == 'X') ? 'O' : 'X';

  for (int tile = 1; tile <= 9; tile++)
  {
    GameBoard copy = m_gameBoard;
    if (copy.isMoveValid(tile))
    {
      copy.EditBoard(tile, playerSymbol);
      if (copy.hasPlayerWon(playerSymbol)) { return tile; }
    }
  }
  return 0;
}

int GameAI::pickRandomMove()
{
  int move = 0;

  while (!m_gameBoard.isMoveValid(move))
     move = Random::getRandomInt(1,9);

  return move;
}