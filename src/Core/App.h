#pragma once

class App
{
public:
    App();
    ~App();

    void Run();
    void Init();
    
    void OnEvent();
    void OnWindowClose();

private:
};