#include "Framework/Application.h"
#include "Lv1Scene.h"
#include "MenuSelectorScene.h"
#include "BossScene.h"
#include "CompleteScene.h"
#include "DeathScene.h"

US_NS_JK

int WINAPI WinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR    lpCmdLine,
  int       nCmdShow)
{
  Application app = Application::Application(hInstance, "Hello Khang", SCREEN_WIDTH, SCREEN_HEIGHT, false, new MenuSelector);
  app.run();

}

