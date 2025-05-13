#include "Platform/MacWindow.h"
#include "Core/App.h"
#include <iostream>

namespace ft_vox
{
static bool s_GLFWInitialized = false;

static void GLFWErrorCallback(int error, const char *description)
{
    std::cout << "GLFW Error ({0}): {1}" << error << " " << description << '\n';
}

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
    if (!s_GLFWInitialized)
    {
        int32_t success = glfwInit();
		// ASSERT
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwSetErrorCallback(GLFWErrorCallback);
		s_GLFWInitialized = true;
    }

    m_Window = glfwCreateWindow(props.width, props.height, m_Data.title.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(m_Window, &m_Data);

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
		WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

        // just for testing
		App::Get().OnClose();
	});
}

void MacWindow::Shutdown()
{
    glfwDestroyWindow(m_Window);
}

void MacWindow::OnUpdate()
{
    // glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

} // namespace ft_vox
