// Joan Andrés (@Andres6936) Github.

#ifndef GT_PANELMESSAGEOPTION_HPP
#define GT_PANELMESSAGEOPTION_HPP

#include <QWidget>
#include <QPushButton>

namespace Gt
{

	class PanelMessageOption : public QWidget
	{

		Q_OBJECT

	private:

		QPushButton* commitButton;

	public:

		explicit PanelMessageOption(QWidget* parent = nullptr) noexcept;

		bool eventFilter(QObject* _object, QEvent* _event) override;

	};

}

#endif //GT_PANELMESSAGEOPTION_HPP
