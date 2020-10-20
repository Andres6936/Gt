
#include <QApplication>
#include <QStyleFactory>

#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyle(QStyleFactory::create("Fusion"));
	Gt::MainWindow window {};
	window.show();
	return a.exec();
}