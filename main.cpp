
#include <QApplication>
#include <QStyleFactory>

#include <git2.h>

#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
	git_libgit2_init();

	QApplication a(argc, argv);
	a.setStyle(QStyleFactory::create("Fusion"));
	Gt::MainWindow window {};
	window.show();
	return a.exec();

	git_libgit2_shutdown();
}