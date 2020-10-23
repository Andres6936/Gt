// Joan Andrés (@Andres6936) Github.

#ifndef GT_PANELFILES_HPP
#define GT_PANELFILES_HPP

#include <QWidget>
#include <QVBoxLayout>

#include "FileSystemTree.hpp"

namespace Gt
{
	class PanelFiles : public QWidget
	{

		Q_OBJECT

	private:

		QVBoxLayout *mainLayout;

		FileSystemTree *fileSystem;

	public:

		explicit PanelFiles(QWidget *parent = nullptr) noexcept;

	};
}

#endif //GT_PANELFILES_HPP
