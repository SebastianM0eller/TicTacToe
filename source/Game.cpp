//
// Created by sebastian on 12/8/25.
//

#include "Game.h"
#include <iostream>
#include <cstdlib>

Game::Game()
  : m_gameBoard() {}

void Game::playGame()
{
  clearConsole();
  m_isGameOver = false;
  while (!m_isGameOver)
  {
    printStatus();
    int tile = getMove();
    m_gameBoard.editBoard(tile, m_currentPlayer);
    if (CheckGameStatus())
    { break; }
    SwitchPlayer();
    clearConsole();
  }
}

void Game::printStatus() const
{
  m_gameBoard.printBoard();
  std::cout << "Current Player: " << m_currentPlayer << "\n";
}

int Game::getMove() const
{
  std::cout << "Enter the tile number (1-9), you want to play: ";

  int tile;
  std::cin >> tile;

  while (!m_gameBoard.isMoveValid(tile))
  {
    std::cout << "Invalid move. Please enter a valid tile number: ";
    std::cin >> tile;
  }

  return tile;
}

void Game::SwitchPlayer()
{
  m_currentPlayer = (m_currentPlayer == 'X') ? 'O' : 'X';
}

bool Game::CheckGameStatus()
{
  if (m_gameBoard.hasPlayerWon(m_currentPlayer))
  {
    clearConsole();
    m_gameBoard.printBoard();

    std::cout << m_currentPlayer << " has won!\n";
    m_isGameOver = true;
    return true;
  }

  if (m_gameBoard.isBoardFull())
  {
    clearConsole();
    m_gameBoard.printBoard();

    std::cout << "It's a draw!\n";
    m_isGameOver = true;
    return true;
  }

  return false;
}

void Game::clearConsole()
{
  std::cout << std::string(100, '\n');
}