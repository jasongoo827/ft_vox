#include "Core/Layer.h"

namespace ft_vox
{
Layer::Layer(const std::string &name)
    : m_DebugName(name)
{
}

Layer::~Layer()
{
}

void Layer::OnAttach()
{
}

void Layer::OnDetach()
{
}

void Layer::OnUpdate()
{
}

void Layer::OnImGuiRender()
{
}
} // namespace ft_vox
