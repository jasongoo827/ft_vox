#include <iostream>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

int main(int argc, char* argv[])
{
    std::cout << "TEST FT_VOX\n";

    glm::vec3 pos = glm::vec3(1.0f, 2.0f, 3.0f);

    std::cout << pos.x << " " << pos.y << " " << pos.z << '\n';

    return 0;
}