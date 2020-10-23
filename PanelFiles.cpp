// Joan Andrés (@Andres6936) Github.

#include "PanelFiles.hpp"

using namespace Gt;

PanelFiles::PanelFiles(QWidget *parent) noexcept : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);
	fileSystem = new FileSystemTree(this);

	mainLayout->addWidget(fileSystem);

	this->setLayout(mainLayout);
}
