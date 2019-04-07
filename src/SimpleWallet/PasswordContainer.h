// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
////////////////////////////////////////////////////////////////////////////////
namespace Tools {
	class PasswordContainer {
		public:
			static const size_t max_password_size = 2048;

			PasswordContainer();
			PasswordContainer(std::string&& password);
			PasswordContainer(PasswordContainer&& rhs);
			~PasswordContainer();

			void clear();
			bool empty() const { return m_empty; }
			const std::string& password() const { return m_password; }
			void password(std::string&& val) { m_password = std::move(val); m_empty = false; }
			bool read_password();
			bool read_password(bool verify, std::string msg);
			bool read_and_validate(std::string msg);

		private:
			bool read_from_file();
			bool read_from_tty(std::string& password);

			bool m_empty;
			std::string m_password;
	};
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
