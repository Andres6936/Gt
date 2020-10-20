// Joan Andrés (@Andres6936) Github.

#include "MainWindow.hpp"

#include <filesystem>

using namespace Gt;


MainWindow::MainWindow()
	: QMainWindow(), fileTableWidget(new FileTableWidget())
{
	setCentralWidget(fileTableWidget);
	setWindowTitle(tr("Git Explorer File"));

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
