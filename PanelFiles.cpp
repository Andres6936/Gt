// Joan Andrés (@Andres6936) Github.

#include <qdebug.h>

#include "Repository.hpp"
#include "PanelFiles.hpp"

using namespace Gt;

PanelFiles::PanelFiles(QWidget *parent) noexcept : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);
	fileSystem = new FileSystemTree(this);

	mainLayout->addWidget(fileSystem);

	this->setLayout(mainLayout);

	Repository repository1;
	repository1.init("./Test/Curriculum");

	fileSystem->openDirectory("./Test/Curriculum");

	for (const std::string& files: repository1.getUntrackedFiles())
	{
		qWarning() << QString::fromStdString(files);
	}
}
