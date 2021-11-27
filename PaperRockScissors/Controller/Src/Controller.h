#pragma once

#include <IController.h>
#include <memory>

#include "IView.h"

class CController : public IController {
public:
  void StartGame(std::shared_ptr<IView> aView) override;
  void UpdatePlayerInput(std::uint8_t aInput) override;
  void UpdateNumberOfRounds(std::uint64_t aRounds) override;
  std::uint64_t GetNumberOfRounds() const override;
  EChoice GetComputerChoice() const override;
  EChoice GetUserChoice() const override;
  EResult GetWinner() const override;
  EGameState GetGameState() const override;

private:
  void UpdateState(EGameState aNewState);
  EChoice GenerateComputerInput();
  void Decide();

  std::shared_ptr<IView> mView;
  EGameState mCurrentState{EGameState::EINIT};
  std::uint64_t mNumRounds{0};
  std::uint64_t mUserWinCount{0};
  std::uint64_t mComputerWinCount{0};
  EChoice mComputerChoice{EChoice::EINVALID};
  EChoice mUserChoice{EChoice::EINVALID};
  EResult mLastRound{EResult::EUNKNOWN};
};