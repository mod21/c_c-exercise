#include "Direction.h"
#include "Exceptions.h"
#include "Game.h"
#include "Level.h"
#include "LevelIO.h"
#include "Util.h"

//------------------------------------------------------------------------------
Game::Game() :
  level_(), isAutoSaveEnabled_(false)
{
}

//------------------------------------------------------------------------------
Game::~Game()
{
  if (level_)
    delete level_;
}

//------------------------------------------------------------------------------
Level* Game::getLevel()
{
  return level_;
}

//------------------------------------------------------------------------------
void Game::setLevel(Level* level)
{
  if (level_)
  {
    delete level_;
  }
  level_ = level;
}

//------------------------------------------------------------------------------
void Game::enableAutoSave(string path)
{
  if (!Util::checkFileName(path))
  {
    throw WrongParameterException();
  }
  autoSavePath_ = path;
  isAutoSaveEnabled_ = true;
}

//------------------------------------------------------------------------------
void Game::disableAutosave()
{
  isAutoSaveEnabled_ = false;
}

//------------------------------------------------------------------------------
void Game::autoSave()
{
  if (isAutoSaveEnabled_)
  {
    try
    {
      LevelIO::saveToFile(level_, autoSavePath_);
    }
    catch (const FileWriteException& exception)
    {
      processErrorMessage(exception);
    }
  }
}

void Game::loadAndInitializeLevel(string path)
{
  if (!Util::checkFileName(path))
  {
    throw InvalidBasicFileException();
  }
  setLevel(LevelIO::loadFromFile(path));
  autoSave();
  level_->print(false, false);
  level_->getPlayer()->checkFinished();
}
