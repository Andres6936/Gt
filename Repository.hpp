// Joan Andrés (@Andres6936) Github.

#ifndef GT_REPOSITORY_HPP
#define GT_REPOSITORY_HPP

#include <git2.h>
#include <vector>
#include <string>
#include <string_view>

namespace Gt
{

	class Repository
	{

	private:

		git_repository* repository {nullptr};

	public:

		// Construct

		/**
		 * Open the repository.
		 *
		 * @pre The 'path' argument must point to either a git repository
		 *  folder, or an existing work dir.
		 *
		 * @post The repository is open and list for use.
		 *
		 * @param path the path to the repository
		 */
		Repository(std::string_view path);

		// Destructor

		~Repository();

		// Methods

		std::vector<std::string> getUntrackedFiles();

	};

}

#endif //GT_REPOSITORY_HPP
