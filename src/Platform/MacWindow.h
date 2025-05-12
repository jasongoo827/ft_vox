#pragma once

#include "Core/Window.h"

namespace ft_vox
{
class MacWindow : public Window
{
public:
    MacWindow(const WindowProps &props);
    virtual ~MacWindow() override;

    void Init(const WindowProps &props);
    void Shutdown();
    virtual void OnUpdate() override;

    virtual uint32_t GetWidth() const override { return m_Data.width; }
    virtual uint32_t GetHeight() const override { return m_Data.height; }
    virtual GLFWwindow *GetNativeWindow() const override { return m_Window; }

private:
    GLFWwindow *m_Window;

    struct WindowData
    {
        std::string title;
        uint32_t width;
        uint32_t height;

        // EventCallbackFn EventCallback;
    };

    WindowData m_Data;
};
} // namespace ft_vox