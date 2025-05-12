#include "Core/App.h"

namespace ft_vox
{
App *App::s_Instance = nullptr;

App::App()
{
}

App::~App()
{
}

void App::Init()
{
}

void App::Run()
{
}

void App::Shutdown()
{
}

void App::OnEvent()
{
}

App &App::Get()
{
    return *s_Instance;
}

void App::OnWindowClose()
{
    m_Running = false;
}

} // namespace ft_vox
