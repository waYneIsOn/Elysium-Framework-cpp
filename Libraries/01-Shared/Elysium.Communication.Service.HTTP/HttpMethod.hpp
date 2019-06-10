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

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API HttpMethod
				{
				public:
					HttpMethod(const Elysium::Core::String& Method);
					HttpMethod(const HttpMethod& Value);
					virtual ~HttpMethod();

					const Elysium::Core::String& GetMethod() const;

					static const Elysium::Core::String& Delete();
					static const Elysium::Core::String& Get();
					static const Elysium::Core::String& Head();
					static const Elysium::Core::String& Options();
					static const Elysium::Core::String& Patch();
					static const Elysium::Core::String& Post();
					static const Elysium::Core::String& Put();
					static const Elysium::Core::String& Trace();
				private:
					const Elysium::Core::String _Method;

					static const Elysium::Core::String _Delete;
					static const Elysium::Core::String _Get;
					static const Elysium::Core::String _Head;
					static const Elysium::Core::String _Options;
					static const Elysium::Core::String _Patch;
					static const Elysium::Core::String _Post;
					static const Elysium::Core::String _Put;
					static const Elysium::Core::String _Trace;
				};
			}
		}
	}
}
#endif
