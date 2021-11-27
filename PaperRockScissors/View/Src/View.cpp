
#include "View.h"
#include <iostream>

CView::CView(std::shared_ptr<IController> aController)
    : mController(std::move(aController)) {}

void CView::UpdateView(EView aView) {

  switch (aView) {

  case EView::EINIT: {
    Initialize();
    break;
  }

  case EView::ERECEIVE_ROUNDS: {

    bool isInputValid = false;
    int input;

    while (!isInputValid) {
      std::cout << "Enter nubmer of rounds you want to play (should be > 0) \n";
      std::cin >> input;
      if (input > 0) {
        isInputValid = true;
      }
    }

    mController->UpdateNumberOfRounds(input);

  } break;
  case EView::ERECEIVE_USERINPUT: {
    int input;
    bool isInputValid = false;
    while (!isInputValid) {
      // std::system("reset");
      DisplayOutcome("Enter `1` for Rock");
      DisplayOutcome("Enter `2` for Paper");
      DisplayOutcome("Enter `3` for Scissor");

      std::cin >> input;
      if (input > 0 && input < 4) {
        isInputValid = true;
      } else {
        DisplayOutcome("Invalid Input! Enter again");
      }
    }
    mController->UpdatePlayerInput(input);
  } break;
  case EView::EDISPLAY_RESULT: {
    const std::string inputMessage =
        "You choose " + ConvertUserInputToString(mController->GetUserChoice()) +
        " and computer choose " +
        ConvertUserInputToString(mController->GetComputerChoice());

    const auto result = [&mController = mController]() {
      const auto winner = mController->GetWinner();
      switch (winner) {
      case EResult::ECOMPUTER: {
        return "Computer Wins...";
      }
      case EResult::EUSER: {
        return "You Win....";
      }
      case EResult::EDRAW: {
        return "Its a DRAW...";
      }
      case EResult::EUNKNOWN: {
        return "Result is UNKNOWN...";
      }
      }

      return "";
    };

    DisplayOutcome("===============================");
    DisplayOutcome(inputMessage);
    DisplayOutcome(result());
    DisplayOutcome("===============================");
  } break;

  case EView::EFINALOUTCOME: {
    const std::string data =
        "After " + std::to_string(mController->GetNumberOfRounds()) +
        " rounds -> " +
        (mController->GetWinner() == EResult::ECOMPUTER ? "Computer wins"
                                                        : "You win");
    DisplayOutcome(data);
  } break;
  }
}

void CView::Initialize() {

  std::system("reset");
  DisplayWelcomeScreen();
  DisplayRules();
}

void CView::DisplayRules() {
  std::cout << "Rules are as follows \n";
  std::cout << "***************************************\n";
  std::cout << "paper    beats rock     \n";
  std::cout << "rock     beats scissors \n";
  std::cout << "scissors beat  paper    \n";
  std::cout << "***************************************\n";
}

void CView::DisplayWelcomeScreen() {
  std::cout << "***************************************\n";
  std::cout << "**********  WELCOME TO  ***************\n";
  std::cout << "****** ROCK  PAPER &  SCISSOR *********\n";
  std::cout << "***************************************\n";
}

void CView::DisplayOutcome(std::string aData) const {
  std::cout << aData << "\n";
}

std::string CView::ConvertUserInputToString(EChoice aChoice) {
  switch (aChoice) {
  case EChoice::EINVALID: {
    return "Invalid";
  }
  case EChoice::EPAPER: {
    return "PAPER";
  }
  case EChoice::EROCK: {
    return "ROCK";
  }
  case EChoice::ESCISSORS: {
    return "SCISSORS";
  }
  }

  return {};
}