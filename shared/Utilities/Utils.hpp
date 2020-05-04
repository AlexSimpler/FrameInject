#pragma once

namespace Utils {
	int error(const char* error_message);
	void msgBox(const char* msg);
	void successInput(PCSTR msg);
	void getProcId(const char* procName, DWORD& proc_id);
	bool file_exists(std::string file_name);
	int safeExit(void);

	class form {
	public:
	private:
	};
}