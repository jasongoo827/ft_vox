#pragma once

#include <iostream>
#include "Core/Window.h"

namespace ft_vox
{
class App
{
public:
    App();
    ~App();

    void Init();
    void Run();
    void Shutdown();
    void OnEvent();

    static App &Get();
    void OnClose();

private:
    void OnWindowClose();


    // void PushLayer(Layer *layer);
    // void PushOverlay(Layer *overlay);

private:
    std::unique_ptr<Window> m_Window;

    // LayerStack
    // EngineContext

    static App *s_Instance;
    bool m_Running = true;
};
} // namespace ft_vox