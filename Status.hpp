// Joan Andrés (@Andres6936) Github.

#ifndef GT_STATUS_HPP
#define GT_STATUS_HPP

#include <git2.h>
#include <vector>
#include <string>

namespace Gt
{

	class Status
	{

	private:

		/**
		 * Representation of a status collection.
		 */
		git_status_list* status {nullptr};

	public:

		// Construct

		/**
		 * @post Gather file status information.
		 *
		 * @param _repository Repository object.
		 */
		Status(git_repository* _repository);

		// Destructor

		~Status();

		// Methods

		std::vector<std::string> getUntrackedFiles();

	};

}

#endif //GT_STATUS_HPP
