#pragma once

#include "IController.h"
#include "IView.h"
#include <memory>
#include <string>

class IController;

class CView : public IView {
public:
  explicit CView(std::shared_ptr<IController> aController);
  void UpdateView(EView aView) override;

private:
  void DisplayWelcomeScreen();
  void DisplayRules();
  void Initialize();
  void DisplayOutcome(std::string aData) const;
  std::string ConvertUserInputToString(EChoice aChoice);

  std::shared_ptr<IController> mController;
};