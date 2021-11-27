#pragma once

#include <cstdint>
#include <memory>

enum class EGameState {
  EINIT,
  EPROGRESS,
  ECOMPLETE,
};

enum class EResult {
  ECOMPUTER,
  EUSER,
  EDRAW,
  EUNKNOWN,
};

enum class EChoice {
  EINVALID,
  EROCK,
  EPAPER,
  ESCISSORS,
};

class IView;

class IController {
public:
  virtual ~IController() = default;
  virtual void StartGame(std::shared_ptr<IView> aView) = 0;
  virtual void UpdatePlayerInput(std::uint8_t aInput) = 0;
  virtual void UpdateNumberOfRounds(std::uint64_t aRounds) = 0;
  virtual std::uint64_t GetNumberOfRounds() const = 0;
  virtual EGameState GetGameState() const = 0;
  virtual EChoice GetComputerChoice() const = 0;
  virtual EChoice GetUserChoice() const = 0;
  virtual EResult GetWinner() const = 0;
};