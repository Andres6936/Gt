// Joan Andrés (@Andres6936) Github.

#include "MainWindow.hpp"

using namespace Gt;

MainWindow::MainWindow()
	: QMainWindow(), fileTableWidget(new FileTableWidget())
{
	setCentralWidget(fileTableWidget);
	setWindowTitle(tr("Git Explorer File"));
}
