//
// Created by sebastian on 12/8/25.
//

#include "Game.h"
#include <iostream>
#include <limits>

Game::Game()
  : m_gameBoard() {}

void Game::playCoopGame()
{
  clearConsole();
  m_isGameOver = false;

  while (!m_isGameOver)
  {
    // Print the current status of the board
    printStatus();

    // Get the players move, and check if the game is over
    m_gameBoard.EditBoard(getMove(), m_currentPlayer);
    if (checkGameStatus())
    { break; }
    switchPlayer();
    clearConsole();
  }
}

void Game::playSinglePlayerGame()
{
  GameAI ai(m_gameBoard, (m_currentPlayer == 'X') ? 'O' : 'X');
  clearConsole();
  m_isGameOver = false;

  while (!m_isGameOver)
  {
    // Print the current board
    printStatus();

    // Get the players move and check if the game is over
    m_gameBoard.EditBoard(getMove(), m_currentPlayer);
    if (checkGameStatus())
    { break; }

    // Now let the AI take its turn and check if the game is over
    switchPlayer();
    ai.makeMove();
    if (checkGameStatus())
    { break; }

    // Switch back to the player
    switchPlayer();
    clearConsole();
  }
}

void Game::printStatus() const
{
  m_gameBoard.PrintBoard();
  std::cout << "Current Player: " << m_currentPlayer << "\n";
}

int Game::getMove() const
{
  std::cout << "Enter the tile number (1-9), you want to play: ";
  int tile {0};

  // Keep trying to get an input until you get a valid input
  while (true)
  {
    // Check if the input you get is an integer
    if (std::cin >> tile)
    {
      // Check if the integer is valid
      if (m_gameBoard.isMoveValid(tile))
      {
        return tile;
      }

      std::cout << "Invalid move. Please enter a valid tile number: ";
    }
    // If the input isn't an int
    else
    {
      std::cout << "Invalid input. Please enter a number." << std::endl;

      // Reset the input
      std::cin.clear();
      // Clear the buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

void Game::switchPlayer()
{
  m_currentPlayer = (m_currentPlayer == 'X') ? 'O' : 'X';
}

bool Game::checkGameStatus()
{
  if (m_gameBoard.hasPlayerWon(m_currentPlayer))
  {
    clearConsole();
    m_gameBoard.PrintBoard();

    std::cout << m_currentPlayer << " has won!\n";
    m_isGameOver = true;
    return true;
  }

  if (m_gameBoard.isBoardFull())
  {
    clearConsole();
    m_gameBoard.PrintBoard();

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