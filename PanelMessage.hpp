// Joan Andrés (@Andres6936) Github.

#ifndef GT_PANELMESSAGE_HPP
#define GT_PANELMESSAGE_HPP

#include <QWidget>

namespace Gt
{
	class PanelMessage : public QWidget
	{

		Q_OBJECT

	public:

		explicit PanelMessage(QWidget* parent = nullptr) noexcept;

	};
}

#endif //GT_PANELMESSAGE_HPP
