// Joan Andrés (@Andres6936) Github.

#include "MainWindow.hpp"
#include "PanelFiles.hpp"
#include "PanelMessage.hpp"

#include <QVBoxLayout>
#include <QFontDatabase>

#include <qdebug.h>

using namespace Gt;


MainWindow::MainWindow()
	: QWidget()
{
	setWindowTitle(tr("Git Explorer File"));

	// The function returns -1 if the font could not be loaded.
	// Feature C++17, initialize variable in if-block
	if (const int id = QFontDatabase::addApplicationFont(
			"./Font/Atkinson-Hyperlegible-Regular-102.ttf"); id == -1)
	{
		qWarning() << "The font Atkinson Hyperlegible cannot be found.";
	}

	this->setFont({ "Atkinson Hyperlegible", 11 });

	auto mainLayout = new QVBoxLayout(this);

	auto panelFiles = new PanelFiles(this);
	auto panelMessage = new PanelMessage(this);

	mainLayout->addWidget(panelFiles);
	mainLayout->addWidget(panelMessage);

	this->setLayout(mainLayout);
}
