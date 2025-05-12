#include "Platform/MacWindow.h"

namespace ft_vox
{
Window *Window::Create(const WindowProps &props)
{
    return new MacWindow(props);
}

MacWindow::MacWindow(const WindowProps &props)
{
    Init(props);
}

MacWindow::~MacWindow()
{
    Shutdown();
}

void MacWindow::Init(const WindowProps &props)
{
    m_Data.title = props.title;
    m_Data.width = props.width;
    m_Data.height = props.height;

    // glfw settings
}

void MacWindow::Shutdown()
{
    glfwDestroyWindow(m_Window);
}

void MacWindow::OnUpdate()
{
    glfwSwapBuffers(m_Window);
}

} // namespace ft_vox
