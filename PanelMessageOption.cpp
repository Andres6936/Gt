// Joan Andrés (@Andres6936) Github.

#include "PanelMessageOption.hpp"

#include <QHBoxLayout>

using namespace Gt;

PanelMessageOption::PanelMessageOption(QWidget* parent) noexcept : QWidget(parent)
{
	auto mainLayout = new QHBoxLayout(this);

	this->setLayout(mainLayout);
}
