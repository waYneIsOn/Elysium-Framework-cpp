/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_IENUMERABLE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/IEnumerable.hpp"
#endif

#ifndef _MAP_
#include <map>
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_GENERIC_LIST
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/List.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				namespace Headers
				{
					class ELYSIUM_COMMUNICATION_API HttpHeaders : public Elysium::Core::Collections::IEnumerable<std::pair<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>>
					{
					public:
						virtual ~HttpHeaders();

						void Add(const Elysium::Core::String& Name, const Elysium::Core::Collections::Generic::List<Elysium::Core::String> & Values);
						void Add(const Elysium::Core::String& Name, const Elysium::Core::String& Value);
						void Clear();
						bool Contains(const ElysiumChar* Name) const;
						bool Contains(const Elysium::Core::String& Name) const;
						const Elysium::Core::Collections::Generic::List<Elysium::Core::String>& GetValues(const ElysiumChar* Name) const;
						const Elysium::Core::Collections::Generic::List<Elysium::Core::String>& GetValues(const Elysium::Core::String& Name) const;
						bool Remove(const Elysium::Core::String& Name);
					protected:
						HttpHeaders();
					private:
						std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>> _Headers;
					};
				}
			}
		}
	}
}
#endif
