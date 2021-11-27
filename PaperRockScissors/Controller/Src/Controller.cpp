#include "Controller.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

void CController::StartGame(std::shared_ptr<IView> aView) {
  mView = std::move(aView);

  mView->UpdateView(EView::EINIT);
  mView->UpdateView(EView::ERECEIVE_ROUNDS);
}

void CController::UpdatePlayerInput(std::uint8_t aInput) {
  mComputerChoice = GenerateComputerInput();
  mUserChoice = static_cast<EChoice>(aInput);
  Decide();
}

void CController::UpdateNumberOfRounds(std::uint64_t aRounds) {
  mNumRounds = aRounds;
  UpdateState(EGameState::EPROGRESS);
}

std::uint64_t CController::GetNumberOfRounds() const { return mNumRounds; }

EGameState CController::GetGameState() const { return mCurrentState; }

EChoice CController::GetComputerChoice() const { return mComputerChoice; }

EChoice CController::GetUserChoice() const { return mUserChoice; }

EResult CController::GetWinner() const {

  if (mCurrentState == EGameState::ECOMPLETE) {
    if (mComputerWinCount == 0 && mUserWinCount == 0) {
      return EResult::EUNKNOWN;
    } else if (mComputerWinCount > mUserWinCount) {
      return EResult::ECOMPUTER;
    } else if (mComputerWinCount < mUserWinCount) {
      return EResult::EUSER;
    } else {
      return EResult::EDRAW;
    }
  } else if (mCurrentState == EGameState::EPROGRESS) {
    return mLastRound;
  } else {
    return EResult::EUNKNOWN;
  }
}

EChoice CController::GenerateComputerInput() {

  unsigned seed = time(0);
  srand(seed);
  auto choice = (rand() % 3);

  return static_cast<EChoice>(choice + 1);
}

void CController::Decide() {

  if (mComputerChoice == EChoice::EROCK) {
    if (mUserChoice == EChoice::EPAPER) {

      mUserWinCount++;
      mLastRound = EResult::EUSER;

    } else if (mUserChoice == EChoice::ESCISSORS) {
      mComputerWinCount++;
      mLastRound = EResult::ECOMPUTER;

    } else if (mUserChoice == EChoice::EROCK) {
      mLastRound = EResult::EDRAW;
    }
  } else if (mComputerChoice == EChoice::EPAPER) {
    if (mUserChoice == EChoice::EROCK) {
      mComputerWinCount++;
      mLastRound = EResult::ECOMPUTER;
    } else if (mUserChoice == EChoice::ESCISSORS) {
      mUserWinCount++;
      mLastRound = EResult::EUSER;
    } else if (mUserChoice == EChoice::EPAPER) {
      mLastRound = EResult::EDRAW;
    }
  } else if (mComputerChoice == EChoice::ESCISSORS) {
    if (mUserChoice == EChoice::EROCK) {
      mUserWinCount++;
      mLastRound = EResult::EUSER;
    } else if (mUserChoice == EChoice::EPAPER) {
      mComputerWinCount++;
      mLastRound = EResult::ECOMPUTER;
    } else if (mUserChoice == EChoice::ESCISSORS) {
      mLastRound = EResult::EDRAW;
    }
  }
}

void CController::UpdateState(EGameState aNewState) {
  if (mCurrentState != aNewState) {
    if (aNewState == EGameState::EPROGRESS &&
        mCurrentState == EGameState::EINIT) {
      mCurrentState = aNewState;
      auto rounds = mNumRounds;
      while (rounds) {
        mView->UpdateView(EView::ERECEIVE_USERINPUT);
        mView->UpdateView(EView::EDISPLAY_RESULT);
        rounds--;
      }

      mCurrentState = EGameState::ECOMPLETE;
      mView->UpdateView(EView::EFINALOUTCOME);
    }
  }
}