#pragma once

#include <cocos2d.h>
#include <cocos-ext.h>
#include <fmod.hpp>
#include "../predeclare.hpp"
#include "enums.hpp"
#include <fmt/core.h>

using TodoReturn = void;

namespace redecore {
	inline auto m_base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

	inline uintptr_t m_cocosBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));

	inline uintptr_t m_extensionsBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("libExtensions.dll"));

	inline uintptr_t getBase() { return m_base; };

	inline uintptr_t getCocosBase() { return m_cocosBase; };

	inline uintptr_t getExtensionsBase() { return m_extensionsBase; };

	inline bool init() {
#if (__WARN_DEBUG__ == true)
		static_assert(sizeof(std::string) == 24,
			"Any classes containing member strings or using strings in functions will break!\n"
			"Please switch your compiler to x64-Release\n"
			"");
#endif
		return m_base;
	}
};


#include "classes.hpp"