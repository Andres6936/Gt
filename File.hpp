// Joan Andrés (@Andres6936) Github.

#ifndef GT_FILE_HPP
#define GT_FILE_HPP

#include <QString>

namespace Gt
{
	class File
	{

	public:

		QString name {};

		QString path {};

		bool equals(const File& _other) const noexcept;
	};
}


#endif //GT_FILE_HPP
