#include "Core/App.h"

int main(int argc, char* argv[])
{
    std::cout << "TEST FT_VOX\n";

    ft_vox::App *app = new ft_vox::App();
    app->Run();

    delete app;

    return 0;
}