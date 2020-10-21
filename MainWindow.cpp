// Joan Andrés (@Andres6936) Github.

#include "MainWindow.hpp"

#include <QFontDatabase>
#include <filesystem>
#include <qdebug.h>

using namespace Gt;


MainWindow::MainWindow()
	: QMainWindow(), fileTableWidget(new FileTableWidget())
{
	setCentralWidget(fileTableWidget);
	setWindowTitle(tr("Git Explorer File"));

	// The function returns -1 if the font could not be loaded.
	// Feature C++17, initialize variable in if-block
	if (const int id = QFontDatabase::addApplicationFont(
			"./Font/Atkinson-Hyperlegible-Regular-102.ttf"); id == -1)
	{
		qWarning() << "The font Atkinson Hyperlegible cannot be found.";
	}

	this->setFont({ "Atkinson Hyperlegible", 11 });

	startUp();
}

void MainWindow::startUp() const noexcept
{
	namespace fs = std::filesystem;

	for (const fs::directory_entry& directory: fs::directory_iterator("/"))
	{
		const fs::path& path = directory.path();

		fileTableWidget->addEntry(QString::fromStdString(path.filename().string()),
				QString::fromStdString(path.relative_path()));
	}
}
