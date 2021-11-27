#include "Controller/Src/Controller.h"
#include "View/Src/View.h"

int main() {

  std::shared_ptr<IController> controller = std::make_shared<CController>();
  std::shared_ptr<IView> view = std::make_shared<CView>(controller);
  controller->StartGame(view);
  return 0;
}