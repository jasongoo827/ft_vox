#include "Core/App.h"

namespace ft_vox
{
App *App::s_Instance = nullptr;

App::App()
{
    s_Instance = this;
    Init();
}

App::~App()
{
    Shutdown();
}

void App::Init()
{
    m_Window = std::unique_ptr<Window>(Window::Create());
    // m_Window->SetEventCallback(BIND_EVENT_FN(App::OnEvent));
}

void App::Run()
{
    while (m_Running)
    {
        m_Window->OnUpdate();
    }
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

void App::OnClose()
{
    // just for testing
    m_Running = false;
}

} // namespace ft_vox
