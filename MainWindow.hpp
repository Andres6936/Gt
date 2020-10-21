// Joan Andrés (@Andres6936) Github.

#ifndef QTGIT_MAINWINDOW_HPP
#define QTGIT_MAINWINDOW_HPP

#include <QMainWindow>

#include "FileSystemTree.hpp"

namespace Gt
{

	class MainWindow : public QMainWindow
	{

		Q_OBJECT

	private:

		FileSystemTree *fileTableWidget{};

		void startUp() const noexcept;

	public:

		explicit MainWindow();

		virtual ~MainWindow() = default;

	signals:

	public slots:

	};

}

#endif //QTGIT_MAINWINDOW_HPP
