// Joan Andrés (@Andres6936) Github.

#include "MainWindow.hpp"

#include <QFontDatabase>
#include <QMessageBox>
#include <filesystem>
#include <qdebug.h>

using namespace Gt;


MainWindow::MainWindow()
	: QMainWindow(), fileTableWidget(new FileTableWidget())
{
	setCentralWidget(fileTableWidget);
	setWindowTitle(tr("Git Explorer File"));

	int id = QFontDatabase::addApplicationFont("./Font/Atkinson-Hyperlegible-Regular-102.ttf");
	QMessageBox::information(nullptr, "Message", QString::number(id));

	QFont font("Atkinson Hyperlegible", 11);

	qDebug() << font.family();

	this->setFont(font);

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
