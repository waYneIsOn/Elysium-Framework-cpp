/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMETHOD
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMETHOD

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API HttpMethod final
	{
	public:
		HttpMethod(const Elysium::Core::String& Method);
		HttpMethod(const HttpMethod& Source);
		HttpMethod(HttpMethod&& Right) noexcept;
		~HttpMethod();

		HttpMethod& operator=(const HttpMethod& Source);
		HttpMethod& operator=(HttpMethod&& Right) noexcept;

		const Elysium::Core::String& GetMethod() const;

		static const HttpMethod& Connect();
		static const HttpMethod& Delete();
		static const HttpMethod& Get();
		static const HttpMethod& Head();
		static const HttpMethod& Options();
		static const HttpMethod& Patch();
		static const HttpMethod& Post();
		static const HttpMethod& Put();
		static const HttpMethod& Trace();
	private:
		Elysium::Core::String _Method;

		static const HttpMethod _Connect;
		static const HttpMethod _Delete;
		static const HttpMethod _Get;
		static const HttpMethod _Head;
		static const HttpMethod _Options;
		static const HttpMethod _Patch;
		static const HttpMethod _Post;
		static const HttpMethod _Put;
		static const HttpMethod _Trace;
	};
}
#endif
