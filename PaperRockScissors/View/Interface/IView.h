#pragma once

enum class EView {
  EINIT,
  ERECEIVE_ROUNDS,
  ERECEIVE_USERINPUT,
  EDISPLAY_RESULT,
  EFINALOUTCOME
};

class IView {
public:
  virtual ~IView() = default;
  virtual void UpdateView(EView aView) = 0;
};