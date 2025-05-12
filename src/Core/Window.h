#pragma once

#include <string>
#include <GLFW/glfw3.h>

namespace ft_vox
{
struct WindowProps
{
	std::string title;
	uint32_t width;
	uint32_t height;

	WindowProps(const std::string &title = "ft_vox", unsigned int width = 1280,
				unsigned int height = 720)
		: title(title), width(width), height(height)
	{
	}
};

class Window
{
public:
    Window() = default;
    virtual ~Window() = default;

    virtual void OnUpdate() = 0;

    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;
    virtual GLFWwindow *GetNativeWindow() const = 0;

    // virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

    static Window *Create(const WindowProps &props = WindowProps());

private:
    GLFWwindow *m_Window = nullptr;
};
} // namespace ft_vox